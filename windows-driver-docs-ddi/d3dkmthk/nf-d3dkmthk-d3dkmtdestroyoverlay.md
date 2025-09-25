# D3DKMTDestroyOverlay function

## Description

The **D3DKMTDestroyOverlay** function destroys a kernel-mode overlay object.

## Parameters

### `unnamedParam1` [in]

A pointer to a [D3DKMT_DESTROYOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_destroyoverlay) structure that contains the handle to the overlay to destroy.

## Return value

**D3DKMTDestroyOverlay** returns one of the following values:

| Return code | Description |
|--|--|
| STATUS_SUCCESS | The kernel-mode overlay object was successfully destroyed. |
| STATUS_INVALID_PARAMETER | Parameters were validated and determined to be incorrect. |

This function might also return other **NTSTATUS** values.

## See also

[D3DKMT_DESTROYOVERLAY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_destroyoverlay)