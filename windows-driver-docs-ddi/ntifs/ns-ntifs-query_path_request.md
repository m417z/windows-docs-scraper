## Description

The **QUERY_PATH_REQUEST** structure contains the prefix resolution request for [**IOCTL_REDIR_QUERY_PATH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-ioctl_redir_query_path).

## Members

### `PathNameLength`

The length, in bytes, of the Unicode string contained in ***FilePathName***.

### `SecurityContext`

A pointer to the security context.

### `FilePathName`

A non-NULL terminated Unicode string of **PathNameLength** bytes with the form \\\\<*server*>\\<*share*>\\<*path*>.

## See also

[**IOCTL_REDIR_QUERY_PATH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-ioctl_redir_query_path)

[**QUERY_PATH_REQUEST_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-query_path_request_ex)

[**QUERY_PATH_RESPONSE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-query_path_response)