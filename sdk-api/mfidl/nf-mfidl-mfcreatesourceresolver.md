# MFCreateSourceResolver function

## Description

Creates the source resolver, which is used to create a media source from a URL or byte stream.

## Parameters

### `ppISourceResolver` [out]

Receives a pointer to the source resolver's [IMFSourceResolver](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsourceresolver) interface. The caller must release the interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Note** Prior to Windows 7, this function was exported from mf.dll. Starting in Windows 7, this function is exported from mfplat.dll, and mf.dll exports a stub function that calls into mfplat.dll. For more information, see [Library Changes in Windows 7](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-headers-and-libraries).

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Source Resolver](https://learn.microsoft.com/windows/desktop/medfound/source-resolver)