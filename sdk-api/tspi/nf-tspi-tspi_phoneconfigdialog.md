# TSPI_phoneConfigDialog function

## Description

The
**TSPI_phoneConfigDialog** function is obsolete. TAPI version 1.4 or earlier service providers can implement this TSPI function. TAPI version 2.0 or later TSPs implement
[TUISPI_phoneConfigDialog](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tuispi_phoneconfigdialog).

The
**TSPI_phoneConfigDialog** function causes the provider of the specified phone device to display a modal dialog box as a child window of *hwndOwner* to allow the user to configure parameters related to the phone device.

## Parameters

### `dwDeviceID`

The phone device to be configured.

### `hwndOwner`

A handle to a parent window in which the dialog box window is to be placed.

### `lpszDeviceClass`

A pointer to a **null**-terminated Unicode string that identifies a device class name. This device class allows the caller to select a specific subscreen of configuration information applicable to that device class. If this parameter is **NULL** or an empty string, the highest level configuration dialog box is selected.

## Return value

Returns zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

PHONEERR_BADDEVICEID, PHONEERR_NOMEM, PHONEERR_INUSE, PHONEERR_OPERATIONFAILED, PHONEERR_INVALPARAM, PHONEERR_OPERATIONUNAVAIL, PHONEERR_INVALDEVICECLASS, PHONEERR_RESOURCEUNAVAIL.

## Remarks

**TSPI_phoneConfigDialog** causes the service provider to display a modal dialog box as a child window of *hWndOwner* to allow the user to configure parameters related to the phone specified by *dwDeviceID*. The *lpszDeviceClass* parameter allows the application to select a specific subscreen of configuration information applicable to the device class in which the user is interested. The permitted strings are the same as for
[TSPI_phoneGetID](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonegetid). For example, if the phone supports the Comm API, passing comm/datamodem as *lpszDeviceClass* causes the provider to display the parameters related specifically to Comm (or, at least, to start at the corresponding point in a multilevel configuration dialog box chain, so that the user doesn't have to search to find the desired parameters). The *szDeviceClass* parameter should be "tapi/phone", "", or **NULL** to cause the provider to display the highest level configuration for the phone.

The procedure must update the [Windows Telephony] section in the Win.ini file and broadcast the WM_WININICHANGE message if it makes any changes to Telephon.ini that affect the contents of structures visible to applications (such as
[PHONECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonecaps)), or if phone devices are created or removed.

## See also

[PHONECAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phonecaps)

[TSPI_phoneGetID](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonegetid)