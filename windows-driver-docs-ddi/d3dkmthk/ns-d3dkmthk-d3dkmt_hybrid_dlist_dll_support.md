## Description

The **D3DKMT_HYBRID_DLIST_DLL_SUPPORT** structure indicates whether the adapter provides [dList DLL support on a hybrid system](https://learn.microsoft.com/windows-hardware/drivers/display/hybrid-system-ddi).

## Members

### `Supported`

If true, the adapter provides hybrid dList DLL support; otherwise, false.

## Remarks

Prior to WDDM 2.8, a driver identified as a hybrid discrete GPU was required to support the dList DDI (and provide the relevant registry keys). Starting in WDDM 2.8, IHVs can choose to support the dList DDI via [**D3DKMT_QUERYADAPTERINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_queryadapterinfo) for a [**KMTQUERYADAPTERINFOTYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-_kmtqueryadapterinfotype) of **KMTQAITYPE_HYBRID_DLIST_DLL_SUPPORT**.

For information on how to set up the DLL, see [Hybrid system DDI](https://learn.microsoft.com/windows-hardware/drivers/display/hybrid-system-ddi).

For more general information on hybrid systems, see [Using cross-adapter resources in a hybrid system](https://learn.microsoft.com/windows-hardware/drivers/display/using-cross-adapter-resources-in-a-hybrid-system).

## See also

[**D3DKMT_QUERYADAPTERINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_queryadapterinfo)

[**KMTQUERYADAPTERINFOTYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ne-d3dkmthk-_kmtqueryadapterinfotype)

[**Pfnd3dddiQuerydlistforapplication1**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_querydlistforapplication1)

[**Pfnd3dddiQuerydlistforapplication2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_querydlistforapplication2)