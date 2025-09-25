# lineConfigDialogA function

## Description

The
**lineConfigDialog** function causes the provider of the specified line device to display a dialog box (attached to *hwndOwner* of the application) to allow the user to configure parameters related to the line device.

## Parameters

### `dwDeviceID`

Identifier of the line device to be configured.

### `hwndOwner`

Handle to a window to which the dialog box is to be attached. Can be **NULL** to indicate that any window created during the function should have no owner window.

### `lpszDeviceClass`

Pointer to a **null**-terminated string that identifies a device class name. This device class allows the application to select a specific subscreen of configuration information applicable to that device class. This parameter is optional and can be left **NULL** or empty, in which case the highest level configuration is selected.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

LINEERR_BADDEVICEID, LINEERR_NOMEM, LINEERR_INUSE, LINEERR_OPERATIONFAILED, LINEERR_INVALDEVICECLASS, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALPARAM, LINEERR_UNINITIALIZED, LINEERR_INVALPOINTER, LINEERR_OPERATIONUNAVAIL, LINEERR_NODEVICE.

## Remarks

The
**lineConfigDialog** function causes the service provider to display a modal dialog box (attached to *hwndOwner* of the application) to allow the user to configure parameters related to the line specified by *dwDeviceID*. The *lpszDeviceClass* parameter allows the application to select a specific subscreen of configuration information applicable to the device class in which the user is interested; the permitted strings are the same as for
[lineGetID](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetid). For example, if the line supports the Comm API, passing "COMM" as *lpszDeviceClass* causes the provider to display the parameters related specifically to Comm (or, at least, start at the corresponding point in a multilevel configuration dialog box chain, so the user doesn't have to "dig" to find the parameters of interest).

The *lpszDeviceClass* parameter would be "tapi/line" , "", or **NULL** to cause the provider to display the highest level configuration for the line.

> [!NOTE]
> The tapi.h header defines lineConfigDialog as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Basic Telephony Services Reference](https://learn.microsoft.com/windows/desktop/Tapi/basic-telephony-services-reference)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[lineGetID](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetid)