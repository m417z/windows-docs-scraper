## Description

A **D3DDDI_DLIST_QUERY_RESULT** enum value describes the GPU preference returned by [**pfnQueryDlistForApplication2Cb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_querydlistforapplication2) for the queried application.

## Constants

### `D3DDDI_DLIST_QUERY_RESULT_NO_DATA`

There is no GPU preference for this app.

### `D3DDDI_DLIST_QUERY_RESULT_POWER_SAVING_PREFERENCE`

The preference is to run this app on the power saving (also known as the default) GPU.

### `D3DDDI_DLIST_QUERY_RESULT_HIGH_PERFORMANCE_PREFERENCE`

The preference is to run this app on the high performance GPU.

## See also

[**D3DDDI_DLIST_QUERY_DECISION_FACTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-d3dddi_dlist_query_decision_factor)

[**pfnQueryDlistForApplication2Cb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_querydlistforapplication2)