# RasSecurityDialogBegin function

## Description

The
**RasSecurityDialogBegin** function is a third-party RAS security DLL entry point that the RAS server calls when a remote user tries to connect. This enables the security DLL to begin its authentication of the remote user.

**Note** Windows Server 2008,
Windows Server 2003,
Windows 2000 Server, and
Windows NT Server 4.0 currently provide RAS security host support for serial devices only. Other types of connections, such as Integrated Services Digital Network (ISDN) or virtual private network (VPN) connections, are not supported.

## Parameters

### `hPort` [in]

Specifies a RAS port handle. The security DLL uses this handle in other RAS security functions, such as
[RasSecurityDialogSend](https://learn.microsoft.com/windows/desktop/api/rasshost/nf-rasshost-rassecuritydialogsend) and
[RasSecurityDialogReceive](https://learn.microsoft.com/windows/desktop/api/rasshost/nf-rasshost-rassecuritydialogreceive), to identify this authentication transaction.

Note that this handle is valid only in RAS security functions; do not use it in other I/O functions.

### `pSendBuf` [in]

Pointer to a buffer allocated by the RAS server. The security DLL uses this buffer with the
[RasSecurityDialogSend](https://learn.microsoft.com/windows/desktop/api/rasshost/nf-rasshost-rassecuritydialogsend) function to send text that is displayed in the RAS terminal window on the remote computer.

### `SendBufSize` [in]

Specifies the size, in bytes, of the *pSendBuf* buffer.

### `pRecvBuf` [in]

Pointer to a buffer allocated by the RAS server. The security DLL uses this buffer with the
[RasSecurityDialogReceive](https://learn.microsoft.com/windows/desktop/api/rasshost/nf-rasshost-rassecuritydialogreceive) function to receive the response from the remote user.

### `RecvBufSize` [in]

Specifies the size, in bytes, of the *pRecvBuf* buffer.

### `VOID` [in]

Pointer to the
[RasSecurityDialogComplete](https://learn.microsoft.com/windows/desktop/api/rasshost/nf-rasshost-rassecuritydialogcomplete) function. When the security DLL has completed the authentication of the remote user, it calls this function to report the results to the RAS server.

This callback function has no parameters.

## Return value

If the security DLL successfully starts the authentication operation,
**RasSecurityDialogBegin** should return **NO_ERROR**. In this case, the security DLL must later terminate the authentication transaction by calling the function pointed to by the *RasSecurityDialogComplete* parameter.

If an error occurs,
**RasSecurityDialogBegin** should return a nonzero error code. In this case, the RAS server hangs up the call and records the error in the event log. Returning a nonzero error code terminates the authentication transaction, so the security DLL does not need to call the [RasSecurityDialogComplete](https://learn.microsoft.com/windows/desktop/api/rasshost/nf-rasshost-rassecuritydialogcomplete) function.

## Remarks

When a RAS server receives a call from a remote computer, it calls the
**RasSecurityDialogBegin** function exported by the registered RAS security DLL, if there is one. When the RAS server calls this function, it passes the following information to the security DLL:

* A port handle to identify the connection
* Pointers to buffers to use when communicating with the remote user
* A pointer to the
  [RasSecurityDialogComplete](https://learn.microsoft.com/windows/desktop/api/rasshost/nf-rasshost-rassecuritydialogcomplete) function to call when the authentication has been completed

The port handle and buffer pointers are valid until
[RasSecurityDialogComplete](https://learn.microsoft.com/windows/desktop/api/rasshost/nf-rasshost-rassecuritydialogcomplete) is called to terminate the authentication transaction.

The
**RasSecurityDialogBegin** implementation must return as soon as possible, because the RAS server is blocked and cannot accept any other calls until
**RasSecurityDialogBegin** returns. The
**RasSecurityDialogBegin** function should copy the input parameters and create a thread to communicate with and authenticate the remote user.

## See also

[RAS Server Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/ras-server-administration-functions)

[RasSecurityDialogComplete](https://learn.microsoft.com/windows/desktop/api/rasshost/nf-rasshost-rassecuritydialogcomplete)

[RasSecurityDialogReceive](https://learn.microsoft.com/windows/desktop/api/rasshost/nf-rasshost-rassecuritydialogreceive)

[RasSecurityDialogSend](https://learn.microsoft.com/windows/desktop/api/rasshost/nf-rasshost-rassecuritydialogsend)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)