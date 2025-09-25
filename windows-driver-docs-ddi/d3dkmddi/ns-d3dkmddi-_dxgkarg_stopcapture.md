# _DXGKARG_STOPCAPTURE structure

## Description

The DXGKARG_STOPCAPTURE structure contains the handle to the allocation that is used for a capture buffer.

## Members

### `hAllocation` [in]

A handle to the allocation that is used for a capture buffer. The display miniport driver stops the capture hardware from using the allocation.

## See also

[DxgkDdiStopCapture](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_stopcapture)