# IDXGIDevice::GetGPUThreadPriority

## Description

Gets the GPU thread priority.

## Parameters

### `pPriority` [out]

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

A pointer to a variable that receives a value that indicates the current GPU thread priority. The value will be between -7 and 7, inclusive, where 0 represents normal priority.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Return S_OK if successful; otherwise, returns E_POINTER if the *pPriority* parameter is **NULL**.

## See also

[DXGI Interfaces](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-interfaces)

[IDXGIDevice](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgidevice)