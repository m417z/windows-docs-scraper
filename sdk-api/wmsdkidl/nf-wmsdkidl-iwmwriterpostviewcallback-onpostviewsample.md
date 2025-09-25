# IWMWriterPostViewCallback::OnPostViewSample

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **OnPostViewSample** method is called when new postview data is available. The application implements this method.

## Parameters

### `wStreamNumber` [in]

**WORD** containing the stream number.

### `cnsSampleTime` [in]

Sample time, in 100-nanosecond units.

### `cnsSampleDuration` [in]

Sample duration, in 100-nanosecond units. This will usually be 10000 (1 millisecond).

### `dwFlags` [in]

**DWORD** containing none, one, or more of the following flags.

| Flag | Description |
| --- | --- |
| No flag set | None of the conditions for the other flags applies. For example, a [delta frame](https://learn.microsoft.com/windows/desktop/wmformat/wmformat-glossary) in most cases would not have any flags set for it. |
| WM_SF_CLEANPOINT | This is basically the same as a key frame. It indicates a good point to go to during a seek, for example. |
| WM_SF_DISCONTINUITY | The data stream has a gap in it, which could be due to a seek, a network loss, or some other reason. This can be useful extra information for an application such as a codec or renderer. The flag is set on the first piece of data following the gap. |
| WM_SF_DATALOSS | Some data has been lost between the previous sample and the sample with this flag set. |

### `pSample` [in]

Pointer to an [INSSBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsbuffer/nn-wmsbuffer-inssbuffer) interface on an object that contains the sample.

### `pvContext` [in]

Generic pointer, for use by the application.

## Return value

This method is implemented by the application. It should return S_OK.

## Remarks

Postview data is available only for video.

## See also

[IWMReaderCallback::OnSample](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadercallback-onsample)

[IWMWriterPostViewCallback Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwriterpostviewcallback)