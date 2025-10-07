# DeletePrinterDriverEx function

The **DeletePrinterDriverEx** function removes the specified printer-driver name from the list of names of supported drivers on a server and deletes the files associated with the driver. This function can also delete specific versions of the driver.

## Parameters

*pName* \[in\]

A pointer to a null-terminated string that specifies the name of the server from which the driver is to be deleted. If this parameter is **NULL**, the function deletes the printer-driver from the local computer.

*pEnvironment* \[in\]

A pointer to a null-terminated string that specifies the environment from which the driver is to be deleted (for example, Windows NT x86, Windows IA64, or Windows x64). If this parameter is **NULL**, the driver name is deleted from the current environment of the calling application and client computer (not of the destination application and print server).

*pDriverName* \[in\]

A pointer to a null-terminated string specifying the name of the driver to delete.

*dwDeleteFlag* \[in\]

The options for deleting files and versions of the driver. This parameter can be one or more of the following values.

| Value | Meaning |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **DPD\_DELETE\_SPECIFIC\_VERSION** | Deletes the version specified in *dwVersionFlag*. This does not ensure that the driver will be removed from the list of supported drivers for the server.<br> |
| **DPD\_DELETE\_UNUSED\_FILES** | Removes any unused driver files.<br> |
| **DPD\_DELETE\_ALL\_FILES** | Deletes the driver only if all its associated files can be removed. The delete operation fails if any of the driver's files are being used by some other installed driver.<br> |

If DPD\_DELETE\_SPECIFIC\_VERSION is not specified, the function deletes all versions of the driver if none of them is in use. If neither DPD\_DELETE\_UNUSED\_FILES nor DPD\_DELETE\_ALL\_FILES is specified, the function does not delete driver files.

*dwVersionFlag* \[in\]

The version of the driver to be deleted. This parameter can be 0, 1, 2 or 3. This parameter is used only if *dwDeleteFlag* includes the DPD\_DELETE\_SPECIFIC\_VERSION flag.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero.

## Remarks

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

Before the function deletes the driver files, it calls the driver's **DrvDriverEvent** function, allowing the driver to remove any private files that are not used. For more information about **DrvDriverEvent**, see the Microsoft Windows Driver Development Kit (DDK).

If the driver files are currently loaded, the function moves them to a temp directory and marks them for deletion on restart.

Before calling **DeletePrinterDriverEx**, you must delete all printer objects that use the printer driver.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Library<br> | Winspool.lib |
| DLL<br> | Winspool.drv |
| Unicode and ANSI names<br> | **DeletePrinterDriverExW** (Unicode) and **DeletePrinterDriverExA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**AddPrinterDriverEx**](https://learn.microsoft.com/windows/win32/printdocs/addprinterdriverex)

