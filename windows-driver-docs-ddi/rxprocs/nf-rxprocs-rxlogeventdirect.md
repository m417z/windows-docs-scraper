# RxLogEventDirect function

## Description

**RxLogEventDirect** is called to log an error to the I/O error log.

It is recommended that the RXLogEvent macro or the RxLogFailure macro be used instead of calling this routine directly.

## Parameters

### `DeviceObject` [in]

A pointer to the RDBSS device object.

### `OriginatorId` [in]

A string indicating the caller generating the error.

### `EventId` [in]

The value indicating the I/O error log code value which is different than an NTSTATUS value returned by a routine. The legal I/O error log code values are defined in the *ntiolog.h* header file included with the Microsoft Windows SDK and Visual Studio.

### `Status` [in]

The value indicating the status code of a routine indicating a failure.

### `Line` [in]

The line number in the source code file where this failure occurred.

## Remarks

**RxLogEventDirect** internally calls the **RxLogEventWithAnnotation** routine to create and write the log entry.

The I/O error log entry size is limited to a length of 255 characters. So if the combined length of the *OriginatorId* plus the size of the fixed part of the I/O error log exceeds 255, then no I/O error log entry will be created.

The **RxLogEventWithAnnotation** routine needs to allocate memory in order to create the I/O error log entry . Consequently, **RxLogEventDirect** can silently fail if the memory allocation fails.

## See also

[RxLogEventWithAnnotation](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxlogeventwithannotation)

[RxLogEventWithBufferDirect](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxprocs/nf-rxprocs-rxlogeventwithbufferdirect)

[_RxLog](https://learn.microsoft.com/windows-hardware/drivers/ddi/rxlog/nf-rxlog-_rxlog)