# IMFTopologyNode::GetInput

## Description

Retrieves the node that is connected to a specified input stream on this node.

## Parameters

### `dwInputIndex` [in]

Zero-based index of an input stream on this node.

### `ppUpstreamNode` [out]

Receives a pointer to the [IMFTopologyNode](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopologynode) interface of the node that is connected to the specified input stream. The caller must release the interface.

### `pdwOutputIndexOnUpstreamNode` [out]

Receives the index of the output stream that is connected to this node's input stream.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The index is out of range. |
| **MF_E_NOT_FOUND** | The specified input stream is not connected to another node. |

## See also

[IMFTopologyNode](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopologynode)

[Topologies](https://learn.microsoft.com/windows/desktop/medfound/topologies)