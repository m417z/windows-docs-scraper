# IMFTopology::RemoveNode

## Description

Removes a node from the topology.

## Parameters

### `pNode` [in]

Pointer to the node's [IMFTopologyNode](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopologynode) interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The specified node is not a member of this topology. |

## Remarks

This method does not destroy the node, so the [IMFTopologyNode](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopologynode) pointer is still valid after the method returns.

The method breaks any connections between the specified node and other nodes.

## See also

[IMFTopology](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopology)

[Topologies](https://learn.microsoft.com/windows/desktop/medfound/topologies)