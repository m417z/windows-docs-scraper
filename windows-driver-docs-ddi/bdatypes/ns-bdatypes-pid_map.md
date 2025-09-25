# PID_MAP structure

## Description

The PID_MAP structure describes a group of packets in the output stream of a packet identifier (PID) filter. This group consists of packets that are identified with an identical PID and contain particular media content.

## Members

### `ulPID`

Identifier of particular packets.

### `MediaSampleContent`

MEDIA_SAMPLE_CONTENT enumerated type value that specifies the type of media content that packets contain.

## See also

[BDA_PID_MAP](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdatypes/ns-bdatypes-_bda_pid_map)

[KSPROPSETID_BdaPIDFilter](https://learn.microsoft.com/windows-hardware/drivers/stream/kspropsetid-bdapidfilter)

[MEDIA_SAMPLE_CONTENT](https://learn.microsoft.com/windows/win32/directshow/media-sample-content)