# TSPI_lineGetDevCaps function

## Description

The
**TSPI_lineGetDevCaps** function queries a specified line device to determine its telephony capabilities. The returned information is valid for all addresses on the line device.

## Parameters

### `dwDeviceID`

The line device to be queried.

### `dwTSPIVersion`

The negotiated TSPI version number. This value has already been negotiated for this device through the
[TSPI_lineNegotiateTSPIVersion](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linenegotiatetspiversion) function.

### `dwExtVersion`

The negotiated extension version number. This value has already been negotiated for this device through the
[TSPI_lineNegotiateExtVersion](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linenegotiateextversion) function. This parameter is not validated by TAPI when this function is called.

### `lpLineDevCaps`

A pointer to a variably sized structure of type
[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps). Upon successful completion of the request, this structure is filled with line device capabilities information.

## Return value

Returns zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

LINEERR_INCOMPATIBLEAPIVERSION, LINEERR_OPERATIONUNAVAIL, LINEERR_INCOMPATIBLEEXTVERSION, LINEERR_OPERATIONFAILED, LINEERR_NODRIVER, LINEERR_RESOURCEUNAVAIL, LINEERR_NOMEM.

## Remarks

Line device identifier numbering for a service provider is sequential from the value set by the *dwLineDeviceIDBase* parameter that is passed to the
[TSPI_providerInit](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_providerinit) function.

The *dwExtVersion* formal parameter indicates the version number of the requested extension information. If it is zero, no extension information is requested. If it is nonzero, it holds a value that was negotiated for this device with the
[TSPI_lineNegotiateExtVersion](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linenegotiateextversion) function. The service provider fills in device- and vendor-specific extended information according to the extension version specified.

The service provider fills in all the members of the
[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps) data structure, except for **dwTotalSize**, which is filled in by TAPI. The service provider must not overwrite the **dwTotalSize** member.

The service provider must fill in all members of the
[LINETERMCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linetermcaps) data structure or structures embedded in the varying part of the
[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps) data structure.

After the service provider returns from the
**TSPI_lineGetDevCaps** function, TAPI sets the **dwLinesStates** member of the
[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps) structure as follows:

``` syntax
LINEDEVCAPS.dwLineStates |=
    LINEDEVSTATE_OPEN |
    LINEDEVSTATE_CLOSE |
    LINEDEVSTATE_REINIT |
    LINEDEVSTATE_TRANSLATECHANGE;
```

## See also

[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps)

[LINETERMCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linetermcaps)

[TSPI_lineNegotiateExtVersion](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linenegotiateextversion)

[TSPI_lineNegotiateTSPIVersion](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linenegotiatetspiversion)

[TSPI_providerInit](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_providerinit)