## Description

The **AcxStreamResumeIoActual** function is used to resume IO for a stream.

## Parameters

### `Stream` [in]

A pointer to an existing ACXSTREAM Object. For more information, see [ACX - Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `ObjectTag` [in, optional]

An optional tag that is a driver-defined value that the framework includes with diagnostic tracing.

### `Line` [in]

The line number in the driver code that can be displayed for diagnostic purposes.

### `File` [in]

The file name in the driver code that can be displayed for diagnostic purposes.

## Remarks

Don't use this version of the resume IO call, but rather [AcxStreamResumeIoWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/nf-acxstreams-acxstreamresumeiowithtag).

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxstreams.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/)