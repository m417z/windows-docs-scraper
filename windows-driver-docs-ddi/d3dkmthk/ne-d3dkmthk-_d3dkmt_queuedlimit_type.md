# _D3DKMT_QUEUEDLIMIT_TYPE enumeration

## Description

The D3DKMT_QUEUEDLIMIT_TYPE enumeration type contains values that indicate the type of operations to set or retrieve the queued limit for in a call to the [D3DKMTSetQueuedLimit](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtsetqueuedlimit) function.

## Constants

### `D3DKMT_SET_QUEUEDLIMIT_PRESENT`

Indicates to set the limit for the number of present operations that can be queued.

### `D3DKMT_GET_QUEUEDLIMIT_PRESENT`

Indicates to retrieve the limit for the number of present operations that can be queued.

## See also

[D3DKMTSetQueuedLimit](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtsetqueuedlimit)

[D3DKMT_SETQUEUEDLIMIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_setqueuedlimit)