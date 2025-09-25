# ADDRESS_LIST_DESCRIPTOR structure

## Description

The
**ADDRESS_LIST_DESCRIPTOR** structure provides network address descriptor information for a given interface. For point-to-point media such as WAN connections, the list is a pair of addresses, the first of which is always the local or source address, the second of which is the remote or destination address. Note that the members of
**ADDRESS_LIST_DESCRIPTOR** are defined in Ntddndis.h.

## Members

### `MediaType`

Media type of the interface.

### `AddressList`

Pointer to the address list for the interface. The **NETWORK_ADDRESS_LIST** structure is defined in Ntddndis.h.

## See also

[FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec)