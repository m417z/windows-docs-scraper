# RasSecurityDialogEnd function

## Description

The
**RasSecurityDialogEnd** function is a third-party RAS security DLL entry point that the RAS server calls to terminate an authentication transaction.

**Note** Windows Server 2008,
Windows Server 2003,
Windows 2000 Server, and
Windows NT Server 4.0 currently provide RAS security host support for serial devices only. Other types of connections, such as Integrated Services Digital Network (ISDN) or virtual private network (VPN) connections, are not supported.

## Parameters

### `hPort` [in]

Specifies the port handle that the RAS server passed to the security DLL in the
[RasSecurityDialogBegin](https://learn.microsoft.com/windows/desktop/api/rasshost/nf-rasshost-rassecuritydialogbegin) call for this authentication transaction.

## Return value

If the security DLL returns **NO_ERROR**, the RAS server does not terminate the authentication transaction. In this case, the security DLL must later call the
[RasSecurityDialogComplete](https://learn.microsoft.com/windows/desktop/api/rasshost/nf-rasshost-rassecuritydialogcomplete) function when it is ready to terminate.

If the security DLL returns a nonzero error code, the RAS server terminates the authentication transaction. In this case, the security DLL does not need to make another
[RasSecurityDialogComplete](https://learn.microsoft.com/windows/desktop/api/rasshost/nf-rasshost-rassecuritydialogcomplete) call. Return an error code defined in Winerror.h or Raserror.h, such as **ERROR_PORT_DISCONNECTED**.

## Remarks

When a security DLL has finished authenticating the remote user, it calls the
[RasSecurityDialogComplete](https://learn.microsoft.com/windows/desktop/api/rasshost/nf-rasshost-rassecuritydialogcomplete) function. The RAS server then performs a cleanup sequence that includes a call to the DLL's
**RasSecurityDialogEnd** function. This gives the security DLL an opportunity to perform any necessary cleanup. To terminate the authentication transaction,
**RasSecurityDialogEnd** must return a nonzero error code.

The RAS server may also call
**RasSecurityDialogEnd** if it needs to abnormally terminate the authentication transaction before the security DLL calls
[RasSecurityDialogComplete](https://learn.microsoft.com/windows/desktop/api/rasshost/nf-rasshost-rassecuritydialogcomplete). In this case, the security DLL should terminate the worker thread associated with the *hPort* port handle, and perform any other necessary cleanup. If
**RasSecurityDialogEnd** returns a nonzero value, the security DLL does not need to call
**RasSecurityDialogComplete**.

For both normal and abnormal termination, the
**RasSecurityDialogEnd** function returns NO_ERROR to delay the termination. If it does so, it must later call
[RasSecurityDialogComplete](https://learn.microsoft.com/windows/desktop/api/rasshost/nf-rasshost-rassecuritydialogcomplete) when it is ready to terminate.

## See also

[RAS Server Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/ras-server-administration-functions)

[RasSecurityDialogBegin](https://learn.microsoft.com/windows/desktop/api/rasshost/nf-rasshost-rassecuritydialogbegin)

[RasSecurityDialogComplete](https://learn.microsoft.com/windows/desktop/api/rasshost/nf-rasshost-rassecuritydialogcomplete)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)