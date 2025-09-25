# NetDfsGetFtContainerSecurity function

## Description

Retrieves the security descriptor of the container object for the domain-based DFS namespaces in the specified Active Directory domain.

## Parameters

### `DomainName` [in]

Pointer to a string that specifies the Active Directory domain name.

### `SecurityInformation` [in]

[SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information) structure that contains bit flags that indicate the type of security information to retrieve.

### `ppSecurityDescriptor` [out]

Pointer to a list [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structures that contain the security items requested in the *SecurityInformation* parameter.

**Note** This buffer must be freed by calling the [NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) function.

### `lpcbSecurityDescriptor` [out]

The size of *ppSecurityDescriptor*, in bytes.

## Return value

If the function succeeds, the return value is **NERR_Success**.

If the function fails, the return value is a system error code. For a list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The security descriptor is retrieved from the "CN=DFS-Configuration,CN=System,DC=*domain*" object in Active Directory from the primary domain controller (PDC) of the domain specified in the *DomainName* parameter, where *domain* is the distinguished name of the domain specified in the *DomainName* parameter.

## See also

[Distributed File System (DFS) Functions](https://learn.microsoft.com/previous-versions/windows/desktop/dfs/distributed-file-system-dfs-functions)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)