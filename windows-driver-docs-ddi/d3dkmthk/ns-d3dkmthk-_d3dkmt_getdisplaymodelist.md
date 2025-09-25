# D3DKMT_GETDISPLAYMODELIST structure

## Description

The **D3DKMT_GETDISPLAYMODELIST** structure describes a list of display modes.

## Members

### `hAdapter`

[in] A handle to the graphics adapter.

### `VidPnSourceId`

[in] The zero-based identification number of the video present source in a path of a video present network (VidPN) topology that the display modes apply to.

### `pModeList`

[in/out] An array of [**D3DKMT_DISPLAYMODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_displaymode) structures that represent the list of display modes. If **pModeList** is NULL and **ModeCount** is zero on input, [**D3DKMTGetDisplayModeList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtgetdisplaymodelist) sets **ModeCount** to be the number of display modes for the specified **VidPnSourceId** on the specified graphics adapter.

### `ModeCount`

[in/out] The number of display modes in the array that **pModeList** specifies. If **pModeList** is NULL and **ModeCount** is zero on input, [**D3DKMTGetDisplayModeList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtgetdisplaymodelist) sets **ModeCount** to be the number of display modes for the specified **VidPnSourceId** on the specified graphics adapter.

## See also

[**D3DKMTGetDisplayModeList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtgetdisplaymodelist)

[**D3DKMT_DISPLAYMODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_displaymode)