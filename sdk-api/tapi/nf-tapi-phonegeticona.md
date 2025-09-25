# phoneGetIconA function

## Description

The
**phoneGetIcon** function allows an application to retrieve a service phone device-specific (or provider-specific) icon that can be displayed to the user.

## Parameters

### `dwDeviceID`

Identifier of the phone device whose icon is requested.

### `lpszDeviceClass`

Pointer to a **null**-terminated string that identifies a device class name. This device class allows the application to select a specific sub-icon applicable to that device class. This parameter is optional and can be left **NULL** or empty, in which case the highest-level icon associated with the phone device rather than a specified media stream device would be selected.

### `lphIcon`

Pointer to a memory location in which the handle to the icon is returned.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

PHONEERR_BADDEVICEID, PHONEERR_RESOURCEUNAVAIL, PHONEERR_INVALPOINTER, PHONEERR_OPERATIONFAILED, PHONEERR_INVALDEVICECLASS, PHONEERR_UNINITIALIZED, PHONEERR_NOMEM, PHONEERR_NODEVICE.

## Remarks

The
**phoneGetIcon** function causes the provider to return a handle (in *lphIcon*) to an icon resource (obtained from
[LoadIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadicona)) associated with the specified phone. The icon handle is for a resource associated with the provider; the application must use
[CopyIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-copyicon) if it wants to reference the icon after the provider is unloaded, which is unlikely to happen as long as the application has the phone open.

The *lpszDeviceClass* parameter allows the provider to return different icons based on the type of service being referenced by the caller. The permitted strings are the same as for
[phoneGetID](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegetid). For example, if the phone supports the Comm API, passing "COMM" as *lpszDeviceClass* causes the provider to return an icon related specifically to the Comm device functions of the service provider. The parameters "tapi/phone", "", or **NULL** can be used to request the icon for the phone service.

For applications using a TAPI version earlier than 2.0, if the provider does not return an icon (whether because the given device class is invalid or the provider does not support icons), TAPI substitutes a generic Telephony phone device icon. For applications using TAPI version 2.0 or later, TAPI substitutes the default phone icon only if the *lpszDeviceClass* parameter is "tapi/phone", "", or **NULL**. For any other device class, if the given device class is not valid or the provider does not support icons for the class,
**phoneGetIcon** returns PHONEERR_INVALDEVICECLASS.

> [!NOTE]
> The tapi.h header defines phoneGetIcon as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Supplementary Phone Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-phone-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[phoneGetID](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegetid)