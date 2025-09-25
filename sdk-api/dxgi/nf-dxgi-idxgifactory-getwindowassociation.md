# IDXGIFactory::GetWindowAssociation

## Description

Get the window through which the user controls the transition to and from full screen.

## Parameters

### `pWindowHandle` [out]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

A pointer to a window handle.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns a code that indicates success or failure. **S_OK** indicates success, [DXGI_ERROR_INVALID_CALL](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) indicates *pWindowHandle* was passed in as **NULL**.

## Remarks

**Note** If you call this API in a Session 0 process, it returns [DXGI_ERROR_NOT_CURRENTLY_AVAILABLE](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error).

## See also

[DXGI Interfaces](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-interfaces)

[IDXGIFactory](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgifactory)