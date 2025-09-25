# D3DDDIARG_OPENADAPTER structure

## Description

The **D3DDDIARG_OPENADAPTER** structure contains information that describes the graphics adapter object.

## Members

### `hAdapter` [in/out]

A handle to the graphics adapter object. On input to the [**OpenAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_openadapter) function, **hAdapter** specifies the handle that the user-mode display driver (UMD) should use to query for graphics adapter capabilities when the driver calls the Direct3D runtime-supplied [**pfnQueryAdapterInfoCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_queryadapterinfocb) callback function.

The UMD generates a unique handle and passes it back to the Direct3D runtime. On output from the [**OpenAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_openadapter) function, **hAdapter** specifies the handle that the Direct3D runtime uses in subsequent driver calls to identify the graphics adapter object.

### `Interface` [in]

The Direct3D/DirectDraw interface version (for example, 9, 10, 11, 12) that opens the graphics adapter.

### `Version` [in]

A number that the driver can use to identify when the Direct3D/DirectDraw runtime was built. For example, the driver can use the version number to differentiate between a runtime that is released with Windows Vista and a runtime that is released with a subsequent service pack, which might contain a fix that the driver requires.

### `pAdapterCallbacks` [in]

A pointer to a [**D3DDDI_ADAPTERCALLBACKS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_adaptercallbacks) structure that contains the Direct3D runtime-supplied callback functions that the driver can use, including:

* [**pfnQueryAdapterInfoCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_queryadapterinfocb)
* [**pfnGetMultisampleMethodListCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getmultisamplemethodlistcb)
* [**pfnQueryAdapterInfoCb2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_queryadapterinfocb2)

### `pAdapterFuncs` [out]

A pointer to a [**D3DDDI_ADAPTERFUNCS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_adapterfuncs) structure that contains a table of UMD adapter-specific functions. The Direct3D runtime uses these functions to communicate with the UMD about operations that are specific to the graphics adapter.

### `DriverVersion` [out]

The version of the Direct3D UMD's interface, which was obtained from the *D3dumddi.h* header file, that the driver was compiled with. The UMD should return D3D_UMD_INTERFACE_VERSION.

## See also

[**D3DDDI_ADAPTERCALLBACKS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_adaptercallbacks)

[**D3DDDI_ADAPTERFUNCS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_adapterfuncs)

[**OpenAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_openadapter)

[**pfnQueryAdapterInfoCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_queryadapterinfocb)