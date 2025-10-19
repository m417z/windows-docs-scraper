# IMFSourceReader::SetStreamSelection

## Description

Selects or deselects one or more streams.

## Parameters

### `dwStreamIndex` [in]

The stream to set. The value can be any of the following.

| Value | Meaning |
| --- | --- |
| 0–0xFFFFFFFB | The zero-based index of a stream. |
| **MF_SOURCE_READER_FIRST_VIDEO_STREAM**<br><br>0xFFFFFFFC | The first video stream. |
| **MF_SOURCE_READER_FIRST_AUDIO_STREAM**<br><br>0xFFFFFFFD | The first audio stream. |
| **MF_SOURCE_READER_ALL_STREAMS**<br><br>0xFFFFFFFE | All streams. |

### `fSelected` [in]

Specify **TRUE** to select streams or **FALSE** to deselect streams. If a stream is deselected, it will not generate data.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

There are two common uses for this method:

* To change the default stream selection. Some media files contain multiple streams of the same type. For example, a file might include audio streams for multiple languages. You can use this method to change which of the streams is selected. To get information about each stream, call [IMFSourceReader::GetPresentationAttribute](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsourcereader-getpresentationattribute) or [IMFSourceReader::GetNativeMediaType](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsourcereader-getnativemediatype).
* If you will not need data from one of the streams, it is a good idea to deselect that stream. If the stream is selected, the media source might hold onto a queue of unread data, and the queue might grow indefinitely, consuming memory.

For an example of deselecting a stream, see [Tutorial: Decoding Audio](https://learn.microsoft.com/windows/desktop/medfound/tutorial--decoding-audio).

If a stream is deselected, the [IMFSourceReader::ReadSample](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsourcereader-readsample) method returns **MF_E_INVALIDREQUEST** for that stream. Other [IMFSourceReader](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsourcereader) methods are valid for deselected streams.

Stream selection does not affect how the source reader loads or unloads decoders in memory. In particular, deselecting a stream does not force the source reader to unload the decoder for that stream.

This interface is available on Windows Vista if Platform Update Supplement for Windows Vista is installed.

## See also

[IMFSourceReader](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsourcereader)

[Source Reader](https://learn.microsoft.com/windows/desktop/medfound/source-reader)