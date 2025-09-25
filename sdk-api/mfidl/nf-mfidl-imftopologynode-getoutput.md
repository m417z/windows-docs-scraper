# IMFTopologyNode::GetOutput

## Description

Retrieves the node that is connected to a specified output stream on this node.

## Parameters

### `dwOutputIndex` [in]

Zero-based index of an output stream on this node.

### `ppDownstreamNode` [out]

Receives a pointer to the [IMFTopologyNode](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopologynode) interface of the node that is connected to the specified output stream. The caller must release the interface.

### `pdwInputIndexOnDownstreamNode` [out]

Receives the index of the input stream that is connected to this node's output stream.

## Return value

The method returns an HRESULT. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The index is out of range. |
| **MF_E_NOT_FOUND** | The specified input stream is not connected to another node. |

## See also

[IMFTopologyNode](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopologynode)

[Topologies](https://learn.microsoft.com/windows/desktop/medfound/topologies)