#
# Specify all headers
#
set( constitutive_headers
     ConstitutiveBase.hpp
     ConstitutiveManager.hpp
     ConstitutivePassThru.hpp
     ConstitutivePassThruHandler.hpp
     ExponentialRelation.hpp
     NullModel.hpp
     capillaryPressure/BrooksCoreyCapillaryPressure.hpp
     capillaryPressure/CapillaryPressureBase.hpp
     capillaryPressure/CapillaryPressureFields.hpp
     capillaryPressure/JFunctionCapillaryPressure.hpp
     capillaryPressure/TableCapillaryPressure.hpp
     capillaryPressure/TableCapillaryPressureHelpers.hpp
     capillaryPressure/VanGenuchtenCapillaryPressure.hpp
     capillaryPressure/capillaryPressureSelector.hpp
     capillaryPressure/layouts.hpp
     contact/ContactBase.hpp
     contact/CoulombContact.hpp
     contact/ContactSelector.hpp
     contact/FrictionlessContact.hpp
     diffusion/ConstantDiffusion.hpp
     diffusion/DiffusionBase.hpp
     diffusion/DiffusionFields.hpp
     diffusion/DiffusionSelector.hpp
     dispersion/DispersionBase.hpp
     dispersion/DispersionFields.hpp
     dispersion/DispersionSelector.hpp
     dispersion/LinearIsotropicDispersion.hpp     
     fluid/multifluid/Layouts.hpp
     fluid/multifluid/MultiFluidSelector.hpp
     fluid/multifluid/MultiFluidBase.hpp
     fluid/multifluid/MultiFluidConstants.hpp
     fluid/multifluid/MultiFluidUtils.hpp
     fluid/multifluid/MultiFluidFields.hpp
     fluid/multifluid/PVTDriver.hpp
     fluid/multifluid/PVTDriverRunTest.hpp
     fluid/multifluid/blackOil/BlackOilFluidBase.hpp
     fluid/multifluid/blackOil/BlackOilFluid.hpp
     fluid/multifluid/blackOil/DeadOilFluid.hpp
     fluid/multifluid/blackOil/PVTOData.hpp
     fluid/multifluid/CO2Brine/CO2BrineFluid.hpp
     fluid/multifluid/CO2Brine/PhaseModel.hpp
     fluid/multifluid/CO2Brine/functions/PhillipsBrineDensity.hpp
     fluid/multifluid/CO2Brine/functions/PhillipsBrineViscosity.hpp
     fluid/multifluid/CO2Brine/functions/EzrokhiBrineDensity.hpp
     fluid/multifluid/CO2Brine/functions/EzrokhiBrineViscosity.hpp
     fluid/multifluid/CO2Brine/functions/CO2Solubility.hpp
     fluid/multifluid/CO2Brine/functions/FenghourCO2Viscosity.hpp
     fluid/multifluid/CO2Brine/functions/FlashModelBase.hpp
     fluid/multifluid/CO2Brine/functions/PVTFunctionBase.hpp
     fluid/multifluid/CO2Brine/functions/NoOpPVTFunction.hpp
     fluid/multifluid/CO2Brine/functions/PVTFunctionHelpers.hpp
     fluid/multifluid/CO2Brine/functions/SpanWagnerCO2Density.hpp
     fluid/multifluid/CO2Brine/functions/BrineEnthalpy.hpp
     fluid/multifluid/CO2Brine/functions/CO2Enthalpy.hpp
     fluid/multifluid/CO2Brine/functions/CO2EOSSolver.hpp
     fluid/multifluid/CO2Brine/functions/PureWaterProperties.hpp
     fluid/multifluid/CO2Brine/functions/WaterDensity.hpp
     fluid/multifluid/compositional/functions/CompositionalProperties.hpp     
     fluid/multifluid/compositional/functions/CubicEOSPhaseModel.hpp     
     fluid/multifluid/compositional/functions/KValueInitialization.hpp
     fluid/multifluid/compositional/functions/NegativeTwoPhaseFlash.hpp
     fluid/multifluid/compositional/functions/RachfordRice.hpp     
     fluid/multifluid/reactive/ReactiveBrineFluid.hpp
     fluid/multifluid/reactive/ReactiveMultiFluid.hpp
     fluid/multifluid/reactive/ReactiveMultiFluidFields.hpp
     fluid/multifluid/reactive/ReactiveFluidDriver.hpp
     fluid/multifluid/reactive/ReactiveFluidSelector.hpp
     fluid/multifluid/reactive/chemicalReactions/EquilibriumReactions.hpp
     fluid/multifluid/reactive/chemicalReactions/KineticReactions.hpp
     fluid/multifluid/reactive/chemicalReactions/ReactionsBase.hpp
     fluid/singlefluid/CompressibleSinglePhaseFluid.hpp
     fluid/singlefluid/ParticleFluid.hpp
     fluid/singlefluid/ParticleFluidBase.hpp
     fluid/singlefluid/ParticleFluidSelector.hpp
     fluid/singlefluid/ProppantSlurryFluid.hpp
     fluid/singlefluid/SingleFluidBase.hpp
     fluid/singlefluid/SingleFluidFields.hpp
     fluid/singlefluid/SlurryFluidBase.hpp
     fluid/singlefluid/SlurryFluidFields.hpp
     fluid/singlefluid/SingleFluidSelector.hpp
     fluid/singlefluid/SlurryFluidSelector.hpp
     fluid/singlefluid/ThermalCompressibleSinglePhaseFluid.hpp
     permeability/CarmanKozenyPermeability.hpp
     permeability/ConstantPermeability.hpp
     permeability/ExponentialDecayPermeability.hpp
     permeability/ParallelPlatesPermeability.hpp
     permeability/PermeabilityBase.hpp
     permeability/PermeabilityFields.hpp
     permeability/ProppantPermeability.hpp
     permeability/SlipDependentPermeability.hpp
     permeability/WillisRichardsPermeability.hpp
     relativePermeability/RelpermDriver.hpp
     relativePermeability/RelpermDriverRunTest.hpp
     relativePermeability/BrooksCoreyBakerRelativePermeability.hpp
     relativePermeability/BrooksCoreyRelativePermeability.hpp
     relativePermeability/RelativePermeabilityBase.hpp
     relativePermeability/RelativePermeabilityFields.hpp
     relativePermeability/RelativePermeabilityInterpolators.hpp
     relativePermeability/TableRelativePermeability.hpp
     relativePermeability/TableRelativePermeabilityHelpers.hpp
     relativePermeability/TableRelativePermeabilityHysteresis.hpp
     relativePermeability/VanGenuchtenBakerRelativePermeability.hpp
     relativePermeability/layouts.hpp
     relativePermeability/RelativePermeabilitySelector.hpp
     solid/CompressibleSolid.hpp
     solid/ProppantSolid.hpp
     solid/CoupledSolidBase.hpp
     solid/CoupledSolid.hpp
     solid/DuvautLionsSolid.hpp
     solid/Damage.hpp
     solid/DamageSpectral.hpp
     solid/DamageSpectralUtilities.hpp
     solid/DamageVolDev.hpp
     solid/DruckerPrager.hpp
     solid/DruckerPragerExtended.hpp
     solid/ModifiedCamClay.hpp
     solid/DelftEgg.hpp
     solid/ElasticIsotropic.hpp
     solid/ElasticIsotropicPressureDependent.hpp
     solid/ElasticTransverseIsotropic.hpp
     solid/ElasticOrthotropic.hpp
     solid/InvariantDecompositions.hpp
     solid/PerfectlyPlastic.hpp     
     solid/PorousSolid.hpp
     solid/PropertyConversions.hpp
     solid/SolidBase.hpp
     solid/SolidUtilities.hpp
     solid/SolidInternalEnergy.hpp
     solid/SolidModelDiscretizationOps.hpp
     solid/SolidModelDiscretizationOpsFullyAnisotroipic.hpp
     solid/SolidModelDiscretizationOpsIsotropic.hpp
     solid/SolidModelDiscretizationOpsTransverseIsotropic.hpp
     solid/SolidModelDiscretizationOpsOrthotropic.hpp
     solid/CeramicDamage.hpp
     solid/TriaxialDriver.hpp
     solid/porosity/PorosityFields.hpp
     solid/porosity/BiotPorosity.hpp
     solid/porosity/PorosityBase.hpp
     solid/porosity/PorosityFields.hpp
     solid/porosity/PressurePorosity.hpp
     solid/porosity/ProppantPorosity.hpp
     thermalConductivity/MultiPhaseConstantThermalConductivity.hpp
     thermalConductivity/MultiPhaseThermalConductivityBase.hpp
     thermalConductivity/MultiPhaseThermalConductivityFields.hpp
     thermalConductivity/MultiPhaseThermalConductivitySelector.hpp
     thermalConductivity/MultiPhaseVolumeWeightedThermalConductivity.hpp
     thermalConductivity/SinglePhaseConstantThermalConductivity.hpp
     thermalConductivity/SinglePhaseThermalConductivityBase.hpp
     thermalConductivity/SinglePhaseThermalConductivityFields.hpp
     thermalConductivity/SinglePhaseThermalConductivitySelector.hpp
     thermalConductivity/ThermalConductivityFields.hpp
   )
