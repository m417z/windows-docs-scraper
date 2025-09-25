# CMSPCallBase::RemoveStream

## Description

(Interface
**RemoveStream**) The
**RemoveStream** method is called by the application to remove a stream from the call. Derived MSP call objects that do not want to allow applications to remove streams should override this to simply return TAPI_E_NOTSUPPORTED. (This is a good simplification strategy for many MSPs.) Derived call objects that do support removal of streams by the application should override this method to remove the stream object from the call object's list of streams and release the call's references to the stream. (Also see the
[CMSPCallMultiGraph](https://learn.microsoft.com/windows/desktop/api/mspcall/nl-mspcall-cmspcallmultigraph) implementation.)

## Parameters

### `pStream`

Pointer to
[ITStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itstream) interface to be removed.

## See also

[CMSPCallBase](https://learn.microsoft.com/windows/desktop/api/mspcall/nl-mspcall-cmspcallbase)