# phoneInitialize function

## Description

The
**phoneInitialize** function is obsolete. It continues to be exported by Tapi.dll and Tapi32.dll for backward compatibility with applications using TAPI versions 1.3 and 1.4.

Applications using TAPI version 2.0 or later must use
[phoneInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phoneinitializeexa) instead.

**For TAPI Versions 1.4 and Earlier:** The
**phoneInitialize** function initializes the application's use of TAPI for the subsequent use of the phone functions in the Telephony API. It registers the application's specified notification mechanism and returns the number of phone devices that are available to the application.

## Parameters

### `lphPhoneApp`

Pointer to a location that is filled with the application's usage handle for TAPI.

### `hInstance`

Instance handle of the client application or DLL.

### `lpfnCallback`

Address of a callback function that is invoked to determine status and events on the phone device.

### `lpszAppName`

Pointer to a **null**-terminated string that contains displayable characters. If this parameter is non-**NULL**, it contains an application-supplied name of the application. This name is provided in the
[PHONESTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonestatus) structure to indicate, in a user-friendly way, which application is the current owner of the phone device. This information can be useful for logging and status reporting purposes. If *lpszAppName* is **NULL**, the application's filename is used instead.

### `lpdwNumDevs`

Pointer to **DWORD**. This location is loaded with the number of phone devices available to the application.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

PHONEERR_INVALAPPNAME, PHONEERR_INIFILECORRUPT, PHONEERR_INVALPOINTER, PHONEERR_NOMEM, PHONEERR_OPERATIONFAILED, PHONEERR_REINIT, PHONEERR_RESOURCEUNAVAIL, PHONEERR_NODEVICE, PHONEERR_NODRIVER, PHONEERR_INVALPARAM

## Remarks

The application can refer to individual phone devices by using phone device identifiers that range from zero to *dwNumDevs* minus one. An application should not assume that these phone devices are capable of anything beyond what is specified by the Assisted Telephony subset without first querying their device capabilities with the
[phoneGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegetdevcaps) function.

Applications should not invoke
**phoneInitialize** without subsequently opening a phone (at least for monitoring). If the application is not monitoring and not using any devices, it should call
[phoneShutdown](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phoneshutdown) so that memory resources allocated by TAPI can be released if unneeded, and TAPI itself can be unloaded from memory while not needed.

Another reason for performing a
**phoneShutdown** is that if a user changes the device configuration (adds or removes a line or phone), there is no way for TAPI to notify an application that has a line or phone handle open at the time. After a reconfiguration has taken place, causing a PHONESTATE_REINIT message to be sent, no applications can open a device until all applications have performed a
**phoneShutdown**.

If any service provider fails to initialize properly, the
**phoneInitialize** function fails and returns the error indicated by the service provider. If the PHONEERR_INVALPARAM error value is returned, the specified *hInstance* parameter is invalid.

## See also

[PHONESTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonestatus)

[phoneGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegetdevcaps)

[phoneInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phoneinitializeexa)

[phoneShutdown](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phoneshutdown)