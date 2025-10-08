# ACCELTABLEENTRY structure

Describes the data in an individual accelerator table resource. The structure definition provided here is for explanation only; it is not present in any standard header file.

## Members

**fFlags**

Type: **WORD**

Describes keyboard accelerator characteristics. This member can have one or more of the following values from Winuser.h.

| Value | Meaning |
|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **FVIRTKEY**<br>TRUE | The accelerator key is a [virtual-key code](https://learn.microsoft.com/windows/desktop/inputdev/virtual-key-codes). If this flag is not specified, the accelerator key is assumed to specify an ASCII character code. <br> |
| **FNOINVERT**<br>0x02 | A menu item on the menu bar is not highlighted when an accelerator is used. This attribute is obsolete and retained only for backward compatibility with resource files designed for 16-bit Windows.<br> |
| **FSHIFT**<br>0x04 | The accelerator is activated only if the user presses the SHIFT key. This flag applies only to virtual keys. <br> |
| **FCONTROL**<br>0x08 | The accelerator is activated only if the user presses the CTRL key. This flag applies only to virtual keys. <br> |
| **FALT**<br>0x10 | The accelerator is activated only if the user presses the ALT key. This flag applies only to virtual keys. <br> |
| **0x80** | The entry is last in an accelerator table. <br> |

**wAnsi**

Type: **WORD**

An ANSI character value or a virtual-key code that identifies the accelerator key.

**wId**

Type: **WORD**

An identifier for the keyboard accelerator. This is the value passed to the window procedure when the user presses the specified key.

**padding**

Type: **WORD**

The number of bytes inserted to ensure that the structure is aligned on a **DWORD** boundary.

## Remarks

The **ACCELTABLEENTRY** structure is repeated for all accelerator table entries in the resource. The last entry in the table is flagged with the value 0x0080.

You can compute the number of elements in the table if you divide the length of the resource by eight. Then your application can randomly access the individual fixed-length entries.

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |

## See also

**Reference**

[**CreateAcceleratorTable**](https://learn.microsoft.com/windows/desktop/api/Winuser/nf-winuser-createacceleratortablea)

**Conceptual**

[Resources](https://learn.microsoft.com/windows/win32/menurc/resources)

