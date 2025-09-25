# NetMessageNameEnum function

## Description

[This function is not supported as of Windows Vista because the messenger service is not supported.]

The
**NetMessageNameEnum** function lists the message aliases that receive messages on a specified computer. The function requires that the messenger service be started.

## Parameters

### `servername` [in]

Pointer to a constant string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `level` [in]

Specifies the information level of the data. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **0** | Return message aliases. The *bufptr* parameter points to an array of [MSG_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmmsg/ns-lmmsg-msg_info_0) structures. |
| **1** | Return message aliases. The *bufptr* parameter points to an array of [MSG_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmmsg/ns-lmmsg-msg_info_1) structures. This level exists only for compatibility. Message forwarding is not supported. |

### `bufptr` [out]

Pointer to the buffer that receives the data. The format of this data depends on the value of the *level* parameter. This buffer is allocated by the system and must be freed using the
[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) function. Note that you must free the buffer even if the function fails with ERROR_MORE_DATA.

### `prefmaxlen` [in]

Specifies the preferred maximum length of the returned data, in bytes. If you specify MAX_PREFERRED_LENGTH, the function allocates the amount of memory required for the data. If you specify another value in this parameter, it can restrict the number of bytes that the function returns. If the buffer size is insufficient to hold all entries, the function returns ERROR_MORE_DATA. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers) and
[Network Management Function Buffer Lengths](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffer-lengths).

### `entriesread` [out]

Pointer to a value that receives the count of elements actually enumerated.

### `totalentries` [out]

Pointer to a value that receives the total number of entries that could have been enumerated from the current resume position. Note that applications should consider this value only as a hint.

### `resume_handle` [in, out]

Pointer to a value that contains a resume handle which is used to continue an existing message alias search. The handle should be zero on the first call and left unchanged for subsequent calls. If *resume_handle* is **NULL**, no resume handle is stored.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The caller does not have the appropriate access to complete the operation. |
| **ERROR_INVALID_LEVEL** | The value specified for the *level* parameter is invalid. |
| **ERROR_INVALID_PARAMETER** | A parameter is incorrect. |
| **ERROR_MORE_DATA** | More entries are available. Specify a large enough buffer to receive all entries. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient memory is available. |
| **ERROR_NOT_SUPPORTED** | This request is not supported. This error is returned on Windows Vista and later. |
| **NERR_BufTooSmall** | The supplied buffer is too small. |

## Remarks

Only members of the Administrators local group can successfully execute the
**NetMessageNameEnum** function on a remote server.

To retrieve information about a particular message alias in the message name table, you can call the
[NetMessageNameGetInfo](https://learn.microsoft.com/windows/desktop/api/lmmsg/nf-lmmsg-netmessagenamegetinfo) function.

## See also

[MSG_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmmsg/ns-lmmsg-msg_info_0)

[MSG_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmmsg/ns-lmmsg-msg_info_1)

[Message
Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/message-functions)

[NetMessageNameGetInfo](https://learn.microsoft.com/windows/desktop/api/lmmsg/nf-lmmsg-netmessagenamegetinfo)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)