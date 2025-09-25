# D3DKMTFlipOverlay function

## Description

The **D3DKMTFlipOverlay** function changes the allocation to display on the overlay.

## Parameters

### `unnamedParam1` [in]

A pointer to a [D3DKMT_FLIPOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_flipoverlay) structure that describes how to change the display on the overlay.

## Return value

**D3DKMTFlipOverlay** returns one of the following values:

| Return code | Description |
|--|--|
| STATUS_SUCCESS | The kernel-mode overlay object was successfully flipped. |
| STATUS_DEVICE_REMOVED | The graphics adapter was stopped or the display device was reset. |
| STATUS_INVALID_PARAMETER | Parameters were validated and determined to be incorrect. |
| STATUS_NO_MEMORY | **D3DKMTFlipOverlay** could not complete because of insufficient memory. |

This function might also return other **NTSTATUS** values.

## See also

[D3DKMT_FLIPOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_flipoverlay)