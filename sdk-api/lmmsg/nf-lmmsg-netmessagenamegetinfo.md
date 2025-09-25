# NetMessageNameGetInfo function

## Description

[This function is not supported as of Windows Vista because the messenger service is not supported.]

The
**NetMessageNameGetInfo** function retrieves information about a particular message alias in the message name table. The function requires that the messenger service be started.

## Parameters

### `servername` [in]

Pointer to a constant string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `msgname` [in]

Pointer to a constant string that specifies the message alias for which to return information.

### `level` [in]

Specifies the information level of the data. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **0** | Return the message alias. The *bufptr* parameter points to a [MSG_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmmsg/ns-lmmsg-msg_info_0) structure. |
| **1** | Return the message alias. The *bufptr* parameter points to a [MSG_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmmsg/ns-lmmsg-msg_info_1) structure. This level exists only for compatibility. Message forwarding is not supported. |

### `bufptr` [out]

Pointer to the buffer that receives the data. The format of this data depends on the value of the *level* parameter. This buffer is allocated by the system and must be freed using the
[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) function. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers) and
[Network Management Function Buffer Lengths](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffer-lengths).

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The caller does not have the appropriate access to complete the operation. |
| **ERROR_INVALID_LEVEL** | The value specified for the *level* parameter is invalid. |
| **ERROR_INVALID_PARAMETER** | A parameter is incorrect. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient memory is available. |
| **ERROR_NOT_SUPPORTED** | This request is not supported. This error is returned on Windows Vista and later. |
| **NERR_NotLocalName** | The message alias is not on the local computer. |

## Remarks

Only members of the Administrators local group can successfully execute the
**NetMessageNameGetInfo** function on a remote server.

To list all the message aliases in a message name table, you can call the
[NetMessageNameEnum](https://learn.microsoft.com/windows/desktop/api/lmmsg/nf-lmmsg-netmessagenameenum) function.

## See also

[MSG_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmmsg/ns-lmmsg-msg_info_0)

[MSG_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmmsg/ns-lmmsg-msg_info_1)

[Message
Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/message-functions)

[NetMessageNameEnum](https://learn.microsoft.com/windows/desktop/api/lmmsg/nf-lmmsg-netmessagenameenum)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)