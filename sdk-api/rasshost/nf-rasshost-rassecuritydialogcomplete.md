# RasSecurityDialogComplete function

## Description

The
**RasSecurityDialogComplete** function notifies the RAS server of the results of a third-party security authentication transaction. A third-party RAS security DLL calls
**RasSecurityDialogComplete** when it has completed its authentication of the remote user.

The RAS server passes a pointer to the
**RasSecurityDialogComplete** function when the server calls the
[RasSecurityDialogBegin](https://learn.microsoft.com/windows/desktop/api/rasshost/nf-rasshost-rassecuritydialogbegin) entry point of the security DLL.

**Note** Windows Server 2008,
Windows Server 2003,
Windows 2000 Server, and
Windows NT Server 4.0 currently provide RAS security host support for serial devices only. Other types of connections, such as Integrated Services Digital Network (ISDN) or virtual private network (VPN) connections, are not supported.

## Parameters

### `pSecMsg` [in]

Pointer to the
[SECURITY_MESSAGE](https://learn.microsoft.com/windows/desktop/api/rasshost/ns-rasshost-security_message) structure that specifies the results of the authentication transaction.

## Remarks

When a security DLL has finished authenticating the remote user, it calls the
**RasSecurityDialogComplete** function to report the results. The RAS server then performs a cleanup sequence. As part of this cleanup sequence, the RAS server calls the security DLL's
[RasSecurityDialogEnd](https://learn.microsoft.com/windows/desktop/api/rasshost/nf-rasshost-rassecuritydialogend) function to give the DLL an opportunity to perform its own cleanup, if necessary.

## See also

[RAS Server Administration Functions](https://learn.microsoft.com/windows/desktop/RRAS/ras-server-administration-functions)

[RasSecurityDialogBegin](https://learn.microsoft.com/windows/desktop/api/rasshost/nf-rasshost-rassecuritydialogbegin)

[RasSecurityDialogEnd](https://learn.microsoft.com/windows/desktop/api/rasshost/nf-rasshost-rassecuritydialogend)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[SECURITY_MESSAGE](https://learn.microsoft.com/windows/desktop/api/rasshost/ns-rasshost-security_message)