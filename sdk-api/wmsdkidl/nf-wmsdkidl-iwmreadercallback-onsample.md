# IWMReaderCallback::OnSample

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **OnSample** method is called during the reading of a file (due to a [Start](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreader-start) call) indicating that new data is available.

## Parameters

### `dwOutputNum` [in]

**DWORD** containing the number of the output to which the sample belongs.

### `cnsSampleTime` [in]

**QWORD** containing the sample time, in 100-nanosecond units.

### `cnsSampleDuration` [in]

**QWORD** containing the sample duration, in 100-nanosecond units. For video streams, if the SampleDuration data unit extension was set on this sample when the file was created, then this parameter will contain that value. For more information on SampleDuration , see [INSSBuffer3::GetProperty](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsbuffer/nf-wmsbuffer-inssbuffer3-getproperty).

### `dwFlags` [in]

The flags that can be specified in *dwFlags* have the following uses.

| Flag | Description |
| --- | --- |
| No flag set | None of the conditions for the other flags applies. For example, a [delta frame](https://learn.microsoft.com/windows/desktop/wmformat/wmformat-glossary) in most cases would not have any flags set for it. |
| WM_SF_CLEANPOINT | This is the same as a [key frame](https://learn.microsoft.com/windows/desktop/wmformat/wmformat-glossary). It indicates a good point to go to during a seek, for example. |
| WM_SF_DISCONTINUITY | The data stream has a gap in it, which could be due to a seek, a network loss, or other reason. This can be useful extra information for an application such as a codec or renderer. The flag is set on the first piece of data following the gap. |
| WM_SF_DATALOSS | Some data has been lost between the previous sample and the sample with this flag set. |

### `pSample` [in]

Pointer to the [INSSBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsbuffer/nn-wmsbuffer-inssbuffer) interface of an object containing the sample. The reader calls **SAFE_RELEASE** on this pointer after your **OnSample** method returns. You can call **AddRef** on this pointer if you need to keep a reference count on the buffer. Do not call **Release** on this pointer unless you have called **AddRef**.

### `pvContext` [in]

Generic pointer, for use by the application. This pointer is the context pointer given to the [IWMReader::Start](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreader-start) method.

## Return value

To use this method, you must implement it in your application. The method should always return S_OK.

## Remarks

This method is for receipt of uncompressed samples by output number only. If you need to receive samples for multiple streams in a single output (as in the case of mutually exclusive streams), you must use [IWMReaderCallbackAdvanced::OnStreamSample](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreadercallbackadvanced-onstreamsample). In this case, you will receive compressed samples. There is no way to use the reader to receive uncompressed samples by stream number.

## See also

[IWMReaderCallback Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreadercallback)