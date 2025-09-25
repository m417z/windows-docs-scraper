# IPrintOemUI::UpgradePrinter

## Description

The `IPrintOemUI::UpgradePrinter` method allows a user interface plug-in to upgrade device option values that are stored in the registry.

## Parameters

### `dwLevel`

Caller-supplied version number of the structure pointed to by *pDriverUpgradeInfo*. Current valid value is 1.

### `pDriverUpgradeInfo`

Caller-supplied pointer to a [DRIVER_UPGRADE_INFO_1](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_driver_upgrade_info_1) structure.

## Return value

The method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_FAIL** | The operation failed. |
| **E_NOTIMPL** | The method is not implemented. |

## Remarks

If you provide a user interface plug-in for one of Microsoft's printer drivers, and if the user interface plug-in stores device option values in the registry, it should implement the `IPrintOemUI::UpgradePrinter` method to update those values.

A user interface plug-in's `IPrintOemUI::UpgradePrinter` method performs the same types of operations as the **DrvUpgradePrinter** function that is exported by user-mode printer interface DLLs. When the driver's [DrvUpgradePrinter](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvupgradeprinter) function is called, it updates its own registry values and then calls the `IPrintOemUI::UpgradePrinter` method.

If `IPrintOemUI::UpgradePrinter` methods are exported by multiple user interface plug-ins, the methods are called in the order that the plug-ins are specified for installation.

For more information about creating and installing user interface plug-ins, see [Customizing Microsoft's Printer Drivers](https://learn.microsoft.com/windows-hardware/drivers/print/customizing-microsoft-s-printer-drivers).