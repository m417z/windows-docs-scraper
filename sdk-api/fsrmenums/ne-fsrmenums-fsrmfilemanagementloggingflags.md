# FsrmFileManagementLoggingFlags enumeration

## Description

Defines the options for logging when running a file management job.

## Constants

### `FsrmFileManagementLoggingFlags_None:0`

Do not log events.

### `FsrmFileManagementLoggingFlags_Error:0x1`

Log errors that occur when running the file management job to a log file.

### `FsrmFileManagementLoggingFlags_Information:0x2`

Log information status messages that occur when running the file management job to a log file.

### `FsrmFileManagementLoggingFlags_Audit:0x4`

Log information about every file that met all of the file management job's conditions to the Security audit
log.

## See also

[IFsrmFileManagementJob.Logging](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmfilemanagementjob-get_logging)