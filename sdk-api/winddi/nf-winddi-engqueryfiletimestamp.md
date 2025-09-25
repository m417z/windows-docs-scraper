# EngQueryFileTimeStamp function

## Description

The **EngQueryFileTimeStamp** function returns the time stamp of a file.

## Parameters

### `pwsz` [in]

Pointer to a null-terminated string containing the name of the file to be queried.

## Return value

**EngQueryFileTimeStamp** returns the last time the file was written to upon success. It returns **NULL** if it fails.

## Remarks

The time returned is local system time for the current time zone, specified in system-time format. Absolute system time is the number of 100-nanosecond intervals since the start of 1601.