/*
 * ------------------------------------------------------------------------------------------------------------
 * SPDX-License-Identifier: LGPL-2.1-only
 *
 * Copyright (c) 2018-2020 Lawrence Livermore National Security LLC
 * Copyright (c) 2018-2020 The Board of Trustees of the Leland Stanford Junior University
 * Copyright (c) 2018-2020 TotalEnergies
 * Copyright (c) 2019-     GEOSX Contributors
 * All rights reserved
 *
 * See top level LICENSE, COPYRIGHT, CONTRIBUTORS, NOTICE, and ACKNOWLEDGEMENTS files for details.
 * ------------------------------------------------------------------------------------------------------------
 */

// Source includes
#include "common/DataTypes.hpp"
#include "constitutive/fluid/multifluid/compositional/functions/CubicEOSPhaseModel.hpp"
#include "TestFluid.hpp"
#include "TestFluidUtilities.hpp"

// TPL includes
#include <gtest/gtest.h>

using namespace geos;
using namespace geos::testing;
using namespace geos::constitutive;

static constexpr real64 relTol = 1.0e-5;
static constexpr real64 absTol = 1.0e-8;

TEST( CubicEOSTest, testCubicEOSTwoComponentsSRK )
{
  constexpr integer numComps = 2;

  auto fluid = TestFluid< numComps >::create( {Fluid::C1, Fluid::C5} );

  auto criticalPressure = fluid->getCriticalPressure();
  auto criticalTemperature = fluid->getCriticalTemperature();
  auto omega = fluid->getAcentricFactor();
  real64 binaryInteractionCoefficients = 0.0; // not implemented yet

  real64 pressure = 0.0;
  real64 temperature = 0.0;
  array1d< real64 > composition( numComps );
  array1d< real64 > logFugacityCoefficients( numComps );
  array1d< real64 > expectedLogFugacityCoefficients( numComps );

  ///////////////////////////////////////////

  pressure = 1e6;
  temperature = 350;
  composition[0] = 0.1;
  composition[1] = 0.9;

  expectedLogFugacityCoefficients[0] = 0.0126163;
  expectedLogFugacityCoefficients[1] = -0.00820777;

  CubicEOSPhaseModel< SoaveRedlichKwongEOS >::
  compute( numComps,
           pressure, temperature, composition,
           criticalPressure, criticalTemperature, omega, binaryInteractionCoefficients,
           logFugacityCoefficients );

  checkRelativeError( logFugacityCoefficients[0], expectedLogFugacityCoefficients[0], relTol );
  checkRelativeError( logFugacityCoefficients[1], expectedLogFugacityCoefficients[1], relTol );

  ///////////////////////////////////////////

  pressure = 5e7;
  temperature = 350;
  composition[0] = 0.1;
  composition[1] = 0.9;

  expectedLogFugacityCoefficients[0] = 0.481514;
  expectedLogFugacityCoefficients[1] = -0.0701117;

  CubicEOSPhaseModel< SoaveRedlichKwongEOS >::
  compute( numComps,
           pressure, temperature, composition,
           criticalPressure, criticalTemperature, omega, binaryInteractionCoefficients,
           logFugacityCoefficients );

  checkRelativeError( logFugacityCoefficients[0], expectedLogFugacityCoefficients[0], relTol );
  checkRelativeError( logFugacityCoefficients[1], expectedLogFugacityCoefficients[1], relTol );

  ///////////////////////////////////////////

  pressure = 1e6;
  temperature = 350;
  composition[0] = 0.5;
  composition[1] = 0.5;

  expectedLogFugacityCoefficients[0] = 0.00721367;
  expectedLogFugacityCoefficients[1] = -0.00589892;

  CubicEOSPhaseModel< SoaveRedlichKwongEOS >::
  compute( numComps,
           pressure, temperature, composition,
           criticalPressure, criticalTemperature, omega, binaryInteractionCoefficients,
           logFugacityCoefficients );

  checkRelativeError( logFugacityCoefficients[0], expectedLogFugacityCoefficients[0], relTol );
  checkRelativeError( logFugacityCoefficients[1], expectedLogFugacityCoefficients[1], relTol );

  ///////////////////////////////////////////

  pressure = 5e7;
  temperature = 350;
  composition[0] = 0.5;
  composition[1] = 0.5;

  expectedLogFugacityCoefficients[0] = 0.334027;
  expectedLogFugacityCoefficients[1] = -0.00629384;

  CubicEOSPhaseModel< SoaveRedlichKwongEOS >::
  compute( numComps,
           pressure, temperature, composition,
           criticalPressure, criticalTemperature, omega, binaryInteractionCoefficients,
           logFugacityCoefficients );

  checkRelativeError( logFugacityCoefficients[0], expectedLogFugacityCoefficients[0], relTol );
  checkRelativeError( logFugacityCoefficients[1], expectedLogFugacityCoefficients[1], relTol );

}

