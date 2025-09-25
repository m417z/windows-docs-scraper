# ID3D11DeviceContext::ClearState

## Description

Restore all default settings.

## Remarks

This method resets any device context to the default settings. This sets all input/output resource slots, shaders, input layouts, predications, scissor rectangles, depth-stencil state, rasterizer state, blend state, sampler state, and viewports to **NULL**. The primitive topology is set to UNDEFINED.

For a scenario where you would like to clear a list of commands recorded so far, call [ID3D11DeviceContext::FinishCommandList](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-finishcommandlist) and throw away the resulting [ID3D11CommandList](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11commandlist).

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)