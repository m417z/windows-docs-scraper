# D3DDDI_ADAPTERCALLBACKS structure

## Description

The **D3DDDI_ADAPTERCALLBACKS** structure contains pointers to Direct3D runtime callback functions that the user-mode display driver (UMD) can use.

## Members

### `pfnQueryAdapterInfoCb`

Pointer to the [**pfnQueryAdapterInfoCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_queryadapterinfocb) function, which UMD uses to query the display miniport driver (KMD) for adapter configuration information.

### `pfnGetMultisampleMethodListCb`

Pointer to the [**pfnGetMultisampleMethodListCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getmultisamplemethodlistcb) function, which UMD uses to retrieve the list of multiple-sampling methods that are used for an allocation.

### `pfnQueryAdapterInfoCb2`

Pointer to the runtime's [**pfnQueryAdapterInfoCb2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_queryadapterinfocb2) function, which UMD uses to query the display miniport driver (KMD) for adapter information.

## Remarks

The Direct3D runtime passes **D3DDDI_ADAPTERCALLBACKS** to UMD when it calls UMD's [**OpenAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_openadapter) function.

## See also

[**D3DDDIARG_OPENADAPTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_openadapter)

[**Openadapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_openadapter)

[**pfnGetMultisampleMethodListCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getmultisamplemethodlistcb)

[**pfnQueryAdapterInfoCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_queryadapterinfocb)

[**pfnQueryAdapterInfoCb2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_queryadapterinfocb2)