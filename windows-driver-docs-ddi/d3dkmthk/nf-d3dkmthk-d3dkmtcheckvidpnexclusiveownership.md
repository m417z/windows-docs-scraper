# D3DKMTCheckVidPnExclusiveOwnership function

## Description

The **D3DKMTCheckVidPnExclusiveOwnership** function determines the video present source in the path of a video present network (VidPN) topology that exclusively owns the VidPN.

## Parameters

### `unnamedParam1` [in]

A pointer to a [D3DKMT_CHECKVIDPNEXCLUSIVEOWNERSHIP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_checkvidpnexclusiveownership) structure that describes the parameters to determine exclusive VidPN ownership.

## Return value

**D3DKMTCheckVidPnExclusiveOwnership** returns one of the following values:

| Return code | Description |
|--|--|
| STATUS_SUCCESS | Exclusive ownership of the VidPN was successfully determined. |
| STATUS_DEVICE_REMOVED | The graphics adapter was stopped or the display device was reset. |
| STATUS_GRAPHICS_VIDPN_SOURCE_IN_USE | The video present source that is identified by the VidPnSourceId member of [D3DKMT_CHECKVIDPNEXCLUSIVEOWNERSHIP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_checkvidpnexclusiveownership) is already owned by a display mode manager (DMM) client and cannot be used until the client releases the video present source. |
| STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_SOURCE | The video present source that is identified by the VidPnSourceId member of D3DKMT_CHECKVIDPNEXCLUSIVEOWNERSHIP is invalid. |
| STATUS_INVALID_PARAMETER | Parameters were validated and determined to be incorrect. |

This function might also return other **NTSTATUS** values.

## See also

[D3DKMT_CHECKVIDPNEXCLUSIVEOWNERSHIP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_checkvidpnexclusiveownership)