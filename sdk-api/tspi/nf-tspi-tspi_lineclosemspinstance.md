# TSPI_lineCloseMSPInstance function

## Description

The
**TSPI_lineCloseMSPInstance** function directs the TAPI 3 DLL to close a media service provider (MSP) call instance. This function requires TAPI 3.0 version negotiation.

## Parameters

### `hdMSPLine`

Pointer to the TSP handle for the MSP call.

## Return value

LINEERR_INVALPOINTER, NOERROR.

## Remarks

An MSP instance is associated with a particular application. If multiple applications are running, each TSP line may have multiple MSP instances.

## See also

[About The Media Service Provider (MSP)](https://learn.microsoft.com/windows/desktop/Tapi/about-the-media-service-provider-msp-)

[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps)

[TSPI_lineCreateMSPInstance](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linecreatemspinstance)

[TSPI_lineMSPIdentify](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linemspidentify)

[TSPI_lineReceiveMSPData](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linereceivemspdata)