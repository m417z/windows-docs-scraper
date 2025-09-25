# IMFMediaEngineProtectedContent::SetApplicationCertificate

## Description

Sets the application's certificate.

## Parameters

### `pbBlob` [in]

A pointer to a buffer that contains the certificate in X.509 format, followed by the application identifier signed with a SHA-256 signature using the private key from the certificate.

### `cbBlob` [in]

The size of the *pbBlob* buffer, in bytes.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Call this method to access protected video content in frame-server mode.

## See also

[IMFMediaEngineProtectedContent](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengineprotectedcontent)