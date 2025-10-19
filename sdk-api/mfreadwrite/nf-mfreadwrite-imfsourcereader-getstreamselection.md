# IMFSourceReader::GetStreamSelection

## Description

Queries whether a stream is selected.

## Parameters

### `dwStreamIndex` [in]

The stream to query. The value can be any of the following.

| Value | Meaning |
| --- | --- |
| 0–0xFFFFFFFB | The zero-based index of a stream. |
| **MF_SOURCE_READER_FIRST_VIDEO_STREAM**<br><br>0xFFFFFFFC | The first video stream. |
| **MF_SOURCE_READER_FIRST_AUDIO_STREAM**<br><br>0xFFFFFFFD | The first audio stream. |

### `pfSelected` [out]

Receives **TRUE** if the stream is selected and will generate data. Receives **FALSE** if the stream is not selected and will not generate data.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This interface is available on Windows Vista if Platform Update Supplement for Windows Vista is installed.

## See also

[IMFSourceReader](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsourcereader)

[Source Reader](https://learn.microsoft.com/windows/desktop/medfound/source-reader)