# lineDevSpecificFeature function

## Description

The
**lineDevSpecificFeature** function enables service providers to provide access to features not offered by other TAPI functions. The meaning of these extensions are device specific, and taking advantage of these extensions requires the application to be fully aware of them.

## Parameters

### `hLine`

Handle to the line device.

### `dwFeature`

Feature to invoke on the line device. This parameter uses the
[PHONEBUTTONFUNCTION_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/phonebuttonfunction--constants).

### `lpParams`

Pointer to a memory area used to hold a feature-dependent parameter block. The format of this parameter block is device specific and its contents are passed through by TAPI to or from the service provider.

### `dwSize`

Size of the buffer, in bytes.

## Return value

Returns a positive request identifier if the function is completed asynchronously, or a negative error number if an error occurs. The *dwParam2* parameter of the corresponding
[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply) message is zero if the function succeeds or it is a negative error number if an error occurs. Possible return values are:

LINEERR_INVALFEATURE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALLINEHANDLE, LINEERR_OPERATIONFAILED, LINEERR_INVALPOINTER, LINEERR_RESOURCEUNAVAIL, LINEERR_NOMEM, LINEERR_UNINITIALIZED.

Additional return values are device specific.

## Remarks

This operation is part of the Extended Telephony services. It provides access to a device-specific feature without defining its meaning. This operation is only available if the application has successfully negotiated a device-specific extension version.

This function provides the application with phone feature-button emulation capabilities. When an application invokes this operation, it specifies the equivalent of a button-press event. This method of invoking features is device dependent, as TAPI does not define their meaning. Typically, an application that relies on these device-specific extensions does not work with other service provider environments.

The structure pointed to by *lpParams* should not contain any pointers because they would not be properly translated (thunked) when running a 16-bit application in a 32-bit version of TAPI and vice versa.

## See also

[Extended Telephony Services Reference](https://learn.microsoft.com/windows/desktop/Tapi/extended-telephony-services-reference)

[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)