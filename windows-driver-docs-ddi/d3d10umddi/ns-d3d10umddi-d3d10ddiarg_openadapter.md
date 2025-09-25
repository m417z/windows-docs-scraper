# D3D10DDIARG_OPENADAPTER structure

## Description

The D3D10DDIARG_OPENADAPTER structure describes the graphics adapter object.

## Members

### `hRTAdapter` [in]

A handle to the graphics adapter object that specifies the handle that the driver should use to query for graphics adapter capabilities when the driver calls the Microsoft Direct3D runtime-supplied [pfnQueryAdapterInfoCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_queryadapterinfocb) callback function.

### `hAdapter` [out]

A handle to the graphics adapter object that specifies the handle that the Direct3D runtime uses in subsequent driver calls to identify the graphics adapter object. The driver generates a unique handle and passes it back to the Direct3D runtime.

### `Interface` [in]

The Direct3D interface version. The high 16 bits store the major release number (such as 10, 11, and so on); the low 16 bits store the minor release number (such as 0, 1, 2, and so on). The minor release number will be increased when a change to the interface is released.

### `Version` [in]

A number that the driver can use to identify when the Direct3D runtime was built. The high 16 bits represent the build number; the low 16 bits represent the revision number.

The driver is required only to monitor the high 16 bits. The driver should ensure that the runtime build version that is passed in is greater than or equal to the current build version of the driver. The driver should return a failure from its [OpenAdapter10](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_openadapter) function if the passed in build version is incompatible.

### `pAdapterCallbacks` [in]

A pointer to a [D3DDDI_ADAPTERCALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_adaptercallbacks) structure that contains the Direct3D runtime-supplied **pfnQueryAdapterInfoCb** callback function that the driver can use.

### `pAdapterFuncs` [out]

A pointer to a [D3D10DDI_ADAPTERFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_adapterfuncs) structure that contains a table of user-mode display driver adapter-specific functions. The Direct3D runtime uses these functions to communicate with the user-mode display driver about operations that are specific to the graphics adapter.

### `pAdapterFuncs_2` [out]

Supported in Windows 7 and later versions.

A pointer to a [D3D10_2DDI_ADAPTERFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_2ddi_adapterfuncs) structure that contains a table of user-mode display driver adapter-specific functions. The Direct3D runtime uses these functions to communicate with the user-mode display driver about operations that are specific to the graphics adapter.

## See also

[D3D10DDI_ADAPTERFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_adapterfuncs)

[D3D10_2DDI_ADAPTERFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_2ddi_adapterfuncs)

[D3DDDI_ADAPTERCALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_adaptercallbacks)

[OpenAdapter10](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_openadapter)

[pfnQueryAdapterInfoCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_queryadapterinfocb)