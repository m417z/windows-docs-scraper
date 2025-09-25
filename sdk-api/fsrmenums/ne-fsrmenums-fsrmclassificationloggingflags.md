# FsrmClassificationLoggingFlags enumeration

## Description

Defines the different options for logging information while running classification.

## Constants

### `FsrmClassificationLoggingFlags_None:0`

No logging occurs.

### `FsrmClassificationLoggingFlags_ClassificationsInLogFile:0x1`

Logs to a log file information about all the files and properties that were classified.

### `FsrmClassificationLoggingFlags_ErrorsInLogFile:0x2`

Logs to a log file errors that occurred during classification.

### `FsrmClassificationLoggingFlags_ClassificationsInSystemLog:0x4`

Logs to the System event information about all the files and properties that were classified.

### `FsrmClassificationLoggingFlags_ErrorsInSystemLog:0x8`

Logs to the System event log errors that occurred during classification.

## See also

[IFsrmClassificationManager.Logging](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmpipeline/nf-fsrmpipeline-ifsrmclassificationmanager-get_logging)