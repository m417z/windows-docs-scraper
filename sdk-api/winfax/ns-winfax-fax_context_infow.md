# FAX_CONTEXT_INFOW structure

## Description

The **FAX_CONTEXT_INFO** structure contains information about a fax printer device context. The **SizeOfStruct** member is required. Information for the other members is supplied by a call to the [FaxStartPrintJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxstartprintjoba) function.

## Members

### `SizeOfStruct`

Type: **DWORD**

Specifies the size, in bytes, of the **FAX_CONTEXT_INFO** structure. The calling application must set this member to **sizeof(FAX_CONTEXT_INFO)** before it calls the [FaxStartPrintJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxstartprintjoba) function.

### `hDC`

Type: **HDC**

Handle to a fax printer device context. A call to the [FaxStartPrintJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxstartprintjoba) function supplies the data for this member.

### `ServerName`

Type: **TCHAR[MAX_COMPUTERNAME_LENGTH+1]**

Specifies a variable that contains a null-terminated string that is the fax server name of interest. A call to the [FaxStartPrintJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxstartprintjoba) function supplies the data for this member. If the fax server is on the local computer, this member will be empty. The client application does not need to fill in this member.

## Remarks

A fax client application can call the [FaxStartPrintJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxstartprintjoba) function to retrieve the handle to a fax printer device context. The function returns the handle in a **FAX_CONTEXT_INFO** structure. The application must call the [DeleteDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deletedc) function to deallocate the handle to the printer device context. For more information, see [Printing a Fax to a Device Context](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-printing-a-fax-to-a-device-context).

> [!NOTE]
> The winfax.h header defines FAX_CONTEXT_INFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DeleteDC](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deletedc)

[EndDoc](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enddoc)

[Fax Service Client API Structures](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-structures)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxPrintCoverPage](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxprintcoverpagea)

[FaxStartPrintJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxstartprintjoba)