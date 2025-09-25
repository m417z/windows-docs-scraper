# TSPI_lineGetIcon function

## Description

The
**TSPI_lineGetIcon** function retrieves a service line device-specific icon to display to the user.

## Parameters

### `dwDeviceID`

The line device whose icon is requested.

### `lpszDeviceClass`

A pointer to a **null**-terminated Unicode string that identifies a device class name. This device class allows the caller to select an icon specific to that device class. This parameter is optional and can be left **NULL**, in which case the highest level icon associated with the line device rather than a specified media stream device is selected.

Permitted strings are the same as for
[TSPI_lineGetID](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetid). For example, if the line supports the Comm API, passing comm/datamodem as *lpszDeviceClass* causes the provider to return an icon related specifically to the Comm device functions of the service provider.

### `lphIcon`

A pointer to a memory location in which the handle to the icon is returned.

## Return value

Returns zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

LINEERR_INVALDEVICECLASS, LINEERR_OPERATIONFAILED, LINEERR_NOMEM, LINEERR_RESOURCEUNAVAIL, LINEERR_OPERATIONUNAVAIL.

## Remarks

The provider should return a handle (in the **DWORD** pointed to by *lphIcon*) to an icon resource (obtained from the
[LoadIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadicona) function) associated with the specified line.

A provider may choose to support many icons (selected by *lpszDeviceClass* and/or line number), a single icon (such as for the manufacturer, which would be returned for all
**TSPI_lineGetIcon** requests regardless of the *lpszDeviceClass* selected), or no icons, in which case it sets the **DWORD** pointed to by *lphIcon* to **NULL**. TAPI examines the handle returned by the provider, and if the provider returns **NULL**, TAPI substitutes a generic Telephony icon (the generic "line" icon).

## See also

[TSPI_lineConfigDialog](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineconfigdialog)

[TSPI_lineGetID](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetid)