# RasSecurityDialogReceive function

## Description

The
**RasSecurityDialogReceive** function starts an asynchronous operation that receives a remote user's response to a security challenge. The response is the input that the user typed in a terminal window on the remote computer. A third-party RAS security DLL calls this function as part of its authentication of the remote user.

To call this function, first call the
[LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) function to load Rasman.dll. Then call the
[GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) function to get the DLL's
**RasSecurityDialogReceive** entry point.

**Note** Windows Server 2008,
Windows Server 2003,
Windows 2000 Server, and
Windows NT Server 4.0 currently provide RAS security host support for serial devices only. Other types of connections, such as Integrated Services Digital Network (ISDN) or virtual private network (VPN) connections, are not supported.

## Parameters

### `hPort` [in]

Specifies the port handle that the RAS server passed to the security DLL in the
[RasSecurityDialogBegin](https://learn.microsoft.com/windows/desktop/api/rasshost/nf-rasshost-rassecuritydialogbegin) call for this authentication transaction.

### `pBuffer` [in]

Pointer to the receive buffer that was passed to the security DLL in the
[RasSecurityDialogBegin](https://learn.microsoft.com/windows/desktop/api/rasshost/nf-rasshost-rassecuritydialogbegin) call. When the asynchronous receive operation has been completed successfully, this buffer specifies the response from the remote user.

### `pBufferLength` [in]

Pointer to a **WORD** variable. This variable must specify the size, in bytes, of the *pBuffer* buffer. When the receive operation has been completed, the variable indicates the number of bytes returned in the *pBuffer* buffer.

### `Timeout` [in]

Specifies a time-out period, in seconds, after which the RAS server sets the *hEvent* event object to the signaled state.

If this value is zero, there is no time-out period; that is, the RAS server does not signal the event object until the receive operation has been completed.

### `hEvent` [in]

Specifies the handle of an event object created by the
[CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa) function. The RAS server sets the event object to the signaled state when the receive operation has been completed or when the time-out period has elapsed.

## Return value

If the function is successful, the return value is PENDING (defined in Raserror.h). This indicates that the receive operation is in progress.

If an error occurs, the return value is one of the error codes defined in Raserror.h or Winerror.h.
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) does not provide extended error information.

## Remarks

After calling the
[RasSecurityDialogSend](https://learn.microsoft.com/windows/desktop/api/rasshost/nf-rasshost-rassecuritydialogsend) function to send a security challenge to the remote user, the security DLL must call the
**RasSecurityDialogReceive** function to get the user's response.

The
**RasSecurityDialogReceive** function is asynchronous. When the function returns, the security DLL must use one of the wait functions, such as
[WaitForSingleObject](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-waitforsingleobject), to wait for the *hEvent* event object to be signaled. The RAS server signals the event object when the receive operation has been completed or when the time-out interval has elapsed. If the receive operation is successful, the *pBuffer* buffer contains the response from the remote user, and the *pBufferLength* parameter indicates the number of bytes received. If the remote user sends more bytes than will fit in the buffer, the RAS server buffers the excess bytes and returns them in the next
**RasSecurityDialogReceive** call.

Use the *Timeout* parameter to specify a time-out interval. If the time-out elapses, the RAS server signals the event object, and the *pBufferLength* parameter indicates that zero bytes were transferred. Alternatively, set *Timeout* to zero, and specify a time-out interval in the wait function used to wait for the event object.

When a security DLL is authenticating a remote user, the connection operation on the remote computer enters a RASCS_Interactive paused state. The message sent by
[RasSecurityDialogSend](https://learn.microsoft.com/windows/desktop/api/rasshost/nf-rasshost-rassecuritydialogsend) is displayed as output in a terminal window on the remote computer. The response received by
**RasSecurityDialogReceive** is the input that the remote user types in the terminal window. The RASCS_Interactive value is defined in the
[RASCONNSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376727(v=vs.85)) enumeration.

## See also

[CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa)

[GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress)

[LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya)

[RAS Server Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/ras-server-administration-functions)

[RASCONNSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376727(v=vs.85))

[RasSecurityDialogSend](https://learn.microsoft.com/windows/desktop/api/rasshost/nf-rasshost-rassecuritydialogsend)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[WaitForSingleObject](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-waitforsingleobject)