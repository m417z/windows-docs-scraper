# D3D11_FEATURE_DATA_D3D9_SIMPLE_INSTANCING_SUPPORT structure

## Description

**Note** This structure is supported by the Direct3D 11.2 runtime, which is available on Windows 8.1 and later operating systems.

Describes whether simple instancing is supported.

## Members

### `SimpleInstancingSupported`

Specifies whether the hardware and driver support simple instancing. The runtime sets this member to **TRUE** if the hardware and driver support simple instancing.

## Remarks

If the Direct3D API is the Direct3D 11.2 runtime and can support 11.2 features, [ID3D11Device::CheckFeatureSupport](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-checkfeaturesupport) for **D3D11_FEATURE_D3D9_SIMPLE_INSTANCING_SUPPORT** will return a SUCCESS code when valid parameters are passed. The **SimpleInstancingSupported** member of **D3D11_FEATURE_DATA_D3D9_SIMPLE_INSTANCING_SUPPORT** will be set to **TRUE** or **FALSE**.

Simple instancing means that instancing is supported with the caveat that the **InstanceDataStepRate** member of the [D3D11_INPUT_ELEMENT_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_input_element_desc) structure must be equal to 1. This does not change the full instancing support provided by hardware at feature level 9.3 and above, and is meant to expose the instancing support that may be available on feature level 9.2 and 9.1 hardware.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-structures)

[D3D11_FEATURE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_feature)