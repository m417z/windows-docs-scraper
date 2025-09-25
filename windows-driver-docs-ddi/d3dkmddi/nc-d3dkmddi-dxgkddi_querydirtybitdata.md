## Description

*Dxgkrnl* calls **DxgkDdiQueryDirtyBitData** to request a copy of the dirty bitplane data from the kernel-mode display miniport driver (KMD).

## Parameters

### `hAdapter`

[in] A handle to a context block associated with a display adapter. KMD previously provided this handle to *Dxgkrnl* in the **MiniportDeviceContext** output parameter of the [**DxgiDdiAddDevice**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pArgs`

[in/out] A pointer to a [**DXGKARG_QUERYDIRTYBITDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_querydirtybitdata) structure that contains input and output information for the query.

## Return value

**DxgkDdiQueryDirtyBitData** returns STATUS_SUCCESS if the query was successfully. Otherwise, it returns an appropriate NTSTATUS error code.

## Remarks

The function provides the memory basis and potential subrange identifiers for the requested dirty information. KMD must write the resulting data to the output buffer. **DxgkDdiQueryDirtyBitData** allows either querying all ranges of the memory basis or a single one.

When memory is readily available, *Dxgkrnl* will try to accelerate this operation using a single call to query all needed data at once. However, under low memory conditions, forward progress using a smaller fixed sized buffer might be required, which is only a smaller subset of the memory basis being tracked from a prior call to DdiStartDirtyTracking. The requested dirty bitplane range will never exceed an actively tracked dirty range.

For more information, see [Dirty bit tracking](https://learn.microsoft.com/windows-hardware/drivers/display/dirty-bit-tracking).

## See also

[**DXGKARG_QUERYDIRTYBITDATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_querydirtybitdata)