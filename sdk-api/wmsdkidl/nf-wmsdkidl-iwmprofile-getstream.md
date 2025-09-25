# IWMProfile::GetStream

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetStream** method retrieves a stream from the profile.

## Parameters

### `dwStreamIndex` [in]

**DWORD** containing the stream index.

### `ppConfig` [out]

Pointer to a pointer to the [IWMStreamConfig](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmstreamconfig) interface of the stream configuration object that describes the specified stream.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_FAIL** | The method failed for an unspecified reason. |
| **E_INVALIDARG** | The *ppConfig* or *dwStreamIndex* parameter is not valid. |

## Remarks

You can use this method in conjunction with [GetStreamCount](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmprofile-getstreamcount) to step through all of the streams in the profile.

## See also

[IWMProfile Interface](https://learn.microsoft.com/windows/desktop/wmformat/iwmprofile)

[IWMProfile2](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmprofile2)

[IWMProfile3](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmprofile3)

[IWMProfile::GetStreamByNumber](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmprofile-getstreambynumber)