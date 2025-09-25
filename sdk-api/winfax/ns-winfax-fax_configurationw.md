# FAX_CONFIGURATIONW structure

## Description

The **FAX_CONFIGURATION** structure contains information about the global configuration settings of a fax server. The structure includes data on retransmission, branding, archive, and cover page settings; discount rate periods; and the status of the fax server queue.

## Members

### `SizeOfStruct`

Type: **DWORD**

Specifies the size, in bytes, of the **FAX_CONFIGURATION** structure. The calling application must set this member to **sizeof(FAX_CONFIGURATION)** before it calls the [FaxSetConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsetconfigurationa) function.

### `Retries`

Type: **DWORD**

Specifies a **DWORD** variable that indicates the number of times the fax server will attempt to retransmit an outgoing fax if the initial transmission fails.

### `RetryDelay`

Type: **DWORD**

Specifies a **DWORD** variable that indicates the number of minutes that will elapse between retransmission attempts by the fax server.

### `DirtyDays`

Type: **DWORD**

Specifies a **DWORD** variable that indicates the number of days the fax server will retain an unsent job in the fax job queue. A transmission might not be sent, for example, if an invalid fax number or date is specified, or if the sending device receives a busy signal multiple times.

### `Branding`

Type: **BOOL**

Specifies a Boolean variable that indicates whether the fax server should generate a brand (banner) at the top of outgoing fax transmissions. If this member is **TRUE**, the fax server generates a brand that contains transmission-related information like the transmitting station identifier, date, time, and page count.

### `UseDeviceTsid`

Type: **BOOL**

Specifies a Boolean variable that indicates whether the fax server will use the device's transmitting station identifier instead of the value specified in the **Tsid** member of the [FAX_JOB_PARAM](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_job_parama) structure. If this member is **TRUE**, the server uses the device's transmitting station identifier.

### `ServerCp`

Type: **BOOL**

Specifies a Boolean variable that indicates whether fax client applications can include a user-designed cover page with the fax transmission. If this member is **TRUE**, the client must use a common cover page stored on the fax server. If this member is **FALSE**, the client can use a personal cover page file.

### `PauseServerQueue`

Type: **BOOL**

Specifies a Boolean variable that indicates whether the fax server has paused the fax job queue. If this member is **TRUE**, the queue has been paused.

### `StartCheapTime`

Type: **[FAX_TIME](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_time)**

Specifies a [FAX_TIME](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_time) structure that indicates the hour and minute at which the discount period begins. The discount period applies only to outgoing transmissions.

### `StopCheapTime`

Type: **[FAX_TIME](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_time)**

Specifies a [FAX_TIME](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_time) structure that indicates the hour and minute at which the discount period ends. The discount period applies only to outgoing transmissions.

### `ArchiveOutgoingFaxes`

Type: **BOOL**

Specifies a Boolean variable that indicates whether the fax server should archive outgoing fax transmissions. If this member is **TRUE**, the server archives outgoing transmissions in the directory specified by the **ArchiveDirectory** member.

### `ArchiveDirectory`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that contains the fully qualified path of the directory in which outgoing fax transmissions will be archived. The path can be a UNC path or a path beginning with a drive letter. The fax server ignores this member if the **ArchiveOutgoingFaxes** member is **FALSE**. This member can be **NULL** if the **ArchiveOutgoingFaxes** member is **FALSE**.

### `Reserved`

#### - InboundProfile

Type: **LPCSTR**

The inbound routing profile used for email.

## Remarks

The fax client application passes the **FAX_CONFIGURATION** structure in a call to the [FaxSetConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsetconfigurationa) function to change the global configuration settings for the fax server of interest. If the application calls the [FaxGetConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxgetconfigurationa) function, it returns the current settings in a **FAX_CONFIGURATION** structure. For more information, see [Fax Server Configuration Management](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-server-configuration-management).

> [!NOTE]
> The winfax.h header defines FAX_CONFIGURATION as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[FAX_JOB_PARAM](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_job_parama)

[FAX_TIME](https://learn.microsoft.com/windows/desktop/api/winfax/ns-winfax-fax_time)

[Fax Service Client API Structures](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-structures)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxGetConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxgetconfigurationa)

[FaxSetConfiguration](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsetconfigurationa)