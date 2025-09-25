# _NET_ADAPTER_AUTO_NEGOTIATION_FLAGS enumeration

## Description

Specifies the auto-negotiation settings for the NIC driver.

## Constants

### `NetAdapterAutoNegotiationFlagNone:0x00000000`

No flags are set.

### `NetAdapterAutoNegotiationFlagXmitLinkSpeedAutoNegotiated:0x00000001`

The adapter has auto-negotiated the transmit link speed with the link partner.

### `NetAdapterAutoNegotiationFlagRcvLinkSpeedautoNegotiated:0x00000002`

The adapter has auto-negotiated the receive link speed with the link partner.

### `NetAdapterAutoNegotiationFlagDuplexAutoNegotiated:0x00000004`

The adapter has auto-negotiated the duplex state with the link partner.

### `NetAdapterAutoNegotiationFlagPauseFunctionsAutoNegotiated:0x00000008`

The adapter has auto-negotiated the pause functions with the link partner.

## Remarks

The **NET_ADAPTER_AUTO_NEGOTIATION_FLAGS** enumeration is used to specify auto-negotiation settings in the [**NET_ADAPTER_LINK_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_link_state) structure.

An initialized [**NET_ADAPTER_LINK_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_link_state) structure is an input to [**NetAdapterSetLinkState**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptersetlinkstate).

## See also