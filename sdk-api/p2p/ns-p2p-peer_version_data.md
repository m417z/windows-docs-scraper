# PEER_VERSION_DATA structure

## Description

The **PEER_VERSION_DATA** structure contains the version information about the Peer Graphing and Grouping APIs.

## Members

### `wVersion`

Specifies the version of the Peer Infrastructure for a caller to use. The version to use is based on the Peer Infrastructure DLL installed on a local computer. A high order-byte specifies the minor version (revision) number. A low-order byte specifies the major version number.

### `wHighestVersion`

Specifies the highest version of the Peer Infrastructure that the Peer DLL installed on the local computer can support. Typically, this value is the same as **wVersion**.

## See also

[PeerGraphStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphstartup)

[PeerGroupStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupstartup)