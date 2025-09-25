## Description

The **DXGK_BUILDPAGINGBUFFER_NOTIFYALLOC** structure is used to notify the kernel-mode driver (KMD) of an allocation that is about to be used in a [**DXGK_OPERATION_NOTIFY_ALLOC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_buildpagingbuffer_operation) paging operation.

## Members

### `hAllocation`

The driver allocation handle returned from [**DxgkDdiCreateAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation).

### `hKmdProcessHandle`

The driver process object handle returned from [**DxgkDdiCreateProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createprocess). This handle is zero when the **Eviction** flag is set.

### `Flags`

A [**DXGK_NOTIFYALLOCFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_notifyallocflags) structure specifying the flags related to the operation.

### `OffsetInBytes`

Offset from the start of the allocation, in bytes. This value is used when an operation is performed on part of an allocation.

### `SizeInBytes`

Size of the operation, in bytes.

### `GpuVirtualAddressAtOffset`

The GPU virtual address corresponding to the allocation offset. When the **Eviction** flag is set, the GPU VA address is in the paging process context. When the **IoMmuUnmap** flag is set, the GPU VA address is in the context of the process defined by **hKmdProcessHandle**.

## Remarks

For more information, see [Allocation Notification](https://learn.microsoft.com/windows-hardware/drivers/display/allocation-notification).

## See also

[**DXGK_ALLOCATIONINFOFLAGS2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_allocationinfoflags2)

[**DXGK_BUILDPAGINGBUFFER_OPERATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_buildpagingbuffer_operation)

[**DXGK_NOTIFYALLOCFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_notifyallocflags)

[**DXGKARG_BUILDPAGINGBUFFER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_buildpagingbuffer)

[**DxgkDdiBuildPagingBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_buildpagingbuffer)