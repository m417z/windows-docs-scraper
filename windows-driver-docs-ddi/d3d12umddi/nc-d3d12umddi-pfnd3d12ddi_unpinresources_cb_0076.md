# PFND3D12DDI_UNPINRESOURCES_CB_0076 callback function

## Description

Unpins a resource that has been pinned with [**PFND3D12DDI_PINRESOURCES_CB_0076**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_pinresources_cb_0076).

## Parameters

### `hRTDevice`

Handle that identifies the display device.

### `unnamedParam2`

A [**D3D12DDICB_UNPIN_RESOURCES_0076**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddicb_unpin_resources_0076) structure that provides the list of resources to unpin.

## Return value

Returns HRESULT.

## Prototype

```cpp
//Declaration

PFND3D12DDI_UNPINRESOURCES_CB_0076 Pfnd3d12ddiUnpinResources;

// Definition

HRESULT Pfnd3d12ddiUnpinResources
(
    D3D12DDI_HRTDEVICE hRTDevice,
    CONST D3D12DDICB_UNPIN_RESOURCES_0076*
)
{...}
```

## Remarks

## See also

[**D3D12DDICB_UNPIN_RESOURCES_0076**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddicb_unpin_resources_0076)

[**PFND3D12DDI_PINRESOURCES_CB_0076**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_pinresources_cb_0076)