# LABELED\_SYSTEMTIME structure

The **LABELED\_SYSTEMTIME** structure defines a label that is displayed when a specific SYSTEMTIME property value is detected.

## Members

**Value**

SYSTEMTIME value of a property that you want to detect.

**Label**

Textual description or label that is displayed when the SYSTEMTIME value specified in the **Value** member is detected.

## Remarks

The **lpLabeledSystemTimeTable** member of the [SET](https://learn.microsoft.com/windows/win32/netmon2/set) structure points to an array of **SET** structures that define one or more label value pairs. The pairs are used when you want to display a label in place of a specific LARGEINT value that is found in the protocol packet.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |

## See also

[SET](https://learn.microsoft.com/windows/win32/netmon2/set)

