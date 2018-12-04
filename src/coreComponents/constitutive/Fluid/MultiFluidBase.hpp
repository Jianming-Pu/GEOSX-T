/*
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Copyright (c) 2018, Lawrence Livermore National Security, LLC.
 *
 * Produced at the Lawrence Livermore National Laboratory
 *
 * LLNL-CODE-746361
 *
 * All rights reserved. See COPYRIGHT for details.
 *
 * This file is part of the GEOSX Simulation Framework.
 *
 * GEOSX is a free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License (as published by the
 * Free Software Foundation) version 2.1 dated February 1999.
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */

/**
  * @file MultiFluidBase.hpp
  */

#ifndef SRC_COMPONENTS_CORE_SRC_CONSTITUTIVE_MULTIFLUIDBASE_HPP
#define SRC_COMPONENTS_CORE_SRC_CONSTITUTIVE_MULTIFLUIDBASE_HPP

#include "constitutive/ConstitutiveBase.hpp"

namespace geosx
{

namespace constitutive
{

namespace detail
{

template<typename T, int DIM>
struct array_slice_helper
{
  using type = array_slice<T, DIM>;
};

// an array slice of DIM=0 decays to a reference to scalar
template<typename T>
struct array_slice_helper<T, 0>
{
  using type = T &;
};

// an array1 slice of DIM=1 uses specialization (possibly a raw pointer)
template<typename T>
struct array_slice_helper<T, 1>
{
  using type = arraySlice1d<T>;
};

}

template<int DIM>
using real_array_slice = typename detail::array_slice_helper<real64, DIM>::type;

template<int DIM>
using real_array_const_slice = typename detail::array_slice_helper<real64 const, DIM>::type;

// helper struct to represent a var and its derivatives
template<int DIM>
struct CompositionalVarContainer
{
  real_array_slice<DIM>   value; // variable value
  real_array_slice<DIM>   dPres; // derivative w.r.t. pressure
  real_array_slice<DIM>   dTemp; // derivative w.r.t. temperature
  real_array_slice<DIM+1> dComp; // derivative w.r.t. composition
};

template<int DIM>
struct CompositionalVarConstContainer
{
  real_array_const_slice<DIM>   value; // variable value
  real_array_const_slice<DIM>   dPres; // derivative w.r.t. pressure
  real_array_const_slice<DIM>   dTemp; // derivative w.r.t. temperature
  real_array_const_slice<DIM+1> dComp; // derivative w.r.t. composition
};

class MultiFluidBase : public ConstitutiveBase
{
public:

  // define a limit on number of components
  static constexpr localIndex MAX_NUM_COMPONENTS = 32;
  static constexpr localIndex MAX_NUM_PHASES = 4;

  MultiFluidBase( std::string const & name, ManagedGroup * const parent );

  virtual ~MultiFluidBase() override;

  virtual void FillDocumentationNode() override;

  virtual void ReadXML_PostProcess() override;

  virtual void AllocateConstitutiveData( dataRepository::ManagedGroup * const parent,
                                         localIndex const numConstitutivePointsPerParentIndex ) override;

  virtual void StateUpdate( dataRepository::ManagedGroup const * const input,
                            dataRepository::ManagedGroup const * const parameters,
                            dataRepository::ManagedGroup * const stateVariables,
                            integer const systemAssembleFlag ) const override {}

  // *** MultiphaseFluid-specific interface

  virtual void StateUpdatePointMultiFluid( real64 const & pres,
                                           real64 const & temp,
                                           arraySlice1d<real64 const> const & composition,
                                           localIndex const k,
                                           localIndex const q ) {}

  localIndex numFluidComponents() const;

  string const & componentName( localIndex ic ) const;

  localIndex numFluidPhases() const;

  string const & phaseName( localIndex ip ) const;

  bool getMassFlag() const;

  void setMassFlag(bool flag);

  struct viewKeyStruct : ConstitutiveBase::viewKeyStruct
  {
    static constexpr auto componentNamesString       = "componentNames";
    static constexpr auto componentMolarWeightString = "componentMolarWeight";

    static constexpr auto phaseNamesString     = "phaseNames";

    static constexpr auto phaseFractionString                            = "phaseFraction";                          // xi_p
    static constexpr auto dPhaseFraction_dPressureString                 = "dPhaseFraction_dPressure";               // dXi_p/dP
    static constexpr auto dPhaseFraction_dTemperatureString              = "dPhaseFraction_dTemperature";            // dXi_p/dT
    static constexpr auto dPhaseFraction_dGlobalCompFractionString       = "dPhaseFraction_dGlobalCompFraction";     // dXi_p/dz

    static constexpr auto phaseDensityString                             = "phaseDensity";                           // rho_p
    static constexpr auto dPhaseDensity_dPressureString                  = "dPhaseDensity_dPressure";                // dRho_p/dP
    static constexpr auto dPhaseDensity_dTemperatureString               = "dPhaseDensity_dTemperature";             // dRho_p/dT
    static constexpr auto dPhaseDensity_dGlobalCompFractionString        = "dPhaseDensity_dGlobalCompFraction";      // dRho_p/dz

    static constexpr auto phaseViscosityString                           = "phaseViscosity";                         // mu_p
    static constexpr auto dPhaseViscosity_dPressureString                = "dPhaseViscosity_dPressure";              // dMu_p/dP
    static constexpr auto dPhaseViscosity_dTemperatureString             = "dPhaseViscosity_dTemperature";           // dMu_p/dT
    static constexpr auto dPhaseViscosity_dGlobalCompFractionString      = "dPhaseViscosity_dGlobalCompFraction";    // dMu_p/dz

