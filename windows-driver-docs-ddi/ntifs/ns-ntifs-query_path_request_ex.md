## Description

The **QUERY_PATH_REQUEST_EX** structure contains the prefix resolution request for [**IOCTL_REDIR_QUERY_PATH_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-ioctl_redir_query_path_ex).

## Members

### `pSecurityContext`

A pointer to a [**IO_SECURITY_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_security_context) structure with the security context.

### `EaLength`

The length, in bytes, of the buffer that **pEaBuffer** points to.

### `pEaBuffer`

A pointer to the extended attributes buffer.

### `PathName`

A non-NULL terminated Unicode string of the form \\\\<*server*>\\<*share*>\\<*path*>.

### `DomainServiceName`

Pointer to an optional domain service name. Only providers that register as **FSRTL_UNC_PROVIDER_FLAGS_DOMAIN_SVC_AWARE** will see domain service names.

This consumes 2 of the 5 ULONG_PTRs initially reserved in the [**IOCTL_REDIR_QUERY_PATH_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-ioctl_redir_query_path_ex) query.

Available starting in Windows 7.

### `EcpList`

Pointer to an optional [**ECP_LIST**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff540148(v=vs.85)) structure that contains the extra create parameter (ECP) list associated with the Create IRP that initiated this query path request.

Available starting in Windows 7.

### `Reserved[2]`

Reserved for system use.

### `Silo`

Pointer to a SILO, associated with the file object on the original IRP. This is required for redirectors to query mini RDR context. This consumes 1 of the 5 ULONG_PTRs initially reserved in the [**IOCTL_REDIR_QUERY_PATH_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-ioctl_redir_query_path_ex) query.

### `Reserved`

Reserved for system use.

## See also

[**IOCTL_REDIR_QUERY_PATH_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-ioctl_redir_query_path_ex)