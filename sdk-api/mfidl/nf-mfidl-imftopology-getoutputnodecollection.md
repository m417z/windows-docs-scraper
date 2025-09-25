# IMFTopology::GetOutputNodeCollection

## Description

Gets the output nodes in the topology.

## Parameters

### `ppCollection` [out]

Receives a pointer to the [IMFCollection](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfcollection) interface. The caller must release the pointer. The collection contains **IUnknown** pointers to all of the output nodes in the topology. Each pointer can be queried for the [IMFTopologyNode](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopologynode) interface. The collection might be empty.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFTopology](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopology)

[IMFTopologyNode::GetNodeType](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imftopologynode-getnodetype)

[Topologies](https://learn.microsoft.com/windows/desktop/medfound/topologies)