# DocumentProperties function

The **DocumentProperties** function retrieves or modifies printer initialization information or displays a printer-configuration property sheet for the specified printer.

## Parameters

*hWnd* \[in\]

A handle to the parent window of the printer-configuration property sheet.

*hPrinter* \[in\]

A handle to a printer object. Use the [**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter) or [**AddPrinter**](https://learn.microsoft.com/windows/win32/printdocs/addprinter) function to retrieve a printer handle.

*pDeviceName* \[in\]

A pointer to a null-terminated string that specifies the name of the device for which the printer-configuration property sheet is displayed.

*pDevModeOutput* \[out\]

A pointer to a [**DEVMODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure that receives the printer configuration data specified by the user.

*pDevModeInput* \[in\]

A pointer to a [**DEVMODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure that the operating system uses to initialize the property sheet controls.

This parameter is only used if the **DM\_IN\_BUFFER** flag is set in the *fMode* parameter. If **DM\_IN\_BUFFER** is not set, the operating system uses the printer's default [**DEVMODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea).

*fMode* \[in\]

The operations the function performs. If this parameter is zero, the **DocumentProperties** function returns the number of bytes required by the printer driver's [**DEVMODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) data structure. Otherwise, use one or more of the following constants to construct a value for this parameter; note, however, that in order to change the print settings, an application must specify at least one input value and one output value.

| Value | Meaning |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **DM\_IN\_BUFFER** | Input value. Before prompting, copying, or updating, the function merges the printer driver's current print settings with the settings in the [**DEVMODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure specified by the *pDevModeInput* parameter. The function updates the structure only for those members specified by the **DEVMODE** structure's **dmFields** member. This value is also defined as **DM\_MODIFY**. In cases of conflict during the merge, the settings in the **DEVMODE** structure specified by *pDevModeInput* override the printer driver's current print settings.<br> |
| **DM\_IN\_PROMPT** | Input value. The function presents the printer driver's Print Setup property sheet and then changes the settings in the printer's [**DEVMODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) data structure to those values specified by the user. This value is also defined as **DM\_PROMPT**.<br> |
| **DM\_OUT\_BUFFER** | Output value. The function writes the printer driver's current print settings, including private data, to the [**DEVMODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) data structure specified by the *pDevModeOutput* parameter. The caller must allocate a buffer sufficiently large to contain the information. If the bit **DM\_OUT\_BUFFER** sets is clear, the *pDevModeOutput* parameter can be **NULL**. This value is also defined as **DM\_COPY**.<br> |

## Return value

If the *fMode* parameter is zero, the return value is the size of the buffer required to contain the printer driver initialization data. Note that this buffer can be larger than a [**DEVMODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure if the printer driver appends private data to the structure.

If the function displays the property sheet, the return value is either **IDOK** or **IDCANCEL**, depending on which button the user selects.

If the function does not display the property sheet and is successful, the return value is **IDOK**.

If the function fails, the return value is less than zero.

## Remarks

> [!Note]
> This is a blocking or synchronous function and might not return immediately. How quickly this function returns depends on run-time factors such as network status, print server configuration, and printer driver implementation factors that are difficult to predict when writing an application. Calling this function from a thread that manages interaction with the user interface could make the application appear to be unresponsive.

The string pointed to by the *pDeviceName* parameter can be obtained by calling the [**GetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/getprinter) function.

The [**DEVMODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure actually used by a printer driver contains the device-independent part (as defined above) followed by a driver-specific part that varies in size and content with each driver and driver version. Because of this driver dependence, it is very important for applications to query the driver for the correct size of the **DEVMODE** structure before allocating a buffer for it.

**To make changes to print settings that are local to an application, an application should follow these steps:**

1. Get the number of bytes required for the full [**DEVMODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure by calling **DocumentProperties** and specifying zero in the *fMode* parameter.
2. Allocate memory for the full [**DEVMODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure.
3. Get the current printer settings by calling **DocumentProperties**. Pass a pointer to the [**DEVMODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure allocated in Step 2 as the *pDevModeOutput* parameter and specify the **DM\_OUT\_BUFFER** value.
4. Modify the appropriate members of the returned [**DEVMODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure and indicate which members were changed by setting the corresponding bits in the **dmFields** member of the **DEVMODE**.
5. Call **DocumentProperties** and pass the modified [**DEVMODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure back as both the *pDevModeInput* and *pDevModeOutput* parameters and specify both the **DM\_IN\_BUFFER** and **DM\_OUT\_BUFFER** values (which are combined using the OR operator).The **DEVMODE** structure returned by the third call to **DocumentProperties** can be used as an argument in a call to the [**CreateDC**](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdca) function.

To create a handle to a printer-device context using the current printer settings, you only need to call **DocumentProperties** twice, as described above. The first call gets the size of the full [**DEVMODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) and the second call initializes the **DEVMODE** with the current printer settings. Pass the initialized **DEVMODE** to [**CreateDC**](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdca) to obtain the handle to the printer device context.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Winspool.h (include Windows.h) |
| Library<br> | Winspool.lib |
| DLL<br> | Winspool.drv |
| Unicode and ANSI names<br> | **DocumentPropertiesW** (Unicode) and **DocumentPropertiesA** (ANSI)<br> |

## See also

[Printing](https://learn.microsoft.com/windows/win32/printdocs/printdocs-printing)

[Print Spooler API Functions](https://learn.microsoft.com/windows/win32/printdocs/printing-and-print-spooler-functions)

[**AdvancedDocumentProperties**](https://learn.microsoft.com/windows/win32/printdocs/advanceddocumentproperties)

[**CreateDC**](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdca)

[**DEVMODE**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea)

[**GetPrinter**](https://learn.microsoft.com/windows/win32/printdocs/getprinter)

[**OpenPrinter**](https://learn.microsoft.com/windows/win32/printdocs/openprinter)

