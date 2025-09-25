# D3DKMTWaitForVerticalBlankEvent2 function

## Description

Waits for specified wait objects, including a vertical blank event, to occur and then returns.

## Parameters

### `unnamedParam1` [in]

A [D3DKMT_WAITFORVERTICALBLANKEVENT2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_waitforverticalblankevent2) structure that specifies parameters for waiting on multiple wait objects, including a vertical blank event.

## Return value

Returns one of the following values:

| Return code | Description |
|--|--|
| STATUS_WAIT_0 | The vertical blank event caused the wait object to return. |
| STATUS_WAIT_1–STATUS_WAIT_8 | The number of the user-mode event that caused the wait object to return. |
| STATUS_INVALID_PARAMETER | Parameters were validated and determined to be incorrect. |

## See also

[D3DKMT_WAITFORVERTICALBLANKEVENT2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_waitforverticalblankevent2)