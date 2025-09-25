# IDataCollectorSet::put_SubdirectoryFormatPattern

## Description

Retrieves or sets a format pattern to use when decorating the folder name.

This property is read/write.

## Parameters

## Remarks

PLA uses the pattern only if the [IDataCollectorSet::SubdirectoryFormat](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_subdirectoryformat) property is set to **plaPattern**.

Use the following pattern characters to define your own pattern to append to the file name. For example, the pattern "MMMM d, yyyy \a\t h:mmTt" could yield "January 31, 2005 at 4:20AM".

| Pattern | Description |
| --- | --- |
| D | Day of the year. |
| DDD | Day of the year with leading zeros, if applicable. |
| d | Day of the month. |
| dd | Day of the month with a leading zero, if applicable. |
| ddd | The abbreviated name of the weekday, for example, Tue for Tuesday. |
| dddd | Full name of the weekday. |
| M | Month. |
| MM | Month with leading zero, if applicable. |
| MMM | The abbreviated name of the month, for example, Jan for January. |
| MMMM | Full name of the month. |
| y | Year without the century. |
| yy | Year without the century but including a leading zero, if applicable. |
| yyyy | Year with the century. |
| h | Hour in a 12-hour clock. |
| hh | Hour in a 12-hour clock with a leading zero, if applicable. |
| H | Hour in a 24-hour clock. |
| HH | Hour in a 24-hour clock with a leading zero, if applicable. |
| m | Minute. |
| mm | Minute with a leading zero, if applicable. |
| S | Second. |
| Ss | Second with a leading zero, if applicable. |
| T | The first character of the A.M./P.M. designator. |
| Tt | The A.M./P.M. designator. |
| Z | Time zone offset. |
| Zz | Time zone offset with a leading zero, if applicable. |
| N | Serial number. The number of leading zeros is defined by the number of characters. For example, if the serial number is 32 and the pattern is NNN, the serial number used is 032. |
| \c | Escaped character, where *c* is any character. Unrecognized characters, excluding white space, that are not escaped will result in an error. |

## See also

[IDataCollectorSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatacollectorset)

[IDataCollectorSet::SubdirectoryFormat](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_subdirectoryformat)