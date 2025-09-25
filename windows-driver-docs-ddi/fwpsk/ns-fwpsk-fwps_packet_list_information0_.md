# FWPS_PACKET_LIST_INFORMATION0_ structure

## Description

The **FWPS_PACKET_LIST_INFORMATION0** structure defines information associated with a packet list.

**Note** **FWPS_PACKET_LIST_INFORMATION0** is a specific version of **FWPS_PACKET_LIST_INFORMATION**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Members

### `ipsecInformation`

An
[FWPS_PACKET_LIST_IPSEC_INFORMATION0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_packet_list_ipsec_information0_) structure that contains IPsec information associated with the
packet list.

### `fwpInformation`

An
[FWPS_PACKET_LIST_FWP_INFORMATION0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_packet_list_fwp_information0_) structure that contains Windows Filtering Platform information
associated with the packet list.

## Remarks

A callout driver passes a pointer to an FWPS_PACKET_LIST_INFORMATION0 structure to the
[FwpsGetPacketListSecurityInformation0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsgetpacketlistsecurityinformation0) function when querying information associated with a packet
list.

## See also

[FWPS_PACKET_LIST_FWP_INFORMATION0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_packet_list_fwp_information0_)

[FWPS_PACKET_LIST_IPSEC_INFORMATION0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_packet_list_ipsec_information0_)

[FwpsGetPacketListSecurityInformation0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsgetpacketlistsecurityinformation0)