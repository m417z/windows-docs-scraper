# IPrintOemUI::FontInstallerDlgProc

## Description

A user interface plug-in's `IPrintOemUI::FontInstallerDlgProc` method replaces the Unidrv font installer's user interface.

## Parameters

### `hWnd`

Window handle.

### `usMsg`

Message identifier.

### `wParam`

First message parameter.

### `lParam`

Second message parameter.

## Return value

The method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_FAIL** | The operation failed. |
| **E_NOTIMPL** | The method is not implemented. |

## Remarks

A user interface plug-in can implement the `IPrintOemUI::FontInstallerDlgProc` method as a means of replacing Unidrv's font installer. For more information, see [Customized Font Installers for Unidrv](https://learn.microsoft.com/windows-hardware/drivers/print/customized-font-installers-for-unidrv).

The `IPrintOemUI::FontInstallerDlgProc` method is used by Unidrv as a dialog box procedure, and its address is passed to **DialogBoxParam** (described in the Microsoft Windows SDK documentation) when a user invokes the font installer from Unidrv's user interface.

If the message received for *usMsg* is WM_INIT or WM_USER+WM_FI_NAME, *lParam* points to an [OEMFONTINSTPARAM](https://learn.microsoft.com/windows-hardware/drivers/ddi/prntfont/ns-prntfont-_oemfontinstparam) structure.

## See also

[IPrintOemUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintoemui)

[IPrintOemUI::UpdateExternalFonts](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-updateexternalfonts)