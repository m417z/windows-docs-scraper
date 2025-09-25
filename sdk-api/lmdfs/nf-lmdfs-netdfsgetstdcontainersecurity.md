# NetDfsGetStdContainerSecurity function

## Description

Retrieves the security descriptor for the container object of the specified stand-alone DFS namespace.

## Parameters

### `MachineName` [in]

Pointer to a string that specifies the name of the server that hosts the stand-alone DFS namespace.

### `SecurityInformation` [in]

[SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information) structure that contains bit flags that indicate the type of security information to retrieve.

### `ppSecurityDescriptor` [out]

Pointer to a list of [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structures that contain the security items requested in the *SecurityInformation* parameter.

**Note** This buffer must be freed by calling the [NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) function.

### `lpcbSecurityDescriptor` [out]

The size of the buffer that *ppSecurityDescriptor* points to, in bytes.

## Return value

If the function succeeds, the return value is **NERR_Success**.

If the function fails, the return value is a system error code. For a list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The security descriptor is retrieved from the object specified by the **HKLM**\**Software**\**Microsoft**\**Dfs**\**Standalone** key in the registry of the server specified in the *MachineName* parameter.

## See also

[Distributed File System (DFS) Functions](https://learn.microsoft.com/previous-versions/windows/desktop/dfs/distributed-file-system-dfs-functions)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)