# lineGetIconW function

## Description

The
**lineGetIcon** function allows an application to retrieve a service line device-specific (or provider-specific) icon for display to the user.

## Parameters

### `dwDeviceID`

Identifier of the line device whose icon is requested.

### `lpszDeviceClass`

Pointer to a **null**-terminated string that identifies a device class name. This device class allows the application to select a specific sub-icon applicable to that device class. This parameter is optional and can be left **NULL** or empty, in which case the highest-level icon associated with the line device rather than a specified media stream device would be selected.

### `lphIcon`

Pointer to a memory location in which the handle to the icon is returned.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

LINEERR_BADDEVICEID, LINEERR_OPERATIONFAILED, LINEERR_INVALPOINTER, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALDEVICECLASS, LINEERR_UNINITIALIZED, LINEERR_NOMEM, LINEERR_NODEVICE.

## Remarks

The
**lineGetIcon** function causes the provider to return a handle (in *lphIcon*) to an icon resource (obtained from
[LoadIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadicona)) that is associated with the specified line. The icon handle is for a resource associated with the provider. The application must use
[CopyIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-copyicon) if it wants to reference the icon after the provider is unloaded, which is unlikely to happen as long as the application has the line open.

The *lpszDeviceClass* parameter allows the provider to return different icons based on the type of service being referenced by the caller. The permitted strings are the same as for
[lineGetID](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetid). For example, if the line supports the Comm API, passing "COMM" as *lpszDeviceClass* causes the provider to return an icon related specifically to the Comm device functions of the service provider. The parameters "tapi/line", "", or **NULL** can be used to request the icon for the line service.

For applications using an API version earlier than 2.0, if the provider does not return an icon (whether because the given device class is invalid or the provider does not support icons), TAPI substitutes a generic Telephony line device icon. For applications using API version 2.0 or later, TAPI substitutes the default line icon only if the *lpszDeviceClass* parameter is "tapi/line", "" or **NULL**. For any other device class, if the given device class is not valid or the provider does not support icons for the class,
**lineGetIcon** returns LINEERR_INVALDEVICECLASS.

> [!NOTE]
> The tapi.h header defines lineGetIcon as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Basic Telephony Services Reference](https://learn.microsoft.com/windows/desktop/Tapi/basic-telephony-services-reference)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[lineGetID](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetid)