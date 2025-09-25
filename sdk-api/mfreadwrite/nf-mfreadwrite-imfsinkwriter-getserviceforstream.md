# IMFSinkWriter::GetServiceForStream

## Description

Queries the underlying media sink or encoder for an interface.

## Parameters

### `dwStreamIndex` [in]

The zero-based index of a stream to query, or **MF_SINK_WRITER_MEDIASINK** to query the media sink itself.

### `guidService` [in]

A service identifier GUID, or **GUID_NULL**. If the value is **GUID_NULL**, the method calls **QueryInterface** to get the requested interface. Otherwise, the method calls [IMFGetService::GetService](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfgetservice-getservice). For a list of service identifiers, see [Service Interfaces](https://learn.microsoft.com/windows/desktop/medfound/service-interfaces).

### `riid` [in]

The interface identifier (IID) of the interface being requested.

### `ppvObject` [out]

Receives a pointer to the requested interface. The caller must release the interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the *dwStreamIndex* parameter equals **MF_SINK_WRITER_MEDIASINK**, the method attempts to get the interface from the media sink. Otherwise, it attempts to get the interface from the encoder for the stream at the specified index. If that fails, or if no encoder is present, the method attempts to get the interface from the stream on the media sink.

If the input and output types of the sink are identical and compressed,
it's possible that no encoding is required and the video encoder will not be instantiated.
In that case, **GetServiceForStream** will return MF_E_UNSUPPORTED_SERVICE.

This interface is available on Windows Vista if Platform Update Supplement for Windows Vista is installed.

## See also

[IMFSinkWriter](https://learn.microsoft.com/windows/desktop/api/mfreadwrite/nn-mfreadwrite-imfsinkwriter)

[Sink Writer](https://learn.microsoft.com/windows/desktop/medfound/sink-writer)