# ClusterRegGetKeySecurity function

## Description

Returns a copy of the security descriptor protecting the specified [cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database) key.

## Parameters

### `hKey` [in]

Handle to a cluster database key.

### `RequestedInformation` [in]

A [SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information) structure that indicates the requested security descriptor.

### `pSecurityDescriptor` [out]

Pointer to a [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure containing a copy of the requested security descriptor.

### `lpcbSecurityDescriptor` [in, out]

On input, pointer to a count of the number of bytes in the buffer pointed to by *pSecurityDescriptor*. On output, pointer to a count of the number of bytes written to the buffer.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[ClusterRegOpenKey](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregopenkey)