# LABELED\_DWORD structure

The **LABELED\_DWORD** structure defines a label that is displayed when a specific DWORD property value is detected.

## Members

**Value**

DWORD value of the property that you want to detect.

**Label**

Textual description or label that is displayed when the DWORD value specified in the **Value** member is detected.

## Remarks

The **lpLabeledDwordTable** member of the [SET](https://learn.microsoft.com/windows/win32/netmon2/set) structure points to an array of **SET** structures that define one or more **Label** members of the DWORD value pairs. The pairs are used when you want to display a label in place of a specific DWORD value that is found in the protocol packet.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |

## See also

[SET](https://learn.microsoft.com/windows/win32/netmon2/set)

