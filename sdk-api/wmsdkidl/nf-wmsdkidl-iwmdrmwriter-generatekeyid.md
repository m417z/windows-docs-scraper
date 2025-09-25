# IWMDRMWriter::GenerateKeyID

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

[**GenerateKeyID** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Microsoft PlayReady](https://www.microsoft.com/PlayReady/).
]

The **GenerateKeyID** method generates a DRM key ID.

## Parameters

### `pwszKeyID` [out]

Pointer to a wide-character **null**-terminated string containing the key identifier. Set to **NULL** to retrieve the size of the string, which is returned in *pcwchLength*.

### `pcwchLength` [in, out]

Pointer to a **DWORD** containing the size, in wide characters, of *pwszKeyID*. This size includes the terminating **null** character.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## Remarks

Each file should have its own key ID.

## See also

[IWMDRMWriter Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmdrmwriter)