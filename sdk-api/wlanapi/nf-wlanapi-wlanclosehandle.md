# WlanCloseHandle function

## Description

The **WlanCloseHandle** function closes a connection to the server.

## Parameters

### `hClientHandle` [in]

The client's session handle, which identifies the connection to be closed. This handle was obtained by a previous call to the [WlanOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanopenhandle) function.

### `pReserved`

Reserved for future use. Set this parameter to **NULL**.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value may be one of the following return codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | *hClientHandle* is **NULL** or invalid, or *pReserved* is not **NULL**. |
| **ERROR_INVALID_HANDLE** | The handle *hClientHandle* was not found in the handle table. |
| **RPC_STATUS** | Various error codes. |

## Remarks

After a connection has been closed, any attempted use of the closed handle can cause unexpected errors. Upon closing, all outstanding notifications are discarded.

 Do not call **WlanCloseHandle** from a callback function. If the client is in the middle of a notification callback when **WlanCloseHandle** is called, the function waits for the callback to finish before returning a value. Calling this function inside a callback function will result in the call never completing. If both the callback function and the thread that closes the handle try to acquire the same lock, a deadlock may occur. In addition, do not call **WlanCloseHandle** from the **DllMain** function in an application DLL. This could also cause a deadlock.

## See also

[WlanOpenHandle](https://learn.microsoft.com/windows/desktop/api/wlanapi/nf-wlanapi-wlanopenhandle)