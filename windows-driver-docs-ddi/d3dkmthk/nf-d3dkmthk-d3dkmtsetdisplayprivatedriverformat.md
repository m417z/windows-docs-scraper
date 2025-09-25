# D3DKMTSetDisplayPrivateDriverFormat function

## Description

The **D3DKMTSetDisplayPrivateDriverFormat** function changes the private-format attribute of a video present source.

## Parameters

### `unnamedParam1` [in]

A pointer to a [D3DKMT_SETDISPLAYPRIVATEDRIVERFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_setdisplayprivatedriverformat) structure that describes how to format a video present source.

## Return value

**D3DKMTSetDisplayPrivateDriverFormat** returns one of the following values:

| Return code | Description |
|--|--|
| STATUS_SUCCESS | The video present source was successfully changed. |
| STATUS_DEVICE_REMOVED | The graphics adapter was stopped or the display device was reset. |
| | Parameters were validated and determined to be incorrect. |
| | Before the call to **D3DKMTSetDisplayPrivateDriverFormat**, the device did not acquire exclusive ownership of the view. Therefore, the device could not change the private-format attribute of the video present source. |
| STATUS_NOT_SUPPORTED | The display miniport driver does not support the [DXGKDDI_SETDISPLAYPRIVATEDRIVERFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setdisplayprivatedriverformat) function. |
| STATUS_UNSUCCESSFUL | The display miniport driver could not change the private-format attribute of the view for the video present source. |

This function might also return other **NTSTATUS** values.

## See also

[D3DKMT_SETDISPLAYPRIVATEDRIVERFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_setdisplayprivatedriverformat)

[DXGKDDI_SETDISPLAYPRIVATEDRIVERFORMAT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setdisplayprivatedriverformat)