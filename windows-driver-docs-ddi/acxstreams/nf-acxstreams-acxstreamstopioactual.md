## Description

The **AcxStreamStopIoActual** function is used to signal to the operating system to temporarily stop stream IO. This allows the driver a short period of time to run time sensitive tasks, and then resume IO after the execution of time sensitive code is complete.

## Parameters

### `Stream`

An existing ACXSTREAM Object. For more information, see [ACX - Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `Flags`

Set to AcxStopIoNoFlags.

### `ObjectTag`

An optional Tag that is a driver-defined value that the framework includes with diagnostic tracing.

### `Line`

The Line number in the driver code that can be displayed for diagnostic purposes.

### `File`

The file name in the driver code that can be displayed for diagnostic purposes.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

It is not recommended to use this version of the stop IO call, but rather [AcxStreamStopIoWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/nf-acxstreams-acxstreamstopiowithtag).

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

[acxstreams.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/)
[AcxStreamStopIoWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/nf-acxstreams-acxstreamstopiowithtag)