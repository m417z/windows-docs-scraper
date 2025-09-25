# PxeDhcpv6ParseRelayForw function

## Description

This function can be used by a provider to parse RELAY-FORW messages and their nested OPTION_RELAY_MSG messages. The information returned can be used to construct a RELAY-REPL packet using the [PxeDhcpv6CreateRelayRepl](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxedhcpv6createrelayrepl) function.

For more information about RELAY-FORW and OPTION_RELAY_MSG messages, developers should refer to the Dynamic Host Configuration Protocol for IPv6 ([RFC 3315](https://www.ietf.org/rfc/rfc3315.txt)) maintained by The Internet Engineering Task Force (IETF).

## Parameters

### `pRelayForwPacket` [in]

Specifies a pointer to a DHCPv6 RELAY-FORW message.

### `uRelayForwPacketLen` [in]

The size in bytes of the RELAY-FORW message pointed to by the *pRelayForwPacket* parameter.

### `pRelayMessages` [out]

An array of [PXE_DHCPV6_NESTED_RELAY_MESSAGE](https://learn.microsoft.com/windows/desktop/api/wdspxe/ns-wdspxe-pxe_dhcpv6_nested_relay_message) structures initialized by this routine. The array’s size is specified by *nRelayMessages*. Elements of this array are initialized to point to the nested chain of relay packets encoded in OPTION_RELAY_MSG. Index 0 is the outermost nested OPTION_RELAY_MSG packet. As the index increases the pointers correspond to more deeply nested OPTION_RELAY_MSG packets.

### `nRelayMessages` [in]

The size of the array, in number of array elements, pointed to by the *pRelayMessages* parameter.

### `pnRelayMessages` [out]

Specifies a pointer to a **ULONG** value which on success receives the actual number of elements written into the *pRelayMessages* array.

### `ppInnerPacket` [out]

Specifies a pointer to a **PVOID** value which on success is set to the start of the innermost packet in the relay chain. This is the original client request packet.

### `pcbInnerPacket` [out]

Specifies a pointer to a **ULONG** value which on success will be set to the size, in bytes, of the innermost packet in the relay chain which is the original client request packet.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.