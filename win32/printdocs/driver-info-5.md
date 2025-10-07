# DRIVER\_INFO\_5 structure

The **DRIVER\_INFO\_5** structure contains printer driver information.

## Members

**cVersion**

The operating system version for which the driver was written. The supported value is 3.

**pName**

Pointer to a null-terminated string that specifies the name of the driver (for example, QMS 810).

**pEnvironment**

Pointer to a null-terminated string that specifies the environment for which the driver was written (for example, Windows x86, Windows IA64, and Windows x64).

**pDriverPath**

Pointer to a null-terminated string that specifies a file name or a full path and file name for the file that contains the device driver (for example, C:\\DRIVERS\\Pscript.dll).

**pDataFile**

Pointer to a null-terminated string that specifies a file name or a full path and file name for the file that contains driver data (for example, C:\\DRIVERS\\Qms810.ppd).

**pConfigFile**

Pointer to a null-terminated string that specifies a file name or a full path and file name for the device driver's configuration dynamic-link library (for example, C:\\DRIVERS\\Pscrptui.dll).

**dwDriverAttributes**

Driver attributes, like UMPD/KMPD.

**dwConfigVersion**

Number of times the configuration file for this driver has been upgraded or downgraded since the last spooler restart.

**dwDriverVersion**

Number of times the driver file for this driver has been upgraded or downgraded since the last spooler restart.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Unicode and ANSI names<br> | **\_DRIVER\_INFO\_5W** (Unicode) and **\_DRIVER\_INFO\_5A** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Structures](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-structures)

[**AddPrinterDriver**](https://learn.microsoft.com/windows/win32/printdocs/addprinterdriver)

[**EnumPrinterDrivers**](https://learn.microsoft.com/windows/win32/printdocs/enumprinterdrivers)

[**GetPrinterDriver**](https://learn.microsoft.com/windows/win32/printdocs/getprinterdriver)

