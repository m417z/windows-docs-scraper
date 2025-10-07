# IWICImagingFactory\_CreateDecoderFromFilename\_Proxy function

Proxy function for the [**CreateDecoderFromFilename**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nf-wincodec-iwicimagingfactory-createdecoderfromfilename) method.

## Parameters

*pFactory* \[in\]

Type: **IWICImagingFactory \***

*wzFilename* \[in\]

Type: **LPCWSTR**

A pointer to a null-terminated string that specifies the name of an object to create or open.

*pguidVendor* \[in\]

Type: **const GUID\***

The vendor GUID for the decoder.

*dwDesiredAccess* \[in\]

Type: **DWORD**

The access to the object, which can be read, write, or both.

For more information, see [File Security and Access Rights \[Files\]](https://learn.microsoft.com/windows/win32/fileio/file-security-and-access-rights).

*metadataOptions* \[in\]

Type: **[**WICDecodeOptions**](https://learn.microsoft.com/windows/desktop/api/Wincodec/ne-wincodec-wicdecodeoptions)**

The [**WICDecodeOptions**](https://learn.microsoft.com/windows/desktop/api/Wincodec/ne-wincodec-wicdecodeoptions) to use when creating the decoder.

*ppIDecoder* \[out\]

Type: **[**IWICBitmapDecoder**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapdecoder)\*\***

A pointer that receives a pointer to the new [**IWICBitmapDecoder**](https://learn.microsoft.com/windows/desktop/api/Wincodec/nn-wincodec-iwicbitmapdecoder).

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S\_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

## Requirements

| Requirement | Value |
|-------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP with SP2, Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| DLL<br> | Windowscodecs.dll;

Wincodec.lib |