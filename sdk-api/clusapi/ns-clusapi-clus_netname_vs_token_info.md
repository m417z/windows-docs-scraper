# CLUS_NETNAME_VS_TOKEN_INFO structure

## Description

Contains the data needed to request a token. It is used as the input parameter of the [CLUSCTL_RESOURCE_NETNAME_GET_VIRTUAL_SERVER_TOKEN](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-netname-get-virtual-server-token) control code.

## Members

### `ProcessID`

Process ID of the process requesting the token.

### `DesiredAccess`

Specifies an access mask that specifies the requested types of access. For a list of access rights for access
tokens, see
[Access Rights for Access-Token Objects](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-rights-for-access-token-objects).

### `InheritHandle`

Indicates whether the new handle is inheritable. If **TRUE**, the duplicate handle can
be inherited by new processes created by the target process. If **FALSE**, the new handle
cannot be inherited.

## See also

[CLUSCTL_RESOURCE_NETNAME_GET_VIRTUAL_SERVER_TOKEN](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-netname-get-virtual-server-token)

[Data Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/data-structures)