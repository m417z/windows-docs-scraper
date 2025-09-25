# phoneOpen function

## Description

The
**phoneOpen** function opens the specified phone device. A phone device can be opened using either owner privilege or monitor privilege. An application that opens the phone with owner privilege can control the phone's lamps, display, ringer, and hookswitch or hookswitches. An application that opens the phone device with monitor privilege is notified only about events that occur at the phone, such as hookswitch changes or button presses.

Ownership of a phone device is exclusive. In other words, only one application can have a phone device opened with owner privilege at a time. The phone device can, however, be opened multiple times with monitor privilege.

## Parameters

### `hPhoneApp`

Handle to the application's registration with TAPI.

### `dwDeviceID`

Identifier of the phone device to be opened.

### `lphPhone`

Pointer to an HPHONE handle that identifies the open phone device. Use this handle to identify the device when invoking other phone control functions.

### `dwAPIVersion`

API version number under which the application and Telephony API have agreed to operate. This number is obtained from
[phoneNegotiateAPIVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonenegotiateapiversion).

### `dwExtVersion`

Extension version number under which the application and the service provider agree to operate. This number is zero if the application does not use any extensions. This number is obtained from
[phoneNegotiateExtVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonenegotiateextversion).

### `dwCallbackInstance`

User instance data passed back to the application with each message. This parameter is not interpreted by the Telephony API.

### `dwPrivilege`

Privilege requested. This parameter uses one and only one of the
[PHONEPRIVILEGE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/phoneprivilege--constants).

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

PHONEERR_ALLOCATED, PHONEERR_NODRIVER, PHONEERR_BADDEVICEID, PHONEERR_NOMEM, PHONEERR_INCOMPATIBLEAPIVERSION, PHONEERR_OPERATIONFAILED, PHONEERR_INCOMPATIBLEEXTVERSION, PHONEERR_OPERATIONUNAVAIL, PHONEERR_INVALAPPHANDLE, PHONEERR_RESOURCEUNAVAIL, PHONEERR_INVALPOINTER, PHONEERR_UNINITIALIZED, PHONEERR_INVALPRIVILEGE, PHONEERR_REINIT, PHONEERR_INUSE, PHONEERR_NODEVICE, PHONEERR_INIFILECORRUPT.

## Remarks

When opening a phone device with monitor privileges, the application is sent messages when events occur that change the status of the phone. Messages sent to the application include
[PHONE_BUTTON](https://learn.microsoft.com/windows/desktop/Tapi/phone-button) and
[PHONE_STATE](https://learn.microsoft.com/windows/desktop/Tapi/phone-state). The latter provides an indication of the phone's status item that has changed.

When opening a phone with owner privilege, the phone device can be manipulated in ways that affect the state of the phone device. An application should only open a phone using owner privilege if it actively wants to manipulate the phone device, and it should close the phone device when finished to allow other applications to control the phone.

When an application opens a phone device, it must specify the negotiated API version and, if it wants to use the phone's extensions, the phone's device-specific extension version. This version number should have been obtained with the
[phoneNegotiateAPIVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonenegotiateapiversion) and
[phoneNegotiateExtVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonenegotiateextversion) functions. Version numbering allows the mix and match of different application versions with different API versions and service-provider versions.

## See also

[PHONE_BUTTON](https://learn.microsoft.com/windows/desktop/Tapi/phone-button)

[PHONE_STATE](https://learn.microsoft.com/windows/desktop/Tapi/phone-state)

[Supplementary Phone Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-phone-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[phoneNegotiateAPIVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonenegotiateapiversion)

[phoneNegotiateExtVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonenegotiateextversion)