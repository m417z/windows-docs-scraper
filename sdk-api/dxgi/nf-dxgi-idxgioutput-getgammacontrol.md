# IDXGIOutput::GetGammaControl

## Description

Gets the gamma control settings.

## Parameters

### `pArray` [out]

Type: **[DXGI_GAMMA_CONTROL](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb173061(v=vs.85))***

An array of gamma control settings (see [DXGI_GAMMA_CONTROL](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb173061(v=vs.85))).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) values.

## Remarks

**Note** Calling this method is only supported while in full-screen mode.

For info about using gamma correction, see [Using gamma correction](https://learn.microsoft.com/windows/desktop/direct3ddxgi/using-gamma-correction).

## See also

[IDXGIOutput](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgioutput)