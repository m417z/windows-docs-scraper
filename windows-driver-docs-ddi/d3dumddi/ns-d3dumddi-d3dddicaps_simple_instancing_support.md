# D3DDDICAPS_SIMPLE_INSTANCING_SUPPORT structure

## Description

Describes whether simple instancing is supported.

## Members

### `SimpleInstancingSupported`

Specifies whether the hardware and the user-mode driver support simple instancing. The Direct3D runtime sets this member to **TRUE** if the hardware and driver support simple instancing and the driver is a Direct3D Level 9 driver and supports Windows Display Driver Model (WDDM) 1.3 and later. Otherwise this member is **FALSE**.

Used only by Direct3D Level 9 drivers that support WDDM 1.3 and later.

Supported starting with Windows 8.1.

## Remarks

Instancing capabilities are exposed through the **D3DDDICAPS_GET_SIMPLE_INSTANCING_SUPPORT** constant value of the [D3DDDICAPS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_d3dddicaps_type) enumeration.

For more info on simple instancing, see The Microsoft Direct3D 11 topic, [D3D11_FEATURE_DATA_D3D9_SIMPLE_INSTANCING_SUPPORT](https://learn.microsoft.com/windows/win32/api/d3d11/ns-d3d11-d3d11_feature_data_d3d9_simple_instancing_support).

## See also

[D3D11_FEATURE_DATA_D3D9_SIMPLE_INSTANCING_SUPPORT](https://learn.microsoft.com/windows/win32/api/d3d11/ns-d3d11-d3d11_feature_data_d3d9_simple_instancing_support)

[D3DDDICAPS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_d3dddicaps_type)