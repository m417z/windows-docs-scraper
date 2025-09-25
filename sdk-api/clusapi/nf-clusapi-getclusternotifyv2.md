# GetClusterNotifyV2 function

## Description

Retrieves information about the next notification event for a notification port.

## Parameters

### `hChange` [in]

A handle to the notification port. This handle is created by the
[CreateClusterNotifyPortV2](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-createclusternotifyportv2) function.

### `lpdwNotifyKey` [out]

A pointer to the notification key for the notification port.

### `pFilterAndType` [in, out, optional]

A pointer to a [NOTIFY_FILTER_AND_TYPE](https://learn.microsoft.com/windows/desktop/api/clusapi/ns-clusapi-notify_filter_and_type)
structure that describes the next notification event for the notification port.

### `buffer` [in, out, optional]

A pointer to a buffer for the notification event.

### `lpbBufferSize` [in, out, optional]

A pointer to the size of the *buffer* parameter, in bytes.

### `lpszObjectId` [in, out, optional]

A pointer to a Unicode string with the ID of the
cluster object that triggered the event. The string ends with a terminating null character.

### `lpcchObjectId` [in, out, optional]

On input, a pointer to a **DWORD** that specifies the maximum number of characters
that the *lpszObjectId* parameter can hold, including the terminating null character. On
output, a pointer to a **DWORD** that specifies the number of characters that
*lpszObjectId* received, excluding the terminating null character.

### `lpszParentId` [in, out, optional]

A pointer to a Unicode string with the ID of the parent to the cluster object that triggered the event. The
string ends with a terminating null character.

### `lpcchParentId` [in, out, optional]

On input, a pointer to a **DWORD** that specifies the maximum number of characters
the *lpszParentId* parameter can hold, including the terminating null character. On
output, a pointer to a **DWORD** that specifies the number of characters that
*lpszParentId* received, excluding the terminating null character.

### `lpszName` [in, out, optional]

A pointer to a Unicode string that contains the name of the cluster object that triggered the event. The
string ends with a terminating null character.

### `lpcchName` [in, out, optional]

On input, a pointer to a **DWORD** that specifies the maximum number of characters
that the *lpszName* parameter can hold, including the terminating null character. On
output, a pointer to a **DWORD** that specifies the number of characters that
*lpszName* received, excluding the terminating null character.

### `lpszType` [in, out, optional]

A pointer to a Unicode string that contains the type of cluster object that triggered the event. The
string ends with a terminating null character.

### `lpcchType` [in, out, optional]

On input, a pointer to a **DWORD** that specifies the maximum number of characters
the *lpszType* parameter can hold, including the terminating null character. On output,
a pointer to a **DWORD** that specifies the number of characters that
*lpszType* received, excluding the terminating null character.

### `dwMilliseconds` [in, optional]

A time-out value that specifies how long the caller is willing to wait for the notification.

## Return value

if the operation succeeds, this function returns **ERROR_SUCCESS**.

If the operation fails, this function returns one of the following
[system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

| Return code/value | Description |
| --- | --- |
| **ERROR_INVALID_HANDLE**<br><br>6 | The handle that is represented in the *hChange* parameter is invalid or has been closed by another thread. |
| **WAIT_TIMEOUT**<br><br>258 (0x102) | The call timed out before the notification could be successfully returned. |
| **ERROR_MORE_DATA**<br><br>234 (0xEA) | The buffer pointed to by the *lpszName* parameter is not big enough to hold the result. The *lpcchName* parameter returns the number of characters in the result, excluding the terminating null character. |

## See also

[Failover Cluster Management Function](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-management-functions)