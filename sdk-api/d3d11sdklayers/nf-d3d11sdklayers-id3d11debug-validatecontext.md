# ID3D11Debug::ValidateContext

## Description

Check to see if the draw pipeline state is valid.

## Parameters

### `pContext` [in]

Type: **[ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext)***

A pointer to the [ID3D11DeviceContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicecontext), that represents a device context.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

Use validate prior to calling a draw method (for example, [ID3D11DeviceContext::Draw](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11devicecontext-draw)); validation requires the debug layer.

## See also

[ID3D11Debug Interface](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/nn-d3d11sdklayers-id3d11debug)