TEST( CubicEOSTest, testCubicEOSFourComponentsPR )
{
  constexpr integer numComps = 4;

  auto fluid = TestFluid< numComps >::create( {Fluid::N2, Fluid::C8, Fluid::C10, Fluid::H2O} );

  auto criticalPressure = fluid->getCriticalPressure();
  auto criticalTemperature = fluid->getCriticalTemperature();
  auto omega = fluid->getAcentricFactor();
  real64 binaryInteractionCoefficients = 0.0; // not implemented yet

  real64 pressure = 0.0;
  real64 temperature = 0.0;
  array1d< real64 > composition( numComps );
  array1d< real64 > logFugacityCoefficients( numComps );
  array1d< real64 > expectedLogFugacityCoefficients( numComps );

  ///////////////////////////////////////////

  pressure = 1e7;
  temperature = 297.15;
  composition[0] = 0.0569514;
  composition[1] = 0.104818;
  composition[2] = 0.104822;
  composition[3] = 0.733409;

  expectedLogFugacityCoefficients[0] = 2.8298;
  expectedLogFugacityCoefficients[1] = -8.88628;
  expectedLogFugacityCoefficients[2] = -17.0201;
  expectedLogFugacityCoefficients[3] = -5.33003;

  CubicEOSPhaseModel< PengRobinsonEOS >::
  compute( numComps,
           pressure, temperature, composition,
           criticalPressure, criticalTemperature, omega, binaryInteractionCoefficients,
           logFugacityCoefficients );

  checkRelativeError( logFugacityCoefficients[0], expectedLogFugacityCoefficients[0], relTol );
  checkRelativeError( logFugacityCoefficients[1], expectedLogFugacityCoefficients[1], relTol );
  checkRelativeError( logFugacityCoefficients[2], expectedLogFugacityCoefficients[2], relTol );
  checkRelativeError( logFugacityCoefficients[3], expectedLogFugacityCoefficients[3], relTol );

  ///////////////////////////////////////////

  pressure = 1e5;
  temperature = 297.15;
  composition[0] = 0.00185559;
  composition[1] = 0.332324;
  composition[2] = 0.664862;
  composition[3] = 0.000958244;

  expectedLogFugacityCoefficients[0] = 6.28652;
  expectedLogFugacityCoefficients[1] = -5.83771;
  expectedLogFugacityCoefficients[2] = -16.638;
  expectedLogFugacityCoefficients[3] = 0.361984;

  CubicEOSPhaseModel< PengRobinsonEOS >::
  compute( numComps,
           pressure, temperature, composition,
           criticalPressure, criticalTemperature, omega, binaryInteractionCoefficients,
           logFugacityCoefficients );

  checkRelativeError( logFugacityCoefficients[0], expectedLogFugacityCoefficients[0], relTol );
  checkRelativeError( logFugacityCoefficients[1], expectedLogFugacityCoefficients[1], relTol );
  checkRelativeError( logFugacityCoefficients[2], expectedLogFugacityCoefficients[2], relTol );
  checkRelativeError( logFugacityCoefficients[3], expectedLogFugacityCoefficients[3], relTol );

  ///////////////////////////////////////////

  pressure = 4.78429e+06;
  temperature = 297.15;
  composition[0] = 0.0566196;
  composition[1] = 0.31411;
  composition[2] = 0.628223;
  composition[3] = 0.001047;

  expectedLogFugacityCoefficients[0] = 2.49484;
  expectedLogFugacityCoefficients[1] = -9.36508;
  expectedLogFugacityCoefficients[2] = -19.8123;
  expectedLogFugacityCoefficients[3] = -3.42481;

  CubicEOSPhaseModel< PengRobinsonEOS >::
  compute( numComps,
           pressure, temperature, composition,
           criticalPressure, criticalTemperature, omega, binaryInteractionCoefficients,
           logFugacityCoefficients );

  checkRelativeError( logFugacityCoefficients[0], expectedLogFugacityCoefficients[0], relTol );
  checkRelativeError( logFugacityCoefficients[1], expectedLogFugacityCoefficients[1], relTol );
  checkRelativeError( logFugacityCoefficients[2], expectedLogFugacityCoefficients[2], relTol );
  checkRelativeError( logFugacityCoefficients[3], expectedLogFugacityCoefficients[3], relTol );

}

