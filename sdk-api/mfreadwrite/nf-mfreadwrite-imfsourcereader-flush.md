# IMFSourceReader::Flush

## Description

Flushes one or more streams.

## Parameters

### `dwStreamIndex` [in]

The stream to flush. The value can be any of the following.

| Value | Meaning |
| --- | --- |
| 0–0xFFFFFFFB | The zero-based index of a stream. |
| ****MF_SOURCE_READER_FIRST_VIDEO_STREAM****<br><br>0xFFFFFFFC | The first video stream. |
| ****MF_SOURCE_READER_FIRST_AUDIO_STREAM****<br><br>0xFFFFFFFD | The first audio stream. |
| ****MF_SOURCE_READER_ALL_STREAMS****<br><br>0xFFFFFFFE | All streams. |

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The **Flush** method discards all queued samples and cancels all pending sample requests.

This method can complete either synchronously or asynchronously.

If you provide a callback pointer when you create the source reader, the method is asynchronous. Otherwise, the method is synchronous. For more information about the setting the callback pointer, see [MF_SOURCE_READER_ASYNC_CALLBACK](https://learn.microsoft.com/windows/desktop/medfound/mf-source-reader-async-callback).

In synchronous mode, the method blocks until the operation is complete.

In asynchronous mode, the application's [IMFSourceReaderCallback::OnFlush](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsourcereadercallback-onflush) method is called when the flush operation completes. While a flush operation is pending, the [IMFSourceReader::ReadSample](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsourcereader-readsample) method returns **MF_E_NOTACCEPTING**.

**Note** In Windows 7, there was a bug in the implementation of this method, which causes [OnFlush](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsourcereadercallback-onflush) to be called before the flush operation completes. A hotfix used to be available that fixed that bug.

This interface is available on Windows Vista if Platform Update Supplement for Windows Vista is installed.

## See also

[IMFSourceReader](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsourcereader)

[Source Reader](https://learn.microsoft.com/windows/desktop/medfound/source-reader)