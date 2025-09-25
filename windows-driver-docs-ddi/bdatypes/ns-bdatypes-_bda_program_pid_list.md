# _BDA_PROGRAM_PID_LIST structure

## Description

The BDA_PROGRAM_PID_LIST structure describes data of a specific program to view. This data consists of packets that are identified with packet identifiers (PID).

## Members

### `ulProgramNumber`

Number of the program to be viewed.

### `ulcPIDs`

Number of PIDs in the **ulPID** array.

### `ulPID`

Array of PIDs that identify packets of program data.

## See also

[KSPROPERTY_BDA_CA_SET_PROGRAM_PIDS](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-bda-ca-set-program-pids)

[KSPROPSETID_BdaCA](https://learn.microsoft.com/windows-hardware/drivers/stream/kspropsetid-bdaca)