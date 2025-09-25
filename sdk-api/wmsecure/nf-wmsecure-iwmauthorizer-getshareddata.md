# IWMAuthorizer::GetSharedData

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

[**GetSharedData** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Microsoft PlayReady](https://www.microsoft.com/PlayReady/).
]

Retrieves shared data for the specified certificate.

## Parameters

### `dwCertIndex` [in]

### `pbSharedData` [in]

### `pbCert` [in]

### `ppbSharedData` [out]

An address of a pointer to certification data. *ppbCertData* is allocated with [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc) and must be released by the user.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWMAuthorizer](https://learn.microsoft.com/windows/desktop/api/wmsecure/nn-wmsecure-iwmauthorizer)