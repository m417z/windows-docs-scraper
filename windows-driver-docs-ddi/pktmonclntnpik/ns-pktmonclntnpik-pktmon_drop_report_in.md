## Description

The **PKTMON_DROP_REPORT_IN** structure contains information about why and where a packet was dropped in the network stack. This structure is passed to the **[PKTMON_PROVIDER_PACKET_DROP](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/nc-pktmonclntnpik-pktmon_provider_packet_drop)** callback when reporting packet drop events.

## Members

### `Header`

A [PKTMON_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ns-pktmonnpik-pktmon_header) structure used for versioning and size validation.

### `DropReason`

A 32-bit value indicating the reason code for why the packet was dropped. The interpretation of this code is component-specific and provides diagnostic information about the drop cause.

### `LocationCode`

A 32-bit value indicating the location code where the packet was dropped. This helps identify the specific point in the component's processing path where the drop occurred.

## Remarks

## See also

- [PKTMON_PROVIDER_PACKET_DROP](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/nc-pktmonclntnpik-pktmon_provider_packet_drop)
- [PktMonClntNblDrop](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/nf-pktmonclntk-pktmonclntnbldrop)
- [PktMonClntHeaderInfoDrop](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/nf-pktmonclntk-pktmonclntheaderinfodrop)