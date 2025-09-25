# IDWriteRemoteFontFileLoader::CreateFontFileReferenceFromUrl

## Description

Creates a font file reference from a URL if the loader supports this capability.

## Parameters

### `factory`

Type: **[IDWriteFactory](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefactory)***

Factory used to create the font file reference.

### `baseUrl`

Type: **WCHAR**

Optional base URL. The base URL is used to resolve the fontFileUrl if it is relative. For example, the baseUrl might be the URL of the referring document
that contained the fontFileUrl.

### `fontFileUrl` [in]

Type: **WCHAR**

URL of the font resource.

### `fontFile` [out]

Type: **[IDWriteFontFile](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefontfile)****

Receives a pointer to the newly created font file reference.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an HRESULT success or error code.

## Remarks

If baseUrl is a non-empty string, then baseUrl concatenated with fontFileUrl should form a valid URL, DirectWrite will not supply any additional delimiter.

## See also

[Creating a custom font set using known, remote fonts on the Web](https://learn.microsoft.com/windows/win32/directwrite/custom-font-sets-win10#creating-a-custom-font-set-using-known-remote-fonts-on-the-web)

[IDWriteRemoteFontFileLoader](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwriteremotefontfileloader)