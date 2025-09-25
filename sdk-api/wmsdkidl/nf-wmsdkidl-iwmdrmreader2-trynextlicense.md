# IWMDRMReader2::TryNextLicense

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

[**TryNextLicense** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [Microsoft PlayReady](https://www.microsoft.com/PlayReady/).
]

The **TryNextLicense** method sets the reader to evaluate the next applicable license (if present) for the file loaded in the reader.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **DRM_S_FALSE** | There are no more licenses for this content. |
| **NS_E_INVALID_REQUEST** | No file is opened in the reader. |
| **NS_E_DRM_RIV_TOO_SMALL** | An updated content revocation list is needed. |
| **NS_E_DRM_UNSUPPORTED_PROPERTY** | The file opened in the reader is not protected. |

## See also

[IWMDRMReader2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmdrmreader2)