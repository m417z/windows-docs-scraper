# IPrintOemDriverUI::DrvUpgradeRegistrySetting

## Description

The `IPrintOemDriverUI::DrvUpdateRegistrySetting` method is provided by the Unidrv and Pscript5 minidrivers so that user interface plug-ins can update device settings stored in the registry.

## Parameters

### `hPrinter`

Caller-supplied printer handle.

### `pFeature`

Caller-supplied pointer to a string identifying a printer feature name contained in the printer's [GPD](https://learn.microsoft.com/windows-hardware/drivers/) or [PPD](https://learn.microsoft.com/windows-hardware/drivers/) file.

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

The `IPrintOemDriverUI::DrvUpdateRegistrySetting` method is meant to be called from a user interface plug-in's [IPrintOemUI::UpgradePrinter](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-upgradeprinter) method, when it is necessary to update registry settings that were stored in private registry keys for an earlier version of the driver, but are now contained in a GPD or PPD file.