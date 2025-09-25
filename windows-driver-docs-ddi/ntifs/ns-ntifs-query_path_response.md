## Description

The **QUERY_PATH_RESPONSE** structure contains the response for an [**IOCTL_REDIR_QUERY_PATH_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-ioctl_redir_query_path_ex) (or [**IOCTL_REDIR_QUERY_PATH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-ioctl_redir_query_path)) prefix resolution query.

## Members

### `LengthAccepted`

The length, in bytes, of the prefix claimed by the provider from the Unicode string path that is specified in the **PathName** member of the [**QUERY_PATH_REQUEST_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-query_path_request_ex) (or [**IOCTL_REDIR_QUERY_PATH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-ioctl_redir_query_path)) structure.

## See also

[**IOCTL_REDIR_QUERY_PATH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-ioctl_redir_query_path)

[**IOCTL_REDIR_QUERY_PATH_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-ioctl_redir_query_path_ex)

[**QUERY_PATH_REQUEST_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-query_path_request_ex)