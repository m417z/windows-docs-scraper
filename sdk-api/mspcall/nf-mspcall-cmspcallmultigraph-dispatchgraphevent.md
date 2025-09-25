# CMSPCallMultiGraph::DispatchGraphEvent

## Description

The
**DispatchGraphEvent** method is a static method posted to the
[RegisterWaitForSingleObject](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-registerwaitforsingleobject) function during initialization. This function is called when the filter graph signals the event. The *pContext* parameter is a pointer to the
[MSPSTREAMCONTEXT](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms733448(v=vs.85)) structure. The pointers in the structure carry ref counts. The implementation of this method simply casts the *pContext* argument to type MSPSTREAMCONTEXT *, and then calls
[HandleGraphEvent](https://learn.microsoft.com/windows/desktop/api/mspcall/nf-mspcall-cmspcallmultigraph-handlegraphevent) on the MSP call object whose pointer appears in the structure.

## Parameters

### `pContext`

Contains pointer to
[MSPSTREAMCONTEXT](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms733448(v=vs.85)) structure.

### `bFlag`

Not used. Required for
[RegisterWaitForSingleObject](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-registerwaitforsingleobject). Set **TRUE** if wait times out, but time-out in
[CMSPCallMultiGraph::RegisterWaitEvent](https://learn.microsoft.com/windows/desktop/api/mspcall/nf-mspcall-cmspcallmultigraph-registerwaitevent) is set to INFINITE.

## See also

[CMSPCallMultiGraph](https://learn.microsoft.com/windows/desktop/api/mspcall/nl-mspcall-cmspcallmultigraph)