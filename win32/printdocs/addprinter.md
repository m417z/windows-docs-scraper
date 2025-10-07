# AddPrinter function

The **AddPrinter** function adds a printer to the list of supported printers for a specified server.

## Parameters

*pName* \[in\]

A pointer to a null-terminated string that specifies the name of the server on which the printer should be installed. If this string is **NULL**, the printer is installed locally.

*Level* \[in\]

The version of the structure to which *pPrinter* points. This value must be 2.

*pPrinter* \[in\]

A pointer to a [**PRINTER\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-2) structure that contains information about the printer. You must specify non-**NULL** values for the **pPrinterName**, **pPortName**, **pDriverName**, and **pPrintProcessor** members of this structure before calling **AddPrinter**.

## Return value

If the function succeeds, the return value is a handle (not thread safe) to a new printer object. When you are finished with the handle, pass it to the [**ClosePrinter**](https://learn.microsoft.com/windows/win32/printdocs/closeprinter) function to close it.

If the function fails, the return value is **NULL**.

## Remarks

Do not call this method in [**DllMain**](https://learn.microsoft.com/windows/desktop/Dlls/dllmain).

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

The caller must have the [SeLoadDriverPrivilege](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-constants).

The returned handle is not thread safe. If callers need to use it concurrently on multiple threads, they must provide custom synchronization access to the printer handle using the [Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions). To avoid writing custom code the application can open a printer handle on each thread, as needed.

The following are the members of the [**PRINTER\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-2) structure that can be set before the **AddPrinter** function is called:

- **Attributes**
- **pPrintProcessor**
- **DefaultPriority**
- **Priority**
- **pComment**
- **pSecurityDescriptor**
- **pDatatype**
- **pSepFile**
- **pDevMode**
- **pShareName**
- **pLocation**
- **StartTime**
- **pParameters**
- **UntilTime**

The **Status**, **cJobs**, and **AveragePPM** members of the [**PRINTER\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-2) structure are reserved for use by the [**GetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/getprinter) function. They must not be set before calling **AddPrinter**.

If **pSecurityDescriptor** is **NULL**, the system assigns a default security descriptor to the printer. The default security descriptor has the following permissions.

| Value | Description |
|--------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Administrators and Power Users | Full control on the print queue. This means members of these groups can print, manage the queue (can delete the queue, change any setting of the queue, including the security descriptor), and manage the print jobs of all users (delete, pause, resume, restart jobs).Note that Power Users do not exist before Windows XP Professional.<br> |
| Creator/Owner | Can manage own jobs. This means that user who submit jobs can manage (delete, pause, resume, restart) their own jobs. |
| Everyone | Execute and standard read control. This means that members of the everyone group can print and read properties of the print queue. |

After an application creates a printer object with the **AddPrinter** function, it must use the [**PrinterProperties**](https://learn.microsoft.com/windows/win32/printdocs/printerproperties) function to specify the correct settings for the printer driver associated with the printer object.

The **AddPrinter** function returns an error if a printer object with the same name already exists, unless that object is marked as pending deletion. In that case, the existing printer is not deleted, and the **AddPrinter** creation parameters are used to change the existing printer settings (as if the application had used the [**SetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/setprinter) function).

Use the [**EnumPrintProcessors**](https://learn.microsoft.com/windows/win32/printdocs/enumprintprocessors) function to enumerate the set of print processors installed on a server. Use the [**EnumPrintProcessorDatatypes**](https://learn.microsoft.com/windows/win32/printdocs/enumprintprocessordatatypes) function to enumerate the set of data types that a print processor supports. Use the [**EnumPorts**](https://learn.microsoft.com/windows/win32/printdocs/enumports) function to enumerate the set of available ports. Use the [**EnumPrinterDrivers**](https://learn.microsoft.com/windows/win32/printdocs/enumprinterdrivers) function to enumerate the installed printer drivers.

The caller of the **AddPrinter** function must have SERVER\_ACCESS\_ADMINISTER access to the server on which the printer is to be created. The handle returned by the function will have PRINTER\_ALL\_ACCESS permission, and can be used to perform administrative operations on the printer.

If the **DrvPrinterEvent** function is passed the PRINTER\_EVENT\_FLAG\_NO\_UI flag, the driver should not use a UI call during **DrvPrinterEvent**. To do UI-related jobs, the installer should either use the **VendorSetup** entry in the printer's .inf file or, for Plug and Play devices, the installer can use a device-specific co-installer. For more information about **VendorSetup**, see the Microsoft Windows Driver Development Kit (DDK).

The Internet Connection Firewall (ICF) blocks printer ports by default, but an exception for File and Print Sharing is enabled when you run **AddPrinter**.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Library<br> | Winspool.lib |
| DLL<br> | Winspool.drv |
| Unicode and ANSI names<br> | **AddPrinterW** (Unicode) and **AddPrinterA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**ClosePrinter**](https://learn.microsoft.com/windows/win32/printdocs/closeprinter)

[**DeletePrinter**](https://learn.microsoft.com/windows/win32/printdocs/deleteprinter)

[**EnumPorts**](https://learn.microsoft.com/windows/win32/printdocs/enumports)

[**EnumPrinterDrivers**](https://learn.microsoft.com/windows/win32/printdocs/enumprinterdrivers)

[**EnumPrintProcessors**](https://learn.microsoft.com/windows/win32/printdocs/enumprintprocessors)

[**EnumPrintProcessorDatatypes**](https://learn.microsoft.com/windows/win32/printdocs/enumprintprocessordatatypes)

[**GetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/getprinter)

[**PRINTER\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-2)

[**PrinterProperties**](https://learn.microsoft.com/windows/win32/printdocs/printerproperties)

[**SetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/setprinter)

