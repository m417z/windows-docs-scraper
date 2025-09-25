# CSC_Binding enumeration

## Description

Indicates whether all of the work that is submitted via the activity returned from [CoCreateActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-cocreateactivity) should be bound to only one single-threaded apartment (STA). This enumeration has no impact on the multithreaded apartment (MTA).

## Constants

### `CSC_NoBinding:0`

The work submitted through the activity is not bound to a single STA.

### `CSC_BindToPoolThread`

The work submitted through the activity is bound to a single STA.

## Remarks

Binding all of the work submitted through the activity to a single STA involves a trade-off between avoiding the need to marshal interfaces to components used by many of the different bits of work versus needing to synchronize on a specific STA.

This enumeration is used only to set the thread pool binding for [CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig) when calling [CoCreateActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-cocreateactivity). An error is returned if you try to set the thread pool binding when calling [CoEnterServiceDomain](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-coenterservicedomain). The values of this enumeration have no impact upon the MTA.

## See also

[CoCreateActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-cocreateactivity)

[CoEnterServiceDomain](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-coenterservicedomain)

[IServiceThreadPoolConfig::SetBindingInfo](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iservicethreadpoolconfig-setbindinginfo)