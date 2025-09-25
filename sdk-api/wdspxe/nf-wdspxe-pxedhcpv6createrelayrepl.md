# PxeDhcpv6CreateRelayRepl function

## Description

Generates a RELAY-REPL message.

For more information about RELAY-REPL and RELAY-FORW messages, developers should refer to the Dynamic Host Configuration Protocol for IPv6 ([RFC 3315](https://www.ietf.org/rfc/rfc3315.txt)) maintained by The Internet Engineering Task Force (IETF).

## Parameters

### `pRelayMessages` [in]

An array of **PXE_DHCPV6_NESTED_RELAY_FORW** structures which together specify the sequence of nested RELAY-FORW packets. This value can be obtained from the *pRelayMessages* parameter of [PxeDhcpv6ParseRelayForw](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxedhcpv6parserelayforw).

### `nRelayMessages` [in]

The number of elements in the array pointed to by the *pRelayMessages* argument.

### `pInnerPacket` [in]

A pointer to a packet which is the server’s response to the innermost packet in the RELAY-FORW chain.

### `cbInnerPacket` [in]

The size of the packet pointed to by the *pInnerPacket* argument.

### `pReplyBuffer` [out]

A pointer to a buffer used to construct the outer RELAY-REPL packet. This buffer receives the nested response packet and the nested RELAY-REPL chain specified by the *pRelayMessages* parameter.

### `cbReplyBuffer` [in]

The size of the buffer in bytes pointed to by *pRelyBuffer*.

### `pcbReplyBuffer` [out]

On success, this is set to the actual size of the RELAY-REPL packet in the buffer pointed to by *pRelyBuffer*.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.