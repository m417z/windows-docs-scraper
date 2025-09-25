# IMFSinkWriter::AddStream

## Description

Adds a stream to the sink writer.

## Parameters

### `pTargetMediaType` [in]

A pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface of a media type. This media type specifies the format of the samples that will be written to the file. It does not need to match the input format. To set the input format, call [IMFSinkWriter::SetInputMediaType](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nf-mfreadwrite-imfsinkwriter-setinputmediatype).

### `pdwStreamIndex` [out]

Receives the zero-based index of the new stream.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This interface is available on Windows Vista if Platform Update Supplement for Windows Vista is installed.

## See also

[IMFSinkWriter](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsinkwriter)

[Sink Writer](https://learn.microsoft.com/windows/desktop/medfound/sink-writer)