# TSPI_lineForward function

## Description

The
**TSPI_lineForward** function forwards calls destined for the specified address on the specified line, according to the specified forwarding instructions. When an originating address (*dwAddressID*) is forwarded, the specified incoming calls for that address are deflected to the other number by the switch. This function provides a combination of forward and do-not-disturb features. This function can also cancel specific forwarding currently in effect.

## Parameters

### `dwRequestID`

The identifier of the asynchronous request.

### `hdLine`

The service provider's handle to the line to be forwarded.

### `bAllAddresses`

Specifies whether all originating addresses on the line or just the one specified is to be forwarded. If TRUE, all addresses on the line are forwarded and *dwAddressID* is ignored; if **FALSE**, only the address specified as *dwAddressID* is forwarded. This parameter is not validated by TAPI when this function is called.

### `dwAddressID`

The address on the specified line whose incoming calls are to be forwarded. This parameter is ignored if *bAllAddresses* is TRUE. This parameter is not validated by TAPI when this function is called.

An address identifier is permanently associated with an address; the identifier remains constant across operating system upgrades.

### `lpForwardList`

A pointer to a variably sized data structure of type
[LINEFORWARDLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineforwardlist) that describes the specific forwarding instructions.

### `dwNumRingsNoAnswer`

Specifies the number of rings before an incoming call is considered a "no answer." If *dwNumRingsNoAnswer* is out of range, the actual value is set to the nearest value in the allowable range. This parameter is not validated by TAPI when this function is called.

### `htConsultCall`

The TAPI handle to a new call, if such a call must be created by the service provider. In some telephony environments, forwarding a call has the side effect of creating a consultation call used to consult the party that is being forwarded to. In such an environment, the service provider creates the new consultation call and must save this value and use it in all subsequent calls to the
[LINEEVENT](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-lineevent) procedure reporting events on the call. If no consultation call is created, this value can be ignored by the service provider.

### `lphdConsultCall`

A pointer to an
[HDRVCALL](https://learn.microsoft.com/windows/desktop/Tapi/hdrvline) representing the service provider's identifier for the call. In telephony environments where forwarding a call has the side effect of creating a consultation call used to consult the party that is being forwarded to, the service provider must fill this location with its handle for the call before this procedure returns. The service provider is permitted to do callbacks regarding the new call before it returns from this procedure. If no consultation call is created, the HDRVCALL must be left **NULL**.

### `lpCallParams`

A pointer to a structure of type
[LINECALLPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallparams). This pointer is ignored by the service provider unless
[lineForward](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineforward) requires the establishment of a call to the forwarding destination (and *lphdConsultCall* is returned, in which case *lpCallParams* is optional). If **NULL**, default call parameters are used. Otherwise, the specified call parameters are used for establishing *htConsultCall*.

## Return value

Returns *dwRequestID* or an error number if an error occurs. The *lResult* actual parameter of the corresponding
[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) is zero if the function succeeds or an error number if an error occurs. Possible return values are as follows:

LINEERR_INVALLINEHANDLE, LINEERR_NOMEM, LINEERR_INVALADDRESS, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALADDRESSID, LINEERR_OPERATIONFAILED, LINEERR_INVALCOUNTRYCODE, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALPARAM, LINEERR_STRUCTURETOOSMALL.

## Remarks

The service provider returns LINEERR_INVALPARAM if the specified forward list parameter contains invalid information.

The service provider carries out no dialing if it returns LINEERR_INVALADDRESS.

The service provider returns success to this function to indicate only that the request is accepted by the service provider, not that forwarding is set up at the switch. A
[LINE_ADDRESSSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725215(v=vs.85)) (forwarding) message is sent to provide that forwarding is set up at the switch.

Forwarding of the address or addresses remains in effect until this function is called again. The most recent forwarding list replaces any old one in effect. If this function is called, specifying a **NULL** pointer as *lpForwardList*, the service provider should cancel any forwarding that is being performed at that time. If a **NULL** destination address is specified for an entry in the forwarding list, the operation acts as a "do-not-disturb."

Forwarding status of an address may also be affected externally, for example, through administrative actions at the switch, or by a user from another station. It may not be possible for the service provider to be aware of this state change, and may not be able to keep in sync with the forwarding state known to the switch. The provider must always indicate what it knows to be true, and indicate that the forwarding state is unknown otherwise.

Because a service provider may not know the forwarding state of the address with no doubt (that is, it may have been forwarded or unforwarded in an unknown way),
**TSPI_lineForward** succeeds unless it fails to set the new forwarding instructions. In other words, a request that all forwarding be canceled at a time when there is no forwarding in effect succeeds. This is because there is no unforwarding; you can only invoke a new set of forwarding instructions.

The success or failure of this operation does not depend on the previous set of forwarding instructions, and the same is true when setting different forwarding instructions. If necessary, the provider should "unforward everything" prior to setting the new forwarding instructions. Because this may take time in analog telephony environments, a provider may also want to compare the current forwarding with the new one, and only issue instructions to the switch to get to the final state (leaving unchanged forwarding unaffected).

Invoking
**TSPI_lineForward** when
[LINEFORWARDLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineforwardlist) has **dwNumEntries** set to zero has the same effect as providing a **NULL***lpForwardList* parameter; it cancels all forwarding currently in effect.

Because the **NULL** value returned into *lphdConsultCall* is the only way for TAPI to determine whether the service provider created a consultation call, the service provider cannot use **NULL** as a call handle.

This function differs from the corresponding TAPI function in that it follows the TSPI model for beginning the lifetime of a call. TAPI and the service provider exchange opaque handles representing the call with one another. In addition, the service provider is permitted to do callbacks for the new call before it returns from this procedure. In any case, the service provider must also treat the handle it returned as "not yet valid" until after the matching
[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) reports success. In other words, it must not issue any messages for the new call or include it in call counts in messages or status data structures for the line.

## See also

[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion)

[LINECALLPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallparams)

[LINEEVENT](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-lineevent)

[LINEFORWARDLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineforwardlist)

[LINE_ADDRESSSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725215(v=vs.85))