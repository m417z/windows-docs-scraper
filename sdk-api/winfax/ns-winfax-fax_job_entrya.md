# FAX_JOB_ENTRYA structure

## Description

The **FAX_JOB_ENTRY** structure describes one fax job. The structure includes data on the job type and status, recipient and sender identification, scheduling and delivery settings, and the page count. The **SizeOfStruct** and **RecipientNumber** members are required.

## Members

### `SizeOfStruct`

Type: **DWORD**

Specifies the size, in bytes, of the **FAX_JOB_ENTRY** structure. The calling application must set this member to **sizeof(FAX_JOB_ENTRY)** before it calls the [FaxSetJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsetjoba) function.

### `JobId`

Type: **DWORD**

Specifies a unique number that identifies the fax job of interest. This number must match the value the calling application passes in the JobId parameter to the [FaxSetJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsetjoba) function.

### `UserName`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that specifies the name of the user who submitted the fax job.

### `JobType`

Type: **DWORD**

Specifies a **DWORD** variable that specifies the type of the fax job of interest. This member can be one of the following job types.

#### JT_SEND

The job is an outgoing fax transmission.

#### JT_RECEIVE

The job is an incoming fax transmission.

#### JT_UNKNOWN

The job type is unknown. This value indicates that the fax server has not yet scheduled the job.

#### JT_ROUTING

The fax server tried to route the fax transmission, but routing failed. The fax server will attempt to route the job again.

#### JT_FAIL_RECEIVE

The fax server did not route the fax because it did not receive the entire transmission. The fax server saves the partial transmission in a temporary directory.

### `QueueStatus`

Type: **DWORD**

Specifies a **DWORD** variable that is a set of bit flags indicating the queue status of the fax job identified by the **JobId** member. This member can be one or more of the following values.

#### JS_PENDING

The fax job is in the queue and pending service.

#### JS_INPROGRESS

The fax job is in progress.

#### JS_DELETING

The fax server is deleting the fax job.

#### JS_FAILED

The fax job failed.

#### JS_PAUSED

The fax server paused the fax job.

#### JS_NOLINE

There is no line available to send the fax. The fax server will send the transmission when a line is available.

#### JS_RETRYING

The fax job failed. The fax server will attempt to retransmit the fax after a specified interval. For more information about global configuration settings, such as retransmission intervals, see [FAX_CONFIGURATION](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_configurationa).

#### JS_RETRIES_EXCEEDED

The fax server exceeded the maximum number of retransmission attempts allowed. The fax will not be sent. For more information about global configuration settings, such as the maximum number of retransmission attempts, see [FAX_CONFIGURATION](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_configurationa).

### `Status`

Type: **DWORD**

Specifies a **DWORD** variable that is a fax device status code or value. This value can be one of the following predefined device status codes.

#### FPS_DIALING

The device is dialing a fax number.

#### FPS_SENDING

The device is sending a fax document.

#### FPS_RECEIVING

The device is receiving a fax document.

#### FPS_COMPLETED

The device completed sending or receiving a fax transmission.

#### FPS_UNAVAILABLE

The device is not available because it is in use by another application.

#### FPS_BUSY

The device encountered a busy signal.

#### FPS_NO_ANSWER

The receiving device did not answer the call.

#### FPS_BAD_ADDRESS

The device dialed an invalid fax number.

#### FPS_NO_DIAL_TONE

The sending device cannot complete the call because it does not detect a dial tone.

#### FPS_DISCONNECTED

The fax call was disconnected by the sender or the caller.

#### FPS_FATAL_ERROR

The device has encountered a fatal protocol error.

#### FPS_NOT_FAX_CALL

The device received a call that was a data call or a voice call.

#### FPS_CALL_DELAYED

The device delayed a fax call because the sending device received a busy signal multiple times. The device cannot retry the call because dialing restrictions exist. (Some countries/regions restrict the number of retry attempts when a number is busy.)

#### FPS_CALL_BLACKLISTED

The device could not complete a call because the telephone number was blocked or reserved; emergency numbers such as 911 are blocked.

#### FPS_INITIALIZING

The device is initializing a call.

#### FPS_OFFLINE

The device is offline and unavailable.

#### FPS_RINGING

The device is ringing.

#### FPS_AVAILABLE

The device is available.

#### FPS_ABORTING

The device is aborting a fax job.

#### FPS_ROUTING

The device is routing a received fax document.

#### FPS_ANSWERED

The device answered a new call.

#### FPS_HANDLED

The fax service processed the outbound fax document; the fax service provider will transmit the document.

### `Size`

Type: **DWORD**

Specifies a **DWORD** variable that contains the size, in bytes, of the fax document to transmit. The size must not exceed 4 GB.

### `PageCount`

Type: **DWORD**

Specifies a **DWORD** variable that indicates the total number of pages in the fax transmission.

### `RecipientNumber`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that specifies the fax number of the recipient of the fax transmission.

### `RecipientName`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that specifies the name of the recipient of the fax transmission.

### `Tsid`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that specifies the transmitting station identifier. This identifier is usually a telephone number.

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

Specifies a **DWORD** variable that indicates when to send the fax. This member can be one of the following predefined job scheduling actions.

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

Send the DR or NDR in email to the sender's local personal folder store (PST).

### `DeliveryReportAddress`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string. If the **DeliveryReportType** member is equal to **DRT_EMAIL**, the string is the address to which the DR or NDR should be sent. If the **DeliveryReportType** member is equal to **DRT_NONE**, this member must be **NULL**.

### `DocumentName`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string to associate with the fax document. This is the user-friendly name that appears in the print spooler.

## Remarks

A fax client application passes the **FAX_JOB_ENTRY** structure in a call to the [FaxSetJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsetjoba) function.

An application can call the [FaxEnumJobs](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxenumjobsa) function to enumerate all queued and active fax jobs on the fax server of interest. **FaxEnumJobs** returns an array of **FAX_JOB_ENTRY** structures. Each structure describes one fax job in detail.

For more information, see [Managing Fax Jobs](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-fax-jobs).

> [!NOTE]
> The winfax.h header defines FAX_JOB_ENTRY as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[FAX_CONFIGURATION](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_configurationa)

[Fax Service Client API Structures](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-structures)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxEnumJobs](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxenumjobsa)

[FaxSetJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsetjoba)

[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime)