# FAX_JOB_PARAMA structure

## Description

The **FAX_JOB_PARAM** structure contains the information necessary for the fax server to send an individual fax transmission. The structure includes the recipient's fax number, sender and recipient data, an optional billing code, and job scheduling information.

The **SizeOfStruct**, **RecipientNumber**, and **ScheduleAction** members are required; other members are optional.

## Members

### `SizeOfStruct`

Type: **DWORD**

Specifies the size, in bytes, of the **FAX_JOB_PARAM** structure. The calling application must set this member to **sizeof(FAX_JOB_PARAM)**. This member is required.

### `RecipientNumber`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that specifies the fax number of the recipient of the fax transmission. This member is required.

### `RecipientName`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that specifies the name of the recipient of the fax transmission.

### `Tsid`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that specifies the transmitting station identifier (TSID). This identifier is usually a telephone number. Only printable characters such as English letters, numeric symbols, and punctuation marks (ASCII range 0x20 to 0x7F) can be used in a TSID.

### `SenderName`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that specifies the name of the sender who initiated the fax transmission.

### `SenderCompany`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that specifies the company name of the sender who initiated the fax transmission.

### `SenderDept`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that specifies the department name of the sender who initiated the fax transmission.

### `BillingCode`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that indicates an application- or server-specific billing code that applies to the fax transmission. The fax server uses the string to generate an entry in the fax event log. Billing codes are optional.

### `ScheduleAction`

Type: **DWORD**

Specifies a DWORD variable that indicates when to send the fax. This member is required, and can be one of the following predefined job scheduling actions.

#### JSA_NOW

Send the fax as soon as a device is available.

#### JSA_SPECIFIC_TIME

Send the fax at the time specified by the **ScheduleTime** member.

#### JSA_DISCOUNT_PERIOD

Send the fax during the discount rate period. Call the [FaxGetConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxgetconfigurationa) function to retrieve the discount period for the fax server.

### `ScheduleTime`

Type: **[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime)**

If the **ScheduleAction** member is equal to the value **JSA_SPECIFIC_TIME**, specifies a [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that contains the date and time to send the fax. The time specified must be expressed in UTC.

### `DeliveryReportType`

Type: **DWORD**

Specifies a **DWORD** variable that indicates the type of email delivery report (DR) or nondelivery report (NDR) that the fax server should generate. This member can be one of the following predefined delivery report types.

#### DRT_NONE

Do not send a DR or an NDR to the sender of the fax transmission.

#### DRT_EMAIL

Send the DR or NDR in an email message to the sender of the fax transmission (supported in Windows Server 2003 and later).

#### DRT_INBOX

Send the DR or NDR in email to the sender's local personal information store.

### `DeliveryReportAddress`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string. If the **DeliveryReportType** member is equal to **DRT_EMAIL**, the string is the address to which the DR or NDR should be sent. If the **DeliveryReportType** member is equal to **DRT_NONE**, this member must be **NULL**.

### `DocumentName`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string to associate with the fax document. This is the user-friendly name that appears in the print spooler.

### `CallHandle`

Type: **HCALL**

Reserved, and should be **NULL**.

### `Reserved`

Type: **DWORD_PTR[3]**

This member is reserved for future use by Microsoft. It must be set to zero.

## Remarks

A fax client application passes the **FAX_JOB_PARAM** structure in a call to the [FaxSendDocument](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsenddocumenta) function to inform the fax server how and when to send the fax transmission. For more information, see [Sending a Fax to One Recipient (Win32 Environment)](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-sending-a-fax-to-one-recipient-win32-environment-).

> [!NOTE]
> The winfax.h header defines FAX_JOB_PARAM as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Fax Service Client API Structures](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-structures)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxCompleteJobParams](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxcompletejobparamsa)

[FaxGetConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxgetconfigurationa)

[FaxSendDocument](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsenddocumenta)

[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime)

[lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linemakecall)