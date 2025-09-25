## Description

The **PFND3DDDI_QUERYDLISTFORAPPLICATION2** callback function queries the dList for an application.

## Parameters

### `unnamedParam1` [out]

Pointer to a [**D3DDDI_DLIST_QUERY_RESULT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-d3dddi_dlist_query_result) value that describes the returned GPU preference for the queried application.

### `unnamedParam2` [out]

Pointer to a [**D3DDDI_DLIST_QUERY_DECISION_FACTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-d3dddi_dlist_query_decision_factor) value that describes the factor that determined the returned GPU preference.

### `unnamedParam3` [in]

A handle to the graphics adapter object. This handle is passed to the [**pfnEscapeCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_escapecb) callback function pointed to by *unnamedParam4*.

### `unnamedParam4` [in]

Pointer to a [**pfnEscapeCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_escapecb) callback function that shares info with the display miniport driver.

## Return value

Returns **S_OK**, or an appropriate error result if the operation is not successful.

## Remarks

Starting with WDDM 2.9, drivers must support **PFND3DDDI_QUERYDLISTFORAPPLICATION2** instead of [**PFND3DDDI_QUERYDLISTFORAPPLICATION1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_querydlistforapplication1).

The **PFND3DDDI_QUERYDLISTFORAPPLICATION2** callback function is called by the user-mode graphics runtime (DXGI) during Microsoft Direct3D initialization on a hybrid system to determine which GPU an application should run on. A *dList* is a list of applications that need cross-adapter shared surfaces for high-performance rendering on the discrete GPU.

The [**D3DDDI_DLIST_QUERY_RESULT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-d3dddi_dlist_query_result) and [**D3DDDI_DLIST_QUERY_DECISION_FACTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-d3dddi_dlist_query_decision_factor) returned in this DDI help the runtime to ensure and improve the quality of DxDb content updates, by assessing for risk of application regressions for an update.

Hybrid system drivers need to [set up and register a dList DLL](https://learn.microsoft.com/windows-hardware/drivers/display/hybrid-system-ddi) that exports this function. For more information on hybrid systems, see [Using cross-adapter resources in a hybrid system](https://learn.microsoft.com/windows-hardware/drivers/display/using-cross-adapter-resources-in-a-hybrid-system).

## See also

[**D3DDDI_DLIST_QUERY_DECISION_FACTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-d3dddi_dlist_query_decision_factor)

[**D3DDDI_DLIST_QUERY_RESULT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-d3dddi_dlist_query_result)

[**pfnEscapeCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_escapecb)