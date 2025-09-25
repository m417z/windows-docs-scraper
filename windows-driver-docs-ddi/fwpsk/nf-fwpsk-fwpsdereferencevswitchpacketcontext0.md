# FwpsDereferencevSwitchPacketContext0 function

## Description

This function is not supported.

## Parameters

### `packetContext`

The **vSwitchPacketContext** value in the [FWPS_INCOMING_METADATA_VALUES0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_incoming_metadata_values0_) structure that is passed to callouts during virtual switch transport layer classifies (the FWPS_L2_METADATA_FIELD_VSWITCH_SOURCE_PORT_ID bit will be set in the **currentL2MetadataValues** member).

## Remarks

The **FwpsDereferencevSwitchPacketContext0** function releases a reference that was acquired by the [FwpsReferencevSwitchPacketContext0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsreferencevswitchpacketcontext0) function.

## See also

[FWPS_INCOMING_METADATA_VALUES0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_incoming_metadata_values0_)

[FwpsReferencevSwitchPacketContext0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsreferencevswitchpacketcontext0)