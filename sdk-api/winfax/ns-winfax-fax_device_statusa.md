# FAX_DEVICE_STATUSA structure

## Description

The **FAX_DEVICE_STATUS** structure contains information about the current status of a fax device. In addition to the status, the structure also includes data on whether the device is currently sending or receiving a fax transmission, device and station identifiers, sender and recipient names, and routing information.

## Members

### `SizeOfStruct`

Type: **DWORD**

Specifies the size, in bytes, of the **FAX_DEVICE_STATUS** structure. The fax service sets this member to **sizeof(FAX_DEVICE_STATUS)**.

### `CallerId`

Type: **LPCTSTR**

If the **JobType** member is equal to the **JT_RECEIVE** job type, **CallerId** is a pointer to a null-terminated character string that identifies the calling device that sent the active fax document. This string can include the telephone number of the calling device.

### `Csid`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that specifies the called station identifier of the device.

### `CurrentPage`

Type: **DWORD**

Specifies a **DWORD** variable that indicates the number of the page in the fax transmission that the fax device is currently sending or receiving. The page count is relative to one.

### `DeviceId`

Type: **DWORD**

Specifies a **DWORD** variable that indicates the permanent line identifier for the fax device of interest.

### `DeviceName`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that specifies the name of the fax device of interest.

### `DocumentName`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string to associate with the fax document that the device is currently sending or receiving. This is the user-friendly name that appears in the print spooler.

### `JobType`

Type: **DWORD**

Specifies a **DWORD** variable that identifies the type of fax job that is currently active on the device. This member can be one of the following job types.

#### JT_SEND

The fax device is sending a fax document.

#### JT_RECEIVE

The fax device is receiving a fax document.

#### JT_UNKNOWN

The fax device is in an unknown or idle state.

### `PhoneNumber`

Type: **LPCTSTR**

If the **JobType** member is equal to the **JT_SEND** job type, **PhoneNumber** is a pointer to a constant null-terminated character string that is the fax number dialed for the outgoing fax transmission.

### `RoutingString`

Type: **LPCTSTR**

If the **JobType** member is equal to the **JT_RECEIVE** job type, **RoutingString** is a pointer to a constant null-terminated character string that specifies the routing string for an incoming fax. The string must be of the form:

`Canonical-Phone-Number[|Additional-Routing-Info]`

where `Canonical-Phone-Number` is defined in the [Address](https://learn.microsoft.com/windows/desktop/Tapi/address-ovr) topic of the TAPI documentation (see the Canonical Address subheading); and `Additional-Routing-Info` is the *subaddress* of a Canonical Address, and uses the subaddress format.

### `SenderName`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that specifies the name of the sender who initiated the fax transmission.

### `RecipientName`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that specifies the name of the recipient of the fax transmission.

### `Size`

Type: **DWORD**

Specifies a **DWORD** variable that indicates the size, in bytes, of the active fax document.

### `StartTime`

Type: **[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)**

Specifies a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the starting time of the current fax job expressed in UTC.

### `Status`

Type: **DWORD**

Specifies a **DWORD** variable that is a fax device status code or value. This member can be one of the predefined device status codes shown following.

#### FPS_DIALING

The device is dialing a fax number.

#### FPS_SENDING

The device is sending a fax document.

#### FPS_RECEIVING

The device is receiving a fax document.

#### FPS_COMPLETED

The device has completed sending or receiving a fax transmission.

#### FPS_UNAVAILABLE

The device is not available because it is in use by another application.

#### FPS_BUSY

The device has encountered a busy signal.

#### FPS_NO_ANSWER

The receiving device did not answer the call.

#### FPS_BAD_ADDRESS

The device dialed an invalid fax number.

#### FPS_NO_DIAL_TONE

The sending device cannot complete the call because it does not detect a dial tone.

#### FPS_DISCONNECTED

The fax call was disconnected by the sender or the caller.

#### FPS_FATAL_ERROR

The device encountered a fatal protocol error.

#### FPS_NOT_FAX_CALL

The device has received a data call or a voice call.

#### FPS_CALL_DELAYED

The device delayed a fax call because the sending device received a busy signal multiple times. The device cannot retry the call because dialing restrictions exist. (Some countries/regions restrict the number of retry attempts when a number is busy.)

#### FPS_CALL_BLACKLISTED

The device could not complete a call because the telephone number was blocked or reserved; numbers such as 911 are blocked.

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

### `StatusString`

Type: **LPCTSTR**

This member must be **NULL**.

### `SubmittedTime`

Type: **[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)**

Specifies a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that contains the time the client submitted the fax document for transmission to the fax job queue. The time is expressed in UTC.

### `TotalPages`

Type: **DWORD**

Specifies a **DWORD** variable that indicates the total number of pages in the fax transmission.

### `Tsid`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that specifies the transmitting station identifier (TSID). This identifier is usually a telephone number.

### `UserName`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that specifies the name of the user who submitted the active fax job.

## Remarks

The fax client application can call the [FaxGetDeviceStatus](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxgetdevicestatusa) function to retrieve status information for the fax device of interest. The function returns the information in a **FAX_DEVICE_STATUS** structure.

For more information, see [Fax Device Management](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-device-management). For information about the status information a fax service provider supplies for an active fax operation, see the [FAX_DEV_STATUS](https://learn.microsoft.com/windows/desktop/api/faxdev/ns-faxdev-fax_dev_status) topic.

> [!NOTE]
> The winfax.h header defines FAX_DEVICE_STATUS as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)

[Fax Service Client API Structures](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-structures)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxGetDeviceStatus](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxgetdevicestatusa)