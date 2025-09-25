# FileFormat enumeration

## Description

Defines the format of the data in the log file.

## Constants

### `plaCommaSeparated:0`

Comma-separated log file. The first line in the text file contains column headings followed by comma-separated data in the remaining lines of the log file.

### `plaTabSeparated:1`

Tab-separated log file. The first line in the text file contains column headings followed by tab-separated data in the remaining lines of the log file.

### `plaSql:2`

The log contains SQL records.

### `plaBinary:3`

Binary log file.

## See also

[IPerformanceCounterDataCollector::LogFileFormat](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-iperformancecounterdatacollector-get_logfileformat)