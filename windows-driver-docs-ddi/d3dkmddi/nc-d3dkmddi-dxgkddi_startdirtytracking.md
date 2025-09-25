## Description

KMD's **DxgkDdiStartDirtyTracking** function enables dirty bit tracking within the specified segment and given address range.

## Parameters

### `hAdapter`

[in] A handle to a context block associated with a display adapter. KMD previously provided this handle to *Dxgkrnl* in the **MiniportDeviceContext** output parameter of the [**DxgiDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `hMemoryBasis`

[in] Handle to the memory basis over which to start tracking dirty operations. KMD created this handle in a previous call to [**DxgkDdiCreateMemoryBasis**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_creatememorybasis).

## Return value

**DxgkDdiStartDirtyTracking** returns STATUS_SUCCESS upon success. Otherwise, it returns an appropriate NTSTATUS code.

## Remarks

The driver only needs to ensure that dirty tracking is enabled for the specified memory basis. However, doing so at a coarser granularity (for example, enabling dirty tracking for the entire adapter or segment) is valid as long as all outstanding requests are honored.

*Dxgkrnl* might enable dirty page tracking on multiple segments or ranges within those segments simultaneously.

When dirty tracking is enabled, *Dxgkrnl* expects the dirty bitplane to be initialized to all zeroes (all pages unmodified).

For more information, see [Dirty bit tracking](https://learn.microsoft.com/windows-hardware/drivers/display/dirty-bit-tracking).

## See also

[**DxgkDdiCreateMemoryBasis**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_creatememorybasis)

[**DxgkDdiStopDirtyTracking**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_stopdirtytracking)