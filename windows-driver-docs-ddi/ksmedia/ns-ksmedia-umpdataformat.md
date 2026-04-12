# UMPDATAFORMAT structure

## Description

The **UMPDATAFORMAT** structure describes the format of a Universal MIDI Packet (UMP) for MIDI 2.0 data streaming operations.

## Members

### `Position`

Specifies the timestamp or position information for the UMP data. This field contains timing information that can be used for precise MIDI event scheduling and synchronization in MIDI 2.0 applications.

### `ByteCount`

Specifies the size of the UMP data in bytes. This field indicates the length of the Universal MIDI Packet data, which can vary depending on the UMP message type (32-bit, 64-bit, 96-bit, or 128-bit UMPs).

## Remarks

This structure is used in MIDI 2.0 implementations to package UMP data with associated timing information. Universal MIDI Packets provide enhanced capabilities over traditional MIDI, including higher resolution for parameters, extended addressing, and support for profiles and property exchange.

The **Position** field enables precise timing control for MIDI events, which is essential for professional music applications requiring sample-accurate timing. The **ByteCount** field specifies the size of the UMP data, allowing drivers and applications to properly handle variable-length UMP messages.

UMP format is defined in the MIDI 2.0 specification and represents the next generation of MIDI data transport, providing backward compatibility with MIDI 1.0 while enabling advanced features for modern music production and performance applications. The actual UMP data follows this structure in memory.

## See also

- [KSPROPERTY_MIDILOOPEDSTREAMING](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-ksproperty_midiloopedstreaming)