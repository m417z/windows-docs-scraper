## Description

A **D3DDDI_DLIST_QUERY_DECISION_FACTOR** enum value describes the factor that determined the GPU preference returned by [**pfnQueryDlistForApplication2Cb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_querydlistforapplication2).

## Constants

### `D3DDDI_DLIST_QUERY_DECISION_FACTOR_UNDEFINED`

The factor is unknown or not represented by the available enum values.

### `D3DDDI_DLIST_QUERY_DECISION_FACTOR_DLIST_APP_ENTRY`

GPU preference was determined by dList app entry.

### `D3DDDI_DLIST_QUERY_DECISION_FACTOR_APP_SPECIFIED_BY_USER`

GPU preference was determined by user-specified preference for this specific app.

### `D3DDDI_DLIST_QUERY_DECISION_FACTOR_GLOBAL_PREFERENCE_BY_USER`

GPU preference was determined by user-specified global preference.

## Remarks

The **D3DDDI_DLIST_QUERY_DECISION_FACTOR** value returned by [**pfnQueryDlistForApplication2Cb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_querydlistforapplication2) has no impact on runtime application behavior.

## See also

[**D3DDDI_DLIST_QUERY_RESULT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-d3dddi_dlist_query_result)

[**pfnQueryDlistForApplication2Cb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_querydlistforapplication2)