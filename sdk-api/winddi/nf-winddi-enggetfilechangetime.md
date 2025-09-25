# EngGetFileChangeTime function

## Description

The **EngGetFileChangeTime** function retrieves a file's last write time.

## Parameters

### `h` [in]

Handle to the file whose change time is to be queried.

### `pChangeTime` [out]

Pointer to a LARGE_INTEGER in which the change time is returned.

## Return value

**EngGetFileChangeTime** returns **TRUE** if it succeeds in returning the timestamp; otherwise it returns **FALSE**.

## Remarks

The time returned is specified in system-time format. Absolute system time is the number of 100-nanosecond intervals since the start of the year 1601.