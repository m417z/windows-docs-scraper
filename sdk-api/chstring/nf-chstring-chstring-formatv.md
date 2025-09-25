# CHString::FormatV

## Description

[The [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) class
is part of the WMI Provider Framework which is now considered in final state, and no further development,
enhancements, or updates will be available for non-security related issues affecting these libraries. The
[MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new
development.]

The **FormatV** method writes a formatted string and a variable list of arguments to a [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) string.

## Parameters

### `lpszFormat`

Format control string.

### `argList`

List of arguments that are passed.

## Remarks

The **FormatV** method formats and stores a series of characters and values in the [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) string. The string and arguments are converted and output according to the corresponding format specification in *lpszFormat*.

If the string object is offered as a parameter to **FormatV**, the call fails.

**Note** To reduce exposure to security attacks, always use a format string for **FormatV**. Never use a user-supplied string for the format string. If your format string is stored for a purpose such as localization, ensure that the string is protected from unauthorized write access. If your function writes to a string rather than standard output, you may need to avoid using a trailing "%s" in the format string. For more information, see [www.securityfocus.com/archive/1/81565](https://www.microsoft.com/?ref=go) and [www.securityfocus.com/archive/1/66842](https://www.microsoft.com/?ref=go).

## See also

[CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring)

[CHString::Format](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-format(uint_---))