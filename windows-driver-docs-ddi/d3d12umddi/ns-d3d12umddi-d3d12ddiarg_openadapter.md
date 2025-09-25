# D3D12DDIARG_OPENADAPTER structure

## Description

The D3D12DDIARG_OPENADAPTER structure describes the graphics adapter object.

## Members

### `hRTAdapter` [in]

A runtime handle to the graphics adapter object that specifies the handle that the driver should use to query for graphics adapter capabilities when the driver calls the Microsoft Direct3D runtime-supplied [pfnQueryAdapterInfoCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_queryadapterinfocb) callback function.

### `hAdapter` [out]

A handle to the graphics adapter object that specifies the handle that the Direct3D runtime uses in subsequent driver calls to identify the graphics adapter object. The driver generates a unique handle and passes it back to the Direct3D runtime.

### `pAdapterCallbacks` [in]

A pointer to a [D3DDDI_ADAPTERCALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_adaptercallbacks) structure that contains the Direct3D runtime-supplied **pfnQueryAdapterInfoCb** callback function that the driver can use.

### `pAdapterFuncs` [out]

A pointer to a D3D12DDI_ADAPTERFUNCS structure that contains a table of user-mode display driver adapter-specific functions. The Direct3D runtime uses these functions to communicate with the user-mode display driver about operations that are specific to the graphics adapter.