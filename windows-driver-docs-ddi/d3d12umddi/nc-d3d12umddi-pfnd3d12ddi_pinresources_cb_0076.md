# PFND3D12DDI_PINRESOURCES_CB_0076 callback function

## Description

Marks the resource as not movable and not eligible to be paged out.

## Parameters

### `hRTDevice`

Handle that identifies the display device.

### `unnamedParam2`

A [**D3D12DDICB_PIN_RESOURCES_0076**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddicb_pinresources_0076) structure that provides the list of resources to pin.

## Return value

Returns HRESULT.

## Prototype

```cpp
//Declaration

PFND3D12DDI_PINRESOURCES_CB_0076 Pfnd3d12ddiPinResources;

// Definition

HRESULT Pfnd3d12ddiPinResources
(
    D3D12DDI_HRTDEVICE hRTDevice,
    CONST D3D12DDICB_PIN_RESOURCES_0076*
)
{...}
```

## Remarks

A resource that has been pinned can be unpinned by calling [**PFND3D12DDI_UNPINRESOURCES_CB_0076**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_unpinresources_cb_0076).

## See also

[**D3D12DDICB_PIN_RESOURCES_0076**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddicb_pinresources_0076)

[**PFND3D12DDI_UNPINRESOURCES_CB_0076**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_unpinresources_cb_0076)