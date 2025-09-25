## Description

The DRIVER_INFO_8 structure contains printer driver information.

## Members

### `cVersion`

This member specifies the operating system version for which the driver was written. Currently it can be the following.

| Value | Meaning |
|---|---|
| 3 | Driver for Microsoft Windows 2000, XP, or Windows Vista. |

### `pName`

A pointer to a null-terminated string that specifies the name of the driver (for example, QMS 810).

### `pEnvironment`

A pointer to a null-terminated string that specifies the environment for which the driver was written (for example, Microsoft Windows 7, 8, or Windows Server 2012).

### `pDriverPath`

A pointer to a null-terminated string that specifies a file name or a full path and file name for the file that contains the device driver (for example, C:\DRIVERS\Pscript.dll).

### `pDataFile`

A pointer to a null-terminated string that specifies a file name or a full path and file name for the file that contains driver data (for example, C:\DRIVERS\Qms810.ppd).

### `pConfigFile`

A pointer to a null-terminated string that specifies a file name or a full path and file name for the device driver's configuration dynamic-link library (for example, C:\DRIVERS\Pscrptui.dll).

### `pHelpFile`

A pointer to a null-terminated string that specifies a file name or a full path and file name for the device driver's help file (for example, C:\DRIVERS\Pscrptui.hlp).

### `pDependentFiles`

Pointer to a Multi-SZ string that contains the names of the files on which the driver depends. The file names are stored as a contiguous series of zero-terminated strings followed by an empty string. For example, Pscript.dll\0QMS810.ppd\0Pscriptui.dll\0Pscriptui.hlp\0Pstest.txt\0\0, where \0 represents the terminating null character.

### `pMonitorName`

A pointer to a null-terminated string that specifies a language monitor (for example, "PJL monitor"). This member can be **NULL** and should be specified only for printers capable of bidirectional communication.

### `pDefaultDataType`

A pointer to a null-terminated string that specifies the default data type of the print job (for example, "EMF").

### `pszzPreviousNames`

A pointer to a null-terminated string that specifies any previous printer driver names that are compatible with this driver (for example, OldName1\0OldName2\0\0).

### `ftDriverDate`

The date of the driver package, as coded in the driver files.

### `dwlDriverVersion`

The version number of the driver. This comes out of the version structure of the driver.

### `pszMfgName`

A pointer to a null-terminated string that specifies the manufacturer's name.

### `pszOEMUrl`

A pointer to a null-terminated string that specifies the URL for the manufacturer.

### `pszHardwareID`

A pointer to a null-terminated string that specifies the hardware ID for the printer driver.

### `pszProvider`

A pointer to a null-terminated string that specifies the provider of the printer driver (for example, "Microsoft Windows 8").

### `pszPrintProcessor`

A pointer to a null-terminated string that specifies the name of the print processor associated with the printer driver.

### `pszVendorSetup`

A pointer to a null-terminated string that specifies the vendor setup DLL and entry point for vendor setup that is associated with the printer driver.

### `pszzColorProfiles`

A pointer to a null-terminated string that specifies all color profiles that are associated with the printer driver.

### `pszInfPath`

