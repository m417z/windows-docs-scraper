# IMFMediaKeys::Shutdown

## Description

Shuts down the associated Content Decryption Module (CDM).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Shutdown** should be called by the application before final release. The Content Decryption Module (CDM) reference and any other resources is released at this point. However, related sessions are not freed or closed.

## See also

[IMFMediaKeys](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediakeys)