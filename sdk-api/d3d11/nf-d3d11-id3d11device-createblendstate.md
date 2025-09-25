# ID3D11Device::CreateBlendState

## Description

Create a blend-state object that encapsulates blend state for the output-merger stage.

## Parameters

### `pBlendStateDesc` [in]

Type: **const [D3D11_BLEND_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_blend_desc)***

Pointer to a blend-state description (see [D3D11_BLEND_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_blend_desc)).

### `ppBlendState` [out, optional]

Type: **[ID3D11BlendState](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11blendstate)****

Address of a pointer to the blend-state object created (see [ID3D11BlendState](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11blendstate)).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns E_OUTOFMEMORY if there is insufficient memory to create the blend-state object.
See [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues) for other possible return values.

## Remarks

An application can create up to 4096 unique blend-state objects. For each object created, the runtime checks to see if a previous object
has the same state. If such a previous object exists, the runtime will return a pointer to previous instance instead of creating a duplicate object.

**Windows Phone 8:** This API is supported.

## See also

[ID3D11Device](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11device)