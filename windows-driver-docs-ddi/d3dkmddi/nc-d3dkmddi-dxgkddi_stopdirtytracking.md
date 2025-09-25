## Description

KMD's **DxgkDdiStopDirtyTracking** function disables dirty bit tracking within the specified segment and given address range.

## Parameters

### `hAdapter`

[in] A handle to a context block associated with a display adapter. KMD previously provided this handle to *Dxgkrnl* in the **MiniportDeviceContext** output parameter of the [**DxgiDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `hMemoryBasis`

[in] Handle to the memory basis over which to stop tracking dirty operations. KMD created this handle in a previous call to [**DxgkDdiCreateMemoryBasis**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_creatememorybasis).

## Return value

**DxgkDdiStopDirtyTracking** returns STATUS_SUCCESS upon success. Otherwise, it returns an appropriate NTSTATUS code.

## Remarks

The driver should ensure that all previous start requests are still honored. For example, if KMD only supports dirty tracking on the entire segment at once and there are two outstanding requests for dirty tracking, stopping only one request should keep dirty bit tracking enabled for the other request.

The driver can be guaranteed that a call to **DxgkDdiStopDirtyTracking** will specify the same ranges of memory as the corresponding [**DxgkDdiStartDirtyTracking**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_startdirtytracking) calls. For example, if *Dxgkrnl* made a call to start dirty tracking on [0, 1GB) of segment 1, there will eventually be a resulting call to stop dirty tracking on the segment [0, 1GB) range in segment 1.

For more information, see [Dirty bit tracking](https://learn.microsoft.com/windows-hardware/drivers/display/dirty-bit-tracking).

## See also

[**DxgkDdiCreateMemoryBasis**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_creatememorybasis)

[**DxgkDdiStartDirtyTracking**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_startdirtytracking)