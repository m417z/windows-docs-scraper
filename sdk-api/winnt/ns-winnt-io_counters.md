# IO_COUNTERS structure

## Description

Contains I/O accounting information for a process or a job object. For a job object, the counters include all operations performed by all processes that have ever been associated with the job, in addition to all processes currently associated with the job.

## Members

### `ReadOperationCount`

The number of read operations performed.

### `WriteOperationCount`

The number of write operations performed.

### `OtherOperationCount`

The number of I/O operations performed, other than read and write operations.

### `ReadTransferCount`

The number of bytes read.

### `WriteTransferCount`

The number of bytes written.

### `OtherTransferCount`

The number of bytes transferred during operations other than read and write operations.

## See also

[GetProcessIoCounters](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getprocessiocounters)

[JOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-jobobject_basic_and_io_accounting_information)