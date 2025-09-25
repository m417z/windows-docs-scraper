# TSPI_lineReceiveMSPData function

## Description

The
**TSPI_lineReceiveMSPData** function service provider receives data sent by the media service provider (MSP). This function requires TAPI 3.0 version negotiation.

## Parameters

### `hdLine`

Handle to line device.

### `hdCall`

Handle for call.

### `hdMSPLine`

MSP handle for the call.

### `pBuffer`

Pointer to buffer containing MSP data.

### `dwSize`

Size of MSP data buffer.

## Return value

Returns zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

## See also

[About The Media Service Provider (MSP)](https://learn.microsoft.com/windows/desktop/Tapi/about-the-media-service-provider-msp-)

[TSPI_lineCloseMSPInstance](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineclosemspinstance)

[TSPI_lineCreateMSPInstance](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linecreatemspinstance)

[TSPI_lineMSPIdentify](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linemspidentify)