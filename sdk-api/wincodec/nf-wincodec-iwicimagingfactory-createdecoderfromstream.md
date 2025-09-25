# IWICImagingFactory::CreateDecoderFromStream

## Description

Creates a new instance of the [IWICBitmapDecoder](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapdecoder) class based on the given [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream).

## Parameters

### `pIStream` [in]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

The stream to create the decoder from.

### `pguidVendor` [in]

Type: **const GUID***

The GUID for the preferred decoder vendor. Use **NULL** if no preferred vendor.

### `metadataOptions` [in]

Type: **[WICDecodeOptions](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicdecodeoptions)**

The [WICDecodeOptions](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicdecodeoptions) to use when creating the decoder.

### `ppIDecoder` [out, retval]

Type: **[IWICBitmapDecoder](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapdecoder)****

A pointer that receives a pointer to a new [IWICBitmapDecoder](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapdecoder).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.