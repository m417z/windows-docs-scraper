# IWMMutualExclusion::SetType

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetType** method specifies the GUID of the type of mutual exclusion required.

## Parameters

### `guidType` [in]

GUID specifying the type of mutual exclusion. For a list of values, see [IWMMutualExclusion::GetType](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmmutualexclusion-gettype)

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | Invalid type. |

## Remarks

If you create a multiple bit rate audio file, you may encounter problems streaming the file from Windows Media Services 4.1. To avoid problems, disable auto indexing by calling [IWMWriterFileSink3::SetAutoIndexing](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriterfilesink3-setautoindexing) before writing the file.

## See also

[IWMMutualExclusion Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmmutualexclusion)

[IWMMutualExclusion::GetType](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmmutualexclusion-gettype)