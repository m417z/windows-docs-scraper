# DRIVER\_INFO\_6 structure

The **DRIVER\_INFO\_6** structure contains printer driver information.

## Members

**cVersion**

The operating system version for which the driver was written. The supported value is 3.

**pName**

Pointer to a null-terminated string that specifies the name of the driver (for example, QMS 810).

**pEnvironment**

Pointer to a null-terminated string that specifies the environment for which the driver was written (for example, Windows NT x86, Windows IA64, and Windows x64.

**pDriverPath**

Pointer to a null-terminated string that specifies a file name or a full path and file name for the file that contains the device driver (for example, C:\\DRIVERS\\Pscript.dll).

**pDataFile**

Pointer to a null-terminated string that specifies a file name or a full path and file name for the file that contains driver data (for example, C:\\DRIVERS\\Qms810.ppd).

**pConfigFile**

Pointer to a null-terminated string that specifies a file name or a full path and file name for the device driver's configuration dynamic-link library (for example, C:\\DRIVERS\\Pscrptui.dll).

**pHelpFile**

Pointer to a null-terminated string that specifies a file name or a full path and file name for the device driver's help file (for example, C:\\DRIVERS\\Pscrptui.hlp).

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

Version number of the driver. This comes out of the version structure of the driver.

**pszMfgName**

Pointer to a null-terminated string that specifies the manufacturer's name.

**pszOEMUrl**

Pointer to a null-terminated string that specifies the URL for the manufacturer.

**pszHardwareID**

Pointer to a null-terminated string that specifies the hardware ID for the printer driver.

**pszProvider**

Pointer to a null-terminated string that specifies the provider of the printer driver (for example, "Microsoft Windows 2000")

## Remarks

The strings for these members are contained in the .inf file that is used to add the driver.

If you call [**AddPrinterDriver**](https://learn.microsoft.com/windows/win32/printdocs/addprinterdriver) or [**AddPrinterDriverEx**](https://learn.microsoft.com/windows/win32/printdocs/addprinterdriverex) with *Level* not equal to 6, and then you call [**GetPrinterDriver**](https://learn.microsoft.com/windows/win32/printdocs/getprinterdriver) or [**EnumPrinterDrivers**](https://learn.microsoft.com/windows/win32/printdocs/enumprinterdrivers) with *Level* equal to 6, the **DRIVER\_INFO\_6** structure is returned with **pszMfgName**, **pszOEMUrl**, **pszHardwareID**, and **pszProvider** set to **NULL**, **dwlDriverVersion** set to 0, and **ftDriverDate** set to (0,0).

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Unicode and ANSI names<br> | **\_DRIVER\_INFO\_6W** (Unicode) and **\_DRIVER\_INFO\_6A** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Structures](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-structures)

[**AddPrinterDriver**](https://learn.microsoft.com/windows/win32/printdocs/addprinterdriver)

[**AddPrinterDriverEx**](https://learn.microsoft.com/windows/win32/printdocs/addprinterdriverex)

[**EnumPrinterDrivers**](https://learn.microsoft.com/windows/win32/printdocs/enumprinterdrivers)

[**GetPrinterDriver**](https://learn.microsoft.com/windows/win32/printdocs/getprinterdriver)