TEST( CubicEOSTest, testCubicEOSFourComponentsSRK )
{
  constexpr integer numComps = 4;

  auto fluid = TestFluid< numComps >::create( {Fluid::N2, Fluid::C8, Fluid::C10, Fluid::H2O} );

  auto criticalPressure = fluid->getCriticalPressure();
  auto criticalTemperature = fluid->getCriticalTemperature();
  auto omega = fluid->getAcentricFactor();
  real64 binaryInteractionCoefficients = 0.0; // not implemented yet

  real64 pressure = 0.0;
  real64 temperature = 0.0;
  array1d< real64 > composition( 4 );
  array1d< real64 > logFugacityCoefficients( 4 );
  array1d< real64 > expectedLogFugacityCoefficients( 4 );

  ///////////////////////////////////////////

  pressure = 1e7;
  temperature = 297.15;
  composition[0] = 0.994214;
  composition[1] = 6.05198e-05;
  composition[2] = 5.98122e-08;
  composition[3] = 0.00572563;

  expectedLogFugacityCoefficients[0] = 0.00588361;
  expectedLogFugacityCoefficients[1] = -1.44445;
  expectedLogFugacityCoefficients[2] = -2.83086;
  expectedLogFugacityCoefficients[3] = -0.618972;

  CubicEOSPhaseModel< SoaveRedlichKwongEOS >::
  compute( numComps,
           pressure, temperature, composition,
           criticalPressure, criticalTemperature, omega, binaryInteractionCoefficients,
           logFugacityCoefficients );

  checkRelativeError( logFugacityCoefficients[0], expectedLogFugacityCoefficients[0], relTol );
  checkRelativeError( logFugacityCoefficients[1], expectedLogFugacityCoefficients[1], relTol );
  checkRelativeError( logFugacityCoefficients[2], expectedLogFugacityCoefficients[2], relTol );
  checkRelativeError( logFugacityCoefficients[3], expectedLogFugacityCoefficients[3], relTol );

  ///////////////////////////////////////////

  pressure = 1e5;
  temperature = 297.15;
  composition[0] = 0.997965;
  composition[1] = 0.000851981;
  composition[2] = 2.89283e-08;
  composition[3] = 0.00118249;

  expectedLogFugacityCoefficients[0] = -5.94544e-05;
  expectedLogFugacityCoefficients[1] = -0.0168209;
  expectedLogFugacityCoefficients[2] = -0.0334318;
  expectedLogFugacityCoefficients[3] = -0.00664411;

  CubicEOSPhaseModel< SoaveRedlichKwongEOS >::
  compute( numComps,
           pressure, temperature, composition,
           criticalPressure, criticalTemperature, omega, binaryInteractionCoefficients,
           logFugacityCoefficients );

  checkRelativeError( logFugacityCoefficients[0], expectedLogFugacityCoefficients[0], relTol );
  checkRelativeError( logFugacityCoefficients[1], expectedLogFugacityCoefficients[1], relTol );
  checkRelativeError( logFugacityCoefficients[2], expectedLogFugacityCoefficients[2], relTol );
  checkRelativeError( logFugacityCoefficients[3], expectedLogFugacityCoefficients[3], relTol );

  ///////////////////////////////////////////

  pressure = 1.83959e+06;
  temperature = 297.15;
  composition[0] = 0.0309329;
  composition[1] = 0.319683;
  composition[2] = 0.637861;
  composition[3] = 0.011523;

  expectedLogFugacityCoefficients[0] = 3.47428;
  expectedLogFugacityCoefficients[1] = -8.75355;
  expectedLogFugacityCoefficients[2] = -19.6075;
  expectedLogFugacityCoefficients[3] = -2.69792;

  CubicEOSPhaseModel< SoaveRedlichKwongEOS >::
  compute( numComps,
           pressure, temperature, composition,
           criticalPressure, criticalTemperature, omega, binaryInteractionCoefficients,
           logFugacityCoefficients );

  checkRelativeError( logFugacityCoefficients[0], expectedLogFugacityCoefficients[0], relTol );
  checkRelativeError( logFugacityCoefficients[1], expectedLogFugacityCoefficients[1], relTol );
  checkRelativeError( logFugacityCoefficients[2], expectedLogFugacityCoefficients[2], relTol );
  checkRelativeError( logFugacityCoefficients[3], expectedLogFugacityCoefficients[3], relTol );

}

