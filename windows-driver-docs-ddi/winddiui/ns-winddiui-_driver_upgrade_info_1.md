# _DRIVER_UPGRADE_INFO_1 structure

## Description

The DRIVER_UPGRADE_INFO_1 structure is used as an input to a printer interface DLL's [DrvUpgradePrinter](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvupgradeprinter) function.

## Members

### `pPrinterName`

Pointer to a NULL-terminated string that specifies the name of the printer.

### `pOldDriverDirectory`

Pointer to a NULL-terminated string that specifies the local directory in which the old printer driver files can be found.

## See also

[DRIVER_UPGRADE_INFO_2](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_driver_upgrade_info_2)

[DrvUpgradePrinter](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvupgradeprinter)