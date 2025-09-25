# lineSetDevConfigA function

## Description

The
**lineSetDevConfig** function allows the application to restore the configuration of a media stream device on a line device to a setup previously obtained using
[lineGetDevConfig](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetdevconfig). For example, the contents of this structure could specify data rate, character format, modulation schemes, and error control protocol settings for a "datamodem" media device associated with the line.

## Parameters

### `dwDeviceID`

Identifier of the line device to be configured.

### `lpDeviceConfig`

Pointer to the opaque configuration data structure that was returned by
[lineGetDevConfig](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetdevconfig) in the variable portion of the
[VARSTRING](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-varstring) structure.

### `dwSize`

Number of bytes in the structure pointed to by *lpDeviceConfig*. This value is returned in the **dwStringSize** member in the
[VARSTRING](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-varstring) structure returned by
[lineGetDevConfig](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetdevconfig).

### `lpszDeviceClass`

Pointer to a null-terminated string that specifies the device class of the device whose configuration is to be set. Valid device class strings are the same as those specified for the
[lineGetID](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetid) function.

## Return value

Returns zero if the function succeeds or a negative error number if an error occurs. Possible return values are:

LINEERR_BADDEVICEID, LINEERR_NODRIVER, LINEERR_INVALDEVICECLASS, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALPOINTER, LINEERR_OPERATIONFAILED, LINEERR_INVALPARAM, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALLINESTATE, LINEERR_UNINITIALIZED, LINEERR_NOMEM, LINEERR_NODEVICE.

## Remarks

Call states are device specific.

Typically, an application calls
[lineGetID](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetid) to identify the media stream device associated with a line, and then calls
[lineConfigDialog](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineconfigdialog) to allow the user to set up the device configuration. It could then call
[lineGetDevConfig](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetdevconfig) and save the configuration information in a phone book or other database associated with a particular call destination. When the user wants to call the same destination again, this
**lineSetDevConfig** function can be used to restore the configuration settings selected by the user. The
**lineSetDevConfig**,
**lineConfigDialog**, and
**lineGetDevConfig** functions can be used, in that order, to allow the user to view and update the settings.

The exact format of the data contained within the structure is specific to the line and media stream API (device class), is undocumented, and is undefined. The application must treat it as "opaque" and not manipulate the contents directly. Generally, the structure can be sent using this function only to the same device from which it was obtained. Certain telephony service providers may, however, permit structures to be interchanged between identical devices (that is, multiple ports on the same multiport modem card). Such interchangeability is not guaranteed in any way, even for devices of the same device class.

Some service providers may permit the configuration to be set while a call is active, and others may not.

> [!NOTE]
> The tapi.h header defines lineSetDevConfig as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Basic Telephony Services Reference](https://learn.microsoft.com/windows/desktop/Tapi/basic-telephony-services-reference)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[VARSTRING](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-varstring)

[lineConfigDialog](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineconfigdialog)

[lineGetDevConfig](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetdevconfig)

[lineGetID](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetid)