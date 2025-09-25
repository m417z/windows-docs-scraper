# ICreateDeviceAccessAsync::Wait

## Description

The **Wait** method waits a specified length of time for an asynchronous bind operation that is in progress to finish.

## Parameters

### `timeout` [in]

Timeout value, in milliseconds, for the wait call. Use **INFINITE** if you want the caller to wait until the operation finishes.

## Return value

This method supports standard return values, in addition to these:

| Return code | Description |
| --- | --- |
| **S_OK** | The wait was successful and the operation finished. |
| **ERROR_TIMEOUT** | The wait timed out before the operation finished. |
| **E_ILLEGAL_METHOD_CALL** | The operation has already closed when this method was called. |

## See also

[ICreateDeviceAccessAsync](https://learn.microsoft.com/previous-versions/windows/desktop/api/deviceaccess/nn-deviceaccess-icreatedeviceaccessasync)