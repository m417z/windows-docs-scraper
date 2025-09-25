# CSC_SxsConfig enumeration

## Description

Indicates how side-by-side assemblies are configured for [CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig).

## Constants

### `CSC_NoSxs:0`

Side-by-side assemblies are not used within the enclosed context. This is the default setting for [CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig) when [CSC_InheritanceConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/ne-comsvcs-csc_inheritanceconfig) is set to CSC_Ignore.

### `CSC_InheritSxs`

The current side-by-side assembly of the enclosed context is used. This is the default setting for [CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig) when [CSC_InheritanceConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/ne-comsvcs-csc_inheritanceconfig) is set to CSC_Inherit.

### `CSC_NewSxs`

A new side-by-side assembly is created for the enclosed context.

## Remarks

This enumeration is used to configure side-by-side assemblies through [CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig) for either the work submitted through the activity created by [CoCreateActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-cocreateactivity) or the work that is enclosed between calls to [CoEnterServiceDomain](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-coenterservicedomain) and [CoLeaveServiceDomain](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-coleaveservicedomain).

## See also

[CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig)

[CoCreateActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-cocreateactivity)

[CoEnterServiceDomain](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-coenterservicedomain)

[IServiceSxSConfig::SxSConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iservicesxsconfig)

[Isolated Applications and Side-by-side Assemblies](https://learn.microsoft.com/windows/desktop/SbsCs/isolated-applications-and-side-by-side-assemblies-portal)