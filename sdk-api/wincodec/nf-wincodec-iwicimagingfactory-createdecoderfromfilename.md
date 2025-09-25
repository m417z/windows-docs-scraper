# IWICImagingFactory::CreateDecoderFromFilename

## Description

Creates a new instance of the [IWICBitmapDecoder](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapdecoder) class based on the given file.

## Parameters

### `wzFilename` [in]

Type: **LPCWSTR**

A pointer to a null-terminated string that specifies the name of an object to create or open.

### `pguidVendor` [in]

Type: **const GUID***

The GUID for the preferred decoder vendor. Use **NULL** if no preferred vendor.

### `dwDesiredAccess` [in]

Type: **DWORD**

The access to the object, which can be read, write, or both.

| Value | Meaning |
| --- | --- |
| GENERIC_READ | Read access. |
| GENERIC_WRITE | Write access. |

For more information, see [Generic Access Rights](https://learn.microsoft.com/windows/desktop/SecAuthZ/generic-access-rights).

### `metadataOptions` [in]

Type: **[WICDecodeOptions](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicdecodeoptions)**

The [WICDecodeOptions](https://learn.microsoft.com/windows/desktop/api/wincodec/ne-wincodec-wicdecodeoptions) to use when creating the decoder.

### `ppIDecoder` [out, retval]

Type: **[IWICBitmapDecoder](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapdecoder)****

A pointer that receives a pointer to the new [IWICBitmapDecoder](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicbitmapdecoder).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.