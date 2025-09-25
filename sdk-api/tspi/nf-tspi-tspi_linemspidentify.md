# TSPI_lineMSPIdentify function

## Description

The
**TSPI_lineMSPIdentify** function determines the associated MSP CLSID for every line. This function requires TAPI 3.0 version negotiation.

## Parameters

### `dwDeviceID`

The line device whose CLSID is requested.

### `pCLSID`

The TSP fills in the CLSID of the MSP to be created for the line device indicated in *dwDeviceID*.

## Return value

Returns zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

## Remarks

Note that TAPI 3 calls
**TSPI_lineMSPIdentify** only if the LINEDEVCAPFLAGS_MSP flag is set in the TSP. (You can set
[LINEDEVCAPFLAGS_constants](https://learn.microsoft.com/windows/desktop/Tapi/linedevcapflags--constants) in the **dwDevCapFlags** member of the
[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps) structure.)

If the device does not have an associated MSP, the TSP returns LINEERR_OPERATIONUNAVAIL.

## See also

[About The Media Service Provider (MSP)](https://learn.microsoft.com/windows/desktop/Tapi/about-the-media-service-provider-msp-)

[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps)

[TSPI_lineCloseMSPInstance](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineclosemspinstance)

[TSPI_lineCreateMSPInstance](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linecreatemspinstance)

[TSPI_lineReceiveMSPData](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linereceivemspdata)