# IWICBitmapDecoder::Initialize

## Description

Initializes the decoder with the provided stream.

## Parameters

### `pIStream` [in]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

The stream to use for initialization.

The stream contains the encoded pixels which are decoded each time the [CopyPixels](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapsource-copypixels) method on the [IWICBitmapFrameDecode](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapframedecode) interface (see [GetFrame](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapdecoder-getframe)) is invoked.

### `cacheOptions` [in]

Type: **[WICDecodeOptions](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicdecodeoptions)**

The [WICDecodeOptions](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicdecodeoptions) to use for initialization.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.