# CSC_PartitionConfig enumeration

## Description

Indicates the COM+ partition on which the enclosed context runs.

## Constants

### `CSC_NoPartition:0`

The enclosed context runs on the Base Application Partition. This is the default setting for [CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig) when [CSC_InheritanceConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/ne-comsvcs-csc_inheritanceconfig) is set to CSC_Ignore.

### `CSC_InheritPartition`

The enclosed context runs in the current containing COM+ partition. This is the default setting for [CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig) when [CSC_InheritanceConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/ne-comsvcs-csc_inheritanceconfig) is set to CSC_Inherit.

### `CSC_NewPartition`

The enclosed context runs in a COM+ partition that is different from the current containing partition.

## Remarks

This enumeration is used to specify the working COM+ partition through [CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig) for either the work submitted through the activity created by [CoCreateActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-cocreateactivity) or the work that is enclosed between calls to [CoEnterServiceDomain](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-coenterservicedomain) and [CoLeaveServiceDomain](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-coleaveservicedomain).

## See also

[COM+ Partitions](https://learn.microsoft.com/windows/desktop/cossdk/com--partitions)

[CServiceConfig](https://learn.microsoft.com/windows/desktop/cossdk/cserviceconfig)

[CoCreateActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-cocreateactivity)

[CoEnterServiceDomain](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-coenterservicedomain)

[IServicePartitionConfig::PartitionConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iservicepartitionconfig-partitionconfig)