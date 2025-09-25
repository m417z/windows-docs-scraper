# IWMMediaProps::GetType

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetType** method retrieves the major type of the media in the stream, input, or output described by the object to which the current **IWMMediaProps** interface belongs.

## Parameters

### `pguidType` [out]

Pointer to a GUID specifying the media type.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The *pguidType* parameter is **NULL**. |

## Remarks

These media types are used by the writer, reader, and profile objects to identify the properties of a media stream that are specific to the media type.

**GetType** is provided for convenience; it returns the same value as the **majortype** member of [WM_MEDIA_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ns-wmsdkidl-wm_media_type).

## See also

[IWMMediaProps Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmmediaprops)

[IWMMediaProps::GetMediaType](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmmediaprops-getmediatype)

[IWMVideoMediaProps Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmvideomediaprops)

[Media Types](https://learn.microsoft.com/windows/desktop/wmformat/media-types)