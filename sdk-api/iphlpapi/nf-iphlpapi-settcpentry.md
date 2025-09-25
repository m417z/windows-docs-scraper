# SetTcpEntry function

## Description

The
**SetTcpEntry** function sets the state of a TCP connection.

## Parameters

### `pTcpRow` [in]

A pointer to a
[MIB_TCPROW](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcprow_lh) structure. This structure specifies information to identify the TCP connection to modify. It also specifies the new state for the TCP connection. The caller must specify values for all the members in this structure.

## Return value

The function returns **NO_ERROR** (zero) if the function is successful.

If the function fails, the return value is one of the following error codes.

| Return code/value | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access is denied. This error is returned on Windows Vista and Windows Server 2008 under several conditions that include the following: the user lacks the required administrative privileges on the local computer or the application is not running in an enhanced shell as the built-in Administrator (RunAs administrator). |
| **ERROR_INVALID_PARAMETER** | An input parameter is invalid, no action was taken. This error is returned if the *pTcpRow* parameter is **NULL** or the **Row** member in the [MIB_TCPROW](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcprow_lh) structure pointed to by the *pTcpRow* parameter is not set to MIB_TCP_STATE_DELETE_TCB. |
| **ERROR_NOT_SUPPORTED** | The IPv4 transport is not configured on the local computer. |
| 317 | The function is unable to set the TCP entry since the application is running non-elevated. |
| **Other** | Use [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) to obtain the message string for the returned error. |

## Remarks

Currently, the only state to which a TCP connection can be set is MIB_TCP_STATE_DELETE_TCB.

On Windows Vista and later, the **SetTcpEntry** function can only be called by a user logged on as a member of the Administrators group. If **SetTcpEntry** is called by a user that is not a member of the Administrators group, the function call will fail and **ERROR_ACCESS_DENIED** is returned.

The **SetTcpEntry** function can also fail because of user account control (UAC) on Windows Vista and later. If an application that contains this function is executed by a user logged on as a member of the Administrators group other than the built-in Administrator, this call will fail unless the application has been marked in the manifest file with a **requestedExecutionLevel** set to requireAdministrator. If the application lacks this manifest file, a user logged on as a member of the Administrators group other than the built-in Administrator must then be executing the application in an enhanced shell as the built-in Administrator (RunAs administrator) for this function to succeed.

## See also

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[IP Helper Start Page](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-start-page)

[MIB_TCPROW](https://learn.microsoft.com/windows/desktop/api/tcpmib/ns-tcpmib-mib_tcprow_lh)