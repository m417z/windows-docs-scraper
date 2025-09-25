# IDXGIOutput::GetGammaControlCapabilities

## Description

Gets a description of the gamma-control capabilities.

## Parameters

### `pGammaCaps` [out]

Type: **[DXGI_GAMMA_CONTROL_CAPABILITIES](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb173062(v=vs.85))***

A pointer to a description of the gamma-control capabilities (see [DXGI_GAMMA_CONTROL_CAPABILITIES](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb173062(v=vs.85))).

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) values.

## Remarks

**Note** Calling this method is only supported while in full-screen mode.

For info about using gamma correction, see [Using gamma correction](https://learn.microsoft.com/windows/desktop/direct3ddxgi/using-gamma-correction).

## See also

[IDXGIOutput](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgioutput)