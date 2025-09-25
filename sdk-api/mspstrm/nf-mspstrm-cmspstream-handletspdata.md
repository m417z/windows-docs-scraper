# CMSPStream::HandleTSPData

## Description

The
**HandleTSPData** method may be called by the derived call object to let the stream handle the TSP commands. The default implementation returns S_OK. Override this method to implement the stream-specific portion of your MSP-TSP communication. Note that the base call object classes do not call this method; if you want to use it, you must also override the
[ReceiveTSPCallData](https://learn.microsoft.com/windows/desktop/api/mspcall/nf-mspcall-cmspcallbase-receivetspcalldata) method to dispatch the TSP data to your streams. The stream dispatch information, if any, will be contained in the opaque buffer.

## Parameters

### `pData`

Pointer to opaque buffer containing implementation-dependent information.

### `dwSize`

Size in bytes of opaque buffer.

## See also

[CMSPStream](https://learn.microsoft.com/windows/desktop/api/mspstrm/nl-mspstrm-cmspstream)