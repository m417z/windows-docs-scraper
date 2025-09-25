# PxeDhcpv6Initialize function

## Description

Initializes a response packet as a DHCPv6 reply packet.

For RELAY-FORW messages, this function initializes the message type, hop count, link address and peer address. For other DHCPv6 request types, this function initializes the message type and transaction ID. In all cases, the option payload of the produced packet will be empty.

For more information about RELAY-FORW messages, developers should refer to the Dynamic Host Configuration Protocol for IPv6 ([RFC 3315](https://www.ietf.org/rfc/rfc3315.txt)) maintained by The Internet Engineering Task Force (IETF).

## Parameters

### `pRequest` [in]

Address of a valid DHCPv6 packet received from the client in the
[PxeProviderRecvRequest](https://learn.microsoft.com/windows/desktop/Wds/pxeproviderrecvrequest) callback.

### `cbRequest` [in]

Length of the packet pointed to by the *pRequest* parameter.

### `pReply` [in, out]

Pointer to a reply packet allocated with
the [PxePacketAllocate](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxepacketallocate) function.

### `cbReply` [in]

Allocated length of the packet pointed to by the *pReply* parameter.

### `pcbReplyUsed` [out]

Address of a **ULONG** that on successful completion will receive the length of
the packet pointed to by the *pReply* parameter.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.