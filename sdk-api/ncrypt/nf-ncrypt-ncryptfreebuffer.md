# NCryptFreeBuffer function

## Description

The **NCryptFreeBuffer** function releases a block of memory allocated by a CNG key storage provider.

## Parameters

### `pvInput` [in]

The address of the memory to be released.

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The function was successful. |
| **NTE_INVALID_PARAMETER** | The *pvInput* parameter is not valid. |

## Remarks

A service must not call this function from its [StartService Function](https://learn.microsoft.com/windows/win32/api/winsvc/nf-winsvc-startservicea). If a service calls this function from its StartService function, a deadlock can occur, and the service may stop responding.