// -----------------------------------------------------------------
// Derivative tests
// -----------------------------------------------------------------

template< int NC >
using TestData = std::tuple< real64 const, real64 const, Feed< NC > const >;

template< int NC >
struct TestFeed
{
  static std::array< Feed< NC >, 3 > const feeds;
};

template<>
std::array< Feed< 2 >, 3 > const TestFeed< 2 >::feeds = {
  Feed< 2 >{0.100000, 0.900000},
  Feed< 2 >{0.500000, 0.500000},
  Feed< 2 >{0.001000, 0.999000}
};

template<>
std::array< Feed< 4 >, 3 > const TestFeed< 4 >::feeds = {
  Feed< 4 >{0.030933, 0.319683, 0.637861, 0.011523},
  Feed< 4 >{0.000000, 0.349686, 0.637891, 0.012423},
  Feed< 4 >{0.000000, 0.349686, 0.650314, 0.000000}
};

template< int NC >
std::vector< TestData< NC > > generateTestData()
{
  std::array< real64 const, 2 > pressures( {1.83959e+06, 1.83959e+08} );
  std::array< real64 const, 2 > temperatures( {2.97150e+02, 3.63000e+02} );
  std::vector< TestData< NC > > testData;
  for( const real64 pressure : pressures )
  {
    for( const real64 temperature : temperatures )
    {
      for( const auto & composition : TestFeed< NC >::feeds )
      {
        testData.emplace_back( pressure, temperature, composition );
      }
    }
  }
  return testData;
}

template< typename EOS, int NC >
class DerivativeTestFixture : public ::testing::TestWithParam< TestData< NC > >
{
public:
  static constexpr integer numComps = NC;
  using ParamType = std::tuple< real64 const, real64 const, Feed< NC > const >;
public:
  DerivativeTestFixture();
  ~DerivativeTestFixture() = default;

protected:
  std::unique_ptr< TestFluid< NC > > m_fluid;
};

template<>
DerivativeTestFixture< PengRobinsonEOS, 2 >::DerivativeTestFixture()
  : m_fluid( TestFluid< 2 >::create( {Fluid::C1, Fluid::C5} ))
{}
template<>
DerivativeTestFixture< SoaveRedlichKwongEOS, 2 >::DerivativeTestFixture()
  : m_fluid( TestFluid< 2 >::create( {Fluid::C1, Fluid::C5} ))
{}

template<>
DerivativeTestFixture< PengRobinsonEOS, 4 >::DerivativeTestFixture()
  : m_fluid( TestFluid< 4 >::create( {Fluid::N2, Fluid::C8, Fluid::C10, Fluid::H2O} ))
{}
template<>
DerivativeTestFixture< SoaveRedlichKwongEOS, 4 >::DerivativeTestFixture()
  : m_fluid( TestFluid< 4 >::create( {Fluid::N2, Fluid::C8, Fluid::C10, Fluid::H2O} ))
{}

