# JOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION structure

## Description

Contains basic accounting and I/O accounting information for a job object.

## Members

### `BasicInfo`

A
[JOBOBJECT_BASIC_ACCOUNTING_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_basic_accounting_information) structure that specifies the basic accounting information for the job.

### `IoInfo`

An
[IO_COUNTERS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-io_counters) structure that specifies the I/O accounting information for the job. The structure includes information for all processes that have ever been associated with the job, in addition to the information for all processes currently associated with the job.

## See also

[IO_COUNTERS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-io_counters)

[JOBOBJECT_BASIC_ACCOUNTING_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-jobobject_basic_accounting_information)

[QueryInformationJobObject](https://learn.microsoft.com/windows/desktop/api/jobapi2/nf-jobapi2-queryinformationjobobject)