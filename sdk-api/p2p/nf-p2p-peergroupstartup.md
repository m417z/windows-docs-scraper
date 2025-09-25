# PeerGroupStartup function

## Description

The **PeerGroupStartup** function initiates a peer group by using a requested version of the Peer infrastructure.

## Parameters

### `wVersionRequested` [in]

Specifies the highest version of the Peer Infrastructure that a caller can support. The high order byte specifies the minor version (revision) number. The low order byte specifies the major version number This parameter is required.

### `pVersionData` [out]

Pointer to a [PEER_VERSION_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_version_data) structure that contains the specific level of support provided by the Peer Infrastructure. This parameter is required.

## Return value

Returns **S_OK** if the function succeeds. Otherwise, the function returns one of the following values.

| Return code | Description |
| --- | --- |
| **ERROR_SERVICE_DEPENDENCY_FAIL** | The [Peer Name Resolution Protocol (PNRP)](https://learn.microsoft.com/windows/desktop/P2PSdk/pnrp-namespace-provider-api) service must be started before calling [PeerGroupStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupstartup). |
| **E_OUTOFMEMORY** | There is not enough memory available to complete the operation. |
| **PEER_E_IPV6_NOT_INSTALLED** | The grouping service failed to start because IPv6 is not installed on the computer. |
| **PEER_E_UNSUPPORTED_VERSION** | The requested version is not supported by the installed Peer subsystem. |

Cryptography-specific errors can be returned from the [Microsoft RSA Base Provider](https://learn.microsoft.com/windows/desktop/SecCrypto/microsoft-base-cryptographic-provider). These errors are prefixed with CRYPT_* and defined in Winerror.h.

## Remarks

The [Peer Name Resolution Protocol (PNRP)](https://learn.microsoft.com/windows/desktop/P2PSdk/pnrp-namespace-provider-api) service must be started before calling this function.

This function is called by the application before calling any other Peer Grouping function.

For this release, applications should use **PEER_GROUP_VERSION** as the requested version.

A peer group started with this function is closed by calling [PeerGroupShutdown](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupshutdown) when the application terminates.

## See also

[Grouping API Functions](https://learn.microsoft.com/windows/desktop/P2PSdk/grouping-api-functions)

[PEER_VERSION_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_version_data)

[PeerGroupShutdown](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupshutdown)