# FAX_PRINT_INFOW structure

## Description

The **FAX_PRINT_INFO** structure contains the information necessary for the fax server to print a fax transmission. The structure includes sender and recipient data, an optional billing code, and delivery report information.

The **SizeOfStruct** and **RecipientNumber** members are required; other members are optional.

## Members

### `SizeOfStruct`

Type: **DWORD**

Specifies the size, in bytes, of the **FAX_PRINT_INFO** structure. The calling application must set this member to **sizeof(FAX_PRINT_INFO)**. This member is required.

### `DocName`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that is the user-friendly name that appears in the print spooler.

### `RecipientName`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that specifies the name of the recipient of the fax transmission.

### `RecipientNumber`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that specifies the fax number of the recipient of the fax transmission. This member is required.

### `SenderName`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that specifies the name of the sender who initiated the fax transmission.

### `SenderCompany`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that specifies the company name of the sender who initiated the fax transmission.

### `SenderDept`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that specifies the department name of the sender who initiated the fax transmission.

### `SenderBillingCode`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that indicates an application- or server-specific billing code that applies to the fax transmission. The fax server uses the string to generate an entry in the fax event log. Billing codes are optional.

### `Reserved`

Type: **LPCTSTR**

Reserved. Must be set to **NULL**.

### `DrEmailAddress`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that specifies the email address to which the fax server should send the delivery report (DR) or nondelivery report (NDR).

### `OutputFileName`

Type: **LPCTSTR**

This member is reserved for future use by Microsoft. It must be set to **NULL**.

## Remarks

A fax client application passes the **FAX_PRINT_INFO** structure in a call to the [FaxStartPrintJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxstartprintjoba) function to start a print job on a specified fax printer. For more information, see [Printing a Fax to a Device Context](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-printing-a-fax-to-a-device-context).

> [!NOTE]
> The winfax.h header defines FAX_PRINT_INFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[FAX_CONFIGURATION](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_configurationa)

[Fax Service Client API Structures](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-structures)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxStartPrintJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxstartprintjoba)