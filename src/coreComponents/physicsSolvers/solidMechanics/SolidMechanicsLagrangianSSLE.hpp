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

/**
 * @file SolidMechanicsLagrangianSSLE.hpp
 */

#ifndef GEOS_PHYSICSSOLVERS_SOLIDMECHANICS_SOLIDMECHANICSLAGRANGIANSSLE_HPP_
#define GEOS_PHYSICSSOLVERS_SOLIDMECHANICS_SOLIDMECHANICSLAGRANGIANSSLE_HPP_

#include "SolidMechanicsLagrangianFEM.hpp"

namespace geos
{

/**
 * @class SolidMechanicsLagrangianSSLE
 *
 * This class contains an implementation of a small strain linear elastic solution to the equations of motion which are
 * called through the interface in SolidMechanicsLagrangianFEM.
 */
class SolidMechanicsLagrangianSSLE : public SolidMechanicsLagrangianFEM
{
public:
  SolidMechanicsLagrangianSSLE( string const & name,
                                Group * const parent );
  virtual ~SolidMechanicsLagrangianSSLE() override;

  static string catalogName() { return "SolidMechanicsLagrangianSSLE"; }


};

} /* namespace geos */

#endif /* GEOS_PHYSICSSOLVERS_SOLIDMECHANICS_SOLIDMECHANICSLAGRANGIANSSLE_HPP_ */
