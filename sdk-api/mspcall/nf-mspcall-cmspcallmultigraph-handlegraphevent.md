# CMSPCallMultiGraph::HandleGraphEvent

## Description

The
**HandleGraphEvent** method is called by the
[DispatchGraphEvent](https://learn.microsoft.com/windows/desktop/api/mspcall/nf-mspcall-cmspcallmultigraph-dispatchgraphevent) static method to let the call object instance handle the event. It asks the filter graph for the event code and parameters, and queues an asynchronous work item on the global worker thread object, which will result in the **AsyncMultiGraphEvent** function (as defined in MSPCall.h) being executed on the worker thread. This is to allow the thread pool thread to return as quickly as possible, preventing an event storm from DirectShow's manual reset event.

## Parameters

### `pContext`

Contains pointer to
[MSPSTREAMCONTEXT](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms733448(v=vs.85)) structure.

## See also

[CMSPCallMultiGraph](https://learn.microsoft.com/windows/desktop/api/mspcall/nl-mspcall-cmspcallmultigraph)