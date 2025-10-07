# IsValidDevmode function

The **IsValidDevmode** function verifies that the contents of a DEVMODE structure are valid.

## Parameters

*pDevmode* \[in\]

A pointer to the [**DEVMODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) to validate.

*DevmodeSize*

The size in bytes of the input byte buffer.

## Return value

**TRUE**, if the [**DEVMODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) is structurally valid. If minor errors are found the function will fix them and return **TRUE**.

**FALSE**, if the [**DEVMODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) has one or more significant structural problems. For example, its **dmSize** member is misaligned or specifies a buffer that is too small. Also, **FALSE** if **pDevmode** is **NULL**.

## Remarks

No private printer driver fields of the [**DEVMODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) are checked, only the public fields.

Callers should use **dmSize**+**dmDriverExtra** for **DevmodeSize** only if they can guarantee that the input buffer size is at least that big. Since the [**DEVMODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) is generally untrusted data, the values that are in the input buffer at the **dmSize** and **dmDriverExtra** offsets are also untrusted.

This function is executable in Least-Privileged User Account (LUA) context.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| Header<br> | Winspool.h |
| Library<br> | Winspool.lib |
| DLL<br> | Winspool.drv |
| Unicode and ANSI names<br> | **IsValidDevmodeW** (Unicode) and **IsValidDevmodeA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**DEVMODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea)

