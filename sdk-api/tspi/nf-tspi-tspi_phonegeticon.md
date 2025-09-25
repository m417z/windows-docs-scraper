# TSPI_phoneGetIcon function

## Description

The
**TSPI_phoneGetIcon** function retrieves a service phone device-specific (or provider-specific) icon to display to the user.

## Parameters

### `dwDeviceID`

The phone device whose icon is requested.

### `lpszDeviceClass`

A pointer to a **null**-terminated Unicode string that identifies a device class name. This device class allows the caller to select a specific sub icon applicable to that device class. This parameter is optional and can be left **NULL** or be empty, in which case the highest level icon associated with the phone device rather than a specified media stream device is selected.

### `lphIcon`

A pointer to a memory location in which the handle to the icon is returned.

## Return value

Returns zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

PHONEERR_INVALDEVICECLASS, PHONEERR_OPERATIONFAILED, PHONEERR_NOMEM, PHONEERR_OPERATIONUNAVAIL, PHONEERR_RESOURCEUNAVAIL.

## Remarks

**TSPI_phoneGetIcon** causes the provider to return a handle (in the **DWORD** pointed to by *lphIcon*) to an icon resource (obtained from the
[LoadIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadicona) function) associated with the specified phone. The icon handle is for a resource associated with the provider.

The *lpszDeviceClass* parameter allows the provider to return different icons based on the type of service being referenced by the caller. The permitted strings are the same as for
[TSPI_phoneGetID](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonegetid). For example, if the phone supports the Comm API, passing comm/datamodem as *lpszDeviceClass* causes the provider to return an icon related specifically to the Comm device functions of the service provider. For more information about common device classes, see
[TSPI Device Classes](https://learn.microsoft.com/windows/desktop/Tapi/tspi-device-classes).

The parameters "tapi/phone", "", or **NULL** can be used to request the icon for the phone device. A provider can choose to support many icons (selected by *lpszDeviceClass* and/or phone number), a single icon (such as for the manufacturer, which would be returned for all *phoneGetIcon* requests regardless of the *lpszDeviceClass* selected), or no icons, in which case it sets the **DWORD** pointed to by *lphIcon* to **NULL**. TAPI examines the handle returned by the provider, and if the provider returns **NULL**, TAPI substitutes a generic Telephony icon included as a resource in TAPI (the generic phone icon).

If the service provider supports no icons, it can leave this function unimplemented, in which case TAPI provides a generic phone icon for the application.

## See also

[TSPI_phoneConfigDialog](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phoneconfigdialog)

[TSPI_phoneGetID](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonegetid)