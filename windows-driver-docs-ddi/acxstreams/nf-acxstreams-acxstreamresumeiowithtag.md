## Description

The **AcxStreamResumeIoWithTag** function is used to resume IO for a stream after stream IO has been stopped. It is similar to [AcxStreamResumeIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/nf-acxstreams-acxstreamresumeio) function, but provides the ability to use a Tag that provides additional diagnostic information.

## Parameters

### `Stream` [in]

An existing ACXSTREAM object. For more information, see [ACX - Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `Tag` [in, optional]

An optional tag that is a driver-defined value that the framework includes with diagnostic tracing.

## Remarks

### Example

Example usage is shown below.

```cpp

    //
    // Resume stream IO after it was stopped with AcxStreamStopIoWithTag.
    //
    status = AcxStreamResumeIoWithTag(stream, (PVOID)this);

```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxstreams.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/)