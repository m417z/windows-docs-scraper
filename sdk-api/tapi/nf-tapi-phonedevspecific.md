# phoneDevSpecific function

## Description

The
**phoneDevSpecific** function is used as a general extension mechanism to enable a Telephony API implementation to provide features not described in the other TAPI functions. The meanings of these extensions are device specific.

## Parameters

### `hPhone`

Handle to a phone device.

### `lpParams`

Pointer to a memory area used to hold a parameter block. Its interpretation is device specific. The contents of the parameter block are passed unchanged to or from the service provider by TAPI.

### `dwSize`

Size of the parameter block area, in bytes.

## Return value

Returns a positive request identifier if the function is completed asynchronously or a negative error number if an error occurs. The *dwParam2* parameter of the corresponding
[PHONE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/phone-reply) message is zero if the function succeeds or it is a negative error number if an error occurs. Possible return values are:

PHONEERR_INVALPHONEHANDLE, PHONEERR_NOMEM, PHONEERR_INVALPOINTER, PHONEERR_RESOURCEUNAVAIL, PHONEERR_OPERATIONUNAVAIL, PHONEERR_UNINITIALIZED, PHONEERR_OPERATIONFAILED.

Additional return values are device specific.

## Remarks

This operation provides a generic parameter profile. The interpretation of the parameter block is device specific. Indications and replies that are device specific should use the
[PHONE_DEVSPECIFIC](https://learn.microsoft.com/windows/desktop/Tapi/phone-devspecific) message.

A service provider can provide access to device-specific functions by defining parameters for use with this operation. Applications that want to make use of these device-specific extensions should consult the device-specific (vendor-specific) documentation that describes which extensions are defined. Typically, an application that relies on these device-specific extensions is not portable to work with other service-provider environments.

## See also

[Extended Telephony Services Reference](https://learn.microsoft.com/windows/desktop/Tapi/extended-telephony-services-reference)

[PHONE_DEVSPECIFIC](https://learn.microsoft.com/windows/desktop/Tapi/phone-devspecific)

[PHONE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/phone-reply)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)