# CMSPCallBase::CreateStreamObject

## Description

The
**CreateStreamObject** method is called by
[InternalCreateStream](https://learn.microsoft.com/windows/desktop/api/mspcall/nf-mspcall-cmspcallbase-internalcreatestream). The derived class should **CreateInstance** on its stream object, do an ATL **_InternalQueryInterface** to obtain an
[ITStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itstream) pointer from the stream object, and call the stream object's
[Init](https://learn.microsoft.com/windows/desktop/api/mspcall/nf-mspcall-cmspcallbase-init) method (on the stream object pointer, not the
**ITStream** pointer).

## Parameters

### `dwMediaType`

[Media type](https://learn.microsoft.com/windows/desktop/Tapi/tapimediatype--constants) of stream to be created.

### `Direction`

[Direction](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-terminal_direction) of stream.

### `pGraph`

Pointer to DirectShow **IMediaEvent** interface.

### `ppStream`

Pointer to
[ITStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itstream) interface.

## See also

[CMSPCallBase](https://learn.microsoft.com/windows/desktop/api/mspcall/nl-mspcall-cmspcallbase)