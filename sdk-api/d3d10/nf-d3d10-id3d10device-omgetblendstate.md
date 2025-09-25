# ID3D10Device::OMGetBlendState

## Description

Get the [blend state](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-output-merger-stage) of the output-merger stage.

## Parameters

### `ppBlendState` [out]

Type: **[ID3D10BlendState](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10blendstate)****

Address of a pointer to a blend-state interface (see [ID3D10BlendState](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10blendstate)).

### `BlendFactor` [out]

Type: **[FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Array of blend factors, one for each RGBA component.

### `pSampleMask` [out]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Pointer to a [sample mask](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-omsetblendstate).

## Remarks

The reference count of the returned interface will be incremented by one when the blend state is retrieved. Applications must release returned pointer(s) when they are no longer needed, or else there will be a memory leak.

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)