## Description

Structure containing callback functions that pin and unpin resources.

## Members

### `pfnPinResourcesCb`

A [**PFND3D12DDI_PINRESOURCES_CB_0076**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_pinresources_cb_0076) callback.

### `pfnUnpinResourcesCb`

A [**PFND3D12DDI_UNPINRESOURCES_CB_0076**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_unpinresources_cb_0076) callback.

## Remarks

Drivers that advertise the optional [D3D12DDI_FEATURE_0076_PIN_RESOURCES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_feature_0020) extended feature receive a [**PFND3D12DDI_SET_EXTENDED_FEATURE_CALLBACKS_0021**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_set_extended_feature_callbacks_0021) call with a DDI table type of D3D12DDI_TABLE_TYPE_0076_PIN_RESOURCES_CALLBACKS and this structure filled out with the callback pointers that the driver can use to perform these functions.

## See also

[D3D12DDI_FEATURE_0076_PIN_RESOURCES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_feature_0020)

[**PFND3D12DDI_PINRESOURCES_CB_0076**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_pinresources_cb_0076)

[**PFND3D12DDI_SET_EXTENDED_FEATURE_CALLBACKS_0021**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_set_extended_feature_callbacks_0021)

[**PFND3D12DDI_UNPINRESOURCES_CB_0076**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_unpinresources_cb_0076)