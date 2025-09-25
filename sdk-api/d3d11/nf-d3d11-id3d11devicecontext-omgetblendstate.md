# ID3D11DeviceContext::OMGetBlendState

## Description

Get the blend state of the output-merger stage.

## Parameters

### `ppBlendState` [out, optional]

Type: **[ID3D11BlendState](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11blendstate)****

Address of a pointer to a blend-state interface (see [ID3D11BlendState](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11blendstate)).

### `BlendFactor` [out, optional]

Type: **[FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)[4]**

Array of blend factors, one for each RGBA component.

### `pSampleMask` [out, optional]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Pointer to a [sample mask](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-omsetblendstate).

## Remarks

The reference count of the returned interface will be incremented by one when the blend state is retrieved. Applications must release returned pointer(s) when they are no longer needed, or else there will be a memory leak.

**Windows Phone 8:** This API is supported.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)