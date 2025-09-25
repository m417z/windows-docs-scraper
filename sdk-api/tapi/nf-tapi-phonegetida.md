# phoneGetIDA function

## Description

The
**phoneGetID** function returns a device identifier for the given device class associated with the specified phone device.

## Parameters

### `hPhone`

Handle to an open phone device.

### `lpDeviceID`

Pointer to a data structure of type
[VARSTRING](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-varstring) where the device identifier is returned. Upon successful completion of the request, this location is filled with the device identifier. The format of the returned information depends on the method used by the device class (API) for naming devices.

### `lpszDeviceClass`

Pointer to a null-terminated string that specifies the device class of the device whose identifier is requested. Valid device class strings are those used in the System.ini section to identify device classes.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

PHONEERR_INVALPHONEHANDLE, PHONEERR_NOMEM, PHONEERR_INVALPOINTER, PHONEERR_RESOURCEUNAVAIL, PHONEERR_INVALDEVICECLASS, PHONEERR_UNINITIALIZED, PHONEERR_OPERATIONFAILED, PHONEERR_STRUCTURETOOSMALL, PHONEERR_OPERATIONUNAVAIL.

## Remarks

The
**phoneGetID** function can be used to retrieve a phone device identifier given a phone handle. It can also be used to obtain the device identifier of the media device (for device classes such as COM, wave, MIDI, phone, line, or NDIS) associated with the opened phone device. The names of these device class are not case sensitive. This identifier can then be used with the appropriate media API to select the corresponding device.

See
[TAPI Device Classes](https://learn.microsoft.com/windows/desktop/Tapi/tapi-device-classes) for device class names.

A vendor that defines a device-specific media type also needs to define the corresponding device-specific (proprietary) API to manage devices of the media type. To avoid collisions on device class names assigned independently by different vendors, a vendor should select a name that uniquely identifies both the vendor and, following it, the media type. For example: "intel/video".

> [!NOTE]
> The tapi.h header defines phoneGetID as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Supplementary Phone Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-phone-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[VARSTRING](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-varstring)