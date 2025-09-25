# IMFSourceReaderCallback2::OnStreamError

## Description

Called when an asynchronous error occurs with the [IMFSourceReader](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsourcereader).

## Parameters

### `dwStreamIndex`

The index of the stream of the transform that raised the asynchronous error.

### `hrStatus`

The error that occurred.

## Return value

Returns an **HRESULT** value. Currently, the source reader ignores the return value.

## See also

[IMFSourceReaderCallback2](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsourcereadercallback2)