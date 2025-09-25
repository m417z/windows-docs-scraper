# IServicePartitionConfig::PartitionConfig

## Description

Configures how partitions are used for the enclosed work.

## Parameters

### `partitionConfig` [in]

A value from the [CSC_PartitionConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/ne-comsvcs-csc_partitionconfig) enumeration.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_FAIL, and S_OK.

## Remarks

The user must belong to any partition that is used to run the enclosed work.

## See also

[IServicePartitionConfig](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iservicepartitionconfig)