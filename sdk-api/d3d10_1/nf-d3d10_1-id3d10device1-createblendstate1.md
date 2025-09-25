# ID3D10Device1::CreateBlendState1

## Description

Create a blend-state object that encapsulates blend state for the output-merger stage.

## Parameters

### `pBlendStateDesc` [in]

Type: **const [D3D10_BLEND_DESC1](https://learn.microsoft.com/windows/desktop/api/d3d10_1/ns-d3d10_1-d3d10_blend_desc1)***

Pointer to a blend-state description (see [D3D10_BLEND_DESC1](https://learn.microsoft.com/windows/desktop/api/d3d10_1/ns-d3d10_1-d3d10_blend_desc1)).

### `ppBlendState` [out]

Type: **[ID3D10BlendState1](https://learn.microsoft.com/windows/desktop/api/d3d10_1/nn-d3d10_1-id3d10blendstate1)****

Address of a pointer to the blend-state object created (see [ID3D10BlendState1 Interface](https://learn.microsoft.com/windows/desktop/api/d3d10_1/nn-d3d10_1-id3d10blendstate1)).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

An application can create up to 4096 unique blend-state objects. For each object created, the runtime checks to see if a previous object has the same state. If such a previous object exists, the runtime will return a pointer to previous instance instead of creating a duplicate object.

This method requires Windows Vista Service Pack 1.

## See also

[ID3D10Device1 Interface](https://learn.microsoft.com/windows/desktop/api/d3d10_1/nn-d3d10_1-id3d10device1)