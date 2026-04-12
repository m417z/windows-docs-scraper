## Description

The **PKTMON_HEADER** struct is a common header for version control.

## Members

### `Size`

The size of the encapsulating structure in bytes, including this header.

### `Version`

The version of the encapsulating structure.

## Remarks

Currently, only version 0 is supported.

### See also

- **[PKTMON_PACKET_CONTEXT_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntnpik/ns-pktmonclntnpik-pktmon_packet_context_in)**
- **[PktMonClntHeaderInfoLog](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/nf-pktmonclntk-pktmonclntheaderinfolog)**
- **[PktMonClntHeaderInfoDrop](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/nf-pktmonclntk-pktmonclntheaderinfodrop)**