# RxLogEventWithAnnotation function

## Description

**RxLogEventWithAnnotation** allocates an I/O error log structure, fills it in with information, and writes the entry to the I/O error log.

## Parameters

### `DeviceObject` [in]

A pointer to the RDBSS device object.

### `EventId`

The value indicating the I/O error log code which is different than an NTSTATUS value returned by a routine. The legal I/O error log code values are defined in the *ntiolog.h* header file included with the Microsoft Windows SDK and Visual Studio.

### `Status`

The value indicating the status code of a routine indicating a failure.

### `DataBuffer`

A pointer to a raw data buffer to be added to the I/O error log structure.

### `DataBufferLength`

The length of the raw data buffer to be added to the I/O error log structure.

### `Annotation`

A pointer to any annotation strings to add to the I/O error log structure.

### `AnnotationCount` [in]

The count of the number of annotation strings to add to the I/O error log structure.

## Remarks

A network mini-redirector would call **RxLogEventWithAnnotation** to log an I/O error.

The I/O error log entry size is limited to a length of 255 characters. So if the combined length of the *Id*, *RawDataBuffer*, and *Annotations* parameters plus the size of the fixed part of the I/O error log entry exceeds 255, then **RxLogEventWithAnnotation** will silently fail and no I/O error log entry will be created.

The **RxLogEventWithAnnotation** routine needs to allocate memory in order to create the I/O error log entry . Consequently, **RxLogEventWithAnnotation** can silently fail if the memory allocation fails.

## See also

[RxLogEventDirect](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxlogeventdirect)

[RxLogEventWithBufferDirect](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxlogeventwithbufferdirect)

[_RxLog](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxlog/nf-rxlog-_rxlog)