# SetPrinterDataEx function

The **SetPrinterDataEx** function sets the configuration data for a printer or print server. The function stores the configuration data under the printer's registry key.

## Parameters

*hPrinter* \[in\]

A handle to the printer or print server for which the function sets configuration data. Use the [**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter), [**OpenPrinter2**](https://learn.microsoft.com/windows/win32/printdocs/openprinter2), or [**AddPrinter**](https://learn.microsoft.com/windows/win32/printdocs/addprinter) function to retrieve a printer handle.

*pKeyName* \[in\]

A pointer to a null-terminated string that specifies the key containing the value to set. If the specified key or subkeys do not exist, the function creates them.

To store configuration data that can be published in the directory service (DS), specify one of the following predefined registry keys.

| Value | Meaning |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------|
| **SPLDS_DRIVER_KEY** | Printer drivers use this key to store driver properties.<br> |
| **SPLDS_SPOOLER_KEY** | Reserved. Used only by the print spooler to store internal spooler properties.<br> |
| **SPLDS_USER_KEY** | Applications use this key to store printer properties such as printer asset numbers.<br> |

Values that are stored under the SPLDS_USER_KEY key are published in the directory service only if there is a corresponding property in the schema. A domain administrator must create the property if it doesn't already exist. To publish a user-defined property after you use **SetPrinterDataEx** to add or change a value, call [**SetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/setprinter) with *Level* = 7 and with the **dwAction** member of [**PRINTER_INFO_7**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-7) set to **DSPRINT_UPDATE**.

You can specify other keys to store non-DS configuration data. Use the backslash ( \\ ) character as a delimiter to specify a path that has one or more subkeys.

If *hPrinter* is a handle to a printer and *pKeyName* is **NULL** or an empty string, **SetPrinterDataEx** returns **ERROR_INVALID_PARAMETER**.

If *hPrinter* is a handle to a print server, *pKeyName* is ignored.

Do not use **SPLDS_SPOOLER_KEY**. To change the spooler printer properties, use [**SetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/setprinter) with *Level* = 2.

*pValueName* \[in\]

A pointer to a null-terminated string that identifies the data to set.

For printers, this string specifies the name of a value under the *pKeyName* key.

For print servers, this string is one of the predefined strings listed in the following Remarks section.

*Type* \[in\]

A code indicating the type of data pointed to by the *pData* parameter. For a list of the possible type codes, see [Registry Value Types](https://learn.microsoft.com/windows/desktop/SysInfo/registry-value-types).

If *pKeyName* specifies one of the predefined directory service keys, *Type* must be **REG_SZ**, **REG_MULTI_SZ**, **REG_DWORD**, or **REG_BINARY**. If **REG_BINARY** is used, *cbData* must be equal to 1, and the directory service treats the data as a Boolean value.

*pData* \[in\]

A pointer to a buffer that contains the printer configuration data.

*cbData* \[in\]

The size, in bytes, of the array.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

If the function fails, the return value is an error value.

## Remarks

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

To retrieve existing configuration data for a printer or print spooler, call the [**GetPrinterDataEx**](https://learn.microsoft.com/windows/win32/printdocs/getprinterdataex) function.

Calling **SetPrinterDataEx** with the *pKeyName* parameter set to "PrinterDriverData" is equivalent to calling the [**SetPrinterData**](https://learn.microsoft.com/windows/win32/printdocs/setprinterdata) function.

If *hPrinter* is a handle to a print server, *pValueName* can specify one of the following predefined values.

| Value | Comments |
|---------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **SPLREG_ALLOW_USER_MANAGEFORMS** | Windows XP with Service Pack 2 (SP2) and later<br> Windows Server 2003 with Service Pack 1 (SP1) and later<br> |
| **SPLREG_BEEP_ENABLED** | |
| **SPLREG_DEFAULT_SPOOL_DIRECTORY** | |
| **SPLREG_EVENT_LOG** | |
| **SPLREG_NET_POPUP** | Not supported in Windows Server 2003 and later<br> |
| **SPLREG_PORT_THREAD_PRIORITY_DEFAULT** | |
| **SPLREG_PORT_THREAD_PRIORITY** | |
| **SPLREG_PRINT_DRIVER_ISOLATION_GROUPS** | Windows 7 and later<br> |
| **SPLREG_PRINT_DRIVER_ISOLATION_TIME_BEFORE_RECYCLE** | Windows 7 and later<br> |
| **SPLREG_PRINT_DRIVER_ISOLATION_MAX_OBJECTS_BEFORE_RECYCLE** | Windows 7 and later<br> |
| **SPLREG_PRINT_DRIVER_ISOLATION_IDLE_TIMEOUT** | Windows 7 and later<br> |
| **SPLREG_PRINT_DRIVER_ISOLATION_EXECUTION_POLICY** | Windows 7 and later<br> |
| **SPLREG_PRINT_DRIVER_ISOLATION_OVERRIDE_POLICY** | Windows 7 and later<br> |
| **SPLREG_RETRY_POPUP** | On successful return, *pData* contains 1 if server is set to retry pop-up windows for all jobs, or 0 if server does not retry pop-up windows for all jobs.<br> Not supported in Windows Server 2003 and later<br> |
| **SPLREG_SCHEDULER_THREAD_PRIORITY** | |
| **SPLREG_SCHEDULER_THREAD_PRIORITY_DEFAULT** | |
| **SPLREG_WEBSHAREMGMT** | Windows Server 2003 and later<br> |

Passing one of the following predefined values as *pValueName* sets the pool printing behavior when an error occurs.

| Value | Comments |
|---------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **SPLREG_RESTART_JOB_ON_POOL_ERROR** | The value of *pData* indicates the time, in seconds, when a job is restarted on another port after an error occurs. This setting is used with **SPLREG_RESTART_JOB_ON_POOL_ENABLED**.<br> |
| **SPLREG_RESTART_JOB_ON_POOL_ENABLED** | A nonzero value in *pData* indicates that **SPLREG_RESTART_JOB_ON_POOL_ERROR** is enabled.<br> |

The time specified in **SPLREG_RESTART_JOB_ON_POOL_ERROR** is a minimum time. The actual time can be longer, depending on the following port monitor settings, which are registry values under this registry key:

**HKLM\\SYSTEM\\CurrentControlSet\\Control\\Print\\Monitors\\<*MonitorName*>\\Ports**

Call the [**RegSetValueEx**](https://learn.microsoft.com/windows/win32/api/winreg/nf-winreg-regsetvaluea) function to set these values.

| Port monitor setting | Data type | Meaning |
|--------------------------|----------------|----------------------------------------------------------------------------------------------------------------|
| **StatusUpdateEnabled** | **REG_DWORD** | If a nonzero value, enables the port monitor to update the spooler with the port status.<br> |
| **StatusUpdateInterval** | **REG_DWORD** | Specifies the interval, in minutes, when the port monitor updates the spooler with the port status.<br> |

To ensure that the spooler redirects jobs to the next available printer in the pool (when the print job is not printed within the set time), the port monitor must support SNMP and the network ports in the pool must be configured as "SNMP status enabled." The port monitor that supports SNMP is Standard TCP/IP port monitor.

In Windows 7 and later versions of Windows, print jobs that are sent to a print server are rendered on the client by default. Client-side rendering of print jobs can be configured by setting *pKeyName* to "PrinterDriverData" and *pValueName* to the setting value in the following table.

| Setting | Data type | Description |
|------------------------------|----------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **EMFDespoolingSetting** | **REG_DWORD** | A value of 0, or if this value is not present in the registry, enables the default client-side rendering of print jobs.<br> A value of 1 disables client-side rendering of print jobs.<br> |
| **ForceClientSideRendering** | **REG_DWORD** | A value of 0, or if this value is not present in the registry, will cause the print jobs to be rendered on the client. If a print job cannot be rendered on the client, it will be rendered on the server. If a print job cannot be rendered on the server, it will fail.<br> A value of 1 will render print jobs on the client. If a print job cannot be rendered on the client, it will fail.<br> |

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Library<br> | Winspool.lib |
| DLL<br> | Winspool.drv |
| Unicode and ANSI names<br> | **SetPrinterDataExW** (Unicode) and **SetPrinterDataExA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**GetPrinterDataEx**](https://learn.microsoft.com/windows/win32/printdocs/getprinterdataex)

[**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter)

[**SetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/setprinter)

[**PRINTER_INFO_7**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-7)

