# TSPI_linePickup function

## Description

The
**TSPI_linePickup** function picks up a call alerting at the specified destination address and returns a call handle for the picked-up call. If invoked with **NULL** for the *lpszDestAddress* parameter, a group pickup is performed. If required by the device capabilities, *lpszGroupID* specifies the group identifier to which the alerting station belongs.

## Parameters

### `dwRequestID`

The identifier of the asynchronous request.

### `hdLine`

The handle to the line on which a call is to be picked up.

### `dwAddressID`

The address on *hdLine* at which the pickup is to be originated. An address identifier is permanently associated with an address; the identifier remains constant across operating system upgrades.

### `htCall`

The TAPI handle to the new call. The service provider must save this and use it in all subsequent calls to the
[LINEEVENT](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-lineevent) procedure reporting events on the call.

### `lphdCall`

A pointer to an
[HDRVCALL](https://learn.microsoft.com/windows/desktop/Tapi/hdrvline) representing the service provider's identifier for the call. The service provider must fill this location with its handle for the call before this procedure returns. This handle is ignored by TAPI if the function results in an error.

### `lpszDestAddress`

A pointer to a **null**-terminated Unicode string that contains the address whose call is to be picked up. The address is standard link format.

### `lpszGroupID`

A pointer to a **null**-terminated Unicode string containing the group identifier to which the alerting station belongs. This parameter is required on some switches to pick up calls outside of the current pickup group.

**Note** *lpszGroupID* can be specified by itself with a **NULL** pointer for *lpszDestAddress*. Alternatively, *lpszGroupID* can be specified in addition to *lpszDestAddress*, if required by the device. It can also be **NULL** itself.

## Return value

Returns *dwRequestID*, or an error number if an error occurs. The *lResult* actual parameter of the corresponding
[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) is zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

LINEERR_INVALLINEHANDLE, LINEERR_NOMEM, LINEERR_INVALADDRESSID, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALADDRESS, LINEERR_OPERATIONFAILED, LINEERR_INVALGROUPID, LINEERR_RESOURCEUNAVAIL.

## Remarks

When a call has been picked up successfully, the service provider notifies TAPI with the
[LINE_CALLSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725219(v=vs.85)) message about call state changes. The
[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo) structure supplies information about the call that was picked up. It lists the reason for the call as *pickup*. This structure is available by calling
[TSPI_lineGetCallInfo](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetcallinfo).

The service provider sets LINEADDRCAPFLAGS_PICKUPCALLWAIT to **TRUE** in the
[LINEADDRESSCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineaddresscaps) structure if
**TSPI_linePickup** can be used to pick up a call for which the user has audibly detected the call-waiting signal, but for which the provider is unable to perform the detection. This gives the user a mechanism to answer a waiting call even though the service provider was unable to detect the call-waiting signal. When
**TSPI_linePickup** is being used to pick up a call-waiting call, both *lpszDestAddress* and *lpszGroupID* pointer parameters are **NULL**. The service provider creates a new call handle for the waiting call and passes that handle to the user in *lphdCall*. The *dwAddressID* parameter is most often zero (particularly in single-line residential cases).

Once
**TSPI_linePickup** is used to pick up the second call,
[TSPI_lineSwapHold](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineswaphold) can be used to toggle between them.
[TSPI_lineDrop](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linedrop) can be used to drop one (and toggle to the other), and so forth. If the user wants to drop the current call and pick up the second call, they call
**TSPI_lineDrop** when they get the call-waiting beep, wait for the second call to ring, and then call
[TSPI_lineAnswer](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineanswer) on the new call handle. The service provider sets the LINEADDRFEATURE_PICKUP flag in the **dwAddressFeatures** member in
[LINEADDRESSSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineaddressstatus) to indicate when pickup is actually possible.

This function differs from the corresponding TAPI function in that it follows the TSPI model for beginning the lifetime of a call. TAPI and the service provider exchange opaque handles representing the call with one another. In addition, the service provider is permitted to do callbacks for the new call before it returns from this procedure. In any case, the service provider must also treat the handle it returned as "not yet valid" until after the matching
[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) message reports success. In other words, it must not issue any
[LINEEVENT](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-lineevent) messages for the new call or include it in call counts in messages or status data structures for the line.

## See also

[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion)

[LINEADDRESSCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineaddresscaps)

[LINEADDRESSSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineaddressstatus)

[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo)

[LINECALLSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallstatus)

[LINEEVENT](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-lineevent)

[LINE_CALLSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725219(v=vs.85))

[TSPI_lineAnswer](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineanswer)

[TSPI_lineDrop](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linedrop)

[TSPI_lineGetCallInfo](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetcallinfo)

[TSPI_lineGetCallStatus](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetcallstatus)

[TSPI_lineSwapHold](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineswaphold)