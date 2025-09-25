# NetMessageBufferSend function

## Description

[This function is not supported as of Windows Vista because the messenger service is not supported.]

The
**NetMessageBufferSend** function sends a buffer of information to a registered message alias.

## Parameters

### `servername` [in]

Pointer to a constant string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `msgname` [in]

Pointer to a constant string that specifies the message alias to which the message buffer should be sent.

### `fromname` [in]

Pointer to a constant string specifying who the message is from. If this parameter is **NULL**, the message is sent from the local computer name.

### `buf` [in]

Pointer to a buffer that contains the message text. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers).

### `buflen` [in]

Specifies a value that contains the length, in bytes, of the message text pointed to by the *buf* parameter.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The caller does not have the appropriate access to complete the operation. |
| **ERROR_INVALID_PARAMETER** | A parameter is incorrect. |
| **ERROR_NOT_SUPPORTED** | This request is not supported. This error is returned on Windows Vista and later. |
| **NERR_NameNotFound** | The user name could not be found. |
| **NERR_NetworkError** | A general failure occurred in the network hardware. |

## Remarks

If you call this function on a domain controller that is running Active Directory, access is allowed or denied based on the access control list (ACL) for the securable object. The default ACL permits only Domain Admins and Account Operators to call this function. On a member server or workstation, only Administrators and Server Operators can call this function. For more information, see
[Security Requirements for the Network Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/security-requirements-for-the-network-management-functions). For more information on ACLs and ACEs, see
[Access Control Model](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-model).

## See also

[Message
Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/message-functions)

[NetMessageNameAdd](https://learn.microsoft.com/windows/desktop/api/lmmsg/nf-lmmsg-netmessagenameadd)

[NetMessageNameDel](https://learn.microsoft.com/windows/desktop/api/lmmsg/nf-lmmsg-netmessagenamedel)

[NetMessageNameEnum](https://learn.microsoft.com/windows/desktop/api/lmmsg/nf-lmmsg-netmessagenameenum)

[NetMessageNameGetInfo](https://learn.microsoft.com/windows/desktop/api/lmmsg/nf-lmmsg-netmessagenamegetinfo)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)