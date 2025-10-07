# AddPrinterDriverEx function

The **AddPrinterDriverEx** function installs a local or remote printer driver and links the configuration, data, and driver files. Besides having the capabilities of [**AddPrinterDriver**](https://learn.microsoft.com/windows/win32/printdocs/addprinterdriver), it also has options that permit strict upgrade, strict downgrade, copying of newer files only, and copying of all files (regardless of file time stamps).

> [!Note]
> Installing a printer driver without a driver package is no longer recommended. Use [**InstallPrinterDriverFromPackage**](https://learn.microsoft.com/windows/win32/printdocs/installprinterdriverfrompackage) instead.

## Parameters

*pName* \[in\]

A pointer to a null-terminated string that specifies the name of the server on which the driver should be installed. If this parameter is **NULL**, the function installs the driver on the local computer.

*Level* \[in\]

The version of the structure to which *pDriverInfo* points. This value can be 2, 3, 4, 6, or 8.

*pDriverInfo* \[in, out\]

A pointer to a structure containing printer driver information. It can be one of the following.

| Value of Level | DRIVER\_INFO\_\* Structure |
|------------------------------------------------------------------------------------------------------|-----------------------------------------------------|
| **2** | [**DRIVER\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-2)<br> |
| **3** | [**DRIVER\_INFO\_3**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-3)<br> |
| **4** | [**DRIVER\_INFO\_4**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-4)<br> |
| **6** | [**DRIVER\_INFO\_6**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-6)<br> |
| **8** | [**DRIVER\_INFO\_8**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-8)<br> |

If the **pEnvironment** member of the structure pointed to by *pDriverInfo* is **NULL**, the function uses the current environment of the caller/client, not the environment of the destination/server.

*dwFileCopyFlags* \[in\]

The options for copying the driver files. This parameter can be one of the following values.

| Value | Meaning |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **APD\_COPY\_ALL\_FILES** | Add the printer driver and copy all the files in the printer-driver directory. The file time stamps are ignored with this option.<br> |
| **APD\_COPY\_FROM\_DIRECTORY** | Add the printer driver using the fully qualified file names specified in the [**DRIVER\_INFO\_6**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-6) structure. This flag is ORed in conjunction with one of the other copy flags. If this flag is set, **AddPrinterDriverEx** will fail if the files do not exist where they are specified to exist by the **DRIVER\_INFO\_6** structure. The files do not need to be copied to the system's printer-driver directory. See the Remarks.<br> **Windows 2000:** This flag is not supported.<br> |
| **APD\_COPY\_NEW\_FILES** | Add the printer driver and copy the files in the printer-driver directory that are newer than any corresponding files that are currently in use. This flag emulates the behavior of [**AddPrinterDriver**](https://learn.microsoft.com/windows/win32/printdocs/addprinterdriver).<br> |
| **APD\_STRICT\_DOWNGRADE** | Add the printer driver only if all the files in the printer-driver directory are older than any corresponding files currently in use.<br> |
| **APD\_STRICT\_UPGRADE** | Add the printer driver only if all the files in the printer-driver directory are newer than any corresponding files currently in use.<br> |

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero.

If the printer driver is known to have problems working with the operating system, **AddPrinterDriverEx** will fail with one of the following error codes:

| Error Code | Meaning |
|---------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------|
| ERROR\_PRINTER\_DRIVER\_BLOCKED | The driver does not work on the operating system. |
| ERROR\_PRINTER\_DRIVER\_WARNED | The driver is unreliable on the operating system. However, if APD\_INSTALL\_WARNED\_DRIVER is specified, the driver is installed and no warning is given. |

For more information, see the Remarks.

## Remarks

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

The caller must have the [SeLoadDriverPrivilege](https://learn.microsoft.com/windows/desktop/SecAuthZ/authorization-constants).

Before calling the **AddPrinterDriverEx** function, all files required by the driver must be copied to the system's printer-driver directory. To retrieve the name of this directory, call the [**GetPrinterDriverDirectory**](https://learn.microsoft.com/windows/win32/printdocs/getprinterdriverdirectory) function.

To determine which printer drivers are currently installed, call the [**EnumPrinterDrivers**](https://learn.microsoft.com/windows/win32/printdocs/enumprinterdrivers) function.

If the printer driver has been successfully added, the function calls the DrvDriverEvent (DRIVER\_EVENT\_INITIALIZE, Level, DRIVER\_INFO\_\*, lparam ) function to allow the driver to perform any initializations required during the installation of a printer driver. For more information about **DrvDriverEvent**, see the Microsoft Windows Driver Development Kit (DDK)

The driver should not use a UI call during the call to **DrvDriverEvent**. To do UI-related jobs, the installer should either use the VendorSetup entry in the printer's .inf file or, for Plug and Play devices, the installer can use a device-specific co-installer. For more information about VendorSetup, see the DDK.

The files that are referenced in the [**DRIVER\_INFO\_6**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-6) structure must be local to the machine from which the call is made. A file name can be a UNC name as long as the UNC name is the local machine.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Library<br> | Winspool.lib |
| DLL<br> | Winspool.drv |
| Unicode and ANSI names<br> | **AddPrinterDriverExW** (Unicode) and **AddPrinterDriverExA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**AddPrinterDriver**](https://learn.microsoft.com/windows/win32/printdocs/addprinterdriver)

[**DRIVER\_INFO\_2**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-2)

[**DRIVER\_INFO\_3**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-3)

[**DRIVER\_INFO\_4**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-4)

[**DRIVER\_INFO\_6**](https://learn.microsoft.com/windows/win32/printdocs/driver-info-6)

[**DeletePrinterDriverEx**](https://learn.microsoft.com/windows/win32/printdocs/deleteprinterdriverex)

[**EnumPrinterDrivers**](https://learn.microsoft.com/windows/win32/printdocs/enumprinterdrivers)

[**GetPrinterDriverDirectory**](https://learn.microsoft.com/windows/win32/printdocs/getprinterdriverdirectory)

