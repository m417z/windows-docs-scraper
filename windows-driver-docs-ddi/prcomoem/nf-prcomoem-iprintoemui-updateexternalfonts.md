# IPrintOemUI::UpdateExternalFonts

## Description

The `IPrintOemUI::UpdateExternalFonts` method allows a user interface plug-in to update a printer's [Unidrv Font Format Files](https://learn.microsoft.com/windows-hardware/drivers/print/customized-font-management) (.uff file).

## Parameters

### `hPrinter`

Caller-supplied printer handle.

### `hHeap`

Caller-supplied handle to heap memory the method can use for local storage.

### `pwstrCartridges`

Caller-supplied pointer to an array of strings representing the names of all cartridges currently installed on the printer.

## Return value

The method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_FAIL** | The operation failed. |
| **E_NOTIMPL** | The method is not implemented. |

## Remarks

A user interface plug-in must implement the `IPrintOemUI::UpdateExternalFonts` method if the plug-in is replacing Unidrv's default font installer. For more information, see [Customized Font Installers for Unidrv](https://learn.microsoft.com/windows-hardware/drivers/print/customized-font-installers-for-unidrv).

The `IPrintOemUI::UpdateExternalFonts` method's purpose is to examine the list of installed cartridges (supplied by *pwstrCartridges*) and ensure that the .uff file specified by the "ExternalFontFile" registry value contains font descriptions for only the cartridge fonts contained in the installed cartridges. (This .uff file can also contain descriptions of [PCL](https://learn.microsoft.com/windows-hardware/drivers/)-downloadable soft fonts.)

Descriptions of cartridge fonts can be copied from the .uff file specified by the "ExtFontCartFile" registry value. For more information, see [Unidrv Font Format Files](https://learn.microsoft.com/windows-hardware/drivers/print/customized-font-management).

## See also

[IPrintOemUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintoemui)

[IPrintOemUI::FontInstallerDlgProc](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-fontinstallerdlgproc)