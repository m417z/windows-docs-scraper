# ID3D11Device1::CreateBlendState1

## Description

Creates a blend-state object that encapsulates blend state for the [output-merger stage](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-merger-stage) and allows the configuration of logic operations.

## Parameters

### `pBlendStateDesc` [in]

A pointer to a [D3D11_BLEND_DESC1](https://learn.microsoft.com/windows/win32/api/d3d11_1/ns-d3d11_1-d3d11_blend_desc1) structure that describes blend state.

### `ppBlendState` [out, optional]

Address of a pointer to the [ID3D11BlendState1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nn-d3d11_1-id3d11blendstate1) interface for the blend-state object created.

## Return value

This method returns E_OUTOFMEMORY if there is insufficient memory to create the blend-state object.
See [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues) for other possible return values.

## Remarks

The logical operations (those that enable bitwise logical operations between pixel shader output and render target contents, refer to [D3D11_RENDER_TARGET_BLEND_DESC1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/ns-d3d11_1-d3d11_render_target_blend_desc1) ) are only available on certain feature levels; call [CheckFeatureSupport](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-checkfeaturesupport) with D3D11_FEATURE_D3D11_OPTIONS set, to ensure support by checking the boolean field *OutputMergerLogicOp* of [D3D11_FEATURE_DATA_D3D11_OPTIONS](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options).

An app can create up to 4096 unique blend-state objects. For each object created, the runtime checks to see if a previous object
has the same state. If such a previous object exists, the runtime will return a pointer to previous instance instead of creating a duplicate object.

## See also

[ID3D11Device1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nn-d3d11_1-id3d11device1)