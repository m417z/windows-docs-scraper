# D3DKMTWaitForVerticalBlankEvent function

## Description

The **D3DKMTWaitForVerticalBlankEvent** function waits for the vertical blanking interval to occur and then returns.

## Parameters

### `unnamedParam1` [in]

A pointer to a [D3DKMT_WAITFORVERTICALBLANKEVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_waitforverticalblankevent) structure that describes parameters for waiting for the vertical blank to occur.

## Return value

**D3DKMTWaitForVerticalBlankEvent** returns one of the following values:

| Return code | Description |
|--|--|
| STATUS_SUCCESS | The vertical blanking interval successfully occurred. |
| STATUS_DEVICE_REMOVED | The graphics adapter was stopped or the display device was reset. |
| STATUS_INVALID_PARAMETER | Parameters were validated and determined to be incorrect. |

This function might also return other **NTSTATUS** values.

## See also

[D3DKMT_WAITFORVERTICALBLANKEVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_waitforverticalblankevent)