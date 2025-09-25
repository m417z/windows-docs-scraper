# SHARE_INFO_1501 structure

## Description

Contains the security descriptor associated with the specified share. For more information, see [Security Descriptors](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-descriptors).

## Members

### `shi1501_reserved`

Reserved; must be zero.

### `shi1501_security_descriptor`

Specifies the
[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) associated with the share.

## See also

[NetShareSetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharesetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[Network Share Functions](https://learn.microsoft.com/windows/desktop/NetShare/network-share-functions)