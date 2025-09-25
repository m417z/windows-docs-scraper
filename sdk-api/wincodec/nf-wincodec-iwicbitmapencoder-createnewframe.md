# IWICBitmapEncoder::CreateNewFrame

## Description

Creates a new [IWICBitmapFrameEncode](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapframeencode) instance.

## Parameters

### `ppIFrameEncode` [out]

Type: **[IWICBitmapFrameEncode](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapframeencode)****

A pointer that receives a pointer to the new instance of an [IWICBitmapFrameEncode](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapframeencode).

### `ppIEncoderOptions` [in, out]

Type: **[IPropertyBag2](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa768192(v=vs.85))****

Optional. Receives the named properties to use for subsequent frame initialization. See Remarks.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The parameter *ppIEncoderOptions* can be used to receive an [IPropertyBag2](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa768192(v=vs.85)) that can then be used to specify encoder options. This is done by passing a pointer to a **NULL** IPropertyBag2 pointer in *ppIEncoderOptions*. The returned IPropertyBag2 is initialized with all encoder options that are available for the given format, at their default values. To specify non-default encoding behavior, set the needed encoder options on the IPropertyBag2 and pass it to [IWICBitmapFrameEncode::Initialize](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapframeencode-initialize).

**Note** Do not pass in a pointer to an initialized [IPropertyBag2](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa768192(v=vs.85)). The pointer will be overwritten, and the original IPropertyBag2 will not be freed.

Otherwise, you can pass **NULL** in *ppIEncoderOptions* if you do not intend to specify encoder options.

See [Encoding Overview](https://learn.microsoft.com/windows/desktop/wic/-wic-creating-encoder) for an example of how to set encoder options.

For formats that support encoding multiple frames (for example, TIFF, JPEG-XR), you can work on only one frame at a time. This means that you must call [IWICBitmapFrameEncode::Commit](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapframeencode-commit) before you call **CreateNewFrame** again.

## See also

[Encoding Overview](https://learn.microsoft.com/windows/desktop/wic/-wic-creating-encoder)

[IPropertyBag2](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa768192(v=vs.85))

[IWICBitmapEncoder](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapencoder)