# IWMMutualExclusion::GetType

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetType** method retrieves the GUID of the type of mutual exclusion required.

## Parameters

### `pguidType` [out]

Pointer to a GUID that specifies the type of mutual exclusion.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The *pguidType* parameter is **NULL**. |

## Remarks

The following constants represent the GUIDs supported by this SDK.

| Mutual exclusion type identifier | Description |
| --- | --- |
| CLSID_WMMUTEX_Bitrate | The mutual exclusion streams differ only in bit rate. On playback, the stream that will best use the available bandwidth is chosen. You must use this type of mutual exclusion for multiple bit rate files. |
| CLSID_WMMUTEX_Language | The mutual exclusion streams are the same content only in a different language. A common use of this type of mutual exclusion is for dubbing soundtracks into multiple languages. |
| CLSID_WMMUTEX_Presentation | The mutual exclusion streams are the same video in a different presentation format. The presentation format is usually defined by the aspect ratio of the video frame. |
| CLSID_WMMUTEX_Unknown | The mutual exclusion streams are of a custom type. This sort of mutual exclusion can contain streams of varying types. |

**Note** If you create a multiple bit rate audio file, you may encounter problems streaming the file from Windows Media Services 4.1. To avoid problems, disable auto indexing with a call to [IWMWriterFileSink3::SetAutoIndexing](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriterfilesink3-setautoindexing) before writing the file.

## See also

[IWMMutualExclusion Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmmutualexclusion)

[IWMMutualExclusion::SetType](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmmutualexclusion-settype)