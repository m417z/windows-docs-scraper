# ID3D11DeviceContext::RSGetViewports

## Description

Gets the array of viewports bound to the rasterizer stage.

## Parameters

### `pNumViewports` [in, out]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

A pointer to a variable that, on input, specifies the number of viewports (ranges from 0 to **D3D11_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE**)
in the *pViewports* array; on output, the variable contains the actual number of viewports that are bound to the rasterizer stage.
If *pViewports* is **NULL**, **RSGetViewports** fills the variable with the number of viewports currently bound.

**Note** In some versions of the Windows SDK, a [debug device](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-layers) will raise an exception if the input value in the variable to which *pNumViewports* points is greater than **D3D11_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE** even if *pViewports* is **NULL**. The regular runtime ignores the value in the variable to which *pNumViewports* points when *pViewports* is **NULL**. This behavior of a debug device might be corrected in a future release of the Windows SDK.

### `pViewports` [out, optional]

Type: **[D3D11_VIEWPORT](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_viewport)***

An array of [D3D11_VIEWPORT](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_viewport) structures for the viewports that are bound to the rasterizer stage. If the number of viewports (in the variable to which *pNumViewports* points) is
greater than the actual number of viewports currently bound, unused elements of the array contain 0.
For info about how the viewport size depends on the device [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro), which has changed between Direct3D 11
and Direct3D 10, see **D3D11_VIEWPORT**.

## Remarks

**Windows Phone 8:** This API is supported.

## See also

[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)