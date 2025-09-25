# IPrintCoreUI2::DrvUpgradeRegistrySetting

## Description

The `IPrintCoreUI2::DrvUpgradeRegistrySetting` method is provided by the Windows XP Pscript5 driver so that Pscript5 user interface plug-ins can update device settings stored in the registry.

## Parameters

### `hPrinter`

Caller-supplied printer handle.

### `pFeature`

Caller-supplied pointer to a string identifying a printer feature name contained in the printer's GPD or PPD file.

### `pOption`

Caller-supplied pointer to a string identifying an option name, associated with the specified feature, contained in the printer's GPD or PPD file.

## Return value

The method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_FAIL** | The operation failed. |
| **E_NOTIMPL** | The method is not implemented. |

## Remarks

This method is inherited from the [IPrintOemDriverUI COM Interface](https://learn.microsoft.com/windows-hardware/drivers/print/iprintoemdriverui-com-interface), which includes a `DrvUpgradeRegistrySetting` method. The behavior of this method is exactly the same as that of [IPrintOemDriverUI::DrvUpgradeRegistrySetting](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemdriverui-drvupgraderegistrysetting).

This method should be called only by the OEM's [IPrintOemUI::UpgradePrinter](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-upgradeprinter) method.

## See also

[IPrintCoreUI2](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintcoreui2)

[IPrintOemDriverUI::DrvUpgradeRegistrySetting](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemdriverui-drvupgraderegistrysetting)