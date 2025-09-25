# TSPI_lineGetID function

## Description

The
**TSPI_lineGetID** function returns a device identifier for the specified device class associated with the selected line, address, or call.

## Parameters

### `hdLine`

The service provider's handle to the line to be queried.

### `dwAddressID`

An address on the given open line device. An address identifier is permanently associated with an address; the identifier remains constant across operating system upgrades. TAPI does not validate this parameter when this function is called.

### `hdCall`

The service provider's handle to the call to be queried.

### `dwSelect`

Specifies whether the device identifier requested is associated with the line, address, or a single call. The *dwSelect* parameter can have only one of the
[LINECALLSELECT_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linecallselect--constants).

### `lpDeviceID`

A pointer to the memory location of type
[VARSTRING](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-varstring) where the device identifier is returned. Upon successful completion of the request, this location is filled with the device identifier. The format of the returned information depends on the method used by the device class (API) for naming devices.

### `lpszDeviceClass`

A pointer to a null-terminated Unicode string that specifies the device class of the device whose identifier is requested. Valid device class strings are those used in the System.ini section to identify device classes (such as COM, Wave, and MCI.)

### `hTargetProcess`

The process handle of the application on behalf of which the
**TSPI_lineGetID** function is invoked. If the information returned in the
[VARSTRING](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-varstring) structure includes a handle for use by the application, the service provider should create or duplicate the handle for the process.

If *hTargetProcess* is set to INVALID_HANDLE_VALUE, then the application is executing on a remote client system and it is not possible to create a duplicate handle directly. Instead, the
[VARSTRING](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-varstring) structure should contain a UNC name of a network device or other name that the remote client can use to access the device. If this is not possible, then the function should fail.

## Return value

Returns zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

LINEERR_INVALLINEHANDLE, LINEERR_NOMEM, LINEERR_INVALADDRESSID, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALCALLHANDLE, LINEERR_OPERATIONFAILED, LINEERR_NODEVICE, LINEERR_RESOURCEUNAVAIL.

## Remarks

The service provide returns LINEERR_INVALLINEHANDLE if *dwSelect* is LINECALLSELECT_LINE or LINECALLSELECT_ADDRESS, and *hdLine* is invalid.

The service provider returns LINEERR_INVALCALLHANDLE if *dwSelect* is LINECALLSELECT_CALL and *hdCall* is invalid.

The service provider should support the tapi/line device class to allow applications to determine the real line device identifier of an opened line. In that case, the variable data returned is the *dwDeviceID*. For more information about common device class names, see
[TSPI Device Classes](https://learn.microsoft.com/windows/desktop/Tapi/tspi-device-classes).

A vendor that defines a device-specific media type also needs to define the corresponding device-specific (proprietary) API to manage devices of the media type. To avoid collisions on device class names assigned independently by different vendors, a vendor should select a name that uniquely identifies the vendor and then the media type; for example: "intel/video".

The service provider fills in all the members of the
[VARSTRING](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-varstring) data structure, except for **dwTotalSize**, which is filled in by TAPI. The service provider must not overwrite the **dwTotalSize** member.

The service provider does not need to be concerned with handling tapi/line and tapi/phone device classes because TAPI handles these for the service provider. Therefore, code for handling these device classes is optional.

## See also

[TSPI_lineGetDevConfig](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetdevconfig)

[TSPI_lineSetDevConfig](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linesetdevconfig)

[VARSTRING](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-varstring)