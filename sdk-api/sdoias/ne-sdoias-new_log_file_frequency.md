# NEW_LOG_FILE_FREQUENCY enumeration

## Description

The values of the
**NEW_LOG_FILE_FREQUENCY** enumeration type specify how frequently new log files are created.

## Constants

### `IAS_LOGGING_UNLIMITED_SIZE:0`

Allows the log file to grow without limit. Do not create new log files periodically.

### `IAS_LOGGING_DAILY`

Creates a new log file each day.

### `IAS_LOGGING_WEEKLY`

Creates a new log file each week.

### `IAS_LOGGING_MONTHLY`

Creates a new log file each month.

### `IAS_LOGGING_WHEN_FILE_SIZE_REACHES`

Creates a new log file when the log file reaches a particular size.

## See also

[ACCOUNTINGPROPERTIES](https://learn.microsoft.com/windows/desktop/api/sdoias/ne-sdoias-accountingproperties)