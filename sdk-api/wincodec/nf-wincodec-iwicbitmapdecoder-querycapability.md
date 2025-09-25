# IWICBitmapDecoder::QueryCapability

## Description

Retrieves the capabilities of the decoder based on the specified stream.

## Parameters

### `pIStream` [in]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

The stream to retrieve the decoder capabilities from.

### `pdwCapability` [out]

Type: **DWORD***

The [WICBitmapDecoderCapabilities](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicbitmapdecodercapabilities) of the decoder.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Custom decoder implementations should save the current position of the specified [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream), read whatever information is necessary in order to determine which capabilities it can provide for the supplied stream, and restore the stream position.