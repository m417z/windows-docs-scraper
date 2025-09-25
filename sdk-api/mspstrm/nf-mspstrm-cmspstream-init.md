# CMSPStream::Init

## Description

The
**Init** method is called by the **MSPCall** when the stream is created. It initializes the members, calls
[MSPCallAddRef](https://learn.microsoft.com/windows/desktop/api/mspcall/nf-mspcall-cmspcallbase-mspcalladdref) on the call object, and queries for various interfaces on the filter graph.

## Parameters

### `hAddress`

Handle for address associated with this call.

### `pMSPCall`

Pointer to MSP basic calling handler class,
[CMSPCallBase](https://learn.microsoft.com/windows/desktop/api/mspcall/nl-mspcall-cmspcallbase).

### `pGraph`

Pointer to **IMediaEvent** interface for the stream's filter graph. This DirectShow interface supports event notification to the application from the filter graph and from filters within the filter graph.

### `dwMediaType`

Descriptor of
[media type](https://learn.microsoft.com/windows/desktop/Tapi/tapimediatype--constants) for stream.

### `Direction`

Descriptor of
[terminal direction](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-terminal_direction).

## See also

[CMSPStream](https://learn.microsoft.com/windows/desktop/api/mspstrm/nl-mspstrm-cmspstream)