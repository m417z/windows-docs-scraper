# lineForwardA function

## Description

The
**lineForward** function forwards calls destined for the specified address on the specified line, according to the specified forwarding instructions. When an originating address (*dwAddressID*) is forwarded, the specified incoming calls for that address are deflected to the other number by the switch. This function provides a combination of forward and do-not-disturb features. This function can also cancel forwarding currently in effect.

## Parameters

### `hLine`

Handle to the line device.

### `bAllAddresses`

Specifies whether all originating addresses on the line or just the one specified is to be forwarded. If **TRUE**, all addresses on the line are forwarded and *dwAddressID* is ignored; if **FALSE**, only the address specified as *dwAddressID* is forwarded.

### `dwAddressID`

Address on the specified line whose incoming calls are to be forwarded. This parameter is ignored if *bAllAddresses* is **TRUE**.

An address identifier is permanently associated with an address; the identifier remains constant across operating system upgrades.

### `lpForwardList`

Pointer to a variably sized data structure that describes the specific forwarding instructions, of type
[LINEFORWARDLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineforwardlist).

### `dwNumRingsNoAnswer`

Number of rings before a call is considered a "no answer." If *dwNumRingsNoAnswer* is out of range, the actual value is set to the nearest value in the allowable range.

### `lphConsultCall`

Pointer to an HCALL location. In some telephony environments, this location is loaded with a handle to a consultation call that is used to consult the party that is being forwarded to, and the application becomes the initial sole owner of this call. This pointer must be valid even in environments where call forwarding does not require a consultation call. This handle is set to **NULL** if no consultation call is created.

### `lpCallParams`

Pointer to a structure of type
[LINECALLPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallparams). This pointer is ignored unless
**lineForward** requires the establishment of a call to the forwarding destination (and *lphConsultCall* is returned, in which case *lpCallParams* is optional). If **NULL**, default call parameters are used. Otherwise, the specified call parameters are used for establishing *hConsultCall*.

## Return value

Returns a positive request identifier if the function is completed asynchronously, or a negative error number if an error occurs. The *dwParam2* parameter of the corresponding
[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply) message is zero if the function succeeds or it is a negative error number if an error occurs. Possible return values are:

LINEERR_INVALLINEHANDLE, LINEERR_NOMEM, LINEERR_INVALADDRESSID, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALADDRESS, LINEERR_OPERATIONFAILED, LINEERR_INVALCOUNTRYCODE, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALPOINTER, LINEERR_STRUCTURETOOSMALL, LINEERR_INVALPARAM, LINEERR_UNINITIALIZED.

## Remarks

A successful forwarding indicates only that the request has been accepted by the service provider, not that forwarding is set up at the switch. A
[LINE_ADDRESSSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-addressstate) (forwarding) message provides confirmation for forwarding having been set up at the switch.

Forwarding of the address(es) remains in effect until this function is called again. The most recent forwarding list replaces the old one. Forwarding can be canceled by specifying a **NULL** pointer as *lpForwardList*. If a **NULL** destination address is specified for an entry in the forwarding list, the operation acts as a do-not-disturb.

Forwarding status of an address can also be affected externally; for example, by administrative actions at the switch or by a user from another station. It may not be possible for the service provider to be aware of this state change, and it may not be able to keep in synchronization with the forwarding state known to the switch.

Because a service provider may not know the forwarding state of the address "for sure" (that is, it may have been forwarded or unforwarded in an unknown way),
**lineForward** succeeds unless it fails to set the new forwarding instructions. In other words, a request that all forwarding be canceled at a time that there is no forwarding in effect is successful. This is because there is no "unforwarding"—you can only change the previous set of forwarding instructions.

The success or failure of this operation does not depend on the previous set of forwarding instructions, and the same is true when setting different forwarding instructions. The provider should "unforward everything" prior to setting the new forwarding instructions. Because this can take time in analog telephony environments, a provider may also want to compare the current forwarding with the new one, and only issue instructions to the switch to get to the final state (leaving unchanged forwarding unaffected).

Invoking
**lineForward** when
[LINEFORWARDLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineforwardlist) has *dwNumEntries* set to zero has the same effect as providing a **NULL***lpForwardList* parameter. It cancels all forwarding currently in effect.

> [!NOTE]
> The tapi.h header defines lineForward as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Forward Overview](https://learn.microsoft.com/windows/desktop/Tapi/forward-ovr)

[LINECALLPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallparams)

[LINEFORWARDLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineforwardlist)

[LINE_ADDRESSSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-addressstate)

[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply)

[Supplementary Line Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-line-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)