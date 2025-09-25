# CMSPCallBase::InternalCreateStream

## Description

The
**InternalCreateStream** method is called by
[CreateStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itstreamcontrol-createstream) to create a stream object (the caller does the argument checking). It should create and initialize the stream object (using
[CreateStreamObject](https://learn.microsoft.com/windows/desktop/api/mspcall/nf-mspcall-cmspcallbase-createstreamobject)).

## Parameters

### `dwMediaType`

[Media type](https://learn.microsoft.com/windows/desktop/Tapi/tapimediatype--constants) or types of call.

### `Direction`

Indicates
[terminal direction](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-terminal_direction).

### `ppStream`

Pointer to
[ITStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itstream) object interface.

## See also

[CMSPCallBase](https://learn.microsoft.com/windows/desktop/api/mspcall/nl-mspcall-cmspcallbase)

[CMSPCallMultiGraph::InternalCreateStream](https://learn.microsoft.com/windows/desktop/api/mspcall/nf-mspcall-cmspcallmultigraph-internalcreatestream)

[CreateStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itstreamcontrol-createstream)

[CreateStreamObject](https://learn.microsoft.com/windows/desktop/api/mspcall/nf-mspcall-cmspcallbase-createstreamobject)

[ITStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itstream)