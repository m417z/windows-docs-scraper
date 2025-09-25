## Description

A printer interface DLL's **DrvUpgradePrinter** function is used for updating a printer's registry settings when a new version of the driver is added to a system.

## Parameters

### `Level`

Caller-supplied value indicating the type of structure pointed to by *pDriverUpgradeInfo*, as indicated in the following table.

| *Level* value | Structure pointed to by *pDriverUpgradeInfo* |
|---|---|
| 1 | [**DRIVER_UPGRADE_INFO_1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_driver_upgrade_info_1) |
| 2 | [**DRIVER_UPGRADE_INFO_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_driver_upgrade_info_2) |

### `pDriverUpgradeInfo` [in, optional]

Caller-supplied pointer to a structure whose type is identified by *dwLevel*.

## Return value

If the operation succeeds, the function should return **TRUE**; otherwise, it should call SetLastError to set an error code and return **FALSE**.

## Remarks

A [printer interface DLL](https://learn.microsoft.com/windows-hardware/drivers/print/printer-interface-dll) can optionally provide a **DrvUpgradePrinter** function. If it does, the spooler calls it for every printer when the printer driver is copied onto the system. This occurs when a system is upgraded from one operating system release to the next, or when an application updates a printer driver by calling the Win32 **AddPrinterDriver** function.

Often, a new driver version requires registry settings that are different from those of the old version. The **DrvUpgradePrinter** function's purpose is to update the registry so it is compatible with the driver. For more information about storing printer information in the registry, see [DrvPrinterEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvprinterevent).

For Windows 2000 and later, when the spooler calls **DrvUpgradePrinter**, it supplies a DRIVER_UPGRADE_INFO_2 structure pointer for *pDriverUpgradeInfo*. If the function returns **FALSE**, the spooler calls the function again, this time specifying a DRIVER_UPGRADE_INFO_1 structure pointer. If this call returns **FALSE**, the spooler writes an entry in the event log.

For Windows NT 4.0 and previous, when the spooler calls **DrvUpgradePrinter**, it supplies a DRIVER_UPGRADE_INFO_1 structure pointer for *pDriverUpgradeInfo*. If the function returns **FALSE**, the spooler writes an entry in the event log.

## See also

[**DRIVER_UPGRADE_INFO_1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_driver_upgrade_info_1)

[**DRIVER_UPGRADE_INFO_2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_driver_upgrade_info_2)

[DrvPrinterEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvprinterevent)