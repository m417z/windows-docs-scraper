# IWMPacketSize2::GetMinPacketSize

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetMinPacketSize** method retrieves the minimum [packet](https://learn.microsoft.com/windows/desktop/wmformat/wmformat-glossary) size for files created with the profile. If you use this method from an interface belonging to a reader or synchronous reader object, the retrieved minimum packet size will always be zero.

## Parameters

### `pdwMinPacketSize` [out]

Pointer to a **DWORD** that will receive the minimum packet size.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | NULL pointer argument. |

## See also

[IWMPacketSize2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmpacketsize2)

[IWMPacketSize2::SetMinPacketSize](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmpacketsize2-setminpacketsize)