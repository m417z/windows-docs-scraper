# NetMessageNameDel function

## Description

[This function is not supported as of Windows Vista because the messenger service is not supported.]

The
**NetMessageNameDel** function deletes a message alias in the message name table. The function requires that the messenger service be started.

## Parameters

### `servername` [in]

Pointer to a constant string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `msgname` [in]

Pointer to a constant string that specifies the message alias to delete. The string cannot be more than 15 characters long.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The caller does not have the appropriate access to complete the operation. |
| **ERROR_INVALID_PARAMETER** | A parameter is incorrect. |
| **ERROR_NOT_SUPPORTED** | This request is not supported. This error is returned on Windows Vista and later. |
| **NERR_DelComputerName** | A message alias that is also a computer name cannot be deleted. |
| **NERR_IncompleteDel** | The message alias was not successfully deleted from all networks. |
| **NERR_NameInUse** | The message alias is currently in use. Try again later. |
| **NERR_NotLocalName** | The message alias is not on the local computer. |

## Remarks

Only members of the Administrators local group can successfully execute the
**NetMessageNameDel** function on a remote server.

## See also

[Message
Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/message-functions)

[NetMessageNameAdd](https://learn.microsoft.com/windows/desktop/api/lmmsg/nf-lmmsg-netmessagenameadd)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)