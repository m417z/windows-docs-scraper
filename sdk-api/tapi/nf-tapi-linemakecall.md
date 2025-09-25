# lineMakeCall function

## Description

The
**lineMakeCall** function places a call on the specified line to the specified destination address. Optionally, call parameters can be specified if anything but default call setup parameters are requested.

## Parameters

### `hLine`

Handle to the open line device on which a call is to be originated.

### `lphCall`

Pointer to an HCALL handle. The handle is only valid after the
[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply) message is received by the application indicating that the
**lineMakeCall** function successfully completed. Use this handle to identify the call when invoking other telephony operations on the call. The application is initially the sole owner of this call. This handle is void if the function returns an error (synchronously or asynchronously by the reply message).

### `lpszDestAddress`

Pointer to the destination address. This follows the standard dialable number format. This pointer can be **NULL** for non-dialed addresses (as with a hot phone) or when all dialing is performed using
[lineDial](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linedial). In the latter case,
**lineMakeCall** allocates an available call appearance that would typically remain in the **dialtone** state until dialing begins. Service providers that have inverse multiplexing capabilities can allow an application to specify multiple addresses at once.

### `dwCountryCode`

Country or region code of the called party. If a value of 0 is specified, a default is used by the implementation.

### `lpCallParams`

Pointer to a
[LINECALLPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallparams) structure. This structure allows the application to specify how it wants the call to be set up. If **NULL** is specified, a default 3.1 kHz voice call is established and an arbitrary origination address on the line is selected. This structure allows the application to select elements such as the call's bearer mode, data rate, expected media mode, origination address, blocking of caller ID information, and dialing parameters.

## Return value

Returns a positive request identifier if the function is completed asynchronously, or a negative error number if an error occurs. The *dwParam2* parameter of the corresponding
[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply) message is zero if the function succeeds or it is a negative error number if an error occurs. Possible return values are:

LINEERR_ADDRESSBLOCKED, LINEERR_INVALLINEHANDLE, LINEERR_BEARERMODEUNAVAIL, LINEERR_INVALLINESTATE, LINEERR_CALLUNAVAIL, LINEERR_INVALMEDIAMODE, LINEERR_DIALBILLING, LINEERR_INVALPARAM, LINEERR_DIALDIALTONE, LINEERR_INVALPOINTER, LINEERR_DIALPROMPT, LINEERR_INVALRATE, LINEERR_DIALQUIET, LINEERR_NOMEM, LINEERR_INUSE, LINEERR_OPERATIONFAILED, LINEERR_INVALADDRESS, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALADDRESSID, LINEERR_RATEUNAVAIL, LINEERR_INVALADDRESSMODE, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALBEARERMODE, LINEERR_STRUCTURETOOSMALL, LINEERR_INVALCALLPARAMS, LINEERR_UNINITIALIZED, LINEERR_INVALCOUNTRYCODE, LINEERR_USERUSERINFOTOOBIG.

## Remarks

If LINEERR_INVALLINESTATE is returned, the line is currently not in a state in which this operation can be performed. A list of currently valid operations can be found in the **dwLineFeatures** member (of the type LINEFEATURE_) in the
[LINEDEVSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevstatus) structure. Calling
[lineGetLineDevStatus](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetlinedevstatus) updates the information in
**LINEDEVSTATUS**. If LINEERR_DIALBILLING, LINEERR_DIALQUIET, LINEERR_DIALDIALTONE, or LINEERR_DIALPROMPT is returned, none of the actions otherwise performed by
**lineMakeCall** have occurred; for example, none of the dialable address prior to the offending character has been dialed, no hookswitch state has changed, and so on.

After dialing has completed, several
[LINE_CALLSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-callstate) messages are usually sent to the application to notify it about the progress of the call. No generally valid sequence of call-state transitions is specified, as no single fixed sequence of transitions can be guaranteed in practice. A typical sequence can cause a call to transition from *dialtone*, *dialing*, *proceeding*, *ringback*, to *connected*. With non-dialed lines, the call can typically transition directly to *connected* state.

An application has the option to specify an originating address on the specified line device. A service provider that models all stations on a switch as addresses on a single line device allows the application to originate calls from any of these stations using
**lineMakeCall**.

The call parameters allow the application to make non-voice calls or request special call setup options that are not available by default.

An application can partially dial using
**lineMakeCall** and continue dialing using
[lineDial](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linedial). For more information on partial dialing, see [lineDial](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linedial) and [TSPI_lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linemakecall). To abandon a call attempt, use
[lineDrop](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linedrop).

After
**lineMakeCall** returns a success reply message to the application, a LINE_CALLSTATE message is sent to the application to indicate the current state of the call. This state is not necessarily LINECALLSTATE_DIALTONE.

This function may send data over the wire in unencrypted form; therefore, someone eavesdropping on the network may be able to read the data. The security risk of sending the data in clear text should be considered before using this method.

**Caution** TAPI will write the returned data to the buffer referenced by lphCall when the LINE_REPLY message is returned. This means that the buffer must remain valid until the LINE_REPLY message is returned; otherwise, data corruption and exceptions may occur.

## See also

[Basic Telephony Services Reference](https://learn.microsoft.com/windows/desktop/Tapi/basic-telephony-services-reference)

[Dialable addresses](https://learn.microsoft.com/windows/win32/tapi/address-ovr#dialable-addresses)

[LINECALLPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallparams)

[LINEDEVSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevstatus)

[LINE_CALLSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-callstate)

[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[lineDial](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linedial)

[lineDrop](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linedrop)

[lineGetLineDevStatus](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetlinedevstatus)