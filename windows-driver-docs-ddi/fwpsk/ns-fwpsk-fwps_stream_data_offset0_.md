# FWPS_STREAM_DATA_OFFSET0_ structure

## Description

The **FWPS_STREAM_DATA_OFFSET0** structure defines an offset into a portion of a data stream that is
described by an
[FWPS_STREAM_DATA0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_stream_data0_) structure.

**Note** **FWPS_STREAM_DATA_OFFSET0** is a specific version of **FWPS_STREAM_DATA_OFFSET**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Members

### `netBufferList`

A pointer to the
[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list) structure in which the
offset lies.

### `netBuffer`

A pointer to the
[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer) structure in which the offset
lies.

### `mdl`

A pointer to the Memory Descriptor List (MDL) in which the offset lies.

### `mdlOffset`

The byte offset from the beginning of the MDL pointed to by the
**Mdl** member.

### `netBufferOffset`

Reserved for system use. Callout drivers must not use this member.

### `streamDataOffset`

Reserved for system use. Callout drivers must not use this member.

## Remarks

An FWPS_STREAM_DATA_OFFSET0 structure is contained within an
[FWPS_STREAM_DATA0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_stream_data0_) structure. The
FWPS_STREAM_DATA_OFFSET0 structure specifies an offset into the data stream.

The combination of the
**netBufferList**,
**netBuffer**,
**Mdl**, and
**mdlOffset** members provide the location of the first byte of the data of interest.

## See also

[FWPS_STREAM_DATA0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/ns-fwpsk-fwps_stream_data0_)

[NET_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer)

[NET_BUFFER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/nbl/ns-nbl-net_buffer_list)