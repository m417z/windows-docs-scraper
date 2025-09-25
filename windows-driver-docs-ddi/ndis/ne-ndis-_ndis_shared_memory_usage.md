# _NDIS_SHARED_MEMORY_USAGE enumeration

## Description

The NDIS_SHARED_MEMORY_USAGE enumeration specifies how shared memory is used.

## Constants

### `NdisSharedMemoryUsageUndefined`

The shared memory application is not defined.

### `NdisSharedMemoryUsageXmit`

The shared memory contains transmit data buffers.

### `NdisSharedMemoryUsageXmitHeader`

The shared memory contains transmit header buffers.

### `NdisSharedMemoryUsageXmitData`

The shared memory contains transmit data.

### `NdisSharedMemoryUsageReceive`

The shared memory contains receive data buffers.

### `NdisSharedMemoryUsageReceiveLookahead`

The shared memory contains receive lookahead buffers.

### `NdisSharedMemoryUsageReceivePostLookahead`

The shared memory contains received post lookahead information.

### `NdisSharedMemoryUsageReceiveHeader`

The shared memory contains receive header information.

### `NdisSharedMemoryUsageReceiveData`

The shared memory contains receive data.

### `NdisSharedMemoryUsageOther`

The shared memory application is not specified.

### `NdisSharedMemoryUsageMax`

The maximum value for this enumeration. This value might change in future versions of the NDIS
header files and binaries.

## Remarks

The NDIS_SHARED_MEMORY_USAGE enumeration is used in the
[NDIS_SHARED_MEMORY_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_shared_memory_parameters) and
[NDIS_SCATTER_GATHER_LIST_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_scatter_gather_list_parameters) structures.

## See also

[NDIS_SCATTER_GATHER_LIST_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_scatter_gather_list_parameters)

[NDIS_SHARED_MEMORY_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_shared_memory_parameters)