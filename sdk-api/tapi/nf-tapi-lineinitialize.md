# lineInitialize function

## Description

The
**lineInitialize** function is obsolete. It continues to be exported by Tapi.dll and Tapi32.dll for backward compatibility with applications using API versions 1.3 and 1.4.

Applications using API version 2.0 or later must use
[lineInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineinitializeexa) instead.

**For TAPI Versions 1.4 and Earlier:**  The
**lineInitialize** function initializes the application's use of Tapi.dll for subsequent use of the line abstraction. The function registers the application's specified notification mechanism and returns the number of line devices available to the application. A line device is any device that provides an implementation for the line-prefixed functions in TAPI.

## Parameters

### `lphLineApp`

Pointer to a location that is filled with the application's usage handle for TAPI.

### `hInstance`

Instance handle of the client application or DLL.

### `lpfnCallback`

Address of a callback function that is invoked to determine status and events on the line device, addresses, or calls. For more information, see
[lineCallbackFunc](https://learn.microsoft.com/windows/desktop/api/tapi/nc-tapi-linecallback).

### `lpszAppName`

Pointer to a **null**-terminated text string that contains only displayable characters. If this parameter is not **NULL**, it contains an application-supplied name for the application. This name is provided in the
[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo) structure to indicate, in a user-friendly way, which application originated, or originally accepted or answered the call. This information can be useful for call logging purposes. If *lpszAppName* is **NULL**, the application's file name is used instead.

### `lpdwNumDevs`

Pointer to a **DWORD**-sized location. Upon successful completion of this request, this location is filled with the number of line devices available to the application.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

LINEERR_INVALAPPNAME, LINEERR_OPERATIONFAILED, LINEERR_INIFILECORRUPT, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALPOINTER, LINEERR_REINIT, LINEERR_NODRIVER, LINEERR_NODEVICE, LINEERR_NOMEM, LINEERR_NOMULTIPLEINSTANCE.

## Remarks

If LINEERR_REINIT is returned and TAPI reinitialization has been requested (for example as a result of adding or removing a telephony service provider), then
**lineInitialize** requests are rejected with this error until the last application shuts down its usage of the API (using
[lineShutdown](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineshutdown)). At that time, the new configuration becomes effective and applications are once again permitted to call
**lineInitialize**. If the LINEERR_INVALPARAM error value is returned, the specified *hInstance* parameter is invalid.

The application can refer to individual line devices by using line device identifiers that range from zero to *dwNumDevs* minus one. An application should not assume that these line devices are capable of anything beyond what is specified by the Basic Telephony subset without first querying their device capabilities using
[lineGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetdevcaps) and
[lineGetAddressCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetaddresscaps).

Applications should not invoke
**lineInitialize** without subsequently opening a line (at least for monitoring). If the application is not monitoring and not using any devices, it should call
[lineShutdown](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineshutdown) so that memory resources allocated by Tapi.dll can be released if unneeded, and Tapi.dll itself can be unloaded from memory while not needed.

Another reason for performing a
[lineShutdown](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineshutdown) is that if a user changes the device configuration (adds or removes a line or phone), there is no way for TAPI to notify an application that has a line or phone handle open at the time. After a reconfiguration has taken place, causing a LINEDEVSTATE_REINIT message to be sent, no applications can open a device until all applications have performed a
[lineShutdown](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineshutdown). If any service provider fails to initialize properly, this function fails and returns the error indicated by the service provider.

On all TAPI platforms,
**lineInitialize** is equivalent to
[lineInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineinitializeexa) using the LINEINITIALIZEEXOPTION_USEHIDDENWINDOW option.

## See also

[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo)

[lineCallbackFunc](https://learn.microsoft.com/windows/desktop/api/tapi/nc-tapi-linecallback)

[lineGetAddressCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetaddresscaps)

[lineGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetdevcaps)

[lineInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineinitializeexa)

[lineShutdown](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineshutdown)