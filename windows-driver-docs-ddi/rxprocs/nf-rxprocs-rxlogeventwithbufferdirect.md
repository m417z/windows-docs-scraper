# RxLogEventWithBufferDirect function

## Description

**RxLogEventWithBufferDirect** allocates an I/O error log structure, fills it in with information, and writes the entry to the I/O error log.

## Parameters

### `DeviceOrDriverObject`

A pointer to the RDBSS device object.

### `OriginatorId` [in]

The string indicating the caller generating the error.

### `EventId` [in]

The value indicating the I/O error log code which is different than an NTSTATUS value returned by a routine. The legal I/O error log code values are defined in the *ntiolog.h* header file included with the Microsoft Windows SDK and Visual Studio.

### `Status` [in]

The value indicating the status code of a routine indicating a failure.

### `DataBuffer` [in]

A pointer to a data buffer to be added to the I/O error log structure.

### `DataBufferLength` [in]

The length of the data buffer to be added to the I/O error log structure.

### `LineNumber` [in]

The line number in the source code file where this failure occurred.

## Remarks

**RxLogEventDirect** internally calls the **RxLogEventWithAnnotation** routine to create and write the log entry passing the *Status* and *LineNumber* parameters as the *Annotations* parameter to **RxLogEventWithAnnotation**.

The I/O error log entry size is limited to a length of 255 characters. So if the combined length of the *EventId*, *DataBuffer*, and *Annotations* parameters plus the size of the fixed part of the I/O error log entry exceeds 255, then no I/O error log entry will be created.

The **RxLogEventWithAnnotation** routine needs to allocate memory in order to create the I/O error log entry . Consequently, **RxLogEventWithBufferDirect** can silently fail if the memory allocation fails.

## See also

[RxLogEventDirect](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxlogeventdirect)

[RxLogEventWithAnnotation](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxlogeventwithannotation)

[_RxLog](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxlog/nf-rxlog-_rxlog)