## Description

**FILE_SFIO_RESERVE_INFORMATION** is used to query or set a file's reserved bandwidth information for scheduled file I/O (SFIO).

## Members

### `RequestsPerPeriod`

Number of I/O requests that complete per period of time, as specified by the **Period** field. When setting bandwidth reservation, a value of 0 indicates to the file system that it must free any existing reserved bandwidth.

### `Period`

The period for reservation, which is the time from which the I/O is issued to the kernel until the time the I/O should be completed, specified in milliseconds.

### `RetryFailures`

Boolean value.

### `Discardable`

Boolean value. When TRUE, the I/O should be completed with an error if a driver is unable to satisfy the I/O within the deadline.

### `RequestSize`

Minimum size of any individual I/O request that can be issued by an application using bandwidth reservation.

### `NumOutstandingRequests`

The number of **RequestSize** I/O requests allowed to be outstanding at any time. When setting reservations, this field MUST be ignored by servers and SHOULD be set to 0 by clients.

## Remarks

## See also

[**NtQueryInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryinformationfile)