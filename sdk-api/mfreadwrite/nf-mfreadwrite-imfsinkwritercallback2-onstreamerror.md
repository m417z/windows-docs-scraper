# IMFSinkWriterCallback2::OnStreamError

## Description

Called when an asynchronous error occurs with the [IMFSinkWriter](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsinkwriter).

## Parameters

### `dwStreamIndex`

The index of the stream of the transform that raised the asynchronous error.

### `hrStatus`

The error that occurred.

## Return value

Returns an **HRESULT** value. Currently, the sink writer ignores the return value.

## See also

[IMFSinkWriterCallback2](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsinkwritercallback2)