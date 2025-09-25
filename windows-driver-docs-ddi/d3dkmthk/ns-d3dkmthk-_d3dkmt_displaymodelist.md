# _D3DKMT_DISPLAYMODELIST structure

## Description

Describes a list of display modes.

## Members

### `VidPnSourceId` [in]

The zero-based identification number of the video present source in a path of a video present network (VidPN) topology that the display modes apply to.

### `ModeCount` [in/out]

The number of display modes in the array that **pModeList** specifies.

### `pModeList` [out]

An array of [D3DKMT_DISPLAYMODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_displaymode) structures that represent the list of display modes.