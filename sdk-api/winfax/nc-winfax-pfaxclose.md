# PFAXCLOSE callback function

## Description

The **FaxClose** function closes the following types of fax handles:

* A fax server handle returned by a call to the [FaxConnectFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxconnectfaxservera) function
* A fax port handle returned by a call to the [FaxOpenPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxopenport) function

## Parameters

### `FaxHandle` [in]

Type: **HANDLE**

Specifies the fax handle to close. This value can be a fax server handle returned by a call to the [FaxConnectFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxconnectfaxservera) function, or a fax port handle returned by a call to the [FaxOpenPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxopenport) function.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). GetLastError can return one of the following errors.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access is denied. [FAX_PORT_QUERY](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-specific-fax-access-rights) access is required. |
| **ERROR_INVALID_HANDLE** | The *FaxHandle* parameter is invalid. |

## Remarks

A fax client application must call the **FaxClose** function as the last function before it terminates. The [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function cannot close the handle to a fax server or a fax port.

When the **FaxClose** function closes a handle allocated by the [FaxConnectFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxconnectfaxservera) function, the function disconnects the calling application from the specified fax server.

A fax client application continues to receive fax events from the fax service after the application successfully calls the **FaxClose** function to close a fax server handle. This permits the fax service to shut down and conserve system resources when the service has been idle for an extended period. If you keep the handle to the fax server open, the fax service does not shut down.

For more information, see [Enabling an Application to Receive Notifications of Fax Events](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-enabling-an-application-to-receive-notifications-of-fax-events), [Connecting to a Fax Server](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-connecting-to-a-fax-server) and [Disconnecting from a Fax Server](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-disconnecting-from-a-fax-server), and [FaxInitializeEventQueue](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxinitializeeventqueue).

## See also

[Fax Service Client API Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-functions)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxConnectFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxconnectfaxservera)

[FaxOpenPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nc-winfax-pfaxopenport)