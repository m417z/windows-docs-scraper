# CMSPCallMultiGraph::ProcessGraphEvent

## Description

The **ProcessGraphEvent** method (as defined in MSPCall.h) is called on the MSP worker thread. It calls this method to let the call object instance handle the event, and then releases the call object and stream object references in its context structure. This method finds the indicated stream and dispatches the call to the
**ProcessGraphEvent** method on the appropriate Stream object.

## Parameters

### `pITStream`

Pointer to
[ITStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itstream) interface.

### `lEventCode`

Filled in by filter graph. Implementation dependent.

### `lParam1`

Filled in by filter graph. Implementation dependent.

### `lParam2`

Filled in by filter graph. Implementation dependent.

## See also

[CMSPCallMultiGraph](https://learn.microsoft.com/windows/desktop/api/mspcall/nl-mspcall-cmspcallmultigraph)