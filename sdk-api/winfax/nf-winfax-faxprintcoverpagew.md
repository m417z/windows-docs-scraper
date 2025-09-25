# FaxPrintCoverPageW function

## Description

The **FaxPrintCoverPage** function prints a fax transmission cover page to the specified device context for a fax client application.

## Parameters

### `FaxContextInfo` [in]

Type: **const [FAX_CONTEXT_INFO](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_context_infoa)***

Pointer to a [FAX_CONTEXT_INFO](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_context_infoa) structure that contains a handle to a fax printer device context.

### `CoverPageInfo` [in]

Type: **const [FAX_COVERPAGE_INFO](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_coverpage_infoa)***

Pointer to a [FAX_COVERPAGE_INFO](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_coverpage_infoa) structure that contains personal data to display on the cover page of the fax document.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). GetLastError can return one of the following errors.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or both of the *CoverPageInfo* or *FaxContextInfo* parameters are **NULL**. |
| **ERROR_INVALID_PARAMETER** | The **SizeOfStruct** member of the specified [FAX_COVERPAGE_INFO](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_coverpage_infoa) structure is not equal to **sizeof(FAX_COVERPAGE_INFO)**; or the **SizeOfStruct** member of the specified [FAX_CONTEXT_INFO](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_context_infoa) structure is not equal to **sizeof(FAX_CONTEXT_INFO)**. |
| **ERROR_FILE_NOT_FOUND** | The fax server cannot locate the file specified by the **CoverPageName** member of the [FAX_COVERPAGE_INFO](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_coverpage_infoa) structure. |

## Remarks

A device context handle is obtained by using the [FaxStartPrintJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxstartprintjoba) function.

The cover page can be a personal cover page stored on the local computer, or it can be a common cover page stored on the fax server.

**Note** The application must also call the [AbortDoc](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-abortdoc) function or the [EndDoc](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enddoc) function to complete the print job, and call the [DeleteDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deletedc) function to deallocate the handle to the printer device context. For more information, see [Printing a Fax to a Device Context](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-printing-a-fax-to-a-device-context).

A fax client application must call the [FaxStartPrintJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxstartprintjoba) function before calling the **FaxPrintCoverPage** function to print a cover page with a fax job. For more information, see [Cover Pages](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-cover-pages) and [Printing a Fax to a Device Context](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-printing-a-fax-to-a-device-context).

> [!NOTE]
> The winfax.h header defines FaxPrintCoverPage as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[FAX_CONTEXT_INFO](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_context_infoa)

[FAX_COVERPAGE_INFO](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_coverpage_infoa)

[Fax Service Client API Functions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-functions)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxStartPrintJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxstartprintjoba)