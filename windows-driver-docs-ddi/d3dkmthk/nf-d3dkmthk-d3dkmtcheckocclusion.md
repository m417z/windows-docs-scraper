# D3DKMTCheckOcclusion function

## Description

The **D3DKMTCheckOcclusion** function verifies whether the client area of a window is occluded.

## Parameters

### `unnamedParam1` [in]

A pointer to a [D3DKMT_CHECKOCCLUSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_checkocclusion) structure that describes parameters for checking occlusion.

## Return value

**D3DKMTCheckOcclusion** returns one of the following values:

| Return code | Description |
|--|--|
| STATUS_SUCCESS | The client area of the window is not occluded. |
| STATUS_GRAPHICS_PRESENT_OCCLUDED | The client area of the window is occluded. |
| STATUS_INVALID_PARAMETER | Parameters were validated and determined to be incorrect. |

This function might also return other **NTSTATUS** values.

## Remarks

The handle to the window that is checked for occlusion must be valid. A window is not occluded if a part of its client area lies on an unowned video present network (VidPn) source, if its client area is an empty rectangular area (RECT), or if desktop composition is running.

## See also

[D3DKMT_CHECKOCCLUSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_checkocclusion)