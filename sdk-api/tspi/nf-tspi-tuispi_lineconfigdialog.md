# TUISPI_lineConfigDialog function

## Description

The
**TUISPI_lineConfigDialog** function causes the provider of the specified line device to display a modal dialog box as a child window of *hwndOwner* to allow the user to configure parameters related to the line device. This function makes the
[TSPI_lineConfigDialog](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineconfigdialog) function obsolete in version 2.0 and later (supported in version 1.4 and earlier).

Implementation is optional.

## Parameters

### `lpfnUIDLLCallback`

Pointer to a function the UI DLL can call to communicate with the service provider DLL to obtain information needed to display the dialog box and to send updated configuration to the service provider.

### `dwDeviceID`

The line device to be configured.

### `hwndOwner`

A handle to a parent window in which the dialog box window is to be placed.

### `lpszDeviceClass`

A pointer to a **null**-terminated string that identifies a device class name. This device class allows the caller to select a specific subscreen of configuration information applicable to that device class. If this parameter is **NULL** or an empty string, the highest level configuration dialog box should be selected. The permitted strings are the same as for
[TSPI_lineGetID](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetid). For example, if the line supports the Comm API, passing comm/datamodem as *lpszDeviceClass* causes the provider to display the parameters related specifically to Comm (or, at least, to start at the corresponding point in a multilevel configuration dialog box chain, so that the user doesn't have to search to find the desired parameters.)

## Return value

Returns zero if the function succeeds or an error number if an error occurs. Possible return values are as follows:

LINEERR_INUSE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALDEVICECLASS, LINEERR_OPERATIONFAILED, LINEERR_NOMEM, LINEERR_RESOURCEUNAVAIL.

## Remarks

There is no restriction that
**TUISPI_lineConfigDialog** be called only when the line is closed. However, each provider can impose such a restriction itself. When
**TUISPI_lineConfigDialog** is called, the provider could alert the user with the message "The line is in use by one or more applications. You may not change the line configuration while the line is in use" (and return the error message LINEERR_INUSE). However, some configurations may be safe to change "on the fly," particularly those related to media types (such as the modem error control protocol), especially when that media type is not currently in use. The provider could allow those options to be changed while the line is open.

Users should not be allowed to change anything that alters values returned with
[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps) or
[LINEADDRESSCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineaddresscaps) without first forcibly closing the line as a signal that applications must call functions that return these structures in order to have accurate information.

## See also

[LINEADDRESSCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineaddresscaps)

[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps)

[TSPI_lineGetDevConfig](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetdevconfig)

[TSPI_lineGetID](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetid)

[TSPI_lineSetDevConfig](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linesetdevconfig)