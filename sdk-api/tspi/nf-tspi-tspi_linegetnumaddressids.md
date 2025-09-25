# TSPI_lineGetNumAddressIDs function

## Description

The
**TSPI_lineGetNumAddressIDs** function retrieves the number of address identifiers supported on the indicated line.

## Parameters

### `hdLine`

The handle to the line for which the number of address identifiers is to be retrieved.

### `lpdwNumAddressIDs`

A pointer to a **DWORD**. The location is filled with the number of address identifiers supported on the indicated line. The value is one or larger.

## Return value

Returns zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

LINEERR_NOMEM, LINEERR_OPERATIONFAILED, LINEERR_OPERATIONUNAVAIL, LINEERR_RESOURCEUNAVAIL.

## Remarks

This function is called by TAPI in response to an application calling
[lineSetNumRings](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetnumrings),
[lineGetNumRings](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetnumrings), or
[lineGetNewCalls](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetnewcalls). TAPI uses the retrieved value to determine if the specified address identifier is within the range supported by the service provider.

## See also

[lineGetNewCalls](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetnewcalls)

[lineGetNumRings](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetnumrings)

[lineSetNumRings](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetnumrings)