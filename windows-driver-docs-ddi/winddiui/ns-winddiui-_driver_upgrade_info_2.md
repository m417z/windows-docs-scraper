## Description

The **DRIVER_UPGRADE_INFO_2** structure is used as an input to a printer interface DLL's [DrvUpgradePrinter](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvupgradeprinter) function.

## Members

### `pPrinterName`

Pointer to a NULL-terminated string that specifies the name of the printer. For more information, see the Remarks section.

### `pOldDriverDirectory`

Pointer to a NULL-terminated string that specifies the local directory in which the old printer driver files can be found.

### `cVersion`

Specifies the operating system version for which the driver was written.

| Value | Operating System |
|---|---|
| 0 | Windows 95/98/Me |
| 1 | Windows NT 3.1 through Windows NT 3.51 |
| 2 | Windows NT 4.0 |
| 3 | Windows 2000 and later |

### `pName`

Pointer to a NULL-terminated string that specifies the name of the driver (for example, "QMS 810"). For more information, see the Remarks section.

### `pEnvironment`

Pointer to a NULL-terminated string that specifies the environment for which the driver was written (for example, "Windows NT x86" or "Windows Itanium").

### `pDriverPath`

Pointer to a NULL-terminated string that specifies a file name or full path and file name for the file that contains the device driver (for example, "pscript.dll").

### `pDataFile`

Pointer to a NULL-terminated string that specifies a file name or a full path and file name for the file that contains driver data (for example, "qms810.ppd").

### `pConfigFile`

Pointer to a NULL-terminated string that specifies a file name or a full path and file name for the device driver's configuration dynamic-link library (for example, "pscrptui.dll").

### `pHelpFile`

Pointer to a null-terminated string that specifies a file name or a full path and file name for the device driver's help file.

### `pDependentFiles`

Pointer to a NULL-terminated string that specifies the files the driver depends on. Each file name in the string is also terminated with a null character (for example, "pscript.dll\0qms810.ppd\0pscrptui.dll\0pscrptui.hlp\0pstest.txt\0\0").

### `pMonitorName`

Pointer to a NULL-terminated string that specifies a language monitor (for example, "PJL monitor"). This member can be **NULL** and should be specified as non-**NULL** only for printers capable of bidirectional communication.

### `pDefaultDataType`

Pointer to a NULL-terminated string that specifies the default data type of the print job (for example, "EMF").

### `pszzPreviousNames`

Pointer to a NULL-terminated string that specifies any previous printer driver names that are compatible with this driver (for example, "OldName1\0OldName2\0\0").

## Remarks

When DrvUpgradePrinter is called with its *pDriverUpgradeInfo* parameter pointing to a DRIVER_UPGRADE_INFO_2 structure, the **pPrinterName** member points to a string containing the name of the printer to be updated. The **pName** member points to a string containing the name of the printer driver to be updated, which is not necessarily the driver for the printer whose name is pointed to by the **pPrinterName** member.

To see how this can occur, suppose that a computer is connected to two printers, one whose driver is named "Acme Plotter" and the other whose driver is named "Acme RasterMaster". Suppose also that both drivers share a common driver file, plotui.dll. When the "Acme Plotter" driver is updated by a call to the **AddPrinterDriverEx** function (described in the Microsoft Windows SDK documentation), DrvUpgradePrinter is called for both printers, because both drivers use files affected by the upgrade. In both calls, the **pName** member points to "Acme Plotter", the name of the printer driver used in the call to **AddPrinterDriverEx**. The string pointed to by the **pPrinterName** member is different in both calls to DrvUpgradePrinter, however. In each call, **pPrinterName** points to the name of the printer being updated.

## See also

[DRIVER_UPGRADE_INFO_1](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_driver_upgrade_info_1)

[DrvUpgradePrinter](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvupgradeprinter)