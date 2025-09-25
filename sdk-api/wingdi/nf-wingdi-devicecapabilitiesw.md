# DeviceCapabilitiesW function

## Description

The **DeviceCapabilities** function retrieves the capabilities of a printer driver.

## Parameters

### `pDevice` [in]

A pointer to a null-terminated string that contains the name of the printer. Note that this is the name of the printer, not of the printer driver.

### `pPort` [in]

A pointer to a null-terminated string that contains the name of the port to which the device is connected, such as LPT1.

### `fwCapability` [in]

The capabilities to be queried. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **DC_BINNAMES** | Retrieves the names of the printer's paper bins. The *pOutput* buffer receives an array of string buffers. Each string buffer is 24 characters long and contains the name of a paper bin. The return value indicates the number of entries in the array. The name strings are null-terminated unless the name is 24 characters long. If *pOutput* is **NULL**, the return value is the number of bin entries required. |
| **DC_BINS** | Retrieves a list of available paper bins. The *pOutput* buffer receives an array of **WORD** values that indicate the available paper sources for the printer. The return value indicates the number of entries in the array. For a list of the possible array values, see the description of the **dmDefaultSource** member of the [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure. If *pOutput* is **NULL**, the return value indicates the required number of entries in the array. |
| **DC_COLLATE** | If the printer supports collating, the return value is 1; otherwise, the return value is zero. The *pOutput* parameter is not used. |
| **DC_COLORDEVICE** | If the printer supports color printing, the return value is 1; otherwise, the return value is zero. The *pOutput* parameter is not used. |
| **DC_COPIES** | Returns the number of copies the device can print. |
| **DC_DRIVER** | Returns the version number of the printer driver. |
| **DC_DUPLEX** | If the printer supports duplex printing, the return value is 1; otherwise, the return value is zero. The *pOutput* parameter is not used. |
| **DC_ENUMRESOLUTIONS** | Retrieves a list of the resolutions supported by the printer. The *pOutput* buffer receives an array of **LONG** values. For each supported resolution, the array contains a pair of **LONG** values that specify the x and y dimensions of the resolution, in dots per inch. The return value indicates the number of supported resolutions. If *pOutput* is **NULL**, the return value indicates the number of supported resolutions. |
| **DC_EXTRA** | Returns the number of bytes required for the device-specific portion of the [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure for the printer driver. |
| **DC_FIELDS** | Returns the **dmFields** member of the printer driver's [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure. The **dmFields** member indicates which members in the device-independent portion of the structure are supported by the printer driver. |
| **DC_FILEDEPENDENCIES** | Retrieves the names of any additional files that need to be loaded when a driver is installed. The *pOutput* buffer receives an array of string buffers. Each string buffer is 64 characters long and contains the name of a file. The return value indicates the number of entries in the array. The name strings are null-terminated unless the name is 64 characters long. If *pOutput* is **NULL**, the return value is the number of files. |
| **DC_MAXEXTENT** | Returns the maximum paper size that the **dmPaperLength** and **dmPaperWidth** members of the printer driver's [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure can specify. The LOWORD of the return value contains the maximum **dmPaperWidth** value, and the HIWORD contains the maximum **dmPaperLength** value. |
| **DC_MEDIAREADY** | Retrieves the names of the paper forms that are currently available for use. The *pOutput* buffer receives an array of string buffers. Each string buffer is 64 characters long and contains the name of a paper form. The return value indicates the number of entries in the array. The name strings are null-terminated unless the name is 64 characters long. If *pOutput* is **NULL**, the return value is the number of paper forms. |
| **DC_MEDIATYPENAMES** | Retrieves the names of the supported media types. The *pOutput* buffer receives an array of string buffers. Each string buffer is 64 characters long and contains the name of a supported media type. The return value indicates the number of entries in the array. The strings are null-terminated unless the name is 64 characters long. If *pOutput* is **NULL**, the return value is the number of media type names required. |
| **DC_MEDIATYPES** | Retrieves a list of supported media types. The *pOutput* buffer receives an array of DWORD values that indicate the supported media types. The return value indicates the number of entries in the array. For a list of possible array values, see the description of the **dmMediaType** member of the [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure. If *pOutput* is **NULL**, the return value indicates the required number of entries in the array. |
| **DC_MINEXTENT** | Returns the minimum paper size that the **dmPaperLength** and **dmPaperWidth** members of the printer driver's [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure can specify. The LOWORD of the return value contains the minimum **dmPaperWidth** value, and the HIWORD contains the minimum **dmPaperLength** value. |
| **DC_ORIENTATION** | Returns the relationship between portrait and landscape orientations for a device, in terms of the number of degrees that portrait orientation is rotated counterclockwise to produce landscape orientation. The return value can be one of the following:<br><br>0<br><br>No landscape orientation.<br><br>90<br><br>Portrait is rotated 90 degrees to produce landscape.<br><br>270<br><br>Portrait is rotated 270 degrees to produce landscape. |
| **DC_NUP** | Retrieves an array of integers that indicate that printer's ability to print multiple document pages per printed page. The *pOutput* buffer receives an array of **DWORD** values. Each value represents a supported number of document pages per printed page. The return value indicates the number of entries in the array. If *pOutput* is **NULL**, the return value indicates the required number of entries in the array. |
| **DC_PAPERNAMES** | Retrieves a list of supported paper names (for example, Letter or Legal). The *pOutput* buffer receives an array of string buffers. Each string buffer is 64 characters long and contains the name of a paper form. The return value indicates the number of entries in the array. The name strings are null-terminated unless the name is 64 characters long. If *pOutput* is **NULL**, the return value is the number of paper forms. |
| **DC_PAPERS** | Retrieves a list of supported paper sizes. The *pOutput* buffer receives an array of **WORD** values that indicate the available paper sizes for the printer. The return value indicates the number of entries in the array. For a list of the possible array values, see the description of the **dmPaperSize** member of the [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure. If *pOutput* is **NULL**, the return value indicates the required number of entries in the array. |
| **DC_PAPERSIZE** | Retrieves the dimensions, in tenths of a millimeter, of each supported paper size. The *pOutput* buffer receives an array of [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structures. Each structure contains the width (x-dimension) and length (y-dimension) of a paper size as if the paper were in the **DMORIENT_PORTRAIT** orientation. The return value indicates the number of entries in the array. |
| **DC_PERSONALITY** | Retrieves a list of printer description languages supported by the printer. The *pOutput* buffer receives an array of string buffers. Each buffer is 32 characters long and contains the name of a printer description language. The return value indicates the number of entries in the array. The name strings are null-terminated unless the name is 32 characters long. If *pOutput* is **NULL**, the return value indicates the required number of array entries. |
| **DC_PRINTERMEM** | The return value is the amount of available printer memory, in kilobytes. The *pOutput* parameter is not used. |
| **DC_PRINTRATE** | The return value indicates the printer's print rate. The value returned for **DC_PRINTRATEUNIT** indicates the units of the **DC_PRINTRATE** value. The *pOutput* parameter is not used. |
| **DC_PRINTRATEPPM** | The return value indicates the printer's print rate, in pages per minute. The *pOutput* parameter is not used. |
| **DC_PRINTRATEUNIT** | The return value is one of the following values that indicate the print rate units for the value returned for the **DC_PRINTRATE** flag. The *pOutput* parameter is not used.<br><br>**PRINTRATEUNIT_CPS**<br><br>Characters per second.<br><br>**PRINTRATEUNIT_IPM**<br><br>Inches per minute.<br><br>**PRINTRATEUNIT_LPM**<br><br>Lines per minute.<br><br>**PRINTRATEUNIT_PPM**<br><br>Pages per minute. |
| **DC_SIZE** | Returns the **dmSize** member of the printer driver's [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure. |
| **DC_STAPLE** | If the printer supports stapling, the return value is a nonzero value; otherwise, the return value is zero. The *pOutput* parameter is not used. |
| **DC_TRUETYPE** | Retrieves the abilities of the driver to use TrueType fonts. For **DC_TRUETYPE**, the *pOutput* parameter should be **NULL**. The return value can be one or more of the following:<br><br>**DCTT_BITMAP**<br><br>Device can print TrueType fonts as graphics.<br><br>**DCTT_DOWNLOAD**<br><br>Device can download TrueType fonts.<br><br>**DCTT_SUBDEV**<br><br>Device can substitute device fonts for TrueType fonts. |
| **DC_VERSION** | Returns the specification version to which the printer driver conforms. |

### `pOutput` [out]

A pointer to an array. The format of the array depends on the setting of the *fwCapability* parameter. See each capability above to find out what is returned if *pOutput* is **NULL**.

### `pDevMode` [in]

A pointer to a [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure. If this parameter is **NULL**, **DeviceCapabilities** retrieves the current default initialization values for the specified printer driver. Otherwise, the function retrieves the values contained in the structure to which *pDevMode* points.

## Return value

If the function succeeds, the return value depends on the setting of the *fwCapability* parameter. A return value of zero generally indicates that, while the function completed successfully, there was some type of failure, such as a capability that is not supported. For more details, see the descriptions for the *fwCapability* values.

If the function returns -1, this may mean either that the capability is not supported or there was a general function failure.

## Remarks

**Note** This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation—factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

The [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure pointed to by the *pDevMode* parameter may be obtained by calling the [DocumentProperties](https://learn.microsoft.com/windows/desktop/printdocs/documentproperties) function.

If a printer driver supports custom device capabilities, the driver must call the [SetPrinterData](https://learn.microsoft.com/windows/desktop/printdocs/setprinterdata) function for each custom capability. The **SetPrinterData** function adds the appropriate printer data to the print system, which enables 32-bit applications to access the custom capabilities on 64-bit Windows installations.

For each custom capability, you must first add printer data that describes the type of the capability. To do this, when you call **SetPrinterData**, set the *pValueName* string to **CustomDeviceCapabilityType_Xxx**, where "Xxx" is the hexadecimal representation of the capability. For example, you might have "CustomDeviceCapabilityType_1234". The registry data that you set must be of the **REG_DWORD** type, and you must set its value to one of the following:

* 0, if the custom capability is a **DWORD**
* 1, if the custom capability is a buffer of bytes
* 2, if the custom capability is an array of items

If the custom capability is an array of items, you must call **SetPinterData** a second time to provide information about the size of an item in the array. To do this, when you call **SetPinterData**, the *pValueName* string that you provide must be "CustomDeviceCapabilitySize_Xxx" where Xxx is the hexadecimal representation of the capability. For example, you might have "CustomDeviceCapabilitySize_1234". The registry data that you set must be of the **REG_DWORD** type, and you must set its value to the size in bytes of an item in the array.

> [!NOTE]
> The wingdi.h header defines DeviceCapabilities as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea)

[DOCINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-docinfoa)

[DocumentProperties](https://learn.microsoft.com/windows/desktop/printdocs/documentproperties)

[GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps)

[GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress)

[LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya)

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)

[Print Spooler API Functions](https://learn.microsoft.com/windows/desktop/printdocs/printing-and-print-spooler-functions)

[Printing](https://learn.microsoft.com/windows/desktop/printdocs/printdocs-printing)

[StartDoc](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-startdoca)