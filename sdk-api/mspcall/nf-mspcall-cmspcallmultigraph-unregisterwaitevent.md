# CMSPCallMultiGraph::UnregisterWaitEvent

## Description

The
**UnregisterWaitEvent** method calls the [UnregisterWait](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-unregisterwait) function
to tell the thread pool to stop waiting on the handle indicated by the wait block at the given index. Releases the refcounts in the wait block and frees the wait block. Removes the wait block from the list of wait blocks.

## Parameters

### `index`

Index on appropriate item in the array of
[THREADPOOLWAITBLOCK](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms734804(v=vs.85)) structures.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[CMSPCallMultiGraph](https://learn.microsoft.com/windows/desktop/api/mspcall/nl-mspcall-cmspcallmultigraph)