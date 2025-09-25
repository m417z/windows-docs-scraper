# lineConfigDialogEditW function

## Description

The
**lineConfigDialogEdit** function causes the provider of the specified line device to display a dialog box (attached to *hwndOwner* of the application) to allow the user to configure parameters related to the line device.

## Parameters

### `dwDeviceID`

Identifier of the line device to be configured.

### `hwndOwner`

Handle to a window to which the dialog box is to be attached. Can be **NULL** to indicate that any window created during the function should have no owner window.

### `lpszDeviceClass`

Pointer to a **null**-terminated string that identifies a device class name. This device class allows the application to select a specific subscreen of configuration information applicable to that device class. This parameter is optional and can be left **NULL** or empty, in which case the highest level configuration is selected.

### `lpDeviceConfigIn`

Pointer to the opaque configuration data structure that was returned by
[lineGetDevConfig](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetdevconfig) (or a previous invocation of
**lineConfigDialogEdit**) in the variable portion of the
[VARSTRING](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-varstring) structure.

### `dwSize`

Number of bytes in the structure pointed to by *lpDeviceConfigIn*. This value is returned in the **dwStringSize** member in the
[VARSTRING](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-varstring) structure returned by
[lineGetDevConfig](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetdevconfig) or a previous invocation of
**lineConfigDialogEdit**.

### `lpDeviceConfigOut`

Pointer to the memory location of type
[VARSTRING](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-varstring) where the device configuration structure is returned. Upon successful completion of the request, this location is filled with the device configuration. The **dwStringFormat** member in the
**VARSTRING** structure is set to STRINGFORMAT_BINARY. Prior to calling
[lineGetDevConfig](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetdevconfig) (or a future invocation of
**lineConfigDialogEdit**), the application should set the **dwTotalSize** member of this structure to indicate the amount of memory available to TAPI for returning information.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

LINEERR_BADDEVICEID, LINEERR_OPERATIONFAILED, LINEERR_INVALDEVICECLASS, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALPARAM, LINEERR_STRUCTURETOOSMALL, LINEERR_INVALPOINTER, LINEERR_UNINITIALIZED, LINEERR_NODRIVER, LINEERR_OPERATIONUNAVAIL, LINEERR_NOMEM, LINEERR_NODEVICE.

## Remarks

If LINEERR_STRUCTURETOOSMALL is returned, the **dwTotalSize** member of the
[VARSTRING](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-varstring) structure pointed to by *lpDeviceConfigOut* does not specify enough memory to contain the entire configuration structure. The **dwNeededSize** member has been set to the amount required. To the extent that user entries were reflected in information that could not be returned due to insufficient space, those edits are lost; applications should therefore allocate the maximum amount of space that may be needed by the device class to return its configuration structure (for more information, see
[TAPI Device Classes](https://learn.microsoft.com/windows/desktop/Tapi/tapi-device-classes)).

The
**lineConfigDialogEdit** function causes the service provider to display a modal dialog box (attached to *hwndOwner* of the application) to allow the user to configure parameters related to the line specified by *dwDeviceID*.

The *lpszDeviceClass* parameter allows the application to select a specific subscreen of configuration information applicable to the device class in which the user is interested; the permitted strings are the same as for
[lineGetID](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetid). For example, if the line supports the Comm API, passing "COMM" as *lpszDeviceClass* causes the provider to display the parameters related specifically to Comm (or, at least, start at the corresponding point in a multilevel configuration dialog box chain, so the user doesn't have to "dig" to find the parameters of interest).

The *lpszDeviceClass* parameter would be "tapi/line" , "", or **NULL** to cause the provider to display the highest level configuration for the line.

The difference between this function and
[lineConfigDialog](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineconfigdialog) is the source of the parameters to edit and the result of the editing. In
**lineConfigDialog**, the parameters edited are those currently in use on the device (or set for use on the next call), and any changes made have (to the maximum extent possible) an immediate impact on any active connection; also, the application must use
[lineGetDevConfig](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetdevconfig) to fetch the result of parameter changes from
[lineConfigDialog](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineconfigdialog). With
**lineConfigDialogEdit**, the parameters to edit are passed in from the application, and the results are returned to the application, with no impact on active connections; the results of the editing are returned with this function, and the application does not need to call
**lineGetDevConfig**. Thus,
**lineConfigDialogEdit** permits an application to provide the ability for the user to set up parameters for future calls without having an impact on any active call. However, the output of this function can be passed to
[lineSetDevConfig](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetdevconfig) to affect the current call or next call.

> [!NOTE]
> The tapi.h header defines lineConfigDialogEdit as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Basic Telephony Services Reference](https://learn.microsoft.com/windows/desktop/Tapi/basic-telephony-services-reference)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[VARSTRING](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-varstring)

[lineConfigDialog](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineconfigdialog)

[lineGetDevConfig](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetdevconfig)

[lineGetID](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetid)

[lineSetDevConfig](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetdevconfig)