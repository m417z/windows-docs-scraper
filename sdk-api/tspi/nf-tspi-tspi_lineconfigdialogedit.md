# TSPI_lineConfigDialogEdit function

## Description

The
**TSPI_lineConfigDialogEdit** function is obsolete. TAPI version 1.4 or earlier service providers can implement this TSPI function. TAPI version 2.0 or later TSPs implement
[TUISPI_lineConfigDialogEdit](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tuispi_lineconfigdialogedit).

The
**TSPI_lineConfigDialogEdit** function causes the provider of the specified line device to display a modal dialog box as a child window of *hwndOwner* to allow the user to configure parameters related to the line device.

## Parameters

### `dwDeviceID`

The line device to be configured.

### `hwndOwner`

A handle to a window to which the dialog box is to be attached.

### `lpszDeviceClass`

A pointer to a **null**-terminated Unicode string that identifies a device class name. This device class allows the caller to select a specific subscreen of configuration information applicable to that device class. If this parameter is **NULL** or points to an empty string, the highest level configuration is selected. The permitted strings are the same as for
[TSPI_lineGetID](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetid).

### `lpDeviceConfigIn`

A pointer to the opaque configuration data structure that was returned by
[TSPI_lineGetDevConfig](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetdevconfig) (or a previous invocation of
**TSPI_lineConfigDialogEdit**) in the variable portion of the
[VARSTRING](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-varstring) structure.

### `dwSize`

The number of bytes in the structure pointed to by *lpDeviceConfigIn*. This value is returned in the **dwStringSize** member in the
[VARSTRING](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-varstring) structure returned by
[TSPI_lineGetDevConfig](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetdevconfig) or a previous invocation of
**TSPI_lineConfigDialogEdit**.

### `lpDeviceConfigOut`

A pointer to the memory location of type
[VARSTRING](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-varstring) where the device configuration structure is returned. Upon successful completion of the request, this location is filled with the device configuration. The **dwStringFormat** member in the
[VARSTRING](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-varstring) structure is set to STRINGFORMAT_BINARY. Prior to calling
[lineGetDevConfig](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetdevconfig) (or a future invocation of
[lineConfigDialogEdit](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineconfigdialogedit)), the application should set the **dwTotalSize** member of this structure to indicate the amount of memory available to TAPI for returning information.

## Return value

Returns zero if the request succeeds or an error number if an error occurs. Possible return values are:

LINEERR_INVALDEVICECLASS, LINEERR_OPERATIONFAILED, LINEERR_INVALPARAM, LINEERR_RESOURCEUNAVAIL, LINEERR_NODRIVER, LINEERR_OPERATIONUNAVAIL, LINEERR_NOMEM.

## Remarks

This function causes the service provider to display a modal dialog box (attached to *hwndOwner*) to allow the user to configure parameters related to the line specified by *dwDeviceID*.

The *lpszDeviceClass* parameter selects a specific subscreen of configuration information applicable to the device class in which the user is interested; the permitted strings are the same as for
[TSPI_lineGetID](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetid). For example, if the line supports the Comm API, passing comm/datamodem as *lpszDeviceClass* causes the provider to display the parameters related specifically to Comm (or, at least, start at the corresponding point in a multilevel configuration dialog box chain, so the user doesn't have to "dig" to find the parameters of interest).

The *lpszDeviceClass* parameter is "tapi/line", "", or **NULL** to cause the provider to display the highest level configuration for the line.

The difference between this function and
[TSPI_lineConfigDialog](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineconfigdialog) is the source of the parameters to edit and the result of the editing. In
**TSPI_lineConfigDialog**, the parameters edited are those currently in use on the device (or set for use on the next call), and any changes made have (to the maximum extent possible) an immediate impact on any active connection; also, the application must use
[lineGetDevConfig](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetdevconfig) to fetch the result of parameter changes from
**TSPI_lineConfigDialog**. With
**TSPI_lineConfigDialogEdit**, the parameters to edit are passed in from the application, and the results are returned to the application, with no impact on active connections; the results of the editing are returned with this function, and the application does not need to call
[lineGetDevConfig](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetdevconfig). Thus,
**TSPI_lineConfigDialogEdit** permits an application to provide the ability for the user to set up parameters for future calls without having an impact on any active call. However, the output of this function can be passed to
[TSPI_lineSetDevConfig](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linesetdevconfig) to affect the current call or next call.

For backward compatibility, this function is not exported by older service providers. TAPI detects this condition and reports LINEERR_OPERATIONUNAVAIL if an application attempts to call this function on an older provider.

## See also

[TSPI_lineConfigDialog](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineconfigdialog)

[TSPI_lineGetDevConfig](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetdevconfig)

[TSPI_lineGetID](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetid)

[TSPI_lineSetDevConfig](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linesetdevconfig)

[VARSTRING](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-varstring)