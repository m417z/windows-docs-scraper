# IMFSourceReaderCallback::OnFlush

## Description

Called when the [IMFSourceReader::Flush](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsourcereader-flush) method completes.

## Parameters

### `dwStreamIndex`

The index of the stream that was flushed, or **MF_SOURCE_READER_ALL_STREAMS** if all streams were flushed.

## Return value

Returns an **HRESULT** value. Currently, the source reader ignores the return value.

## Remarks

This interface is available on Windows Vista if Platform Update Supplement for Windows Vista is installed.

## See also

[IMFSourceReaderCallback](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsourcereadercallback)

[Source Reader](https://learn.microsoft.com/windows/desktop/medfound/source-reader)