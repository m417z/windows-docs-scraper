# lineDevSpecific function

## Description

The
**lineDevSpecific** function enables service providers to provide access to features not offered by other TAPI functions. The meaning of the extensions are device specific, and taking advantage of these extensions requires the application to be fully aware of them.

## Parameters

### `hLine`

Handle to a line device. This parameter is required.

### `dwAddressID`

Address identifier on the given line device. An address identifier is permanently associated with an address; the identifier remains constant across operating system upgrades.

### `hCall`

Handle to a call. This parameter is optional, but if it is specified, the call it represents must belong to the *hLine* line device. The call state of *hCall* is device specific.

### `lpParams`

Pointer to a memory area used to hold a parameter block. The format of this parameter block is device specific and its contents are passed by TAPI to or from the service provider.

### `dwSize`

Size of the parameter block area, in bytes.

## Return value

Returns a positive request identifier if the function is completed asynchronously, or a negative error number if an error occurs. The *dwParam2* parameter of the corresponding
[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply) message is zero if the function succeeds, or it is a negative error number if an error occurs. Possible return values are:

LINEERR_INVALADDRESSID, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALCALLHANDLE, LINEERR_OPERATIONFAILED, LINEERR_INVALLINEHANDLE, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALPOINTER, LINEERR_UNINITIALIZED, LINEERR_NOMEM.

Additional return values are device specific.

## Remarks

This operation is part of the Extended Telephony services. It provides access to a device-specific feature without defining its meaning. This operation is only available if the application has successfully negotiated a device-specific extension version.

This function provides a generic parameter profile. The interpretation of the parameter structure is device specific. Whether *dwAddressID* and/or *hCall* are expected to be valid is device specific. If specified, they must belong to *hLine*. Indications and replies sent back the application that are device specific should use the
[LINE_DEVSPECIFIC](https://learn.microsoft.com/windows/desktop/Tapi/line-devspecific) message.

A service provider can provide access to device-specific functions by defining parameters for use with this function. Applications that want to make use of these device-specific extensions should consult the device-specific (in this case, vendor-specific) documentation that describes what extensions are defined. Typically, an application that relies on these device-specific extensions is not able to work with other service provider environments.

**Caution** TAPI will write the returned data to the buffer referenced by lParam when the LINE_REPLY message is returned. This means that the buffer must remain valid until the LINE_REPLY message is returned; otherwise, data corruption and exceptions may occur.

## See also

[Extended Telephony Services Reference](https://learn.microsoft.com/windows/desktop/Tapi/extended-telephony-services-reference)

[LINE_DEVSPECIFIC](https://learn.microsoft.com/windows/desktop/Tapi/line-devspecific)

[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)