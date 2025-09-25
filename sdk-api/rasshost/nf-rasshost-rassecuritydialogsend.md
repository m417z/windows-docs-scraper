# RasSecurityDialogSend function

## Description

The
**RasSecurityDialogSend** function sends a message to be displayed in a terminal window on a remote computer. A third-party RAS security DLL sends this message as part of its authentication of a remote user.

To call this function, first call the
[LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) function to load Rasman.dll. Then call the
[GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) function to get the DLL's
**RasSecurityDialogSend** entry point.

**Note** Windows Server 2008,
Windows Server 2003,
Windows 2000 Server, and
Windows NT Server 4.0 currently provide RAS security host support for serial devices only. Other types of connections, such as Integrated Services Digital Network (ISDN) or virtual private network (VPN) connections, are not supported.

## Parameters

### `hPort` [in]

Specifies the port handle that the RAS server passed to the security DLL in the
[RasSecurityDialogBegin](https://learn.microsoft.com/windows/desktop/api/rasshost/nf-rasshost-rassecuritydialogbegin) call for this authentication transaction.

### `pBuffer` [in]

Pointer to the send buffer that was passed to the security DLL in the call to
[RasSecurityDialogBegin](https://learn.microsoft.com/windows/desktop/api/rasshost/nf-rasshost-rassecuritydialogbegin). Before calling
**RasSecurityDialogSend**, copy into this buffer the message to send to the remote user. The *SendBufSize* parameter of the
**RasSecurityDialogBegin** function indicates the maximum number of bytes the buffer can store.

### `BufferLength` [in]

Specifies the number of bytes to send in the *pBuffer* buffer.

## Return value

If the function is successful, the return value is PENDING (defined in Raserror.h). This indicates that the send operation is in progress.

If an error occurs, the return value is one of the error codes defined in Raserror.h or Winerror.h.
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) does not provide extended error information.

## Remarks

The
**RasSecurityDialogSend** function is asynchronous. After calling it to send a message to the remote user, call the
[RasSecurityDialogReceive](https://learn.microsoft.com/windows/desktop/api/rasshost/nf-rasshost-rassecuritydialogreceive) function, and then wait for a response. The security DLL can make any number of
**RasSecurityDialogSend** calls, with each call followed by a
**RasSecurityDialogReceive** call.

When a security DLL is authenticating a remote user, the connection operation on the remote computer enters a RASCS_Interactive paused state. The message sent by
**RasSecurityDialogSend** is displayed as output in a terminal window on the remote computer. The response received by
[RasSecurityDialogReceive](https://learn.microsoft.com/windows/desktop/api/rasshost/nf-rasshost-rassecuritydialogreceive) is the input that the remote user types in the terminal window. The RASCS_Interactive value is defined in the
[RASCONNSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376727(v=vs.85)) enumeration.

## See also

[GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress)

[LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya)

[RAS Server Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/ras-server-administration-functions)

[RASCONNSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376727(v=vs.85))

[RasSecurityDialogBegin](https://learn.microsoft.com/windows/desktop/api/rasshost/nf-rasshost-rassecuritydialogbegin)

[RasSecurityDialogReceive](https://learn.microsoft.com/windows/desktop/api/rasshost/nf-rasshost-rassecuritydialogreceive)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)