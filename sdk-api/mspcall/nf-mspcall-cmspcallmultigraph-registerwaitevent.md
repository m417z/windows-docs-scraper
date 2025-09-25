# CMSPCallMultiGraph::RegisterWaitEvent

## Description

The
**RegisterWaitEvent** method should be called only within a critical section on the call object. It allocates a thread pool context block, fills in the fields, increments the reference counts, and posts the block to the thread pool by calling the [RegisterWaitForSingleObject](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-registerwaitforsingleobject) function. Saves the wait handle returned for use in
[UnregisterWaitEvent](https://learn.microsoft.com/windows/desktop/api/mspcall/nf-mspcall-cmspcallmultigraph-unregisterwaitevent). Saves the wait block in the list of wait blocks.

## Parameters

### `pIMediaEvent`

Pointer to DirectShow **IMediaEvent** interface.

### `pITStream`

Pointer to
[ITStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itstream) interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[CMSPCallMultiGraph](https://learn.microsoft.com/windows/desktop/api/mspcall/nl-mspcall-cmspcallmultigraph)