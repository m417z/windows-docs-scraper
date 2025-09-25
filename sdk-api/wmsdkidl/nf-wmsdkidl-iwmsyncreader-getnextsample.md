# IWMSyncReader::GetNextSample

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetNextSample** method retrieves the next sample from the file.

## Parameters

### `wStreamNum` [in]

**WORD** containing the stream number for which you would like a sample. If you pass zero, the next sample in the file is returned, regardless of stream number.

### `ppSample` [out]

Pointer to a buffer that receives the sample. Set to **NULL** to retrieve the sample time without getting the sample. If set to **NULL**, *pcnsDuration* and *pdwFlags* must both be set to **NULL** as well.

### `pcnsSampleTime` [out]

Pointer to a **QWORD** variable that receives the sample time in 100-nanosecond units.

### `pcnsDuration` [out]

Pointer to **QWORD** variable that receives the duration of the sample in 100-nanosecond units.

### `pdwFlags` [out]

Pointer to a **DWORD** containing one or more of the following flags.

| Flag | Description |
| --- | --- |
| No flag set | None of the conditions for the other flags applies. For example, a [delta frame](https://learn.microsoft.com/windows/desktop/wmformat/wmformat-glossary) in most cases would not have any flags set for it. |
| WM_SF_CLEANPOINT | Indicates that the sample does not require any other samples to be decompressed. All audio samples and all video samples that are key frames are cleanpoints. |
| WM_SF_DISCONTINUITY | The data stream has a gap in it, which could be due to a seek, a network loss, or other reason. This can be useful extra information for an application such as a codec or renderer. The flag is set on the first piece of data following the gap. |
| WM_SF_DATALOSS | Some data has been lost between the previous sample and the sample with this flag set. |

### `pdwOutputNum` [out]

Pointer to a **DWORD** that receives the output number.

### `pwStreamNum` [out]

Pointer to a **WORD** that receives the stream number.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **NS_E_NO_MORE_SAMPLES** | All the samples in the file have been read. |
| **E_UNEXPECTED** | A problem occurred with a call within the method. |
| **E_INVALIDARG** | *wStreamNum* specifies a stream number that is not valid.<br><br>OR<br><br>*pcnsSampleTime* is **NULL**<br><br>OR<br><br>*ppSample*, *pcnsDuration*, or *pdwFlags* is **NULL**, but one or both of the others are not.<br><br>OR<br><br>*wStreamNum* is 0 and both *pdwOutputNum* and *pwStreamNum* are **NULL**. |
| **NS_E_INVALID_REQUEST** | No file is open and ready for reading by the synchronous reader.<br><br>OR<br><br>*wStreamNum* specifies a stream number that is turned off (not selected for reading). |

## Remarks

Both compressed and uncompressed samples are delivered by this method, depending upon whether you have called [SetReadStreamSamples](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmsyncreader-setreadstreamsamples) for the streams in the file. This is the only method to retrieve samples using the synchronous reader.

To begin receiving samples from anywhere in the file other than the beginning, you must first specify a range for playback. To specify a playback range based on presentation times, use the [SetRange](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmsyncreader-setrange) method. To set a range using frame numbers, use the [SetRangeByFrame](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmsyncreader-setrangebyframe) method. When you have received all of the samples in the file, or in the range if you specified one, the next call made to **GetNextSample** returns NS_E_NO_MORE_SAMPLES.

The timeline is presentation time if no output setting is specified. To get early delivery for a stream, use [SetOutputSetting](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmsyncreader-setoutputsetting).

You can call **GetNextSample** in one of three ways:

* If you pass a non-zero value as *wStreamNum*, you will get the next sample for the specified stream number. In this case, you can pass **NULL** for both *pdwOutputNum* and *pwStreamNum*.
* If you pass zero as *wStreamNum*, and are using output numbers, you can pass **NULL** for *pwStreamNum*. In this case you must pass a valid address for *pdwOutputNum*.
* If you pass zero as *wStreamNum*, and are not using output numbers, you can pass **NULL** for *pdwOutputNum*. In this case you must pass a valid address for *pwStreamNum*.

You can also use *GetNextSample* to retrieve precise times for video frames when reading compressed data. For more information, see To Retrieve Accurate Presentation Times for Compressed Samples by Frame.

**Note** To ensure that you get correct sample durations from this method, you must configure the output for the stream. Call the [SetOutputSetting](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmsyncreader-setoutputsetting) method to set the g_wszVideoSampleDurations setting to **TRUE**. Subsequent calls to **GetNextSample** will return correct sample durations.

## See also

[INSSBuffer Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsbuffer/nn-wmsbuffer-inssbuffer)

[IWMSyncReader Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmsyncreader)