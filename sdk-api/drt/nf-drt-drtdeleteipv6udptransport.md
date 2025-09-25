# DrtDeleteIpv6UdpTransport function

## Description

The **DrtDeleteIpv6UdpTransport** function deletes a transport based on the IPv6 UDP protocol.

## Parameters

### `hTransport` [in]

The DRT transport handle specifying the transport to delete.

## Return value

This function returns S_OK on success. Other possible values include:

| Return code | Description |
| --- | --- |
| **DRT_E_INVALID_TRANSPORT_PROVIDER** | *hTransport* is **NULL** or invalid. |
| **DRT_E_TRANSPORT_EXECUTING_CALLBACK** | The transport provider is currently executing a method. |
| **DRT_E_TRANSPORT_STILL_BOUND** | The transport is still bound. |
| **DRT_E_TRANSPORTPROVIDER_IN_USE** | All clients have not called [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the transport. |

**Note** This function may also surface errors returned by underlying calls to [PeerPnrpStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peerpnrpstartup) or [PeerIdentityGetCryptKey](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peeridentitygetcryptkey).

## See also

[DrtCreateIpv6UdpTransport](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtcreateipv6udptransport)