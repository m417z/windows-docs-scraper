# DRIVER\_INFO\_2 structure

The **DRIVER\_INFO\_2** structure identifies a printer driver, the driver version number, the environment for which the driver was written, the name of the file in which the driver is stored, and so on.

## Members

**cVersion**

The operating system version for which the driver was written. The supported value is 3.

**pName**

A pointer to a null-terminated string that specifies the name of the driver (for example, "QMS 810").

**pEnvironment**

A pointer to a null-terminated string that specifies the environment for which the driver was written (for example, Windows x86, Windows IA64, and Windows x64).

**pDriverPath**

A pointer to null-terminated string that specifies a file name or full path and file name for the file that contains the device driver (for example, "c:\\drivers\\pscript.dll").

**pDataFile**

A pointer to a null-terminated string that specifies a file name or a full path and file name for the file that contains driver data (for example, "c:\\drivers\\Qms810.ppd").

**pConfigFile**

A pointer to a null-terminated string that specifies a file name or a full path and file name for the device-driver's configuration .dll (for example, "c:\\drivers\\Pscrptui.dll").

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Unicode and ANSI names<br> | **\_DRIVER\_INFO\_2W** (Unicode) and **\_DRIVER\_INFO\_2A** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Structures](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-structures)

[**AddPrinterDriver**](https://learn.microsoft.com/windows/win32/printdocs/addprinterdriver)

[**GetPrinterDriver**](https://learn.microsoft.com/windows/win32/printdocs/getprinterdriver)

