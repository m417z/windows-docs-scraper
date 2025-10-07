# FORM\_INFO\_2 structure

Contains information about a localizable print form.

## Members

**Flags**

The form properties. The following values are defined, but only one can be set. When the **FORM\_INFO\_2** is returned by [**GetForm**](https://learn.microsoft.com/windows/win32/printdocs/getform) or [**EnumForms**](https://learn.microsoft.com/windows/win32/printdocs/enumforms), **Flags** is set to the current value in the forms database.

| Value | Meaning |
|---------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| FORM\_USER | If this bit flag is set, the form has been defined by the user. Forms with this flag set are defined in the registry. |
| FORM\_BUILTIN | If this bit-flag is set, the form is part of the spooler. Form definitions with this flag set do not appear in the registry. Built-in forms cannot be modified, so this flag should not be set when the structure is passed to [**AddForm**](https://learn.microsoft.com/windows/win32/printdocs/addform) or [**SetForm**](https://learn.microsoft.com/windows/win32/printdocs/setform). |
| FORM\_PRINTER | If this bit flag is set, the form is associated with a certain printer, and its definition appears in the registry. |

**pName**

A pointer to a null-terminated string that specifies the name of the form. The form name cannot exceed 31 characters.

**Size**

The width and height of the form in thousandths of millimeters.

**ImageableArea**

The width and height, in thousandths of millimeters, of the area of the page on which the printer can print.

**pKeyword**

A pointer to a non-localizable string identifier of the form. When passed to [**AddForm**](https://learn.microsoft.com/windows/win32/printdocs/addform) or [**SetForm**](https://learn.microsoft.com/windows/win32/printdocs/setform), this gives the caller a means of identifying the form in all locales.

**StringType**

Specifies how a localized display name for the form is obtained at runtime. The following values are defined. Only one can be set in any given call to [**AddForm**](https://learn.microsoft.com/windows/win32/printdocs/addform) or [**SetForm**](https://learn.microsoft.com/windows/win32/printdocs/setform). Both STRING\_MUIDLL and STRING\_LANGPAIR can be set in the **FORM\_INFO\_2** (s) returned by [**GetForm**](https://learn.microsoft.com/windows/win32/printdocs/getform) or [**EnumForms**](https://learn.microsoft.com/windows/win32/printdocs/enumforms). See Remarks.

| Value | Meaning |
|------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| STRING\_NONE | There is no localized display name. |
| STRING\_MUIDLL | The display name is extracted from the [Multilingual User Interface](https://learn.microsoft.com/windows/desktop/Intl/mui-resource-management) localized resources DLL specified in **pMuiDll**. The ID is in the **dwResourceId** member. |
| STRING\_LANGPAIR | The display name and language ID are provided directly by **pDisplayName** and the language is specified by **wLangId**. |

**pMuiDll**

The [Multilingual User Interface](https://learn.microsoft.com/windows/desktop/Intl/mui-resource-management) localized resource DLL that contains the localized display name.

**dwResourceId**

The resource ID of the form's display name in **pMuiDll**.

**pDisplayName**

The form's display name in the language specified by **wLangId**.

**wLangId**

The language of the **pDisplayName**.

## Remarks

On a call to [**AddForm**](https://learn.microsoft.com/windows/win32/printdocs/addform) or [**SetForm**](https://learn.microsoft.com/windows/win32/printdocs/setform):

- If **StringType** is STRING\_NONE, both **pMuiDll** and **pDisplayName** must be **NULL** and both **dwResourceId** and **wLangId** must be 0.
- If **StringType** is STRING\_MUIDLL, **pDisplayName** must be **NULL** and **wLangId** must be 0.
- If **StringType** is STRING\_LANGPAIR, **pMuiDll** must be **NULL** and **dwResourceId** must be 0.

For a **FORM\_INFO\_2** returned by a call to [**GetForm**](https://learn.microsoft.com/windows/win32/printdocs/getform) or [**EnumForms**](https://learn.microsoft.com/windows/win32/printdocs/enumforms):

- If **StringType** is both STRING\_MUIDLL and STRING\_LANGPAIR, **pMuiDll**, **pDisplayName**, **dwResourceId**, and **wLangId** will all have valid values.
- If **StringType** is STRING\_MUIDLL only, **pMuiDll** and **dwResourceId** will have valid values. **pDisplayName** will be **NULL** and **wLangId** will be 0.
- If **StringType** is STRING\_LANGPAIR only, **pDisplayName** and **wLangId** will have valid values. **pMuiDll** will be **NULL** and **dwResourceId** will be 0.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Unicode and ANSI names<br> | **\_FORM\_INFO\_2W** (Unicode) and **\_FORM\_INFO\_2A** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Structures](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-structures)

[Multilingual User Interface](https://learn.microsoft.com/windows/desktop/Intl/mui-resource-management)

[**AddForm**](https://learn.microsoft.com/windows/win32/printdocs/addform)

[**GetForm**](https://learn.microsoft.com/windows/win32/printdocs/getform)

[**EnumForms**](https://learn.microsoft.com/windows/win32/printdocs/enumforms)

[**SetForm**](https://learn.microsoft.com/windows/win32/printdocs/setform)

