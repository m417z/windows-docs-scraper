# TSPI_lineCreateMSPInstance function

## Description

The
**TSPI_lineCreateMSPInstance** function directs the TAPI 3 DLL to create a media service provider (MSP) instance for a specific line device. This function returns a TSP handle for the MSP call. This function requires TAPI 3.0 version negotiation.

## Parameters

### `hdLine`

The service provider's handle to the line.

### `dwAddressID`

An address on the specified open line device. An address identifier is permanently associated with an address; the identifier remains constant across operating system upgrades.

### `htMSPLine`

The TAPI handle for the MSP call.

### `lphdMSPLine`

Pointer to the TSP handle for the MSP call.

## Return value

LINEERR_INVALLINEHANDLE, LINEERR_INVALPOINTER, NOERROR

## Remarks

The service provider should save the *htMSPLine* handle field, to be used when sending
[LINE_SENDMSPDATA](https://learn.microsoft.com/windows/desktop/Tapi/line-sendmspdata) messages to TAPISRV.

An MSP instance is associated with a particular application. If multiple applications are running, each TSP line may have multiple MSP instances.

## See also

[About The Media Service Provider (MSP)](https://learn.microsoft.com/windows/desktop/Tapi/about-the-media-service-provider-msp-)

[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps)

[TSPI_lineCloseMSPInstance](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineclosemspinstance)

[TSPI_lineMSPIdentify](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linemspidentify)

[TSPI_lineReceiveMSPData](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linereceivemspdata)