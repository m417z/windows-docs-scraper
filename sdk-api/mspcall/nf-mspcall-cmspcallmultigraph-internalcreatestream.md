# CMSPCallMultiGraph::InternalCreateStream

## Description

The
**InternalCreateStream** method is called by
[CreateStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itstreamcontrol-createstream) to create a stream object (the caller does the argument checking). It creates and initializes the stream object (using
[CreateStreamObject](https://learn.microsoft.com/windows/desktop/api/mspcall/nf-mspcall-cmspcallbase-createstreamobject)). It uses **CoCreateInstance** to create a filter graph for the stream. It calls
[RegisterWaitEvent](https://learn.microsoft.com/windows/desktop/api/mspcall/nf-mspcall-cmspcallmultigraph-registerwaitevent) to start waiting for events on the filter graph. It adds the stream into the call object's list of stream objects. It addrefs the stream pointer and returns it.

## Parameters

### `dwMediaType`

Descriptor of
[media type](https://learn.microsoft.com/windows/desktop/Tapi/tapimediatype--constants) for stream.

### `Direction`

Descriptor of
[terminal direction](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-terminal_direction).

### `ppStream`

Pointer to array of
[ITStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itstream) interfaces.

## See also

[CMSPCallMultiGraph](https://learn.microsoft.com/windows/desktop/api/mspcall/nl-mspcall-cmspcallmultigraph)