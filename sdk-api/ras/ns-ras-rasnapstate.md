# RASNAPSTATE structure

## Description

The RASNAPSTATE structure contains information about the [Network Access Protection](https://learn.microsoft.com/windows/desktop/NAP/network-access-protection-start-page) (NAP) variables for a remote access connection.

## Members

### `dwSize`

Specifies the size of the structure in bytes.

### `dwFlags`

Contains information about what members of this structure are set on the return from a call to the [RasGetNapStatus](https://learn.microsoft.com/windows/desktop/api/ras/nf-ras-rasgetnapstatus) function.

### `isolationState`

An [IsolationState](https://learn.microsoft.com/windows/desktop/api/naptypes/ne-naptypes-isolationstate) value that specifies the isolation NAP state for the RAS connection.

### `probationTime`

Specifies the time required for the connection to come out of quarantine after which the connection will be dropped. A ProbationTime structure is identical to a **FILETIME** structure.

## Remarks

The [IsolationState](https://learn.microsoft.com/windows/desktop/api/naptypes/ne-naptypes-isolationstate) enumerated type and the ProbationTime structure are declared in naptypes.h.