# PxeDhcpInitialize function

## Description

Initializes a response packet as a DHCP reply packet.

## Parameters

### `pRecvPacket` [in]

Address of a valid DHCP packet received from the client in the
[PxeProviderRecvRequest](https://learn.microsoft.com/windows/desktop/Wds/pxeproviderrecvrequest) callback.

### `uRecvPacketLen` [in]

Length of the packet pointed to by the *pRecvPacket* parameter.

### `pReplyPacket` [in, out]

Pointer to a reply packet allocated with
the [PxePacketAllocate](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxepacketallocate) function.

### `uMaxReplyPacketLen` [in]

Allocated length of the packet pointed to by the *pReplyPacket* parameter.

### `puReplyPacketLen` [out]

Address of a **ULONG** that on successful completion will receive the length of
the packet pointed to by the *pReplyPacket* parameter.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

## Remarks

Providers use this function to initialize a reply packet based on the packet received from the client. The
reply packet is initialized as follows.

| DHCP field | Initialized value |
| --- | --- |
| Operation (op) | 2 (BOOTP Reply) |
| Hardware Address Type (htype) | Copied from *pRecvPacket* |
| Hardware Address Length (hlen) | Copied from *pRecvPacket* |
| Hardware Address (chaddr) | Copied from *pRecvPacket* |
| Transaction ID (xid) | Copied from *pRecvPacket* |
| Seconds Since Boot (secs) | Copied from *pRecvPacket* |
| Client IP Address (ciaddr) | Copied from *pRecvPacket* |
| Your IP Address (yiaddr) | Copied from *pRecvPacket* |
| Server IP Address (siaddr) | Copied from *pRecvPacket* |
| Relay Agent IP Address (giaddr) | Copied from *pRecvPacket* |
| Magic Cookie (first 4 octets of vend) | Copied from *pRecvPacket* |

All other fields are initialized to zero.

## See also

[PxePacketAllocate](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxepacketallocate)

[PxeProviderRecvRequest](https://learn.microsoft.com/windows/desktop/Wds/pxeproviderrecvrequest)

[Windows Deployment Services Server Functions](https://learn.microsoft.com/windows/desktop/Wds/windows-deployment-services-server-functions)