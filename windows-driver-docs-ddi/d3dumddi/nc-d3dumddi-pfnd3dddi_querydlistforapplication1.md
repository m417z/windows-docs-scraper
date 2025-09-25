# PFND3DDDI_QUERYDLISTFORAPPLICATION1 callback function

## Description

The **PFND3DDDI_QUERYDLISTFORAPPLICATION1** function queries a dList for an application.

## Parameters

### `unnamedParam1` [out]

If **TRUE**, the application should be run on the discrete GPU. Otherwise, the application should run on the integrated GPU.

### `unnamedParam2` [in]

A handle to the graphics adapter object. This handle is passed to the [**pfnEscapeCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_escapecb) callback function pointed to by *unnamedParam3*.

### `unnamedParam3` [in]

Pointer to a [**pfnEscapeCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_escapecb) callback function that shares info with the display miniport driver.

## Return value

Returns **S_OK**, or an appropriate error result if the operation is not successful.

## Remarks

Starting with WDDM 2.9, drivers must support [**PFND3DDDI_QUERYDLISTFORAPPLICATION2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_querydlistforapplication2) instead of **PFND3DDDI_QUERYDLISTFORAPPLICATION1**.

In WDDM versions prior to WDDM 2.9, **PFND3DDDI_QUERYDLISTFORAPPLICATION1** is called by the user-mode graphics runtime (DXGI) during Microsoft Direct3D initialization on a [hybrid system](https://learn.microsoft.com/windows-hardware/drivers/display/using-cross-adapter-resources-in-a-hybrid-system) to determine which GPU an application should run on. A *dList* is a list of applications that need cross-adapter shared surfaces for high-performance rendering on the discrete GPU.

For more information on how to call this function and set up the DLL that exports it, see [Hybrid system DDI](https://learn.microsoft.com/windows-hardware/drivers/display/hybrid-system-ddi).

For more general information on hybrid systems, see [Using cross-adapter resources in a hybrid system](https://learn.microsoft.com/windows-hardware/drivers/display/using-cross-adapter-resources-in-a-hybrid-system).

## See also

[**PFND3DDDI_QUERYDLISTFORAPPLICATION2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_querydlistforapplication2)

[**pfnEscapeCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_escapecb)