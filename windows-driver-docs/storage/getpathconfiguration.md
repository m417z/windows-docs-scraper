# GetPathConfiguration function

The GetPathConfiguration method is used to retrieve the device information for each path.

## Parameters

*PathID*
A 64-bitfield that specifies the path that is associated with the device.

*EntryCount*
A 32-bitfield that indicates the number of entries that the output contains.

*Address\[\]*
An array that contains as many SCSI\_ADDR structures as specified by the *EntryCount* parameter.

## Return value

None

## Remarks

This WMI method belongs to the MPIO\_WMI\_METHODS WMI class.

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Header | MPIOwmi.h (include MPIOwmi.h) |

