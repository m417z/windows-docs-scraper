# _D3DKMT_SETDISPLAYMODE_FLAGS structure

## Description

The D3DKMT_SETDISPLAYMODE_FLAGS structure identifies attributes for setting the display mode.

## Members

### `PreserveVidPn` [in]

A Boolean value that specifies whether the video present network (VidPN) for a monitor is preserved.

### `Reserved` [in]

This member is reserved and should be set to zero.

## Remarks

To set attributes of the display mode, you specify bitfields of the D3DKMT_SETDISPLAYMODE_FLAGS structure in the **Flags** member of the [D3DKMT_SETDISPLAYMODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_setdisplaymode) structure.

## See also

[D3DKMT_SETDISPLAYMODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_setdisplaymode)