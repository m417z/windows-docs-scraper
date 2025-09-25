## Description

The **AcxStreamStopIo** function is used to stop the IO for a stream.

## Parameters

### `Stream`

An existing ACXSTREAM Object. For more information, see [ACX - Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `Flags`

Set to AcxStopIoNoFlags.

## Remarks

Do not call AcxStreamStopIo from an I/O dispatched thread. This will cause a deadlock.

It is not recommended to use this version of the stop IO call, but rather [AcxStreamStopIoWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/nf-acxstreams-acxstreamstopiowithtag).

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxstreams.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/)