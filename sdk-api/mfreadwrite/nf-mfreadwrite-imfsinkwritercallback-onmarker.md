# IMFSinkWriterCallback::OnMarker

## Description

Called when the [IMFSinkWriter::PlaceMarker](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsinkwriter-placemarker) method completes.

## Parameters

### `dwStreamIndex` [in]

The zero-based index of the stream. This parameter equals the value of the *dwStreamIndex* parameter in the [PlaceMarker](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsinkwriter-placemarker) method.

### `pvContext` [in]

The application-defined value that was given in the *pvContext* parameter in the [PlaceMarker](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsinkwriter-placemarker) method.

## Return value

Returns an **HRESULT** value. Currently, the sink writer ignores the return value.

## Remarks

This interface is available on Windows Vista if Platform Update Supplement for Windows Vista is installed.

## See also

[IMFSinkWriterCallback](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsinkwritercallback)

[Sink Writer](https://learn.microsoft.com/windows/desktop/medfound/sink-writer)