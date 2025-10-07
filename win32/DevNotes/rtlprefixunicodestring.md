# RtlPrefixUnicodeString function

Compares two Unicode strings to determine whether one string is a prefix of the other.

## Parameters

*String1* \[in\]

Pointer to the first string, which might be a prefix of the buffered Unicode string at *String2*.

*String2* \[in\]

Pointer to the second string.

*CaseInSensitive* \[in\]

If **TRUE**, case should be ignored when doing the comparison.

## Return value

**TRUE** if *String1* is a prefix of *String2*.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Target platform<br> | [Universal](https://msdn.microsoft.com/Library/Windows/Hardware/EB2264A4-BAE8-446B-B9A5-19893936DDCA) |
| Header<br> | Ntddk.h (include Ntddk.h) |
| Library<br> | Ntdll.lib |
| DLL<br> | Ntdll.dll |

## See also

[**RtlCompareUnicodeString**](https://learn.microsoft.com/windows/win32/devnotes/rtlcompareunicodestring)

