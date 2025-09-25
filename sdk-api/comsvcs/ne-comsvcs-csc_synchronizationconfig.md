# CSC_SynchronizationConfig enumeration

## Description

Indicates how synchronization is configured for [CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig).

## Constants

### `CSC_NoSynchronization:0`

The code is forced to run unsynchronized. This is the default synchronization setting for [CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig) when [CSC_InheritanceConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/ne-comsvcs-csc_inheritanceconfig) is set to CSC_Ignore.

### `CSC_IfContainerIsSynchronized`

The code runs in the containing synchronization domain if one exists. This is the default synchronization setting for [CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig) when [CSC_InheritanceConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/ne-comsvcs-csc_inheritanceconfig) is set to CSC_Inherit.

### `CSC_NewSynchronizationIfNecessary`

Synchronization is always used. The existing synchronization domain is used, or if the enclosed context does not already use synchronization, a new synchronization domain is created.

### `CSC_NewSynchronization`

A new synchronization domain is always created.

## Remarks

This enumeration is used to configure synchronization through [CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig) for either the work submitted through the activity created by [CoCreateActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-cocreateactivity) or the work that is enclosed between calls to [CoEnterServiceDomain](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-coenterservicedomain) and [CoLeaveServiceDomain](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-coleaveservicedomain).

Synchronization can affect the components created by the contained code even if it has no immediate impact on the contained code itself. For example, if the same code is running on two different threads and this code calls [CoEnterServiceDomain](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-coenterservicedomain) asking for synchronization services, each thread is contained in its own synchronization domain.

If it is incompatible with the transaction setting from [CSC_TransactionConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/ne-comsvcs-csc_transactionconfig), the synchronization setting is increased to the minimum that is required for the transaction.

## See also

[COM+ Synchronization](https://learn.microsoft.com/windows/desktop/cossdk/com--synchronization)

[CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig)

[CoCreateActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-cocreateactivity)

[CoEnterServiceDomain](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-coenterservicedomain)

[IServiceSynchronizationConfig::ConfigureSynchronization](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iservicesynchronizationconfig-configuresynchronization)