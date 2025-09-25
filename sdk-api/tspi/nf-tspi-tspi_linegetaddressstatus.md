# TSPI_lineGetAddressStatus function

## Description

The
**TSPI_lineGetAddressStatus** function queries the specified address for its current status.

## Parameters

### `hdLine`

The service provider's handle to the line containing the address to be queried.

### `dwAddressID`

An address on the given open line device. This is the address to be queried. An address identifier is permanently associated with an address; the identifier remains constant across operating system upgrades. This parameter is not validated by TAPI when this function is called.

### `lpAddressStatus`

A pointer to a variably sized data structure of type
[LINEADDRESSSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineaddressstatus).

## Return value

Returns zero if the function succeeds or an error number if an error occurs. Possible return values are as follows:

LINEERR_INVALLINEHANDLE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALADDRESSID, LINEERR_OPERATIONFAILED, LINEERR_NOMEM, LINEERR_RESOURCEUNAVAIL.

## Remarks

The service provider fills in all the members of the
[LINEADDRESSSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineaddressstatus) data structure, except for **dwTotalSize**, which is filled in by TAPI. The service provider must not overwrite the **dwTotalSize** member.

## See also

[LINEADDRESSSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineaddressstatus)