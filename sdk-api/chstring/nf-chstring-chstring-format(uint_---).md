## Description

[The [CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring) class is part of the WMI Provider Framework which is now considered in final state, and no further development, enhancements, or updates will be available for non-security related issues affecting these libraries.
The [MI APIs](https://learn.microsoft.com/previous-versions/windows/desktop/wmi_v2/windows-management-infrastructure) should be used for all new development.]

The **Format** method formats and stores a series of characters and values in a **CHString** string.

## Parameters

### `nFormatID`

String resource identifier that contains the format control string.

### `...`

Argument list.

## Return value

CHeap_Exception

## Remarks

Each optional argument (if any) is converted and output according to the corresponding format specification in *lpszFormat*, or from the string resource identified by nFormatID.

**Note** To reduce exposure to security attacks, always use a format string for **Format**.
For example, **Format(input)** is exploitable, and **Format("%s", input)** is not.
Never use a user-supplied string for the format string.
If your format string is stored for a purpose such as localization, ensure that the string is protected from unauthorized write access.
If your function writes to a string rather than standard output, you may need to avoid using a trailing "%s" in the format string.

If the string object is offered as a parameter to **Format**, the call fails.
For example, the following code causes unpredictable results.

## Examples

```cpp
CHString str = L"Some Data";

// Attention: str is also used in the parameter list.
str.Format(L"%s%d", str, 123);
```

**Note** When you pass a character string as an optional argument, you must cast it explicitly as **LPCWSTR**.
The format argument has the same form and function as the *format* argument for the **printf** function.
A **NULL** character is appended to the end of the written characters.

## See also

[CHString](https://learn.microsoft.com/windows/desktop/WmiSdk/chstring)

[CHString::GetBuffer](https://learn.microsoft.com/windows/desktop/api/chstring/nf-chstring-chstring-getbuffer)