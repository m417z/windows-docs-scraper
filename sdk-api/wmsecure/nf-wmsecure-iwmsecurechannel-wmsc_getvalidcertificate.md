# IWMSecureChannel::WMSC_GetValidCertificate

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

[**WMSC_GetValidCertificate** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Microsoft PlayReady](https://www.microsoft.com/PlayReady/).
]

The **WMSC_GetValidCertificate** method returns a copy of the certificate that was used provided by the other side
of the connection. Also returns the index of the signature that validated
that certificate.

## Parameters

### `ppbCertificate` [out]

*ppbCertificate* must be released with [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) by the user.
*ppbCertificate* can be **NULL** if no certificate was provided.
If no connection was made, this function returns E_FAIL

### `pdwSignature` [out]

*pdwSignature* can be 0xFFFFFFFF if no signature was used to validate the cert.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWMSecureChannel](https://learn.microsoft.com/windows/desktop/api/wmsecure/nn-wmsecure-iwmsecurechannel)