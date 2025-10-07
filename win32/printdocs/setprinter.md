# SetPrinter function

The **SetPrinter** function sets the data for a specified printer or sets the state of the specified printer by pausing printing, resuming printing, or clearing all print jobs.

## Parameters

*hPrinter* \[in\]

A handle to the printer. Use the [**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter), [**OpenPrinter2**](https://learn.microsoft.com/windows/win32/printdocs/openprinter2), or [**AddPrinter**](https://learn.microsoft.com/windows/win32/printdocs/addprinter) function to retrieve a printer handle.

*Level* \[in\]

The type of data that the function stores into the buffer pointed to by *pPrinter*. If the *Command* parameter is not equal to zero, the *Level* parameter must be zero.

This value can be 0, 2, 3, 4, 5, 6, 7, 8, or 9.

*pPrinter* \[in\]

A pointer to a buffer containing data to set for the printer, or containing information for the command specified by the *Command* parameter. The type of data in the buffer is determined by the value of *Level*.

| Level | Structure |
|------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**0**

| If the *Command* parameter is **PRINTER\_CONTROL\_SET\_STATUS**, *pPrinter* must contain a **DWORD** value that specifies the new printer status to set. For a list of the possible status values, see the **Status** member of the [**PRINTER\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-2) structure. Note that **PRINTER\_STATUS\_PAUSED** and **PRINTER\_STATUS\_PENDING\_DELETION** are not valid status values to set.<br> If *Level* is 0, but the *Command* parameter is not **PRINTER\_CONTROL\_SET\_STATUS**, *pPrinter* must be **NULL**.<br> |
|

**2**

| A [**PRINTER\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-2) structure containing detailed information about the printer.<br> |
|

**3**

| A [**PRINTER\_INFO\_3**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-3) structure containing the printer's security information.<br> |
|

**4**

| A [**PRINTER\_INFO\_4**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-4) structure containing minimal printer information, including the name of the printer, the name of the server, and whether the printer is remote or local.<br> |
|

**5**

| A [**PRINTER\_INFO\_5**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-5) structure containing printer information such as printer attributes and time-out settings.<br> |
|

**6**

| A [**PRINTER\_INFO\_6**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-6) structure specifying the status value of a printer.<br> |
|

**7**

| A [**PRINTER\_INFO\_7**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-7) structure. The *dwAction* member of this structure indicates whether **SetPrinter** should publish, unpublish, re-publish, or update the printer's data in the directory service.<br> |
|

**8**

| A [**PRINTER\_INFO\_8**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-8) structure specifying the global default printer settings.<br> |
|

**9**

| A [**PRINTER\_INFO\_9**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-9) structure specifying the per-user default printer settings.<br> |

*Command* \[in\]

The action to perform.

If the *Level* parameter is nonzero, set the value of this parameter to zero. In this case, the printer retains its current state and the function reconfigures the printer data as specified by the *Level* and *pPrinter* parameters.

If the *Level* parameter is zero, set the value of this parameter to one of the following values.

| Value | Meaning |
|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------|
|

**PRINTER\_CONTROL\_PAUSE**

| Pause the printer.<br> |
|

**PRINTER\_CONTROL\_PURGE**

| Delete all print jobs in the printer.<br> |
|

**PRINTER\_CONTROL\_RESUME**

| Resume a paused printer.<br> |
|

**PRINTER\_CONTROL\_SET\_STATUS**

| Set the printer status.<br> Set the *pPrinter* parameter to a pointer to a **DWORD** value that specifies the new printer status.<br> |

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero.

If *Level* is 7 and the publish action failed, **SetPrinter** returns **ERROR\_IO\_PENDING** and attempts to complete the action in the background. If *Level* is 7 and the update action failed, **SetPrinter** returns **ERROR\_FILE\_NOT\_FOUND**.

## Remarks

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

You cannot use **SetPrinter** to change the default printer.

To modify the current printer settings, call the [**GetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/getprinter) function to retrieve the current settings into a [**PRINTER\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-2) structure, modify the members of that structure as necessary, and then call **SetPrinter**.

The **SetPrinter** function ignores the **pServerName**, **AveragePPM**, **Status**, and **cJobs** members of a [**PRINTER\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-2) structure.

Pausing a printer suspends scheduling of all print jobs for that printer, except for the one print job that may be currently printing. Print jobs can be submitted to a paused printer, but no jobs will be scheduled to print on that printer until printing is resumed. If a printer is cleared, all print jobs for that printer are deleted, except for the current print job.

If you use **SetPrinter** to modify the default [**DEVMODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure for a printer (globally setting the printer defaults), you must first call the [**DocumentProperties**](https://learn.microsoft.com/windows/win32/printdocs/documentproperties) function to validate the **DEVMODE** structure.

For the [**PRINTER\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-2) and [**PRINTER\_INFO\_3**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-3) structures that contain a pointer to a security descriptor, the function can set only those components of the security descriptor that the caller has permission to modify. To set particular security descriptor components, you must specify the necessary access rights when you call the [**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter) or [**OpenPrinter2**](https://learn.microsoft.com/windows/win32/printdocs/openprinter2) function to retrieve a handle to the printer. The following table shows the access rights required to modify the various security descriptor components.

| Access permission | Security descriptor component |
|------------------------------|-------------------------------------------|
| **WRITE\_OWNER** | Owner<br> Primary group<br> |
| **WRITE\_DAC** | Discretionary access-control list (DACL) |
| **ACCESS\_SYSTEM\_SECURITY** | System access-control list (SACL) |

If the security descriptor contains a component that the caller does not have the access right to modify, **SetPrinter** fails. Those components of a security descriptor that you don't want to modify should be **NULL** or not be present, as appropriate. If you do not want to modify the security descriptor, and are calling **SetPrinter** with a [**PRINTER\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-2) structure, set the **pSecurityDescriptor** member of that structure to **NULL**.

The Internet Connection Firewall (ICF) blocks printer ports by default, but an exception for File and Print Sharing can be enabled. If **SetPrinter** is called by a machine admin, it enables the exception. If it is called by a non-admin and the exception has not already been enabled, the call fails.

You can use level 7 with the [**PRINTER\_INFO\_7**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-7) structure to publish, unpublish, or update directory service data for the printer. The directory service data for a printer includes all the data stored under the SPLDS\_\* keys by calls to the [**SetPrinterDataEx**](https://learn.microsoft.com/windows/win32/printdocs/setprinterdataex) function for the printer. Before calling **SetPrinter**, set the **pszObjectGUID** member of **PRINTER\_INFO\_7** to **NULL** and set the *dwAction* member to one of the following values.

| Value | Description |
|-----------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **DSPRINT\_PUBLISH**<br> | Publishes the directory service data.<br> |
| **DSPRINT\_REPUBLISH**<br> | The directory service data for the printer is unpublished and then published again, refreshing all properties in the published printer. Re-publishing also changes the GUID of the published printer. Use this value if you suspect the printer's published data has been corrupted.<br> |
| **DSPRINT\_UNPUBLISH**<br> | Unpublishes the directory service data.<br> |
| **DSPRINT\_UPDATE**<br> | Updates the directory service data. This is the same as **DSPRINT\_PUBLISH**, except that **SetPrinter** fails with **ERROR\_FILE\_NOT\_FOUND** if the printer is not already published.<br> Use **DSPRINT\_UPDATE** to update published properties but not force publishing. Printer drivers should always use **DSPRINT\_UPDATE** rather than **DSPRINT\_PUBLISH**.<br> |

**DSPRINT\_PENDING** is not a valid *dwAction* value for **SetPrinter**.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | WinSpool.h (include Windows.h) |
| Library<br> | WinSpool.lib |
| DLL<br> | WinSpool.drv |
| Unicode and ANSI names<br> | **SetPrinterW** (Unicode) and **SetPrinterA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**AddPrinter**](https://learn.microsoft.com/windows/win32/printdocs/addprinter)

[**GetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/getprinter)

[**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter)

[**OpenPrinter2**](https://learn.microsoft.com/windows/win32/printdocs/openprinter2)

[**PRINTER\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-2)

[**PRINTER\_INFO\_3**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-3)

[**PRINTER\_INFO\_4**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-4)

[**PRINTER\_INFO\_5**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-5)

[**PRINTER\_INFO\_6**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-6)

[**PRINTER\_INFO\_7**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-7)

[**PRINTER\_INFO\_8**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-8)

[**PRINTER\_INFO\_9**](https://learn.microsoft.com/windows/win32/printdocs/printer-info-9)

[**SetPrinterDataEx**](https://learn.microsoft.com/windows/win32/printdocs/setprinterdataex)