A pointer to a null-terminated string that specifies the path of the INF file inside the driver store from which the printer driver was installed. Must be **NULL** if using the [AddPrinterDriver](https://learn.microsoft.com/windows/win32/printdocs/addprinterdriver) or [AddPrinterDriverEx](https://learn.microsoft.com/windows/win32/printdocs/addprinterdriverex) functions with DRIVER_INFO_8.

### `dwPrinterDriverAttributes`

This member specifies printer driver related properties. Must be zero if using the [AddPrinterDriver](https://learn.microsoft.com/windows/win32/printdocs/addprinterdriver) or [AddPrinterDriverEx](https://learn.microsoft.com/windows/win32/printdocs/addprinterdriverex) functions with DRIVER_INFO_8. The following table shows the flags that have been defined for the *dwPrinterDriverAttributes* parameter.

| Flag name/value | Meaning | Minimum OS |
|---|---|---|
| PRINTER_DRIVER_PACKAGE_AWARE<br><br>0x00000001 | The printer driver is part of a driver package. | Windows Vista |
| PRINTER_DRIVER_XPS<br><br>0x00000002 | The printer driver supports the Microsoft XPS format described in the [XML Paper Specification: Overview](https://learn.microsoft.com/previous-versions/windows/hardware/design/dn641615(v=vs.85)), and also in [Product Behavior, section \<27\>](https://learn.microsoft.com/openspecs/windows_protocols/ms-rprn/e81cbc09-ab05-4a32-ae4a-8ec57b436c43). | Windows 8<br><br>Windows Server 2012 |
| PRINTER_DRIVER_SANDBOX_ENABLED<br><br>0x00000004 | The printer driver is compatible with [printer driver isolation](https://learn.microsoft.com/openspecs/windows_protocols/ms-rprn/831cd729-be7c-451e-b729-bd8d84ce4d24). For more information, see [Product Behavior, section \<28\>](https://learn.microsoft.com/openspecs/windows_protocols/ms-rprn/e81cbc09-ab05-4a32-ae4a-8ec57b436c43). | Windows 7<br><br>Windows Server 2008 R2 |
| PRINTER_DRIVER_CLASS<br><br>0x00000008 | The printer driver is a [class printer driver](https://learn.microsoft.com/openspecs/windows_protocols/ms-rprn/831cd729-be7c-451e-b729-bd8d84ce4d24). | Windows 8<br><br>Windows Server 2012 |
| PRINTER_DRIVER_DERIVED<br><br>0x00000010 | The printer driver is a [derived printer driver](https://learn.microsoft.com/openspecs/windows_protocols/ms-rprn/831cd729-be7c-451e-b729-bd8d84ce4d24). | Windows 8<br><br>Windows Server 2012 |
| PRINTER_DRIVER_NOT_SHAREABLE<br><br>0x00000020 | Printers using this printer driver cannot be shared. | Windows 8<br><br>Windows Server 2012 |
| PRINTER_DRIVER_CATEGORY_FAX<br><br>0x00000040 | The printer driver is intended for use with [fax printers](https://learn.microsoft.com/openspecs/windows_protocols/ms-rprn/831cd729-be7c-451e-b729-bd8d84ce4d24). | Windows 8<br><br>Windows Server 2012 |
| PRINTER_DRIVER_CATEGORY_FILE<br><br>0x00000080 | The printer driver is intended for use with [file printers](https://learn.microsoft.com/openspecs/windows_protocols/ms-rprn/831cd729-be7c-451e-b729-bd8d84ce4d24). | Windows 8<br><br>Windows Server 2012 |
| PRINTER_DRIVER_CATEGORY_VIRTUAL<br><br>0x00000100 | The printer driver is intended for use with [virtual printers](https://learn.microsoft.com/openspecs/windows_protocols/ms-rprn/831cd729-be7c-451e-b729-bd8d84ce4d24). | Windows 8<br><br>Windows Server 2012 |
| PRINTER_DRIVER_CATEGORY_SERVICE<br><br>0x00000200 | The printer driver is intended for use with [service printers](https://learn.microsoft.com/openspecs/windows_protocols/ms-rprn/831cd729-be7c-451e-b729-bd8d84ce4d24). | Windows 8<br><br>Windows Server 2012 |
| PRINTER_DRIVER_SOFT_RESET_REQUIRED<br><br>0x00000400 | Printers that use this printer driver should follow the guidelines outlined in [USB Device Class Definition](https://www.usb.org/documents?search=USB+Device+Class+Definition). For more information, see [Product Behavior, section \<36\>](https://learn.microsoft.com/openspecs/windows_protocols/ms-rprn/e81cbc09-ab05-4a32-ae4a-8ec57b436c43) | Windows 8<br><br>Windows Server 2012 |
| PRINTER_DRIVER_CATEGORY_3D<br><br>0x00001000 | The printer driver is intended for use with 3D printers. | Windows 8<br><br>Windows Server 2012 |

### `pszzCoreDriverDependencies`

A pointer to a null-terminated string that contains all the core printer driver dependencies for the driver package that are defined by *pszInfPath*. Must be **NULL** if using the [AddPrinterDriver](https://learn.microsoft.com/windows/win32/printdocs/addprinterdriver) or [AddPrinterDriverEx](https://learn.microsoft.com/windows/win32/printdocs/addprinterdriverex) functions with DRIVER_INFO_8.

### `ftMinInboxDriverVerDate`

The earliest allowed date of any drivers that shipped with Windows and on which this driver depends.

### `dwlMinInboxDriverVerVersion`

The earliest allowed version of any drivers that shipped with Windows and on which this driver depends.

## Remarks

The strings for these members are contained in the INF file that is used to add the driver.

If you call **AddPrinterDriver** or **AddPrinterDriverEx** with Level not equal to 6 or 8, and then you call **GetPrinterDriver** or **EnumPrinterDrivers** with Level equal to 6 or 8, the **DRIVER_INFO_8** structure is returned with pszMfgName, pszOEMUrl, pszHardwareID, and pszProvider set to **NULL**, dwlDriverVersion set to zero, and ftDriverDate set to (0,0).