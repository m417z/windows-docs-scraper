# NetDfsSetFtContainerSecurity function

## Description

Sets the security descriptor of the container object for the domain-based DFS namespaces in the specified Active Directory domain.

## Parameters

### `DomainName` [in]

Pointer to a string that specifies the Active Directory domain name.

### `SecurityInformation` [in]

[SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information) structure that contains bit flags that indicate the type of security information to set.

### `pSecurityDescriptor` [in]

Pointer to a [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure that contains the security attributes to set as specified in the *SecurityInformation* parameter.

## Return value

If the function succeeds, the return value is **NERR_Success**.

If the function fails, the return value is a system error code. For a list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The security descriptor is set on the "CN=DFS-Configuration,CN=System,DC=*domain*" object in Active Directory from the primary domain controller (PDC) of the domain specified in the *DomainName* parameter, where \<domain> is the distinguished name of the domain specified in the *DomainName* parameter.

## See also

[Distributed File System (DFS) Functions](https://learn.microsoft.com/previous-versions/windows/desktop/dfs/distributed-file-system-dfs-functions)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)