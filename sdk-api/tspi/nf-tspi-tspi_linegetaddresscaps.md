# TSPI_lineGetAddressCaps function

## Description

The
**TSPI_lineGetAddressCaps** function queries the specified address on the specified line device to determine its telephony capabilities.

## Parameters

### `dwDeviceID`

The line device containing the address to be queried.

### `dwAddressID`

The address on the given line device whose capabilities are to be queried. An address identifier is permanently associated with an address; the identifier remains constant across operating system upgrades. This parameter is not validated by TAPI when this function is called.

### `dwTSPIVersion`

The version number of the Telephony SPI to be used. The high-order word contains the major version number; the low-order word contains the minor version number.

### `dwExtVersion`

The version number of the service-provider specific extensions to be used. This number is zero if no device-specific extensions are to be used. Otherwise, the high-order word contains the major version number; the low-order word contain the minor version number. This parameter is not validated by TAPI when this function is called.

### `lpAddressCaps`

A pointer to a variably sized structure of type
[LINEADDRESSCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineaddresscaps). Upon successful completion of the request, this structure is filled with address capabilities information.

## Return value

Returns zero if the function succeeds or an error number if an error occurs. Possible return values are as follows:

LINEERR_INCOMPATIBLEAPIVERSION, LINEERR_NOMEM, LINEERR_INCOMPATIBLEEXTVERSION, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALADDRESSID, LINEERR_OPERATIONFAILED, LINEERR_NODRIVER, LINEERR_RESOURCEUNAVAIL.

## Remarks

The line device identifiers supported by a particular driver are numbered sequentially starting with the value of *dwLineDeviceIDBase* that is passed into the
[TSPI_providerInit](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_providerinit) function.

The service provider fills in all the members of the
[LINEADDRESSCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineaddresscaps) data structure, except for **dwTotalSize**, which is filled in by TAPI. The service provider must not overwrite the **dwTotalSize** member.

After the service provider returns from the
**TSPI_lineGetAddressCaps** function, TAPI sets the **dwCallInfoStates** and **dwCallStates** members of the
[LINEADDRESSCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineaddresscaps) structure as follows:

``` syntax
LINEADDRESSCAPS.dwCallInfoStates |=
    LINECALLINFOSTATE_NUMOWNERINCR |
    LINECALLINFOSTATE_NUMOWNERDECR |
    LINECALLINFOSTATE_NUMMONITORS;

LINEADDRESSCAPS.dwCallStates |= LINECALLSTATE_UNKNOWN;
```

## See also

[LINEADDRESSCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineaddresscaps)

[TSPI_providerInit](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_providerinit)