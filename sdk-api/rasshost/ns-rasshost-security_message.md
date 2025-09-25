# SECURITY_MESSAGE structure

## Description

The
**SECURITY_MESSAGE** structure is used with the
[RasSecurityDialogComplete](https://learn.microsoft.com/windows/desktop/api/rasshost/nf-rasshost-rassecuritydialogcomplete) function to indicate the results of a RAS security DLL authentication transaction.

## Members

### `dwMsgId`

Indicates whether the RAS server should grant access to the remote user. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SECURITYMSG_SUCCESS** | The security DLL successfully authenticated the remote user identified by the **UserName** member. The RAS server proceeds with its PPP authentication. |
| **SECURITYMSG_FAILURE** | The security DLL denied access to the remote user identified by the **UserName** member. The RAS server hangs up the call and records the failed authentication in the event log. |
| **SECURITYMSG_ERROR** | An error occurred that prevented validation of the remote user. The RAS server hangs up the call and records the error in the event log. |

### `hPort`

Specifies the port handle that the RAS server passed to the security DLL in the
[RasSecurityDialogBegin](https://learn.microsoft.com/windows/desktop/api/rasshost/nf-rasshost-rassecuritydialogbegin) call for this authentication transaction.

### `dwError`

Specifies an error code. If **dwMsgId** is SECURITYMSG_ERROR, set **dwError** to one of the nonzero error codes defined in Winerror.h or Raserror.h. The RAS server records this error code in the event log. If the **dwMsgId** member indicates success or failure, set **dwError** to zero.

### `UserName`

Specifies the name of the remote user if **dwMsgId** is SECURITYMSG_SUCCESS or SECURITYMSG_FAILURE. This string can be empty if **dwMsgId** is SECURITYMSG_ERROR.

### `Domain`

Specifies the name of the logon domain for the remote user if **dwMsgId** is SECURITYMSG_SUCCESS or SECURITYMSG_FAILURE. This string can be empty if **dwMsgId** is SECURITYMSG_ERROR.

## See also

[RAS Server Administration Structures](https://learn.microsoft.com/windows/desktop/RRAS/ras-server-administration-structures)

[RasSecurityDialogBegin](https://learn.microsoft.com/windows/desktop/api/rasshost/nf-rasshost-rassecuritydialogbegin)

[RasSecurityDialogComplete](https://learn.microsoft.com/windows/desktop/api/rasshost/nf-rasshost-rassecuritydialogcomplete)

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)