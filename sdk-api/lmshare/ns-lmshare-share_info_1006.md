# SHARE_INFO_1006 structure

## Description

Specifies the maximum number of concurrent connections that the shared resource can accommodate.

## Members

### `shi1006_max_uses`

Specifies a DWORD value that indicates the maximum number of concurrent connections that the shared resource can accommodate. The number of connections is unlimited if the value specified in this member is –1.

## See also

[NetShareSetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharesetinfo)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Structures](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-structures)

[Network Share Functions](https://learn.microsoft.com/windows/desktop/NetShare/network-share-functions)