# IMFTopologyNode::GetTopoNodeID

## Description

Retrieves the identifier of the node.

## Parameters

### `pID` [out]

Receives the identifier.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

When a node is first created, it is assigned an identifier. Node identifiers are unique within a topology, but can be reused across several topologies. The topology loader uses the identifier to look up nodes in the previous topology, so that it can reuse objects from the previous topology.

To find a node in a topology by its identifier, call [IMFTopology::GetNodeByID](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imftopology-getnodebyid).

## See also

[IMFTopologyNode](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopologynode)

[TOPOID](https://learn.microsoft.com/windows/desktop/medfound/topoid)

[Topologies](https://learn.microsoft.com/windows/desktop/medfound/topologies)