# PFND3DKMT_SETVIDPNSOURCEOWNER1 callback function

## Description

Sets and releases the video present source in the path of a video present network (VidPN) topology that owns the VidPN, and lets output duplication options be specified. Supported starting with Windows 8.

## Parameters

### `unnamedParam1` [in]

*pSetVidPnSourceOwner1*

A pointer to a [D3DKMT_SETVIDPNSOURCEOWNER1](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_setvidpnsourceowner1) structure that describes the parameters for setting or releasing the video present source.

## Return value

Returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **STATUS_SUCCESS** | The video present source was successfully set or released. |
| **STATUS_DEVICE_REMOVED** | The graphics adapter was stopped or the display device was reset. |
| **STATUS_GRAPHICS_VIDPN_SOURCE_IN_USE** | The video present source that is specified by an element in the array that the pVidPnSourceId member of [D3DKMT_SETVIDPNSOURCEOWNER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_setvidpnsourceowner) specifies is already owned by a display mode manager (DMM) client and cannot be used until the client releases the video present source. |
| **STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_SOURCE** | The video present source that is specified by an element in the array that the pVidPnSourceId member of [D3DKMT_SETVIDPNSOURCEOWNER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_setvidpnsourceowner) specifies is invalid. |
| **STATUS_INVALID_PARAMETER** | Parameters were validated and determined to be incorrect. |

This function might also return other NTSTATUS values.

## See also

[D3DKMT_SETVIDPNSOURCEOWNER1](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_setvidpnsourceowner1)