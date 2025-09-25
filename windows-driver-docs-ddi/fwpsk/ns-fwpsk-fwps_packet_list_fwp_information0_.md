# FWPS_PACKET_LIST_FWP_INFORMATION0_ structure

## Description

The **FWPS_PACKET_LIST_FWP_INFORMATION0** structure defines Windows Filtering Platform information
associated with a packet list.

**Note** **FWPS_PACKET_LIST_FWP_INFORMATION0** is a specific version of **FWPS_PACKET_LIST_FWP_INFORMATION**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Members

### `isReinjected`

A value that indicates whether the packet data was reinjected by a callout driver.

## Remarks

A FWPS_PACKET_LIST_FWP_INFORMATION0 structure is included as a member of the
[FWPS_PACKET_LIST_INFORMATION0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_packet_list_information0_) structure.

## See also

[FWPS_PACKET_LIST_INFORMATION0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_packet_list_information0_)