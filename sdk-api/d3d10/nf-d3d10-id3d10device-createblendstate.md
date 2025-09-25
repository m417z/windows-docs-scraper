# ID3D10Device::CreateBlendState

## Description

Create a blend-state object that encapsulates blend state for the output-merger stage.

## Parameters

### `pBlendStateDesc` [in]

Type: **const [D3D10_BLEND_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_blend_desc)***

Pointer to a blend-state description (see [D3D10_BLEND_DESC](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_blend_desc)).

### `ppBlendState` [out]

Type: **[ID3D10BlendState](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10blendstate)****

Address of a pointer to the blend-state object created (see [ID3D10BlendState Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10blendstate)).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

An application can create up to 4096 unique blend-state objects. For each object created, the runtime checks to see if a previous object has the same state. If such a previous object exists, the runtime will return a pointer to previous instance instead of creating a duplicate object.

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)