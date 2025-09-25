# FWPS_PACKET_LIST_INBOUND_IPSEC_INFORMATION0_ structure

## Description

The **FWPS_PACKET_LIST_INBOUND_IPSEC_INFORMATION0** structure defines IPsec information associated with
inbound packet data.

**Note** **FWPS_PACKET_LIST_INBOUND_IPSEC_INFORMATION0** is a specific version of **FWPS_PACKET_LIST_INBOUND_IPSEC_INFORMATION**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Members

### `isSecure`

A value that indicates whether IPsec tunnel mode or IPsec transport mode processing has been performed
on the packet list.

### `isTransportMode`

A value that indicates whether IPsec has applied a transport mode security association to the packet
list.

### `isTunnelMode`

A value that indicates whether IPsec has applied a tunnel mode security association to the packet
list.

### `isTransportModeVerified`

A value that indicates whether the packet list has been verified against the IPsec transport mode
filter in the inbound transport layer.

### `isTunnelModeVerified`

A value that indicates whether the packet list has been verified against the IPsec tunnel mode filter
in the inbound transport layer.

### `isDeTunneled`

A value that indicates whether the packet list has been detunneled by IPsec.

## Remarks

An FWPS_PACKET_LIST_INBOUND_IPSEC_INFORMATION0 structure is included as a member of the
[FWPS_PACKET_LIST_IPSEC_INFORMATION0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_packet_list_ipsec_information0_) structure.

## See also

[FWPS_PACKET_LIST_IPSEC_INFORMATION0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_packet_list_ipsec_information0_)