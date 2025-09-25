# linePickupW function

## Description

The
**linePickup** function picks up a call alerting at the specified destination address and returns a call handle for the picked-up call. If invoked with **NULL** for the *lpszDestAddress* parameter, a group pickup is performed. If required by the device, *lpszGroupID* specifies the group identifier to which the alerting station belongs.

## Parameters

### `hLine`

Handle to the open line device on which a call is to be picked up.

### `dwAddressID`

Address on *hLine* at which the pickup is to be originated. An address identifier is permanently associated with an address; the identifier remains constant across operating system upgrades.

### `lphCall`

Pointer to a memory location where the handle to the picked up call is returned. The application is the initial sole owner of the call.

### `lpszDestAddress`

Pointer to a **null**-terminated character buffer that contains the address whose call is to be picked up. The address is in standard dialable address format.

### `lpszGroupID`

Pointer to a **null**-terminated character buffer containing the group identifier to which the alerting station belongs. This parameter is required on some switches to pick up calls outside of the current pickup group.

The *lpszGroupID* parameter can be specified by itself with a **NULL** pointer for *lpszDestAddress*. Alternatively, *lpszGroupID* can be specified in addition to *lpszDestAddress*, if required by the device.

## Return value

Returns a positive request identifier if the function is completed asynchronously, or a negative error number if an error occurs. The *dwParam2* parameter of the corresponding
[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply) message is zero if the function succeeds or it is a negative error number if an error occurs. Possible return values are:

LINEERR_INVALADDRESS, LINEERR_NOMEM, LINEERR_INVALADDRESSID, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALGROUPID, LINEERR_OPERATIONFAILED, LINEERR_INVALLINEHANDLE, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALPOINTER, LINEERR_UNINITIALIZED.

## Remarks

When a call has been picked up successfully, the application is notified by the
[LINE_CALLSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-callstate) message about call state changes. The
[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo) structure supplies information about the call that was picked up. It lists the reason for the call as *pickup*. This structure is available using
[lineGetCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetcallinfo).

If LINEADDRCAPFLAGS_PICKUPCALLWAIT is **TRUE**,
**linePickup** can be used to pick up a call for which the user has audibly detected the call-waiting signal but for which the provider is unable to perform the detection. This gives the user a mechanism to "answer" a waiting call even though the service provider was unable to detect the call-waiting signal. Both *lpszDestAddress* and *lpszGroupID* pointer parameters must be **NULL** to pick up a call-waiting call. The
**linePickup** function creates a new call handle for the waiting call and passes that handle to the user. The *dwAddressID* parameter is most often zero (particularly in single-line residential cases).

After
**linePickup** has been used to pick up the second call,
[lineSwapHold](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineswaphold) can be used to toggle between them. The
[lineDrop](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linedrop) function can be used to drop one (and toggle to the other), and so forth. If the user wants to drop the current call and pick up the second call, they should call
**lineDrop** when they get the call-waiting beep, wait for the second call to ring, and then call
[lineAnswer](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineanswer) on the new call handle. The LINEADDRFEATURE_PICKUP flag in the **dwAddressFeatures** member in
[LINEADDRESSSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineaddressstatus) indicates when pickup is actually possible.

> [!NOTE]
> The tapi.h header defines linePickup as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[LINEADDRESSSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineaddressstatus)

[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo)

[LINE_CALLSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-callstate)

[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply)

[Pickup overview](https://learn.microsoft.com/windows/desktop/Tapi/pickup-ovr)

[Supplementary Line Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-line-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[lineAnswer](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineanswer)

[lineDrop](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linedrop)

[lineGetCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetcallinfo)

[lineSwapHold](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineswaphold)