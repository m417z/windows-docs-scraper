## Description

Creates a frame that's linked to a chain of a given type.

## Parameters

### `chainType`

Type: **[WICBitmapChainType](https://learn.microsoft.com/windows/win32/api/wincodec/ne-wincodec-wicbitmapchaintype)**

The chain type to link the new frame to.

### `ppIFrameEncode`

Type: **[IWICBitmapFrameEncode](https://learn.microsoft.com/windows/win32/api/wincodec/nn-wincodec-iwicbitmapframeencode)\*\***

Receives the new frame for a chain of type *chainType*.

### `ppIEncoderOptions`

Type: **[IPropertyBag2](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa768192(v=vs.85))\*\***

Optional. Receives the named properties to use for subsequent frame initialization. For more info, see the **Remarks** in the [IWICBitmapEncoder::CreateNewFrame](https://learn.microsoft.com/windows/win32/api/wincodec/nf-wincodec-iwicbitmapencoder-createnewframe) topic.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/desktop/com/com-error-codes-10).

## Remarks

## See also