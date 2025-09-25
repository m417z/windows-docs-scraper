# CMSPCallMultiGraph::RemoveStream

## Description

(Interface
**RemoveStream**) The
**RemoveStream** method is called by the application to remove a stream from the call. Derived MSP call objects that do not want to allow applications to remove streams should override this to simply return TAPI_E_NOTSUPPORTED. (This is a good simplification strategy for many MSPs.) The default implementation removes the stream object from the call object's list of streams and releases the call's references to the stream.

## Parameters

### `ppStream`

Pointer to
[ITStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itstream) interface for stream to be removed from the call.

## See also

[CMSPCallMultiGraph](https://learn.microsoft.com/windows/desktop/api/mspcall/nl-mspcall-cmspcallmultigraph)