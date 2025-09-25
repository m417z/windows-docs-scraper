# phoneConfigDialogW function

## Description

The
**phoneConfigDialog** function causes the provider of the specified phone device to display a modal dialog box (attached to the application's *hwndOwner* parameter) that allows the user to configure parameters related to the phone device specified by *dwDeviceID*.

## Parameters

### `dwDeviceID`

Identifier of the phone device to be configured.

### `hwndOwner`

Handle to a window to which the dialog box is to be attached. Can be a **NULL** value to indicate that any window created during the function should have no owner window.

### `lpszDeviceClass`

Pointer to a **null**-terminated string that identifies a device class name. This device class allows the application to select a specific subscreen of configuration information applicable to that device class. This parameter is optional and can be left **NULL** or empty, in which case the highest level configuration is selected.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

PHONEERR_BADDEVICEID, PHONEERR_NOMEM, PHONEERR_INUSE, PHONEERR_OPERATIONFAILED, PHONEERR_INVALPARAM, PHONEERR_OPERATIONUNAVAIL, PHONEERR_INVALDEVICECLASS, PHONEERR_RESOURCEUNAVAIL, PHONEERR_INVALPOINTER, PHONEERR_UNINITIALIZED, PHONEERR_NODEVICE.

## Remarks

The *lpszDeviceClass* parameter allows the application to select a specific subscreen of configuration information applicable to the device class in which the user is interested; the permitted strings are the same as for
[phoneGetID](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegetid). For example, if the phone supports the wave API, passing "wave/in" as *lpszDeviceClass* would cause the provider to display the parameters related specifically to wave (or at least to start at the corresponding point in a multilevel configuration dialog box chain, eliminating the need to search for relevant parameters).

The *lpszDeviceClass* parameter should be "tapi/phone", "", or **NULL** to cause the provider to display the highest level configuration for the phone.

> [!NOTE]
> The tapi.h header defines phoneConfigDialog as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Supplementary Phone Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-phone-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[phoneGetID](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonegetid)