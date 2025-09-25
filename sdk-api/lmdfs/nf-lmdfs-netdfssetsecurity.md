# NetDfsSetSecurity function

## Description

Sets the security descriptor for the root object of the specified DFS namespace.

## Parameters

### `DfsEntryPath` [in]

Pointer to a string that specifies the Universal Naming Convention (UNC) path of a DFS namespace root.

The string can be in one of two forms. The first form is as follows:

\\*ServerName*\*DfsName*

where *ServerName* is the name of the root target server that hosts the stand-alone DFS namespace and *Dfsname* is the name of the DFS namespace.

The second form is as follows:

\\*DomainName*\*DomDfsName*

where *DomainName* is the name of the domain that hosts the domain-based DFS namespace and *DomDfsName* is the name of the DFS namespace.

### `SecurityInformation` [in]

[SECURITY_INFORMATION](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-information) structure that contains bit flags that indicate the type of security information to set on the root object.

### `pSecurityDescriptor` [in]

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) structure that contains the security descriptor to set as specified in the *SecurityInformation* parameter.

## Return value

If the function succeeds, the return value is **NERR_Success**.

If the function fails, the return value is a system error code. For a list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

For domain-based DFS namespaces, the security descriptor is set on the "CN=*DomDfsName*,CN=DFS-Configuration,CN=System,DC=*domain*" object in Active Directory at the primary domain controller (PDC) of the domain that hosts the DFS namespace, where <*DomDfsName*> is the name of the domain-based DFS namespace and <domain> is the distinguished name of the Active Directory domain that hosts the namespace.

For stand-alone roots, the security descriptor is set on the object specified by the **HKLM**\**Software**\**Microsoft**\**Dfs**\**Standalone**\**<root-name>** registry entry.

## See also

[Distributed File System (DFS) Functions](https://learn.microsoft.com/previous-versions/windows/desktop/dfs/distributed-file-system-dfs-functions)

[NetDfsGetSecurity](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsgetsecurity)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)