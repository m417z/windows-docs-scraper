## Description

The **AcxStreamResumeIo** function is used to resume IO for a stream.

## Parameters

### `Stream` [in]

An existing ACXSTREAM Object. For more information, see [ACX - Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

## Remarks

It is not recommended to use this version of the resume IO call, but rather [AcxStreamResumeIoWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/nf-acxstreams-acxstreamresumeiowithtag).

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

[acxstreams.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/)
[AcxStreamResumeIoWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/nf-acxstreams-acxstreamresumeiowithtag)