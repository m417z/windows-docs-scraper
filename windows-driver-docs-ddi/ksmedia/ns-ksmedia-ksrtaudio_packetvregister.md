# KSRTAUDIO_PACKETVREGISTER structure

## Description

The **KSRTAUDIO_PACKETVREGISTER** structure contains information about the packet virtual register pointers.

## Members

### `CompletedPacketCount`

A PULONG64 pointer to the completed packet count buffer.

### `CompletedPacketQPC`

A PULONG64 pointer to the query performance counter (QPC) value.

### `CompletedPacketHash`

A PULONG64 pointer to the packet hash value that is a combination of the two low-order DWORDs for count and QPC.

## Remarks

## See also

[KSPROPSETID_RTAudio](https://learn.microsoft.com/windows-hardware/drivers/audio/kspropsetid-rtaudio)