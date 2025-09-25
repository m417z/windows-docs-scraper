# MFCreateTopologyNode function

## Description

Creates a topology node.

## Parameters

### `NodeType` [in]

The type of node to create, specified as a member of the [MF_TOPOLOGY_TYPE](https://learn.microsoft.com/windows/desktop/api/mfidl/ne-mfidl-mf_topology_type) enumeration.

### `ppNode` [out]

Receives a pointer to the node's [IMFTopologyNode](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopologynode) interface. The caller must release the interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Creating Output Nodes](https://learn.microsoft.com/windows/desktop/medfound/creating-output-nodes)

[Creating Source Nodes](https://learn.microsoft.com/windows/desktop/medfound/creating-source-nodes)

[Creating Transform Nodes](https://learn.microsoft.com/windows/desktop/medfound/creating-transform-nodes)

[IMFTopologyNode](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopologynode)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Topologies](https://learn.microsoft.com/windows/desktop/medfound/topologies)