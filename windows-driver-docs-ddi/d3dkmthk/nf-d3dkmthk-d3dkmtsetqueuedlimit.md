# D3DKMTSetQueuedLimit function

## Description

The **D3DKMTSetQueuedLimit** function sets or retrieves the limit for the number of operations of the given type that can be queued for the given device.

## Parameters

### `unnamedParam1` [in]

A pointer to a [D3DKMT_SETQUEUEDLIMIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_setqueuedlimit) structure that describes parameters for setting or retrieving the limit of queued operations.

## Return value

**D3DKMTSetQueuedLimit** returns one of the following values:

| Return code | Description |
|--|--|
| STATUS_SUCCESS | The limit of queued operations was successfully set or retrieved. |
| STATUS_DEVICE_REMOVED | The graphics adapter was stopped or the display device was reset. |
| STATUS_INVALID_PARAMETER | Parameters were validated and determined to be incorrect. |

This function might also return other **NTSTATUS** values.

## See also

[D3DKMT_QUEUEDLIMIT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-_d3dkmt_queuedlimit_type)

[D3DKMT_SETQUEUEDLIMIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_setqueuedlimit)