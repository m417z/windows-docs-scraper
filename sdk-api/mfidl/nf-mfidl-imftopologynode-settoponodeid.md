# IMFTopologyNode::SetTopoNodeID

## Description

Sets the identifier for the node.

## Parameters

### `ullTopoID` [in]

The identifier for the node.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The [TOPOID](https://learn.microsoft.com/windows/desktop/medfound/topoid) has already been set for this object. |

## Remarks

When a node is first created, it is assigned an identifier. Typically there is no reason for an application to override the identifier. Within a topology, each node identifier should be unique.

## See also

[IMFTopologyNode](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopologynode)

[TOPOID](https://learn.microsoft.com/windows/desktop/medfound/topoid)

[Topologies](https://learn.microsoft.com/windows/desktop/medfound/topologies)