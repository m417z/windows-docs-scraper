# AddPrintProvidor function

> [!IMPORTANT]
> On July 6, 2021, [KB5005010](https://support.microsoft.com/topic/kb5005010-restricting-installation-of-new-printer-drivers-after-applying-the-july-6-2021-updates-31b91c02-05bc-4ada-a7ea-183b129578a7) introduced an optional registry-based configuration option to restrict access to this API to admin users only. This option was off be default.
>
> On August 10, 2021, [KB5005652](https://aka.ms/print_install_kb) changes this configuration's default value to require admin rights to install new printer drivers.

The **AddPrintProvidor** function installs a local print provider and links the configuration, data, and provider files.

## Parameters

*pName* \[in\]

A pointer to a null-terminated string that specifies the name of the server on which the provider should be installed. For systems that only support local installation of providers, this parameter should be **NULL**.

*Level* \[in\]

The level of the structure to which *pProviderInfo* points. It can be one of the following.

| Value | Meaning |
|------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------|
|

**1**

| Function uses a [**PROVIDOR\_INFO\_1**](https://learn.microsoft.com/windows/win32/printdocs/providor-info-1) structure.<br> |
|

**2**

| Function uses a [**PROVIDOR\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/providor-info-2) structure.<br> |

*pProviderInfo* \[in\]

A pointer to a print provider structure, as indicated by *Level*.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero.

## Remarks

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

Before an application calls the **AddPrintProvidor** function, all files required by the provider must be copied to the SYSTEM32 directory.

A provider added by **AddPrintProvidor** may be removed by calling [**DeletePrintProvidor**](https://learn.microsoft.com/windows/win32/printdocs/deleteprintprovidor).

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Library<br> | Winspool.lib |
| DLL<br> | Winspool.drv |
| Unicode and ANSI names<br> | **AddPrintProvidorW** (Unicode) and **AddPrintProvidorA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**DeletePrintProvidor**](https://learn.microsoft.com/windows/win32/printdocs/deleteprintprovidor)

[**PROVIDOR\_INFO\_1**](https://learn.microsoft.com/windows/win32/printdocs/providor-info-1)

[**PROVIDOR\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/providor-info-2)

