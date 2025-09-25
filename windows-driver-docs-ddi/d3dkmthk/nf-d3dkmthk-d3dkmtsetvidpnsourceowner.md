# D3DKMTSetVidPnSourceOwner function

## Description

The **D3DKMTSetVidPnSourceOwner** function sets and releases the video present source in the path of a video present network (VidPN) topology that owns the VidPN.

## Parameters

### `unnamedParam1` [in]

A pointer to a [D3DKMT_SETVIDPNSOURCEOWNER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_setvidpnsourceowner) structure that describes the parameters for setting or releasing.

## Return value

**D3DKMTSetVidPnSourceOwner** returns one of the following values:

| Return code | Description |
|--|--|
| STATUS_SUCCESS | The video present source was successfully set or released. |
| STATUS_DEVICE_REMOVED | The graphics adapter was stopped or the display device was reset. |
| STATUS_GRAPHICS_VIDPN_SOURCE_IN_USE | The video present source that is specified by an element in the array that the pVidPnSourceId member of [D3DKMT_SETVIDPNSOURCEOWNER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_setvidpnsourceowner) specifies is already owned by a display mode manager (DMM) client and cannot be used until the client releases the video present source. |
| STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_SOURCE | The video present source that is specified by an element in the array that the pVidPnSourceId member of [D3DKMT_SETVIDPNSOURCEOWNER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_setvidpnsourceowner) specifies is invalid. |
| STATUS_INVALID_PARAMETER | Parameters were validated and determined to be incorrect. |

This function might also return other **NTSTATUS** values.

## Remarks

To set ownership of video present sources, the OpenGL installable client driver (ICD) sets values in the array that the *pType* member of the [D3DKMT_SETVIDPNSOURCEOWNER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_setvidpnsourceowner) structure specifies, identifiers of the video present sources in the array that the *pVidPnSourceId* member of **D3DKMT_SETVIDPNSOURCEOWNER** specifies, and the number of video present sources in the *VidPnSourceCount* member of **D3DKMT_SETVIDPNSOURCEOWNER**.

To release ownership of any video present sources, the ICD sets *pType* and *pVidPnSourceId* to NULL and *VidPnSourceCount* to zero in **D3DKMT_SETVIDPNSOURCEOWNER**.

The ICD passes a pointer to [D3DKMT_SETVIDPNSOURCEOWNER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_setvidpnsourceowner) in the *pData* parameter in a call to **D3DKMTSetVidPnSourceOwner**.

## See also

[D3DKMT_SETVIDPNSOURCEOWNER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_setvidpnsourceowner)