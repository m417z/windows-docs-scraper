# VDMEnumTaskWOWEx function

## Description

[This function is not supported and may be altered or unavailable in the future.]

Enumerates tasks within a particular virtual DOS machine (VDM).

## Parameters

### `dwProcessId` [in]

The process identifier of the VDM. This should be the process identifier that the **VDMEnumProcessWOW** function returns.

### `fp` [in]

A pointer to a callback function. The function is called for each enumerated task. For details, see the [ProcessTask](https://learn.microsoft.com/previous-versions/bb963828(v=vs.85)) callback function.

### `lparam` [in]

A user-defined value that is passed to the callback function.

## Return value

The number of tasks running within the specified VDM, or the number enumerated before enumeration was terminated.

## Remarks

VdmDbg.dll contains many functions that are useful for working with 16-bit applications. For more details on using some of the VDM debug functions, see knowledge base article KB182559.

#### Examples

For an example, see [VDMEnumProcessWOW](https://learn.microsoft.com/windows/desktop/api/vdmdbg/nf-vdmdbg-vdmenumprocesswow).