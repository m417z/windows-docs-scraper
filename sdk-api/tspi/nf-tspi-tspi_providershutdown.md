# TSPI_providerShutdown function

## Description

The
**TSPI_providerShutdown** function shuts down the service provider. The service provider terminates any activities it has in progress and releases any resources it has allocated.

## Parameters

### `dwTSPIVersion`

The version of the TSPI definition under which this function must operate. The caller can use
[TSPI_lineNegotiateTSPIVersion](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linenegotiatetspiversion) or
[TSPI_phoneNegotiateTSPIVersion](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonenegotiatetspiversion) with the special *dwDeviceID*
[INITIALIZE_NEGOTIATION](https://learn.microsoft.com/windows/desktop/Tapi/initialize-negotiation) to negotiate a version that is guaranteed to be acceptable to the service provider.

### `dwPermanentProviderID`

This parameter allows the service provider to determine which among multiple possible instances of the service provider is being shut down. The value of the parameter is identical to that passed in the parameter of the same name in
[TSPI_providerInit](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_providerinit).

## Return value

Returns zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

LINEERR_INCOMPATIBLEAPIVERSION, LINEERR_NOMEM.

## Remarks

The final paired call to this function must be the last call to any of the TSPI functions prefixed with **TSPI_line** or **TSPI_phone** other than
[TSPI_lineNegotiateTSPIVersion](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linenegotiatetspiversion), or
[TSPI_phoneNegotiateTSPIVersion](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonenegotiatetspiversion). It is the caller's responsibility to ensure this.

This function should always succeed except in extraordinary circumstances. Most callers will probably ignore the return code because they will be unable to compensate for any error that occurs. The specified return values are more advisory for development diagnostic purposes than anything else.

There is no directly corresponding function in TAPI. In TAPI, multiple different usage instances can be outstanding, with an "application handle" parameter to identify the instance to be operated on. In TSPI, the interface architecture supports only a single usage instance for each distinct service provider.

## See also

[TSPI_lineNegotiateTSPIVersion](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linenegotiatetspiversion)

[TSPI_phoneNegotiateTSPIVersion](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonenegotiatetspiversion)

[TSPI_providerInit](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_providerinit)