    static constexpr auto phaseCompFractionString                        = "phaseCompFraction";                      // x_cp
    static constexpr auto dPhaseCompFraction_dPressureString             = "dPhaseCompFraction_dPressure";           // dx_cp/dP
    static constexpr auto dPhaseCompFraction_dTemperatureString          = "dPhaseCompFraction_dTemperature";        // dx_cp/dT
    static constexpr auto dPhaseCompFraction_dGlobalCompFractionString   = "dPhaseCompFraction_dGlobalCompFraction"; // dx_cp/dz

    static constexpr auto totalDensityString                             = "totalDensity";                           // rho_t
    static constexpr auto dTotalDensity_dPressureString                  = "dTotalDensity_dPressure";                // dRho_t/dP
    static constexpr auto dTotalDensity_dTemperatureString               = "dTotalDensity_dTemperature";             // dRho_t/dT
    static constexpr auto dTotalDensity_dGlobalCompFractionString        = "dTotalDensity_dGlobalCompFraction";      // dRho_t/dz

    using ViewKey = dataRepository::ViewKey;

    ViewKey componentNames       = { componentNamesString };
    ViewKey componentMolarWeight = { componentMolarWeightString };

    ViewKey phaseNames     = { phaseNamesString };

    ViewKey phaseFraction                            = { phaseFractionString };                            // xi_p
    ViewKey dPhaseFraction_dPressure                 = { dPhaseFraction_dPressureString };                 // dXi_p/dP
    ViewKey dPhaseFraction_dTemperature              = { dPhaseFraction_dTemperatureString };              // dXi_p/dT
    ViewKey dPhaseFraction_dGlobalCompFraction       = { dPhaseFraction_dGlobalCompFractionString };       // dXi_p/dz

    ViewKey phaseDensity                             = { phaseDensityString };                             // rho_p
    ViewKey dPhaseDensity_dPressure                  = { dPhaseDensity_dPressureString };                  // dRho_p/dP
    ViewKey dPhaseDensity_dTemperature               = { dPhaseDensity_dTemperatureString };               // dRho_p/dT
    ViewKey dPhaseDensity_dGlobalCompFraction        = { dPhaseDensity_dGlobalCompFractionString };        // dRho_p/dz

    ViewKey phaseViscosity                           = { phaseViscosityString };                           // rho_p
    ViewKey dPhaseViscosity_dPressure                = { dPhaseViscosity_dPressureString };                // dRho_p/dP
    ViewKey dPhaseViscosity_dTemperature             = { dPhaseViscosity_dTemperatureString };             // dRho_p/dT
    ViewKey dPhaseViscosity_dGlobalCompFraction      = { dPhaseViscosity_dGlobalCompFractionString };      // dRho_p/dz

    ViewKey phaseCompFraction                        = { phaseCompFractionString };                        // x_cp
    ViewKey dPhaseCompFraction_dPressure             = { dPhaseCompFraction_dPressureString };             // dx_cp/dP
    ViewKey dPhaseCompFraction_dTemperature          = { dPhaseCompFraction_dTemperatureString };          // dx_cp/dT
    ViewKey dPhaseCompFraction_dGlobalCompFraction   = { dPhaseCompFraction_dGlobalCompFractionString };   // dx_cp/dz

    ViewKey totalDensity                             = { totalDensityString };                             // rho_t
    ViewKey dTotalDensity_dPressure                  = { dTotalDensity_dPressureString };                  // dRho_t/dP
    ViewKey dTotalDensity_dTemperature               = { dTotalDensity_dTemperatureString };               // dRho_t/dT
    ViewKey dTotalDensity_dGlobalCompFraction        = { dTotalDensity_dGlobalCompFractionString };        // dRho_t/dz

  } viewKeysMultiFluidBase;

protected:

  // flag indicating whether input/output component fractions are treated as mass fractions
  bool m_useMass;

  // general fluid composition information
  string_array    m_componentNames;
  array1d<real64> m_componentMolarWeight;

  string_array    m_phaseNames;

  array3d<real64> m_phaseFraction;
  array3d<real64> m_dPhaseFraction_dPressure;
  array3d<real64> m_dPhaseFraction_dTemperature;
  array4d<real64> m_dPhaseFraction_dGlobalCompFraction;

  array3d<real64> m_phaseDensity;
  array3d<real64> m_dPhaseDensity_dPressure;
  array3d<real64> m_dPhaseDensity_dTemperature;
  array4d<real64> m_dPhaseDensity_dGlobalCompFraction;

  array3d<real64> m_phaseViscosity;
  array3d<real64> m_dPhaseViscosity_dPressure;
  array3d<real64> m_dPhaseViscosity_dTemperature;
  array4d<real64> m_dPhaseViscosity_dGlobalCompFraction;

  array4d<real64> m_phaseCompFraction;
  array4d<real64> m_dPhaseCompFraction_dPressure;
  array4d<real64> m_dPhaseCompFraction_dTemperature;
  array5d<real64> m_dPhaseCompFraction_dGlobalCompFraction;

  array2d<real64> m_totalDensity;
  array2d<real64> m_dTotalDensity_dPressure;
  array2d<real64> m_dTotalDensity_dTemperature;
  array3d<real64> m_dTotalDensity_dGlobalCompFraction;

};

} //namespace constitutive

} //namespace geosx

#endif //SRC_COMPONENTS_CORE_SRC_CONSTITUTIVE_MULTIFLUIDBASE_HPP