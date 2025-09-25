# IWICBitmapFrameEncode::Initialize

## Description

Initializes the frame encoder using the given properties.

## Parameters

### `pIEncoderOptions` [in]

Type: **[IPropertyBag2](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa768192(v=vs.85))***

The set of properties to use for [IWICBitmapFrameEncode](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapframeencode) initialization.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If you don't want any encoding options, pass **NULL** for *pIEncoderOptions*. Otherwise, pass the [IPropertyBag2](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa768192(v=vs.85)) that was provided by [IWICBitmapEncoder::CreateNewFrame](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapencoder-createnewframe) with updated values.

For a complete list of encoding options supported by the Windows-provided codecs, see [Native WIC Codecs](https://learn.microsoft.com/windows/desktop/wic/native-wic-codecs).