# FORM_INFO_1 structure

The **FORM_INFO_1** structure contains information about a print form. The information includes the print form's origin, its name, its dimensions, and the dimensions of its printable area.

## Members

**Flags**

The form properties. The following values are defined.

| Value | Meaning |
|---------------|------------------------------------------------------------------------------------------------------------------------------|
| FORM_USER | If this bit flag is set, the form has been defined by the user. Forms with this flag set are defined in the registry. |
| FORM_BUILTIN | If this bit-flag is set, the form is part of the spooler. Form definitions with this flag set do not appear in the registry. |
| FORM_PRINTER | If this bit flag is set, the form is associated with a certain printer, and its definition appears in the registry. |

**pName**

Pointer to a null-terminated string that specifies the name of the form. The form name cannot exceed 31 characters.

**Size**

The width and height, in thousandths of millimeters, of the form.

**ImageableArea**

The width and height, in thousandths of millimeters, of the form.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Unicode and ANSI names<br> | **_FORM_INFO_1W** (Unicode) and **_FORM_INFO_1A** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Structures](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-structures)

[**AddForm**](https://learn.microsoft.com/windows/win32/printdocs/addform)

[**GetForm**](https://learn.microsoft.com/windows/win32/printdocs/getform)

[**SetForm**](https://learn.microsoft.com/windows/win32/printdocs/setform)

