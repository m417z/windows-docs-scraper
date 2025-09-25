# D3DKMTUpdateOverlay function

## Description

The **D3DKMTUpdateOverlay** function modifies a kernel-mode overlay object.

## Parameters

### `unnamedParam1` [in]

A pointer to a [D3DKMT_UPDATEOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_updateoverlay) structure that describes how to modify the overlay.

## Return value

**D3DKMTUpdateOverlay** returns one of the following values:

| Return code | Description |
|--|--|
| STATUS_SUCCESS | The kernel-mode overlay object was successfully modified. |
| STATUS_DEVICE_REMOVED | The graphics adapter was stopped or the display device was reset. |
| STATUS_INVALID_PARAMETER | Parameters were validated and determined to be incorrect. |
| STATUS_NO_MEMORY | **D3DKMTUpdateOverlay** could not complete because of insufficient memory. |

This function might also return other **NTSTATUS** values.

## See also

[D3DKMT_UPDATEOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_updateoverlay)