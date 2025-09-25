# FaxStartPrintJobW function

## Description

A fax client application calls the **FaxStartPrintJob** function to start printing an outbound fax transmission on the specified fax printer.

## Parameters

### `PrinterName` [in]

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that contains the name of a fax printer. The string can specify one of the following:

* A local printer, such as, "*printername*"
* A network printer, such as "\\*machinename*\*printername*"
* **NULL** to specify the local fax printer

### `PrintInfo` [in]

Type: **const [FAX_PRINT_INFO](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_print_infoa)***

Pointer to a [FAX_PRINT_INFO](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_print_infoa) structure that contains the information necessary for the fax server to print the fax transmission. The structure includes, among other items, the recipient's fax number, sender and recipient data, an optional billing code, and delivery report information. For more information, see the following Remarks section.

### `FaxJobId` [out]

Type: **LPDWORD**

Pointer to a **DWORD** variable to receive the print spooler's unique ID for the fax print job. (This is not the same as the fax queue's ID for the job and it cannot be used as a parameter in any fax API that takes a fax ID parameter.) This parameter is required.

### `FaxContextInfo` [out]

Type: **PFAX_CONTEXT_INFO**

Pointer to a [FAX_CONTEXT_INFO](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_context_infoa) structure to receive a handle to a printer device context. When the fax client application calls the [FaxPrintCoverPage](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxprintcoverpagea) function, it must pass this value in that function's *FaxContextInfo* parameter. For more information, see [Device Contexts](https://learn.microsoft.com/windows/desktop/gdi/device-contexts) and the [Printing and Print Spooler Reference](https://learn.microsoft.com/previous-versions/ms535790(v=vs.85)).

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). GetLastError can return one of the following errors.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or both of the *PrintInfo* or *FaxContextInfo* parameters are **NULL**. |
| **ERROR_INVALID_PARAMETER** | The **RecipientNumber** member of the [FAX_PRINT_INFO](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_print_infoa) structure is **NULL**; or the **OutputFileName** member is **NULL** and the **RecipientNumber** member is not specified. |
| **ERROR_INVALID_PRINTER_NAME** | The *PrinterName* parameter specifies a printer that is not a fax printer, or there is no fax printer installed. |
| **ERROR_NOT_ENOUGH_MEMORY** | An error occurred during memory allocation. |
| **ERROR_SPL_NO_STARTDOC** | [FaxStartPrintJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxstartprintjoba) was not called first, hence there was no [StartDoc](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-startdoca) call. |

## Remarks

The function returns a handle to a device context. The handle is used by the [FaxPrintCoverPage](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxprintcoverpagea) function, and by the [AbortDoc](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-abortdoc), [EndDoc](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enddoc), [DeleteDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deletedc), [StartPage](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-startpage), [EndPage](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-endpage) and other Win32 Windows Graphics Device Interface (GDI) functions.

**Note** The application must also call the [AbortDoc](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-abortdoc) function or the [EndDoc](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enddoc) function to complete the print job, and call the [DeleteDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deletedc) function to deallocate the handle to the printer device context. For more information, see [Printing a Fax to a Device Context](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-printing-a-fax-to-a-device-context).

A fax client application should not call the [CreateDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createdca) GDI function to create the fax printer device context; nor should it call the [StartPage](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-startpage) printing function to start a fax print job. Instead, the application should call the **FaxStartPrintJob** function. This is because **FaxStartPrintJob** modifies information in the [DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea) structure specific to the fax printer of interest.

The change prevents the display of the Fax Send Wizard that collects information from the user. The fax server uses the data in the [FAX_PRINT_INFO](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_print_infoa) structure pointed to by the *PrintInfo* parameter to print the fax transmission. This structure contains data the Fax Send Wizard would have collected, had the wizard been displayed.

A fax client application must call the **FaxStartPrintJob** function before calling the [FaxPrintCoverPage](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxprintcoverpagea) function to print a cover page with a fax job.

> [!NOTE]
> The winfax.h header defines FaxStartPrintJob as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[AbortDoc](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-abortdoc)

[DEVMODE](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodea)

[DeleteDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deletedc)

[EndDoc](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enddoc)

[FAX_CONTEXT_INFO](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_context_infoa)

[FAX_PRINT_INFO](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_print_infoa)

[Fax Service Client API Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-functions)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxPrintCoverPage](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxprintcoverpagea)