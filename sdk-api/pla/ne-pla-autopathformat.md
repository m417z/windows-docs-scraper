# AutoPathFormat enumeration

## Description

Defines how to decorate the file name or subdirectory name.

## Constants

### `plaNone:0`

Do not decorate the name.

### `plaPattern:0x1`

Add a pattern to the name. The pattern is specified in the [IDataCollector::FileNameFormatPattern](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollector-get_filenameformatpattern) or [IDataCollectorSet::SubdirectoryFormatPattern](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_subdirectoryformatpattern) property.

### `plaComputer:0x2`

Prefix the name with the computer name.

### `plaMonthDayHour:0x100`

Append the month, day, and hour to the name, in the form MMddHH.

### `plaSerialNumber:0x200`

Append the serial number specified in the [IDataCollectorSet::SerialNumber](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_serialnumber) property to the subdirectory name in the form NNNNNN.

### `plaYearDayOfYear:0x400`

Append the year and day of the year to the name, in the form yyyyDDD.

### `plaYearMonth:0x800`

Append the year and month to the name, in the form yyyyMM.

### `plaYearMonthDay:0x1000`

Append the year, month, and day to the name, in the form yyyyMMdd.

### `plaYearMonthDayHour:0x2000`

Append the year, month, day, and hour to the name, in the form yyyyMMddHH.

### `plaMonthDayHourMinute:0x4000`

Append the month, day, hour, and minute to the name, in the form MMddHHmm.

## Remarks

Patterns apply to files and subdirectories in the same way.

For details on patterns, see the Remarks section of [FileNameFormatPattern](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollector-get_filenameformatpattern).

## See also

[IDataCollector::FileNameFormat](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollector-get_filenameformat)

[IDataCollectorSet::SubdirectoryFormat](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_subdirectoryformat)