/*
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Copyright (c) 2019, Lawrence Livermore National Security, LLC.
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
 * @file FiniteElementSpace.hpp
 */

#ifndef SRC_COMPONENTS_CORE_SRC_FINITEELEMENT_FINITEELEMENTSPACE_HPP_
#define SRC_COMPONENTS_CORE_SRC_FINITEELEMENT_FINITEELEMENTSPACE_HPP_
#include "dataRepository/Group.hpp"
#include "dataRepository/Wrapper.hpp"

namespace geosx
{

class NodeManager;
class CellBlockManager;
class ElementSubRegionBase;

namespace dataRepository
{
namespace keys
{
string const finiteElementSpace = "FiniteElementSpace";
string const basis = "basis";
string const quadrature = "quadrature";
string const dNdX = "dNdX";
string const detJ = "detJ";
string const parentSpace="parentSpace";
}
}

class BasisBase;
class QuadratureBase;
class FiniteElementBase;

class FiniteElementDiscretization : public dataRepository::Group
{
public:

  FiniteElementDiscretization() = delete;

  explicit FiniteElementDiscretization( std::string const & name, Group * const parent );

  ~FiniteElementDiscretization() override;

  /**
   * @name Static Factory Catalog Functions
   */
  ///@{
  static string CatalogName() { return dataRepository::keys::finiteElementSpace; }

  ///@}


  std::unique_ptr<FiniteElementBase> getFiniteElement( string const & catalogName ) const;

  void ApplySpaceToTargetCells( ElementSubRegionBase * const group ) const;




  void CalculateShapeFunctionGradients( arrayView1d<R1Tensor const> const & X,
                                        ElementSubRegionBase * const cellBlock ) const;

  localIndex getNumberOfQuadraturePoints() const;

public:

  string m_basisName;
  string m_quadratureName;
  string m_parentSpace;

  BasisBase const *    m_basis    = nullptr;
  QuadratureBase const * m_quadrature = nullptr;
  FiniteElementBase * m_finiteElement = nullptr;
protected:
  void PostProcessInput() override final;

};

} /* namespace geosx */

#endif /* SRC_COMPONENTS_CORE_SRC_FINITEELEMENT_FINITEELEMENTSPACE_HPP_ */
