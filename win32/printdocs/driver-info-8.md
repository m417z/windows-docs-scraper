# DRIVER\_INFO\_8 structure

Contains printer driver information.

## Members

**cVersion**

The operating system version for which the driver was written. The supported value is 3.

**pName**

A pointer to a null-terminated string that specifies the name of the driver (for example, QMS 810).

**pEnvironment**

A pointer to a null-terminated string that specifies the environment for which the driver was written (for example, Windows x86, Windows IA64, and Windows x64.

**pDriverPath**

A pointer to a null-terminated string that specifies a file name or a full path and file name for the file that contains the device driver (for example, C:\\DRIVERS\\Pscript.dll).

**pDataFile**

A pointer to a null-terminated string that specifies a file name or a full path and file name for the file that contains driver data (for example, C:\\DRIVERS\\Qms810.ppd).

**pConfigFile**

A pointer to a null-terminated string that specifies a file name or a full path and file name for the device driver's configuration dynamic-link library (for example, C:\\DRIVERS\\Pscrptui.dll).

**pHelpFile**

A pointer to a null-terminated string that specifies a file name or a full path and file name for the device driver's help file (for example, C:\\DRIVERS\\Pscrptui.hlp).

**pDependentFiles**

A pointer to a MultiSZ buffer that contains a sequence of null-terminated strings. Each null-terminated string in the buffer contains the name of a file the driver depends on. The sequence of strings is terminated by an empty, zero-length string. If **pDependentFiles** is not **NULL** and does not contain any file names, it will point to a buffer that contains two empty strings.

**pMonitorName**

A pointer to a null-terminated string that specifies a language monitor (for example, "PJL monitor"). This member can be **NULL** and should be specified only for printers capable of bidirectional communication.

**pDefaultDataType**

A pointer to a null-terminated string that specifies the default data type of the print job (for example, "EMF").

**pszzPreviousNames**

A pointer to a null-terminated string that specifies previous printer driver names that are compatible with this driver. For example, OldName1\\0OldName2\\0\\0.

**ftDriverDate**

The date of the driver package, as coded in the driver files.

**dwlDriverVersion**

The version number of the driver. This comes from the version structure of the driver.

**pszMfgName**

A pointer to a null-terminated string that specifies the manufacturer's name.

**pszOEMUrl**

A pointer to a null-terminated string that specifies the URL for the manufacturer.

**pszHardwareID**

A pointer to a null-terminated string that specifies the hardware ID for the printer driver.

**pszProvider**

A pointer to a null-terminated string that specifies the provider of the printer driver (for example, "Microsoft Windows 2000").

**pszPrintProcessor**

A pointer to a null-terminated string that specifies the print processor (for example, "WinPrint").

**pszVendorSetup**

A pointer to a null-terminated string that specifies the vendor's driver setup DLL and entry point.

**pszzColorProfiles**

A pointer to a null-terminated string that specifies the color profiles associated with the driver.

**pszInfPath**

A pointer to a null-terminated string that specifies the path to the driver's .inf file in the driver store. (See Remarks.) This must be **NULL** if the DRIVER\_INFO\_8 is being passed to [**AddPrinterDriver**](https://learn.microsoft.com/windows/win32/printdocs/addprinterdriver) or [**AddPrinterDriverEx**](https://learn.microsoft.com/windows/win32/printdocs/addprinterdriverex).

**dwPrinterDriverAttributes**

Attribute flags for printer drivers. This must be 0 if the DRIVER\_INFO\_8 is being passed to [**AddPrinterDriver**](https://learn.microsoft.com/windows/win32/printdocs/addprinterdriver) or [**AddPrinterDriverEx**](https://learn.microsoft.com/windows/win32/printdocs/addprinterdriverex). Otherwise, it can be any combination of the following flags:

| Flag name/value | Meaning | Minimum OS |
|-------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------|
| PRINTER\_DRIVER\_PACKAGE\_AWARE<br> 0x00000001<br> | The printer driver is part of a driver package. | Windows Vista |
| PRINTER\_DRIVER\_XPS<br> 0x00000002<br> | The printer driver supports the Microsoft XPS format described in the [XML Paper Specification: Overview](https://learn.microsoft.com/previous-versions/windows/hardware/design/dn641615(v=vs.85)), and also in [Product Behavior, section <27>](https://learn.microsoft.com/openspecs/windows_protocols/ms-rprn/e81cbc09-ab05-4a32-ae4a-8ec57b436c43). | Windows 8<br> Windows Server 2012<br> |
| PRINTER\_DRIVER\_SANDBOX\_ENABLED<br> 0x00000004<br> | The printer driver is compatible with [printer driver isolation](https://learn.microsoft.com/openspecs/windows_protocols/ms-rprn/831cd729-be7c-451e-b729-bd8d84ce4d24). For more information, see [Product Behavior, section <28>](https://learn.microsoft.com/openspecs/windows_protocols/ms-rprn/e81cbc09-ab05-4a32-ae4a-8ec57b436c43). | Windows 7<br> Windows Server 2008 R2<br> |
| PRINTER\_DRIVER\_CLASS<br> 0x00000008<br> | The printer driver is a [class printer driver](https://learn.microsoft.com/openspecs/windows_protocols/ms-rprn/831cd729-be7c-451e-b729-bd8d84ce4d24). | Windows 8<br> Windows Server 2012<br> |
| PRINTER\_DRIVER\_DERIVED<br> 0x00000010<br> | The printer driver is a [derived printer driver](https://learn.microsoft.com/openspecs/windows_protocols/ms-rprn/831cd729-be7c-451e-b729-bd8d84ce4d24). | Windows 8<br> Windows Server 2012<br> |
| PRINTER\_DRIVER\_NOT\_SHAREABLE<br> 0x00000020<br> | Printers using this printer driver cannot be shared. | Windows 8<br> Windows Server 2012<br> |
| PRINTER\_DRIVER\_CATEGORY\_FAX<br> 0x00000040<br> | The printer driver is intended for use with [fax printers](https://learn.microsoft.com/openspecs/windows_protocols/ms-rprn/831cd729-be7c-451e-b729-bd8d84ce4d24). | Windows 8<br> Windows Server 2012<br> |
| PRINTER\_DRIVER\_CATEGORY\_FILE<br> 0x00000080<br> | The printer driver is intended for use with [file printers](https://learn.microsoft.com/openspecs/windows_protocols/ms-rprn/831cd729-be7c-451e-b729-bd8d84ce4d24). | Windows 8<br> Windows Server 2012<br> |
| PRINTER\_DRIVER\_CATEGORY\_VIRTUAL<br> 0x00000100<br> | The printer driver is intended for use with [virtual printers](https://learn.microsoft.com/openspecs/windows_protocols/ms-rprn/831cd729-be7c-451e-b729-bd8d84ce4d24). | Windows 8<br> Windows Server 2012<br> |
| PRINTER\_DRIVER\_CATEGORY\_SERVICE<br> 0x00000200<br> | The printer driver is intended for use with [service printers](https://learn.microsoft.com/openspecs/windows_protocols/ms-rprn/831cd729-be7c-451e-b729-bd8d84ce4d24). | Windows 8<br> Windows Server 2012<br> |
| PRINTER\_DRIVER\_SOFT\_RESET\_REQUIRED<br> 0x00000400<br> | Printers that use this printer driver should follow the guidelines outlined in the USB Device Class Definition. For more information, see [Product Behavior, section <36>](https://learn.microsoft.com/openspecs/windows_protocols/ms-rprn/e81cbc09-ab05-4a32-ae4a-8ec57b436c43) | Windows 8<br> Windows Server 2012<br> |

**pszzCoreDriverDependencies**

A pointer to a null-terminated multi-string that specifies all the core printer drivers that the driver depends on. This must be **NULL** if the **DRIVER\_INFO\_8** is being passed to [**AddPrinterDriver**](https://learn.microsoft.com/windows/win32/printdocs/addprinterdriver) or [**AddPrinterDriverEx**](https://learn.microsoft.com/windows/win32/printdocs/addprinterdriverex).

**ftMinInboxDriverVerDate**

The earliest allowed date of any drivers that shipped with Windows and on which this driver depends.

**dwlMinInboxDriverVerVersion**

The earliest allowed version of any drivers that shipped with Windows and on which this driver depends.

## Remarks

The strings for these members are contained in the .inf file that is used to add the driver.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Unicode and ANSI names<br> | **\_DRIVER\_INFO\_8W** (Unicode) and **\_DRIVER\_INFO\_8A** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Structures](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-structures)

[**AddPrinterDriver**](https://learn.microsoft.com/windows/win32/printdocs/addprinterdriver)

[**AddPrinterDriverEx**](https://learn.microsoft.com/windows/win32/printdocs/addprinterdriverex)