template< typename EOS, int NC >
class MixCoeffDerivativeTestFixture : public DerivativeTestFixture< EOS, NC >
{
public:
  using DerivativeTestFixture< EOS, NC >::numComps;
  using ParamType = typename DerivativeTestFixture< EOS, NC >::ParamType;
public:
  void testNumericalDerivatives( ParamType const & testData ) const
  {
    auto const & fluid = *this->m_fluid;
    auto criticalPressure = fluid.getCriticalPressure();
    auto criticalTemperature = fluid.getCriticalTemperature();
    auto omega = fluid.getAcentricFactor();
    real64 constexpr binaryInteractionCoefficients = 0.0; // not implemented yet

    array1d< real64 > aPureCoefficient( numComps );
    array1d< real64 > bPureCoefficient( numComps );

    real64 daMixtureCoefficient_dp = 0.0;
    real64 dbMixtureCoefficient_dp = 0.0;
    real64 daMixtureCoefficient_dt = 0.0;
    real64 dbMixtureCoefficient_dt = 0.0;
    array1d< real64 > daMixtureCoefficient_dz( numComps );
    array1d< real64 > dbMixtureCoefficient_dz( numComps );

    array1d< real64 > composition;
    real64 const pressure = std::get< 0 >( testData );
    real64 const temperature = std::get< 1 >( testData );
    TestFluid< NC >::createArray( composition, std::get< 2 >( testData ));

    auto computeCoefficients = [&]( real64 const p, real64 const t, auto const & zmf ) -> std::pair< real64 const, real64 const > {
      real64 a = 0.0;
      real64 b = 0.0;
      CubicEOSPhaseModel< EOS >::computeMixtureCoefficients(
        numComps,
        p, t, zmf,
        criticalPressure, criticalTemperature, omega,
        binaryInteractionCoefficients,
        aPureCoefficient,
        bPureCoefficient,
        a, b
        );
      return {a, b};
    };

    // Calculate values
    auto [aMixtureCoefficient, bMixtureCoefficient] = computeCoefficients( pressure, temperature, composition );

    // Calculate derivatives
    CubicEOSPhaseModel< EOS >::computeMixtureCoefficients(
      numComps,
      pressure,
      temperature,
      composition,
      criticalPressure,
      criticalTemperature,
      omega,
      binaryInteractionCoefficients,
      aPureCoefficient,
      bPureCoefficient,
      aMixtureCoefficient,
      bMixtureCoefficient,
      daMixtureCoefficient_dp,
      dbMixtureCoefficient_dp,
      daMixtureCoefficient_dt,
      dbMixtureCoefficient_dt,
      daMixtureCoefficient_dz,
      dbMixtureCoefficient_dz );

    // Compare against numerical derivatives
    // -- Pressure derivative
    real64 const dp = 1.0e-4 * pressure;
    geos::testing::internal::testNumericalDerivative(
      pressure, dp, daMixtureCoefficient_dp,
      [&]( real64 const p ) -> real64 {
      return computeCoefficients( p, temperature, composition ).first;
    } );
    geos::testing::internal::testNumericalDerivative(
      pressure, dp, dbMixtureCoefficient_dp,
      [&]( real64 const p ) -> real64 {
      return computeCoefficients( p, temperature, composition ).second;
    } );

    // -- Temperature derivative
    real64 const dT = 1.0e-6 * temperature;
    geos::testing::internal::testNumericalDerivative(
      temperature, dT, daMixtureCoefficient_dt,
      [&]( real64 const t ) -> real64 {
      return computeCoefficients( pressure, t, composition ).first;
    } );
    geos::testing::internal::testNumericalDerivative(
      temperature, dT, dbMixtureCoefficient_dt,
      [&]( real64 const t ) -> real64 {
      return computeCoefficients( pressure, t, composition ).second;
    } );

    // -- Composition derivatives derivative
    real64 const dz = 1.0e-7;
    for( integer ic = 0; ic < numComps; ++ic )
    {
      auto computeComponentCoefficients = [&]( real64 const z ) {
        composition[ic] += z;
        auto const coefficients =  computeCoefficients( pressure, temperature, composition );
        composition[ic] -= z;
        return coefficients;
      };
      geos::testing::internal::testNumericalDerivative(
        0.0, dz, daMixtureCoefficient_dz[ic],
        [&]( real64 const z ) -> real64 {
        return computeComponentCoefficients( z ).first;
      } );
      geos::testing::internal::testNumericalDerivative(
        0.0, dz, dbMixtureCoefficient_dz[ic],
        [&]( real64 const z ) -> real64 {
        return computeComponentCoefficients( z ).second;
      } );
    }
  }
};

using MixCoeffDerivativePR2TestFixture = MixCoeffDerivativeTestFixture< PengRobinsonEOS, 2 >;
using MixCoeffDerivativePR4TestFixture = MixCoeffDerivativeTestFixture< PengRobinsonEOS, 4 >;
using MixCoeffDerivativeSRK2TestFixture = MixCoeffDerivativeTestFixture< SoaveRedlichKwongEOS, 2 >;
using MixCoeffDerivativeSRK4TestFixture = MixCoeffDerivativeTestFixture< SoaveRedlichKwongEOS, 4 >;

