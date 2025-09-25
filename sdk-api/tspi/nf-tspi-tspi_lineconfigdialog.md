# TSPI_lineConfigDialog function

## Description

The
**TSPI_lineConfigDialog** function is obsolete. TAPI version 1.4 or earlier service providers can implement this TSPI function. TAPI version 2.0 or later TSPs implement
[TUISPI_lineConfigDialog](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tuispi_lineconfigdialog).

The
**TSPI_lineConfigDialog** function causes the provider of the specified line device to display a modal dialog box as a child window of *hwndOwner* to allow the user to configure parameters related to the line device.

## Parameters

### `dwDeviceID`

The line device to be configured.

### `hwndOwner`

A handle to a parent window in which the dialog box window is to be placed.

### `lpszDeviceClass`

A pointer to a **null**-terminated Unicode string that identifies a device class name. This device class allows the caller to select a specific subscreen of configuration information applicable to that device class. If this parameter is **NULL** or an empty string, the highest level configuration dialog box should be selected. The permitted strings are the same as for
[TSPI_lineGetID](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetid). For example, if the line supports the Comm API, passing comm/datamodem as *lpszDeviceClass* causes the provider to display the parameters related specifically to Comm (or, at least, to start at the corresponding point in a multilevel configuration dialog box chain, so that the user doesn't have to search to find the desired parameters.)

## Return value

Returns zero if the function succeeds or an error number if an error occurs. Possible return values are as follows:

LINEERR_INUSE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALDEVICECLASS, LINEERR_OPERATIONFAILED, LINEERR_NOMEM, LINEERR_RESOURCEUNAVAIL.

## Remarks

The procedure must update the [Windows Telephony] section in the Win.ini file and broadcast the WM_WININICHANGE message if it makes any changes to the Telephon.ini file that would cause a change in the line or address capabilities reported in
[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps) or
[LINEADDRESSCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineaddresscaps), or if a line device is created or removed.

There is no restriction that this function (**TSPI_lineConfigDialog**) be called only when the line is closed. However, each provider can impose such a restriction itself. When
**TSPI_lineConfigDialog** is called, the provider could alert the user with the message "The line is in use by one or more applications. You may not change the line configuration while the line is in use" (and return the error message LINEERR_INUSE). However, some configuration may be safe to change "on the fly," particularly those related to media types (such as the modem error control protocol), especially when that media type is not currently in use. The provider could allow those options to be changed while the line is open.

Users should not be allowed to change anything that alters values returned with
[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps) or
[LINEADDRESSCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineaddresscaps) without first forcibly closing the line as a signal that applications must call functions that return these structures in order to have accurate information.

## See also

[LINEADDRESSCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineaddresscaps)

[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps)

[TSPI_lineGetDevConfig](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetdevconfig)

[TSPI_lineGetID](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetid)

[TSPI_lineSetDevConfig](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linesetdevconfig)