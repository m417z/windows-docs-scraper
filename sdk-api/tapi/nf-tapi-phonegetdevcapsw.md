# phoneGetDevCapsW function

## Description

The
**phoneGetDevCaps** function queries a specified phone device to determine its telephony capabilities.

## Parameters

### `hPhoneApp`

Handle to the application's registration with TAPI.

### `dwDeviceID`

Identifier of the phone device to be queried.

### `dwAPIVersion`

Version number of the Telephony API to be used. The high-order word contains the major version number; the low-order word contains the minor version number. This number is obtained with the function
[phoneNegotiateAPIVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonenegotiateapiversion).

### `dwExtVersion`

Version number of the service provider-specific extensions to be used. This number is obtained with the function
[phoneNegotiateExtVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonenegotiateextversion). It can be left zero if no device-specific extensions are to be used. Otherwise, the high-order word contains the major version number; the low-order word contains the minor version number.

### `lpPhoneCaps`

Pointer to a variably sized structure of type
[PHONECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonecaps). Upon successful completion of the request, this structure is filled with phone device capabilities information.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

PHONEERR_INVALAPPHANDLE, PHONEERR_INVALPOINTER, PHONEERR_BADDEVICEID, PHONEERR_OPERATIONFAILED, PHONEERR_INCOMPATIBLEAPIVERSION, PHONEERR_OPERATIONUNAVAIL, PHONEERR_INCOMPATIBLEEXTVERSION, PHONEERR_NOMEM, PHONEERR_STRUCTURETOOSMALL, PHONEERR_RESOURCEUNAVAIL, PHONEERR_NODRIVER, PHONEERR_UNINITIALIZED, PHONEERR_NODEVICE.

## Remarks

Before using
**phoneGetDevCaps**, the application must negotiate the TAPI version number to use (see
[phoneNegotiateAPIVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonenegotiateapiversion)) and, optionally, the extension version to use (see
[phoneNegotiateExtVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonenegotiateextversion)).

TAPI and extension version numbers are those under which TAPI, Telephony DLL, and service provider must operate. If version ranges do not overlap, the application and API or service-provider versions are incompatible and an error is returned.

> [!NOTE]
> The tapi.h header defines phoneGetDevCaps as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[PHONECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonecaps)

[Supplementary Phone Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-phone-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[phoneNegotiateAPIVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonenegotiateapiversion)

[phoneNegotiateExtVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonenegotiateextversion)