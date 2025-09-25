# IDXGIOutput::TakeOwnership

## Description

Takes ownership of an output.

## Parameters

### `pDevice` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface of a device (such as an [ID3D10Device](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)).

### `Exclusive`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Set to **TRUE** to enable other threads or applications to take ownership of the device; otherwise, set to **FALSE**.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error) values.

## Remarks

When you are finished with the output, call [IDXGIOutput::ReleaseOwnership](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgioutput-releaseownership).

**TakeOwnership** should not be called directly by applications, since results will be unpredictable. It is called implicitly by the DXGI swap chain object during full-screen transitions, and should not be used as a substitute for swap-chain methods.

### Notes for Windows Store apps

If a Windows Store app uses **TakeOwnership**, it fails with [DXGI_ERROR_NOT_CURRENTLY_AVAILABLE](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error).

## See also

[IDXGIOutput](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgioutput)