## Description

The **WHEA_TIMESTAMP** union describes the time that an error was reported to the operating system.

## Members

### `DUMMYSTRUCTNAME`

Defines the **DUMMYSTRUCTNAME** structure.

### `DUMMYSTRUCTNAME.Seconds`

The number of seconds past the minute.

### `DUMMYSTRUCTNAME.Minutes`

The number of minutes past the hour.

### `DUMMYSTRUCTNAME.Hours`

The hour in the day.

### `DUMMYSTRUCTNAME.Precise`

If this member is set to 1, the timestamp correlates precisely to the time of the error event.

This member is supported in Windows 7 and later versions of Windows.

### `DUMMYSTRUCTNAME.Reserved`

Reserved for system use.

### `DUMMYSTRUCTNAME.Day`

The day of the month.

### `DUMMYSTRUCTNAME.Month`

The month of the year.

### `DUMMYSTRUCTNAME.Year`

The year within the century.

### `DUMMYSTRUCTNAME.Century`

The century.

### `AsLARGE_INTEGER`

A LARGE_INTEGER representation of the contents of the **WHEA_TIMESTAMP** union.

## Remarks

A **WHEA_TIMESTAMP** union is contained within the [WHEA_ERROR_RECORD_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_header) structure.

## See also

[WHEA_ERROR_RECORD_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_whea_error_record_header)