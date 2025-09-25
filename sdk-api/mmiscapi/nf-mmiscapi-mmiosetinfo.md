# mmioSetInfo function

## Description

The **mmioSetInfo** function updates the information retrieved by the [mmioGetInfo](https://learn.microsoft.com/previous-versions/dd757321(v=vs.85)) function about a file opened by using the [mmioOpen](https://learn.microsoft.com/previous-versions/dd757331(v=vs.85)) function. Use this function to terminate direct buffer access of a file opened for buffered I/O.

## Parameters

### `hmmio`

File handle of the file.

### `pmmioinfo`

Pointer to an [MMIOINFO](https://learn.microsoft.com/previous-versions/dd757322(v=vs.85)) structure filled with information by the [mmioGetInfo](https://learn.microsoft.com/previous-versions/dd757321(v=vs.85)) function.

### `fuInfo`

Reserved; must be zero.

## Return value

Returns zero if successful or an error otherwise.

## Remarks

If you have written to the file I/O buffer, set the MMIO_DIRTY flag in the **dwFlags** member of the [MMIOINFO](https://learn.microsoft.com/previous-versions/dd757322(v=vs.85)) structure before calling **mmioSetInfo** to terminate direct buffer access. Otherwise, the buffer will not get flushed to disk.