TEST_P( MixCoeffDerivativePR2TestFixture, testNumericalDerivatives )
{
  testNumericalDerivatives( GetParam() );
}
TEST_P( MixCoeffDerivativePR4TestFixture, testNumericalDerivatives )
{
  testNumericalDerivatives( GetParam() );
}
TEST_P( MixCoeffDerivativeSRK2TestFixture, testNumericalDerivatives )
{
  testNumericalDerivatives( GetParam() );
}
TEST_P( MixCoeffDerivativeSRK4TestFixture, testNumericalDerivatives )
{
  testNumericalDerivatives( GetParam() );
}

// 2-component fluid test
INSTANTIATE_TEST_SUITE_P(
  CubicEOSTest,
  MixCoeffDerivativePR2TestFixture,
  ::testing::ValuesIn( generateTestData< 2 >())
  );
INSTANTIATE_TEST_SUITE_P(
  CubicEOSTest,
  MixCoeffDerivativeSRK2TestFixture,
  ::testing::ValuesIn( generateTestData< 2 >())
  );

// 4-component fluid test
INSTANTIATE_TEST_SUITE_P(
  CubicEOSTest,
  MixCoeffDerivativePR4TestFixture,
  ::testing::ValuesIn( generateTestData< 4 >())
  );

INSTANTIATE_TEST_SUITE_P(
  CubicEOSTest,
  MixCoeffDerivativeSRK4TestFixture,
  ::testing::ValuesIn( generateTestData< 4 >())
  );

template< typename EOS, int NC >
class CompressibilityDerivativeTestFixture : public DerivativeTestFixture< EOS, NC >
{
public:
  using DerivativeTestFixture< EOS, NC >::numComps;
  using ParamType = typename DerivativeTestFixture< EOS, NC >::ParamType;
public:
  void testNumericalDerivatives( ParamType const & testData ) const
  {
    auto const & fluid = *this->m_fluid;
    auto criticalPressure = fluid.getCriticalPressure();
    auto criticalTemperature = fluid.getCriticalTemperature();
    auto omega = fluid.getAcentricFactor();
    real64 constexpr binaryInteractionCoefficients = 0.0; // not implemented yet

    array1d< real64 > aPureCoefficient( numComps );
    array1d< real64 > bPureCoefficient( numComps );
    real64 aMixtureCoefficient = 0.0;
    real64 bMixtureCoefficient = 0.0;
    real64 daMixtureCoefficient_dp = 0.0;
    real64 dbMixtureCoefficient_dp = 0.0;
    real64 daMixtureCoefficient_dt = 0.0;
    real64 dbMixtureCoefficient_dt = 0.0;
    array1d< real64 > daMixtureCoefficient_dz( numComps );
    array1d< real64 > dbMixtureCoefficient_dz( numComps );

    real64 dCompressibilityFactor_dp = 0.0;
    real64 dCompressibilityFactor_dt = 0.0;
    array1d< real64 > dCompressibilityFactor_dz( numComps );

    array1d< real64 > composition;
    real64 const pressure = std::get< 0 >( testData );
    real64 const temperature = std::get< 1 >( testData );
    TestFluid< NC >::createArray( composition, std::get< 2 >( testData ));

    auto computeCompressibilityFactor = [&]( real64 const p, real64 const t, auto const & zmf ) -> real64 {
      real64 z = 0.0;
      CubicEOSPhaseModel< EOS >::computeMixtureCoefficients(
        numComps,
        p, t, zmf,
        criticalPressure, criticalTemperature, omega,
        binaryInteractionCoefficients,
        aPureCoefficient,
        bPureCoefficient,
        aMixtureCoefficient, bMixtureCoefficient
        );
      CubicEOSPhaseModel< EOS >::computeCompressibilityFactor(
        numComps,
        zmf,
        binaryInteractionCoefficients,
        aPureCoefficient,
        bPureCoefficient,
        aMixtureCoefficient,
        bMixtureCoefficient,
        z );
      return z;
    };

    // Calculate values
    real64 const compressibilityFactor = computeCompressibilityFactor( pressure, temperature, composition );

    // Calculate derivatives
    CubicEOSPhaseModel< EOS >::computeMixtureCoefficients(
      numComps,
      pressure,
      temperature,
      composition,
      criticalPressure,
      criticalTemperature,
      omega,
      binaryInteractionCoefficients,
      aPureCoefficient,
      bPureCoefficient,
      aMixtureCoefficient,
      bMixtureCoefficient,
      daMixtureCoefficient_dp,
      dbMixtureCoefficient_dp,
      daMixtureCoefficient_dt,
      dbMixtureCoefficient_dt,
      daMixtureCoefficient_dz,
      dbMixtureCoefficient_dz );
    CubicEOSPhaseModel< EOS >::computeCompressibilityFactor(
      numComps,
      aMixtureCoefficient,
      bMixtureCoefficient,
      compressibilityFactor,
      daMixtureCoefficient_dp,
      dbMixtureCoefficient_dp,
      daMixtureCoefficient_dt,
      dbMixtureCoefficient_dt,
      daMixtureCoefficient_dz,
      dbMixtureCoefficient_dz,
      dCompressibilityFactor_dp,
      dCompressibilityFactor_dt,
      dCompressibilityFactor_dz );

    // Compare against numerical derivatives
    // -- Pressure derivative
    real64 const dp = 1.0e-4 * pressure;
    geos::testing::internal::testNumericalDerivative(
      pressure, dp, dCompressibilityFactor_dp,
      [&]( real64 const p ) -> real64 {
      return computeCompressibilityFactor( p, temperature, composition );
    } );

    // -- Temperature derivative
    real64 const dT = 1.0e-6 * temperature;
    geos::testing::internal::testNumericalDerivative(
      temperature, dT, dCompressibilityFactor_dt,
      [&]( real64 const t ) -> real64 {
      return computeCompressibilityFactor( pressure, t, composition );
    } );

    // -- Composition derivatives derivative
    real64 const dz = 1.0e-7;
    for( integer ic = 0; ic < numComps; ++ic )
    {
      geos::testing::internal::testNumericalDerivative(
        0.0, dz, dCompressibilityFactor_dz[ic],
        [&]( real64 const z ) -> real64 {
        composition[ic] += z;
        real64 const compressibility = computeCompressibilityFactor( pressure, temperature, composition );
        composition[ic] -= z;
        return compressibility;
      } );
    }
  }
};

