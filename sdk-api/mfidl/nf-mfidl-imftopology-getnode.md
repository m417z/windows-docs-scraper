# IMFTopology::GetNode

## Description

Gets a node in the topology, specified by index.

## Parameters

### `wIndex` [in]

The zero-based index of the node. To get the number of nodes in the topology, call [IMFTopology::GetNodeCount](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imftopology-getnodecount).

### `ppNode` [out]

Receives a pointer to the node's [IMFTopologyNode](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopologynode) interface. The caller must release the pointer.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The index is less than zero. |
| **MF_E_INVALIDINDEX** | No node can be found at the index *wIndex*. |

## See also

[IMFTopology](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopology)

[Topologies](https://learn.microsoft.com/windows/desktop/medfound/topologies)