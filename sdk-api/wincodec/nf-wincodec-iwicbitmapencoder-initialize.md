# IWICBitmapEncoder::Initialize

## Description

Initializes the encoder with an [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) which tells the encoder where to encode the bits.

## Parameters

### `pIStream` [in]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

The output stream.

### `cacheOption` [in]

Type: **[WICBitmapEncoderCacheOption](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicbitmapencodercacheoption)**

The [WICBitmapEncoderCacheOption](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicbitmapencodercacheoption) used on initialization.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.