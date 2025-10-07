# LABELED\_WORD structure

The **LABELED\_WORD** structure defines a label that is displayed when a specific WORD property value is detected.

## Members

**Value**

WORD value of the property that you want to detect.

**Label**

Textual description or label that is displayed when the WORD value specified in the **Value** member is detected.

## Remarks

The **lpLabeledWordTable** member of the [SET](https://learn.microsoft.com/windows/win32/netmon2/set) structure points to an array of SET structures to define one or more label value pairs. These pairs are used when you want to display a label in place of a specific WORD value that is found in a protocol packet.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |

## See also

[SET](https://learn.microsoft.com/windows/win32/netmon2/set)

