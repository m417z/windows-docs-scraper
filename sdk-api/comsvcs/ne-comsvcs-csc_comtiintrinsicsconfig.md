# CSC_COMTIIntrinsicsConfig enumeration

## Description

Indicates whether the current COM Transaction Integrator (COMTI) intrinsics are propagated into the new context. Values from this enumeration are passed to [IServiceComTIIntrinsicsConfig::ComTIIntrinsicsConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iservicecomtiintrinsicsconfig-comtiintrinsicsconfig). The COMTI eases the task of wrapping mainframe transactions and business logic as COM components.

## Constants

### `CSC_NoCOMTIIntrinsics:0`

The current COMTI intrinsics do not propagate to the new context. This is the default setting for [CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig) when [CSC_InheritanceConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/ne-comsvcs-csc_inheritanceconfig) is set to CSC_Ignore.

### `CSC_InheritCOMTIIntrinsics`

The current COMTI intrinsics propagate to the new context. This is the default setting for [CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig) when [CSC_InheritanceConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/ne-comsvcs-csc_inheritanceconfig) is set to CSC_Inherit.

## Remarks

This enumeration is used to configure the COMTI intrinsics settings through [CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig) for either the work submitted through the activity created by [CoCreateActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-cocreateactivity) or the work that is enclosed between calls to [CoEnterServiceDomain](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-coenterservicedomain) and [CoLeaveServiceDomain](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-coleaveservicedomain).

## See also

[CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig)

[CoCreateActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-cocreateactivity)

[CoEnterServiceDomain](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-coenterservicedomain)

[IServiceComTIIntrinsicsConfig::ComTIIntrinsicsConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iservicecomtiintrinsicsconfig-comtiintrinsicsconfig)