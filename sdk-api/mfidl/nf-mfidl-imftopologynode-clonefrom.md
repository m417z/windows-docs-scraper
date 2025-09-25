# IMFTopologyNode::CloneFrom

## Description

Copies the data from another topology node into this node.

## Parameters

### `pNode` [in]

A pointer to the [IMFTopologyNode](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopologynode) interface of the node to copy.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_INVALIDREQUEST** | The node types do not match. |

## Remarks

The two nodes must have the same node type. To get the node type, call [IMFTopologyNode::GetNodeType](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imftopologynode-getnodetype).

This method copies the object pointer, preferred types, and attributes from *pNode* to this node. It also copies the [TOPOID](https://learn.microsoft.com/windows/desktop/medfound/topoid) that uniquely identifies each node in a topology. It does not duplicate any of the connections from *pNode* to other nodes.

The purpose of this method is to copy nodes from one topology to another. Do not use duplicate nodes within the same topology.

## See also

[IMFTopologyNode](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopologynode)

[Topologies](https://learn.microsoft.com/windows/desktop/medfound/topologies)