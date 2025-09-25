# _D3DKMT_DEVICE_ESCAPE structure

## Description

 Do not use the D3DKMT_DEVICE_ESCAPE structure or D3DKMT_DEVICEESCAPE_TYPE enumeration. They are for testing purposes only.

The D3DKMT_DEVICE_ESCAPE structure describes how to control the display device in a call to the [D3DKMTEscape](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtescape) function.

## Members

### `Type`

### `VidPnFromAllocation`

### `VidPnFromAllocation.hPrimaryAllocation` [in]

The primary allocation handle.

### `VidPnFromAllocation.VidPnSourceId` [out]

The VidPN source ID of the primary allocation.

## See also

[D3DKMTEscape](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtescape)

[D3DKMT_ESCAPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_escape)