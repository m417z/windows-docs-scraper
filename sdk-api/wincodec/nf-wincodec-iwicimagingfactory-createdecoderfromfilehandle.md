# IWICImagingFactory::CreateDecoderFromFileHandle

## Description

Creates a new instance of the [IWICBitmapDecoder](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapdecoder) based on the given file handle.

## Parameters

### `hFile` [in]

Type: **ULONG_PTR**

The file handle to create the decoder from.

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

## Remarks

When a decoder is created using this method, the file handle must remain alive during the lifetime of the decoder.

## See also

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[IWICImagingFactory](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicimagingfactory)