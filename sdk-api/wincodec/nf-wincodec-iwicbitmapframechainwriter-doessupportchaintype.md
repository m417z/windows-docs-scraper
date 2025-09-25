## Description

Determines whether the specified chain type is supported.

## Parameters

### `chainType`

Type: **[WICBitmapChainType](https://learn.microsoft.com/windows/win32/api/wincodec/ne-wincodec-wicbitmapchaintype)**

The specified chain type to query about.

### `pfIsSupported`

Type: **[BOOL](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

Used to retrieve a value indicating whether the chain type specified in *chainType* is supported. **TRUE** if it's supported; otherwise, **FALSE**.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/desktop/com/com-error-codes-10).

## Remarks

## See also