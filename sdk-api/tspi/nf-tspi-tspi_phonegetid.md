# TSPI_phoneGetID function

## Description

The
**TSPI_phoneGetID** function returns a device identifier for the given device class associated with the specified phone device.

## Parameters

### `hdPhone`

The handle to the phone to be queried.

### `lpDeviceID`

A pointer to a data structure of type
[VARSTRING](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-varstring) where the device identifier is returned. The format of the returned information depends on the method used by the device class (API) for naming devices. Prior to calling
**TSPI_phoneGetID**, the application sets the **dwTotalSize** member of this structure to indicate the amount of memory available to TAPI for returning information.

### `lpszDeviceClass`

A pointer to a null-terminated Unicode string that specifies the device class of the device whose identifier is requested.

### `hTargetProcess`

The process handle of the application on behalf of which the
**TSPI_phoneGetID** function is being invoked. If the information being returned in the
[VARSTRING](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-varstring) structure includes a handle for use by the application, the service provider creates or duplicates the handle for the process.

## Return value

Returns zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

PHONEERR_INVALPHONEHANDLE, PHONEERR_RESOURCEUNAVAIL, PHONEERR_INVALDEVICECLASS, PHONEERR_OPERATIONFAILED, PHONEERR_NOMEM, PHONEERR_OPERATIONUNAVAIL.

## Remarks

This operation can be used to retrieve a phone device identifier given a phone handle. It can also be used to obtain the device identifier of the media device (for device classes such as COM, wave, MIDI, phone, line, and mciwave) associated with the opened phone device. This identifier can then be used with the appropriate media API (such as mci, midi, and wav) to select the corresponding device. For more information about common device class names, see
[TSPI Device Classes](https://learn.microsoft.com/windows/desktop/Tapi/tspi-device-classes).

The service provider fills in all the members of the
[VARSTRING](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-varstring) data structure, except for **dwTotalSize**, which is filled in by TAPI. The service provider must not overwrite the **dwTotalSize** member.

The service provider does not need to be concerned with handling tapi/line and tapi/phone device classes because TAPI handles these for the service provider. Therefore, code for handling these device classes is optional.

## See also

[VARSTRING](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-varstring)