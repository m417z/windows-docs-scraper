# IMFSourceReaderCallback::OnReadSample

## Description

Called when the [IMFSourceReader::ReadSample](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsourcereader-readsample) method completes.

## Parameters

### `hrStatus` [in]

The status code. If an error occurred while processing the next sample, this parameter contains the error code.

### `dwStreamIndex` [in]

The zero-based index of the stream that delivered the sample.

### `dwStreamFlags` [in]

A bitwise **OR** of zero or more flags from the [MF_SOURCE_READER_FLAG](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/ne-mfreadwrite-mf_source_reader_flag) enumeration.

### `llTimestamp` [in]

The time stamp of the sample, or the time of the stream event indicated in *dwStreamFlags*. The time is given in 100-nanosecond units.

### `pSample` [in]

A pointer to the [IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample) interface of a media sample. This parameter might be **NULL**.

## Return value

Returns an **HRESULT** value. Currently, the source reader ignores the return value.

## Remarks

The *pSample* parameter might be **NULL**. For example, when the source reader reaches the end of a stream, *dwStreamFlags* contains the **MF_SOURCE_READERF_ENDOFSTREAM** flag, and *pSample* is **NULL**.

If there is a gap in the stream, *dwStreamFlags* contains the **MF_SOURCE_READERF_STREAMTICK** flag, *pSample* is **NULL**, and *llTimestamp* indicates the time when the gap occurred.

This interface is available on Windows Vista if Platform Update Supplement for Windows Vista is installed.

## See also

[IMFSourceReaderCallback](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsourcereadercallback)

[Source Reader](https://learn.microsoft.com/windows/desktop/medfound/source-reader)