# CMSPStream::GetState

## Description

The
**GetState** method is called by the MSPCall object. It returns the current status of the stream. The default implementation returns E_NOTIMPL.

## Parameters

### `pdwStatus`

Pointer to indication of stream's state. The precise return value is implementation dependent. An example set of types that might be defined for this purpose: STRM_RUNNING, STRM_PAUSED, and STRM_STOPPED.

## See also

[CMSPStream](https://learn.microsoft.com/windows/desktop/api/mspstrm/nl-mspstrm-cmspstream)