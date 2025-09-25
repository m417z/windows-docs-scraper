# IMFTopology::AddNode

## Description

Adds a node to the topology.

## Parameters

### `pNode` [in]

Pointer to the node's [IMFTopologyNode](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopologynode) interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *pNode* is invalid, possibly because the node already exists in the topology. |

## See also

[IMFTopology](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopology)

[Topologies](https://learn.microsoft.com/windows/desktop/medfound/topologies)