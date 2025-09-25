# TSPI_lineGetCallAddressID function

## Description

The
**TSPI_lineGetCallAddressID** function retrieves the address identifier for the indicated call.

## Parameters

### `hdCall`

The service provider's handle to the call whose address identifier is to be retrieved. The call state of *hdCall* can be any state.

### `lpdwAddressID`

A pointer to a **DWORD** into which the service provider writes the call's address identifier.

## Return value

Returns zero if the function succeeds or an error number if an error occurs. Possible return values are as follows:

LINEERR_NOMEM, LINEERR_OPERATIONFAILED, LINEERR_OPERATIONUNAVAIL, LINEERR_RESOURCEUNAVAIL.

## Remarks

If the service provider models lines as "pools" of channel resources and does inverse multiplexing of a call over several address identifiers it should consistently choose one of these address identifiers as the primary identifier reported by this function and in the
[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo) data structure.

This function has no direct correspondence at the TAPI level. It gives TAPI sufficient information to implement the
[lineGetNewCalls](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetnewcalls) function invoked with the LINECALLSELECT_ADDRESS option.

## See also

[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo)