## Description

The **PSPINFO** structure is used as an input parameter to a property sheet page's dialog box procedure, when the Windows message is WM_INITDIALOG. The dialog box procedure's address is specified in a [DLGPAGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_dlgpage) structure.

## Members

### `cbSize`

CPSUI-supplied size, in bytes, of the **PSPINFO** structure.

### `wReserved`

Reserved.

### `hComPropSheet`

CPSUI-supplied handle to the parent of the page whose handle is contained in **hCPSUIPage**.

### `hCPSUIPage`

CPSUI-supplied handle to the property sheet page.

### `pfnComPropSheet`

CPSUI-supplied pointer to its [ComPropSheet](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/nc-compstui-pfncompropsheet) function.

## Remarks

Before CPSUI calls [CreatePropertySheetPage](https://learn.microsoft.com/windows/win32/api/prsht/nf-prsht-createpropertysheetpagew) to create a property sheet page, it expands the size of the standard [**PROPSHEETPAGE**](https://learn.microsoft.com/windows/win32/controls/pss-propsheetpage) structure in order to append a **PSPINFO** structure. When the operating system calls a dialog box procedure (pointed to by a [**DLGPAGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_dlgpage) structure) and specifies a [WM_INITDIALOG](https://learn.microsoft.com/windows/win32/dlgbox/wm-initdialog) message, the function's **lParam** member points to the expanded **PROPSHEETPAGE** structure containing the **PSPINFO** structure.

To obtain the **PSPINFO** structure's address, use the PPSPINFO_FROM_WM_INITDIALOG_LPARAM macro (defined in compstui.h) as follows:

```cpp
PPSPINFO pPspInfo;
if (Msg == WM_INITDIALOG) {
    pPspInfo = PPSPINFO_FROM_WM_INITDIALOG_LPARAM(lParam);
}
```

The **PSPINFO** structure pointer can be saved for later use, but the structure's contents must not be modified.