# IDWriteFactory5::CreateHttpFontFileLoader

## Description

Creates a remote font file loader that can create font file references from HTTP or HTTPS URLs. The caller is responsible for registering and unregistering the loader.

## Parameters

### `referrerUrl`

Type: **wchar_t const***

Optional referrer URL for HTTP requests.

### `extraHeaders`

Type: **wchar_t const***

Optional additional header fields to include in HTTP requests. Each header field consists of a name followed by a colon (":") and the field value, as specified by RFC 2616. Multiple header fields may be separated by newlines.

### `newLoader` [out]

Type: **[IDWriteRemoteFontFileLoader](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwriteremotefontfileloader)****

Receives a pointer to the newly-created loader object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns an **HRESULT** success or error code.

## See also

[Creating a custom font set using known, remote fonts on the Web](https://learn.microsoft.com/windows/win32/directwrite/custom-font-sets-win10#creating-a-custom-font-set-using-known-remote-fonts-on-the-web)

[IDWriteFactory5](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefactory5)