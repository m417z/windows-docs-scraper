# IMFSinkWriterCallback::OnFinalize

## Description

Called when the [IMFSinkWriter::Finalize](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsinkwriter-finalize) method completes.

## Parameters

### `hrStatus` [in]

The status code for the [Finalize](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsinkwriter-finalize) operation. If the value is an error code, the output file might be invalid.

## Return value

Returns an **HRESULT** value. Currently, the sink writer ignores the return value.

## Remarks

This interface is available on Windows Vista if Platform Update Supplement for Windows Vista is installed.

## See also

[IMFSinkWriterCallback](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsinkwritercallback)

[Sink Writer](https://learn.microsoft.com/windows/desktop/medfound/sink-writer)