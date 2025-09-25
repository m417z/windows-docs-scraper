# FAX_PORT_INFOA structure

## Description

The **FAX_PORT_INFO** structure describes one fax port. The data includes, among other items, a device identifier, the port's name and current status, and station identifiers.

## Members

### `SizeOfStruct`

Type: **DWORD**

Specifies the size, in bytes, of the **FAX_PORT_INFO** structure. The calling application should ensure that this member is set to **sizeof(FAX_PORT_INFO)** before it calls the [FaxSetPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsetporta) function.

### `DeviceId`

Type: **DWORD**

Specifies a **DWORD** variable that indicates the permanent line identifier for the fax device of interest.

### `State`

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

### `Flags`

Type: **DWORD**

Specifies a **DWORD** variable that is a set of bit flags that specify the capability of the fax port. This member can be a combination of the following values.

#### FPF_RECEIVE

The device can receive faxes.

#### FPF_SEND

The device can send faxes.

#### FPF_VIRTUAL

The device is a virtual fax device. For more information, see [Virtual Fax Devices](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-virtual-fax-devices). Note that you cannot set a device to be virtual. When calling [FaxGetPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxgetporta), the **FAX_PORT_INFO** flag's **FPF_VIRTUAL** value indicates whether the device is virtual. When calling [FaxSetPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsetporta), the service will only relate to the **FPF_RECEIVE** and **FPF_SEND** values.

### `Rings`

Type: **DWORD**

Specifies a **DWORD** variable that indicates the number of times an incoming fax call should ring before the specified device answers the call. Possible values are from 0 to 99 inclusive. This value is ignored unless the **FPF_RECEIVE** port capability bit flag is set.

### `Priority`

Type: **DWORD**

Specifies a **DWORD** variable that determines the relative order in which available fax devices send outgoing transmissions. Valid values for this member are 1 through *n*, where *n* is the value of the *PortsReturned* parameter returned by a call to the [FaxEnumPorts](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxenumportsa) function.

When the fax server initiates an outgoing fax transmission, it attempts to select the device with the highest priority and **FPF_SEND** port capability. If that device is not available, the server selects the next available device that follows in rank order, and so on. The value of the **Priority** member has no effect on incoming transmissions.

### `DeviceName`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that specifies the name of the fax device of interest.

### `Tsid`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that specifies the TSID. This identifier is usually a telephone number. Only printable characters such as English letters, numeric symbols, and punctuation marks (ASCII range 0x20 to 0x7F) can be used in a TSID.

### `Csid`

Type: **LPCTSTR**

Pointer to a constant null-terminated character string that specifies the called station identifier (CSID). This identifier is usually a telephone number. Only printable characters such as English letters, numeric symbols, and punctuation marks (ASCII range 0x20 to 0x7F) can be used in a CSID.

## Remarks

A fax client application passes the **FAX_PORT_INFO** structure in a call to the [FaxSetPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsetporta) function to modify the configuration of the fax port of interest.

If an application calls the [FaxEnumPorts](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxenumportsa) function to enumerate all the fax devices currently attached to a fax server, the function returns an array of **FAX_PORT_INFO** structures. Each structure describes one device in detail. If an application calls the [FaxGetPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxgetporta) function to query one device, that function returns information about the device in one **FAX_PORT_INFO** structure. For more information, see [Fax Ports](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-ports) and [Fax Device Management](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-device-management).

> [!NOTE]
> The winfax.h header defines FAX_PORT_INFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Fax Service Client API Structures](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-structures)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxEnumPorts](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxenumportsa)

[FaxGetPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxgetporta)

[FaxSetPort](https://learn.microsoft.com/previous-versions/windows/desktop/api/winfax/nf-winfax-faxsetporta)

[Virtual Fax Devices](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-virtual-fax-devices)