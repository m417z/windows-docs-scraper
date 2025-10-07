# RtlCompareUnicodeString function

Compares two Unicode strings.

## Parameters

*String1* \[in\]

Pointer to the first string.

*String2* \[in\]

Pointer to the second string.

*CaseInSensitive* \[in\]

If **TRUE**, case should be ignored when doing the comparison.

## Return value

A signed value that gives the results of the comparison:

| Return code | Description |
|-------------------------------------------------------------------------------------------|-------------------------------------------------|
| **Zero** | *String1* equals *String2*.<br> |
| **< Zero** | *String1* is less than *String2*.<br> |
| **> Zero** | *String1* is greater than *String2*.<br> |

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Target platform<br> | [Universal](https://msdn.microsoft.com/Library/Windows/Hardware/EB2264A4-BAE8-446B-B9A5-19893936DDCA) |
| Header<br> | Wdm.h (include Wdm.h, Ntddk.h, or Ntifs.h) |
| Library<br> | Ntdll.lib |
| DLL<br> | Ntdll.dll |

## See also

[**RtlCompareString**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlcomparestring)

[**RtlEqualString**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlequalstring)

