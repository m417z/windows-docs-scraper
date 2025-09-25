# CSC_InheritanceConfig enumeration

## Description

Indicates whether to create a new context based on the current context or to create a new context based solely upon the information in [CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig).

## Constants

### `CSC_Inherit:0`

The new context is created from the existing context.

### `CSC_Ignore`

The new context is created from the default context.

## Remarks

The different values of this enumeration can be used to establish the default configurations for the various services provided through [CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig). The default inheritance configuration for **CServiceConfig** is CSC_Ignore. It is often useful to use CSC_Ignore when calling [CoCreateActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-cocreateactivity), while CSC_Inherit is useful when augmenting an existing context, such as when calling [CoEnterServiceDomain](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-coenterservicedomain).

Calling [IServiceInheritanceConfig::ContainingContextTreatment](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iserviceinheritanceconfig-containingcontexttreatment) overwrites any previous configuration settings of the [CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig) object with the following defaults.

### For CSC_InheritanceConfig set to CSC_Inherit

| Enumeration | Default |
| --- | --- |
| [CSC_COMTIIntrinsicsConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/ne-comsvcs-csc_comtiintrinsicsconfig) | CSC_InheritCOMTIIntrinsics |
| [CSC_IISIntrinsicsConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/ne-comsvcs-csc_iisintrinsicsconfig) | CSC_InheritIISIntrinsics |
| [CSC_PartitionConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/ne-comsvcs-csc_partitionconfig) | CSC_InheritPartition |
| [CSC_SxsConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/ne-comsvcs-csc_sxsconfig) | CSC_InheritSxs |
| [CSC_SynchronizationConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/ne-comsvcs-csc_synchronizationconfig) | CSC_IfContainerIsSynchronized |
| [CSC_ThreadPool](https://learn.microsoft.com/windows/desktop/api/comsvcs/ne-comsvcs-csc_threadpool) | CSC_ThreadPoolInherit |
| [CSC_TransactionConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/ne-comsvcs-csc_transactionconfig) | CSC_IfContainerIsTransactional |

### For CSC_InheritanceConfig set to CSC_Ignore

| Enumeration | Default |
| --- | --- |
| [CSC_COMTIIntrinsicsConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/ne-comsvcs-csc_comtiintrinsicsconfig) | CSC_NoCOMTIIntrinsics |
| [CSC_IISIntrinsicsConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/ne-comsvcs-csc_iisintrinsicsconfig) | CSC_NoIISIntrinsics |
| [CSC_PartitionConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/ne-comsvcs-csc_partitionconfig) | CSC_NoPartition |
| [CSC_SxsConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/ne-comsvcs-csc_sxsconfig) | CSC_NoSxs |
| [CSC_SynchronizationConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/ne-comsvcs-csc_synchronizationconfig) | CSC_NoSynchronization |
| [CSC_ThreadPool](https://learn.microsoft.com/windows/desktop/api/comsvcs/ne-comsvcs-csc_threadpool) | CSC_ThreadPoolNone |
| [CSC_TransactionConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/ne-comsvcs-csc_transactionconfig) | CSC_NoTransaction |

## See also

[CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig)

[CoCreateActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-cocreateactivity)

[CoEnterServiceDomain](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-coenterservicedomain)

[IServiceInheritanceConfig::ContainingContextTreatment](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iserviceinheritanceconfig-containingcontexttreatment)