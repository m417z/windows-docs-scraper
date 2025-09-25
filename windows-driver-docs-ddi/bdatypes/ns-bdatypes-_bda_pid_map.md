# _BDA_PID_MAP structure

## Description

The BDA_PID_MAP structure describes a type of data to filter out of the input stream of a packet identifier (PID) filter and then pass to a downstream filter. This output consists of packets that are identified with PIDs and contain particular media content.

## Members

### `MediaSampleContent`

MEDIA_SAMPLE_CONTENT enumerated type value that specifies the type of media content that packets contain.

### `ulcPIDs`

Number of PIDs in the **aulPIDs** array.

### `aulPIDs`

Array of PIDs that identify packets to map to the output of a PID filter.

## See also

[BDA_PID_UNMAP](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdatypes/ns-bdatypes-_bda_pid_unmap)

[KSPROPSETID_BdaPIDFilter](https://learn.microsoft.com/windows-hardware/drivers/stream/kspropsetid-bdapidfilter)

[MEDIA_SAMPLE_CONTENT](https://learn.microsoft.com/windows/win32/directshow/media-sample-content)