# _BDA_PID_UNMAP structure

## Description

The BDA_PID_UNMAP structure describes packet types to stop filtering from the input stream of a packet identifier (PID) filter. These packet types are identified with PIDs.

## Members

### `ulcPIDs`

Number of PIDs in the **aulPIDs** array.

### `aulPIDs`

Array of PIDs that identify packets to unmap from the output of a PID filter.

## See also

[BDA_PID_MAP](https://learn.microsoft.com/windows-hardware/drivers/ddi/bdatypes/ns-bdatypes-_bda_pid_map)

[KSPROPSETID_BdaPIDFilter](https://learn.microsoft.com/windows-hardware/drivers/stream/kspropsetid-bdapidfilter)

[MEDIA_SAMPLE_CONTENT](https://learn.microsoft.com/windows/win32/directshow/media-sample-content)