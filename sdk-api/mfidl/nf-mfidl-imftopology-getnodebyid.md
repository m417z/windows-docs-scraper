# IMFTopology::GetNodeByID

## Description

Gets a node in the topology, specified by node identifier.

## Parameters

### `qwTopoNodeID` [in]

The identifier of the node to retrieve. To get a node's identifier, call [IMFTopologyNode::GetTopoNodeID](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imftopologynode-gettoponodeid).

### `ppNode` [out]

Receives a pointer to the node's [IMFTopologyNode](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopologynode) interface. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_NOT_FOUND** | The topology does not contain a node with this identifier. |

## See also

[IMFTopology](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopology)

[TOPOID](https://learn.microsoft.com/windows/desktop/medfound/topoid)

[Topologies](https://learn.microsoft.com/windows/desktop/medfound/topologies)