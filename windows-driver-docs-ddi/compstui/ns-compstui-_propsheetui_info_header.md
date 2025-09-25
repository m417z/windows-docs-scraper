## Description

The **PROPSHEETUI_INFO_HEADER** structure is used as an input parameter to an application's [PFNPROPSHEETUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/nc-compstui-pfnpropsheetui)-typed function, when the function is called with a reason value of PROPSHEETUI_REASON_GET_INFO_HEADER.

## Members

### `cbSize`

CPSUI-supplied size, in bytes, of the **PROPSHEETUI_INFO_HEADER** structure.

### `Flags`

Optional, application-specified bit flags that modify the property sheet page's appearance. The flags listed in the following table can be used in any combination.

| Flag | Description |
|---|---|
| PSUIHDRF_DEFTITLE | If set, CPSUI should include "Default" in the title bar string. CPSUI adds "Default" after the **pTitle** string and, if PSUIHDRF_PROPTITLE is set, before "Properties". |
| PSUIHDRF_EXACT_PTITLE | If set, CPSUI uses the text specified by **pTitle** without modification. This flag overrides PSUIHDRF_DEFTITLE and PSUIHDRF_PROPTITLE. |
| PSUIHDRF_NOAPPLYNOW | If set, CPSUI should not include an **Apply Now** button. |
| PSUIHDRF_PROPTITLE | If set, CPSUI should append "Properties" to the title bar string. (By default, CPSUI sets this flag before calling the application.) |
| PSUIHDRF_USEHICON | If set, the **hIcon**/**IconID** union contains an icon handle. If not set, the union contains an icon resource identifier. |

### `pTitle`

String identifier, representing text to be displayed in the property sheet's title bar. This can be a 32-bit pointer to a NULL-terminated string, or it can be a 16-bit string resource identifier with HIWORD set to zero. For printer interface DLLs, the string typically contains the printer's name.

### `hWndParent`

Handle to the window to be used as the parent of the property sheet. By default, CPSUI supplies the window handle that it received for the *hWndOwner* parameter to [CommonPropertySheetUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/nf-compstui-commonpropertysheetuia), but the application can overwrite that handle with another.

### `hInst`

Application-supplied instance handle, which CPSUI uses when loading application resources.

### `DUMMYUNIONNAME`

This union identifies the icon to be displayed in the property sheet's title bar.

### `DUMMYUNIONNAME.hIcon`

Defines the **HICON** member **hIcon**.

### `DUMMYUNIONNAME.IconID`

Defines the **ULONG_PTR** member **IconID**. The union member is selected by PSUIHDRF_USEICON in **Flags**.