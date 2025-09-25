# IMFSourceReader::ReadSample

## Description

Reads the next sample from the media source.

## Parameters

### `dwStreamIndex` [in]

The stream to pull data from. The value can be any of the following.

| Value | Meaning |
| --- | --- |
| 0–0xFFFFFFFB | The zero-based index of a stream. |
| ****MF_SOURCE_READER_FIRST_VIDEO_STREAM****<br><br>0xFFFFFFFC | The first video stream. |
| ****MF_SOURCE_READER_FIRST_AUDIO_STREAM****<br><br>0xFFFFFFFD | The first audio stream. |
| ****MF_SOURCE_READER_ANY_STREAM****<br><br>0xFFFFFFFE | Get the next available sample, regardless of which stream. |

### `dwControlFlags` [in]

A bitwise **OR** of zero or more flags from the [MF_SOURCE_READER_CONTROL_FLAG](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/ne-mfreadwrite-mf_source_reader_control_flag) enumeration.

### `pdwActualStreamIndex` [out]

Receives the zero-based index of the stream.

### `pdwStreamFlags` [out]

Receives a bitwise **OR** of zero or more flags from the [MF_SOURCE_READER_FLAG](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/ne-mfreadwrite-mf_source_reader_flag) enumeration.

### `pllTimestamp` [out]

Receives the time stamp of the sample, or the time of the stream event indicated in *pdwStreamFlags*. The time is given in 100-nanosecond units.

### `ppSample` [out]

Receives a pointer to the [IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample) interface or the value **NULL** (see Remarks). If this parameter receives a non-**NULL** pointer, the caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| ****S_OK**** | The method succeeded. |
| ****MF_E_INVALIDREQUEST**** | Invalid request. |
| ****MF_E_INVALIDSTREAMNUMBER**** | The *dwStreamIndex* parameter is invalid. |
| ****MF_E_NOTACCEPTING**** | A flush operation is pending. See [IMFSourceReader::Flush](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsourcereader-flush). |
| ****E_INVALIDARG**** | Invalid argument. See Remarks. |

## Remarks

If the requested stream is not selected, the return code is **MF_E_INVALIDREQUEST**. See [IMFSourceReader::SetStreamSelection](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsourcereader-setstreamselection).

 This method can complete synchronously or asynchronously. If you provide a callback pointer when you create the source reader, the method is asynchronous. Otherwise, the method is synchronous. For more information about setting the callback pointer, see [MF_SOURCE_READER_ASYNC_CALLBACK](https://learn.microsoft.com/windows/desktop/medfound/mf-source-reader-async-callback).

### Asynchronous Mode

In asynchronous mode:

* All of the `[out]` parameters must be **NULL**. Otherwise, the method returns **E_INVALIDARG**.
* The method returns immediately.
* When the operation completes, the application's [IMFSourceReaderCallback::OnReadSample](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsourcereadercallback-onreadsample) method is called.
* If an error occurs, the method can fail either synchronously or asynchronously. Check the return value of **ReadSample**, and also check the *hrStatus* parameter of [IMFSourceReaderCallback::OnReadSample](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsourcereadercallback-onreadsample).

### Synchronous Mode

In synchronous mode:

* The *pdwStreamFlags* and *ppSample* parameters cannot be **NULL**. Otherwise, the method returns **E_POINTER**.
* The *pdwActualStreamIndex* and *pllTimestamp* parameters can be **NULL**.
* The method blocks until the next sample is available.

In synchronous mode, if the *dwStreamIndex* parameter is **MF_SOURCE_READER_ANY_STREAM**, you should pass a non-**NULL** value for *pdwActualStreamIndex*, so that you know which stream delivered the sample.

This method can return flags in the *pdwStreamFlags* parameter without returning a media sample in *ppSample*. Therefore, the *ppSample* parameter can receive a **NULL** pointer even when the method succeeds. For example, when the source reader reaches the end of the stream, it returns the **MF_SOURCE_READERF_ENDOFSTREAM** flag in *pdwStreamFlags* and sets *ppSample* to **NULL**.

If there is a gap in the stream, *pdwStreamFlags* receives the MF_SOURCE_READERF_STREAMTICK flag, *ppSample* is **NULL**, and *pllTimestamp* indicates the time when the gap occurred.

This interface is available on Windows Vista if Platform Update Supplement for Windows Vista is installed.

## See also

[IMFSourceReader](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsourcereader)

[Source Reader](https://learn.microsoft.com/windows/desktop/medfound/source-reader)