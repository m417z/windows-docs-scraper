# IDXGIResource::GetUsage

## Description

Get the expected resource usage.

## Parameters

### `pUsage`

Type: **[DXGI_USAGE](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-usage)***

A pointer to a usage flag (see [DXGI_USAGE](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-usage)). For Direct3D 10, a surface can be used as a shader input or a render-target output.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error).

## See also

[IDXGIResource](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiresource)