# lineGetID function

## Description

The
**lineGetID** function returns a device identifier for the specified device class associated with the selected line, address, or call.

## Parameters

### `hLine`

Handle to an open line device.

### `dwAddressID`

Address on the given open line device. An address identifier is permanently associated with an address; the identifier remains constant across operating system upgrades.

### `hCall`

Handle to a call.

### `dwSelect`

Specifies whether the requested device identifier is associated with the line, address or a single call. This parameter uses one and only one of the
[LINECALLSELECT_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linecallselect--constants).

### `lpDeviceID`

Pointer to a memory location of type
[VARSTRING](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-varstring), where the device identifier is returned. Upon successful completion of the request, this location is filled with the device identifier. The format of the returned information depends on the method used by the device class API for naming devices. Prior to calling
**lineGetID**, the application must set the **dwTotalSize** member of this structure to indicate the amount of memory available to TAPI for returning information.

**Note** If the size parameters in the structure are not correct, there is a possibility that data could get overwritten. For more information on setting structure sizes, see the
[memory allocation](https://learn.microsoft.com/windows/desktop/Tapi/memory-allocation) topic.

### `lpszDeviceClass`

Pointer to a null-terminated string that specifies the device class of the device whose identifier is requested. Valid device class strings are those used in the SYSTEM.INI section to identify device classes.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

LINEERR_INVALLINEHANDLE, LINEERR_NOMEM, LINEERR_INVALADDRESSID, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALCALLHANDLE, LINEERR_OPERATIONFAILED, LINEERR_INVALCALLSELECT, LINEERR_INVALDEVICECLASS, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALPOINTER, LINEERR_STRUCTURETOOSMALL, LINEERR_NODEVICE, LINEERR_UNINITIALIZED.

## Remarks

The
**lineGetID** function can be used to retrieve a line-device identifier when given a line handle. This is useful after
[lineOpen](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineopen) has been opened using LINEMAPPER as a device identifier in order to determine the real line-device identifier of the opened line. This function can also be used to obtain the device identifier of a phone device or media device (for device classes such as COM, wave, MIDI, phone, line, or NDIS) associated with a call, address or line. This identifier can then be used with the appropriate API (such as phone, MIDI, wave) to select the corresponding media device associated with the specified call.

See
[TAPI Device Classes](https://learn.microsoft.com/windows/desktop/Tapi/tapi-device-classes) for device class names.

A vendor that defines a device-specific media mode also needs to define the corresponding device-specific (proprietary) API to manage devices of the media mode. To avoid collisions on device class names assigned independently by different vendors, a vendor should select a name that uniquely identifies both the vendor and, following it, the media type. For example: "intel/video".

## See also

[Basic Telephony Services Reference](https://learn.microsoft.com/windows/desktop/Tapi/basic-telephony-services-reference)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[VARSTRING](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-varstring)

[lineOpen](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineopen)