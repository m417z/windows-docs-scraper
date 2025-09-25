## Description

Retrieves a frame for a chain of a given type.

## Parameters

### `chainType`

Type: **[WICBitmapChainType](https://learn.microsoft.com/windows/win32/api/wincodec/ne-wincodec-wicbitmapchaintype)**

The chain type for which to retrieve a frame.

### `index`

Type: **[UINT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The index of the frame to retrieve.

### `ppIBitmapFrame`

Type: **[IWICBitmapFrameDecode](https://learn.microsoft.com/windows/win32/api/wincodec/nn-wincodec-iwicbitmapframedecode)\*\***

Receives the frame at *index* for chains of type *chainType*.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/desktop/com/com-error-codes-10).

## Remarks

## See also