#
# Specify all sources
#
set( constitutive_sources
     ConstitutiveBase.cpp
     ConstitutiveManager.cpp
     NullModel.cpp
     capillaryPressure/BrooksCoreyCapillaryPressure.cpp
     capillaryPressure/CapillaryPressureBase.cpp
     capillaryPressure/JFunctionCapillaryPressure.cpp
     capillaryPressure/TableCapillaryPressure.cpp
     capillaryPressure/TableCapillaryPressureHelpers.cpp
     capillaryPressure/VanGenuchtenCapillaryPressure.cpp
     contact/ContactBase.cpp
     contact/CoulombContact.cpp
     contact/FrictionlessContact.cpp
     diffusion/ConstantDiffusion.cpp
     diffusion/DiffusionBase.cpp
     dispersion/DispersionBase.cpp
     dispersion/LinearIsotropicDispersion.cpp
     fluid/multifluid/MultiFluidBase.cpp
     fluid/multifluid/PVTDriver.cpp
     fluid/multifluid/blackOil/BlackOilFluidBase.cpp
     fluid/multifluid/blackOil/BlackOilFluid.cpp
     fluid/multifluid/blackOil/DeadOilFluid.cpp
     fluid/multifluid/blackOil/PVTDriverRunTestDeadOilFluid.cpp
     fluid/multifluid/blackOil/PVTOData.cpp
     fluid/multifluid/CO2Brine/CO2BrineFluid.cpp
     fluid/multifluid/CO2Brine/PVTDriverRunTestCO2BrinePhillipsFluid.cpp
     fluid/multifluid/CO2Brine/PVTDriverRunTestCO2BrinePhillipsThermalFluid.cpp
     fluid/multifluid/CO2Brine/PVTDriverRunTestCO2BrineEzrokhiFluid.cpp
     fluid/multifluid/CO2Brine/PVTDriverRunTestCO2BrineEzrokhiThermalFluid.cpp
     fluid/multifluid/CO2Brine/functions/PhillipsBrineDensity.cpp
     fluid/multifluid/CO2Brine/functions/PhillipsBrineViscosity.cpp
     fluid/multifluid/CO2Brine/functions/EzrokhiBrineDensity.cpp
     fluid/multifluid/CO2Brine/functions/EzrokhiBrineViscosity.cpp
     fluid/multifluid/CO2Brine/functions/CO2Solubility.cpp
     fluid/multifluid/CO2Brine/functions/FenghourCO2Viscosity.cpp
     fluid/multifluid/CO2Brine/functions/SpanWagnerCO2Density.cpp
     fluid/multifluid/CO2Brine/functions/PVTFunctionHelpers.cpp
     fluid/multifluid/CO2Brine/functions/BrineEnthalpy.cpp
     fluid/multifluid/CO2Brine/functions/CO2Enthalpy.cpp
     fluid/multifluid/CO2Brine/functions/CO2EOSSolver.cpp
     fluid/multifluid/CO2Brine/functions/PureWaterProperties.cpp
     fluid/multifluid/CO2Brine/functions/WaterDensity.cpp
     fluid/multifluid/compositional/functions/CompositionalProperties.cpp
     fluid/multifluid/reactive/ReactiveBrineFluid.cpp
     fluid/multifluid/reactive/ReactiveMultiFluid.cpp
     fluid/multifluid/reactive/ReactiveFluidDriver.cpp
     fluid/multifluid/reactive/chemicalReactions/EquilibriumReactions.cpp
     fluid/multifluid/reactive/chemicalReactions/KineticReactions.cpp
     fluid/multifluid/reactive/chemicalReactions/ReactionsBase.cpp
     fluid/singlefluid/CompressibleSinglePhaseFluid.cpp
     fluid/singlefluid/ParticleFluid.cpp
     fluid/singlefluid/ParticleFluidBase.cpp
     fluid/singlefluid/ProppantSlurryFluid.cpp
     fluid/singlefluid/SingleFluidBase.cpp
     fluid/singlefluid/SlurryFluidBase.cpp
     fluid/singlefluid/ThermalCompressibleSinglePhaseFluid.cpp
     permeability/CarmanKozenyPermeability.cpp
     permeability/ConstantPermeability.cpp
     permeability/ExponentialDecayPermeability.cpp
     permeability/ParallelPlatesPermeability.cpp
     permeability/PermeabilityBase.cpp
     permeability/ProppantPermeability.cpp
     permeability/SlipDependentPermeability.cpp
     permeability/WillisRichardsPermeability.cpp
     relativePermeability/BrooksCoreyBakerRelativePermeability.cpp
     relativePermeability/BrooksCoreyRelativePermeability.cpp
     relativePermeability/RelativePermeabilityBase.cpp
     relativePermeability/TableRelativePermeability.cpp
     relativePermeability/TableRelativePermeabilityHelpers.cpp
     relativePermeability/TableRelativePermeabilityHysteresis.cpp
     relativePermeability/VanGenuchtenBakerRelativePermeability.cpp
     relativePermeability/RelpermDriver.cpp
     relativePermeability/RelpermDriverBrooksCoreyBakerRunTest.cpp
     relativePermeability/RelpermDriverBrooksCoreyRunTest.cpp
     relativePermeability/RelpermDriverVanGenuchtenBakerRunTest.cpp
     relativePermeability/RelpermDriverTableRelativeRunTest.cpp
     relativePermeability/RelpermDriverTableRelativeHysteresisRunTest.cpp
     solid/CompressibleSolid.cpp
     solid/CoupledSolidBase.cpp
     solid/ProppantSolid.cpp
     solid/DuvautLionsSolid.cpp
     solid/Damage.cpp
     solid/DamageSpectral.cpp
     solid/DamageVolDev.cpp
     solid/DruckerPrager.cpp
     solid/DruckerPragerExtended.cpp
     solid/ModifiedCamClay.cpp
     solid/DelftEgg.cpp
     solid/ElasticIsotropic.cpp
     solid/ElasticIsotropicPressureDependent.cpp
     solid/ElasticTransverseIsotropic.cpp
     solid/ElasticOrthotropic.cpp
     solid/PerfectlyPlastic.cpp
     solid/PorousSolid.cpp
     solid/SolidBase.cpp
     solid/SolidInternalEnergy.cpp
     solid/CeramicDamage.cpp
     solid/TriaxialDriver.cpp
     solid/porosity/BiotPorosity.cpp
     solid/porosity/PorosityBase.cpp
     solid/porosity/PressurePorosity.cpp
     solid/porosity/ProppantPorosity.cpp
     thermalConductivity/MultiPhaseConstantThermalConductivity.cpp
     thermalConductivity/MultiPhaseThermalConductivityBase.cpp
     thermalConductivity/MultiPhaseVolumeWeightedThermalConductivity.cpp
     thermalConductivity/SinglePhaseConstantThermalConductivity.cpp
     thermalConductivity/SinglePhaseThermalConductivityBase.cpp
   )

set( dependencyList ${parallelDeps} events dataRepository functions denseLinearAlgebra )

if( ENABLE_PVTPackage )
    set( constitutive_headers
         ${constitutive_headers}
         fluid/multifluid/compositional/CompositionalMultiphaseFluid.hpp
         )

    set( constitutive_sources
         ${constitutive_sources}
         fluid/multifluid/compositional/CompositionalMultiphaseFluid.cpp
	 fluid/multifluid/compositional/PVTDriverRunTestCompositionalMultiphaseFluid.cpp
         )

    add_subdirectory( PVTPackage )

    set( dependencyList ${dependencyList} PVTPackage )
endif()

blt_add_library( NAME       constitutive
                 SOURCES    ${constitutive_sources}
                 HEADERS    ${constitutive_headers}
                 DEPENDS_ON ${dependencyList}
                 OBJECT     ${GEOSX_BUILD_OBJ_LIBS}
               )

target_include_directories( constitutive PUBLIC ${CMAKE_SOURCE_DIR}/coreComponents )

if( GEOS_ENABLE_TESTS )
  add_subdirectory( unitTests )
endif( )

geosx_add_code_checks( PREFIX constitutive
                       EXCLUDES PVTPackage )
