# IDXGIOutput::SetGammaControl

## Description

Sets the gamma controls.

## Parameters

### `pArray` [in]

Type: **const [DXGI_GAMMA_CONTROL](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb173061(v=vs.85))***

A pointer to a [DXGI_GAMMA_CONTROL](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb173061(v=vs.85)) structure that describes the gamma curve to set.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) values.

## Remarks

**Note** Calling this method is only supported while in full-screen mode.

For info about using gamma correction, see [Using gamma correction](https://learn.microsoft.com/windows/desktop/direct3ddxgi/using-gamma-correction).

## See also

[IDXGIOutput](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgioutput)