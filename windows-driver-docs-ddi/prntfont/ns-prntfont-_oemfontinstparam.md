# _OEMFONTINSTPARAM structure

## Description

The OEMFONTINSTPARAM structure is used as an input parameter to a user interface plug-in's [IPrintOemUI::FontInstallerDlgProc](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-fontinstallerdlgproc) method.

## Members

### `cbSize`

Size, in bytes, of the OEMFONTINSTPARAM structure.

### `hPrinter`

Unidrv-supplied printer handle.

### `hModule`

Unidrv-supplied handle to the user interface plug-in.

### `hHeap`

Unidrv-supplied handle to a heap from which space can be allocated by calling the **HeapAlloc** function (described in the Microsoft Windows SDK documentation).

### `dwFlags`

Unidrv-supplied flags. The only defined flag is FG_CANCHANGE which, if set, indicates the user interface should allow the user to change the installed fonts. Otherwise the user interface should be displayed in read-only mode.

### `pFontInstallerName`

Pointer to a string representing the font installer's name. The [IPrintOemUI::FontInstallerDlgProc](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-fontinstallerdlgproc) method must supply this string if the received message is WM_USER+WM_FI_NAME. The string must be placed in memory allocated using **hHeap**.