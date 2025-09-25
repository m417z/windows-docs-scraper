# KSRTAUDIO_SETWRITEPACKET_INFO structure

## Description

The KSRTAUDIO_SETWRITEPACKET_INFO structure describes information associated with an audio packet.

## Members

### `PacketNumber`

 The number of the packet written by the OS to the WaveRT buffer. Depending on the values returned by the driver in the KSPROPERTY_RTAUDIO_GETPACKETCOUNT property, the PacketNumber may skip values. For more information, see [KSPROPERTY_RTAUDIO_PACKETCOUNT](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-packetcount).

### `Flags`

Additional attributes related to the packet or stream.

*KSSTREAM_HEADER_OPTIONSF_ENDOFSTREAM* - This flag indicates that this packet represents the end of the data stream.

### `EosPacketLength`

The length of the EOS packet if *KSSTREAM_HEADER_OPTIONSF_ENDOFSTREAM* is specified in Flags. Zero is a valid value. If *KSSTREAM_HEADER_OPTIONSF_ENDOFSTREAM* is not specified in Flags, this parameter is ignored. The EosPacketLength is measured in bytes.

## See also

[KSPROPERTY_RTAUDIO_SETWRITEPACKET](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-setwritepacket)