using CompressibilityDerivativePR2TestFixture = CompressibilityDerivativeTestFixture< PengRobinsonEOS, 2 >;
using CompressibilityDerivativePR4TestFixture = CompressibilityDerivativeTestFixture< PengRobinsonEOS, 4 >;
using CompressibilityDerivativeSRK2TestFixture = CompressibilityDerivativeTestFixture< SoaveRedlichKwongEOS, 2 >;
using CompressibilityDerivativeSRK4TestFixture = CompressibilityDerivativeTestFixture< SoaveRedlichKwongEOS, 4 >;

TEST_P( CompressibilityDerivativePR2TestFixture, testNumericalDerivatives )
{
  testNumericalDerivatives( GetParam() );
}
TEST_P( CompressibilityDerivativePR4TestFixture, testNumericalDerivatives )
{
  testNumericalDerivatives( GetParam() );
}
TEST_P( CompressibilityDerivativeSRK2TestFixture, testNumericalDerivatives )
{
  testNumericalDerivatives( GetParam() );
}
TEST_P( CompressibilityDerivativeSRK4TestFixture, testNumericalDerivatives )
{
  testNumericalDerivatives( GetParam() );
}

// 2-component fluid test
INSTANTIATE_TEST_SUITE_P(
  CubicEOSTest,
  CompressibilityDerivativePR2TestFixture,
  ::testing::ValuesIn( generateTestData< 2 >())
  );
INSTANTIATE_TEST_SUITE_P(
  CubicEOSTest,
  CompressibilityDerivativeSRK2TestFixture,
  ::testing::ValuesIn( generateTestData< 2 >())
  );

// 4-component fluid test
INSTANTIATE_TEST_SUITE_P(
  CubicEOSTest,
  CompressibilityDerivativePR4TestFixture,
  ::testing::ValuesIn( generateTestData< 4 >())
  );
INSTANTIATE_TEST_SUITE_P(
  CubicEOSTest,
  CompressibilityDerivativeSRK4TestFixture,
  ::testing::ValuesIn( generateTestData< 4 >())
  );
