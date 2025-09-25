# PFND3D11_1DDI_CALCPRIVATECRYPTOSESSIONSIZE callback function

## Description

Returns the number of bytes that the driver requires to store private data for the cryptographic session state.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `pCreateData`

A pointer to a [D3D11_1DDIARG_CREATECRYPTOSESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddiarg_createcryptosession) structure that describes the cryptographic session.

## Return value

The required number of bytes for the cryptographic session state.

## Remarks

The runtime will validate the members of the [D3D11_1DDIARG_CREATECRYPTOSESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddiarg_createcryptosession) structure before it calls this function.

This function is not expected to fail.

## See also

[D3D11_1DDIARG_CREATECRYPTOSESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d11_1ddiarg_createcryptosession)