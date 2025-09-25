# IMFTopologyNode::ConnectOutput

## Description

Connects an output stream from this node to the input stream of another node.

## Parameters

### `dwOutputIndex` [in]

Zero-based index of the output stream on this node.

### `pDownstreamNode` [in]

Pointer to the [IMFTopologyNode](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopologynode) interface of the node to connect to.

### `dwInputIndexOnDownstreamNode` [in]

Zero-based index of the input stream on the other node.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_FAIL** | The method failed. |
| **E_INVALIDARG** | Invalid parameter. |

## Remarks

Node connections represent data flow from one node to the next. The streams are logical, and are specified by index.

If the node is already connected at the specified output, the method breaks the existing connection. If *dwOutputIndex* or *dwInputIndexOnDownstreamNode* specify streams that do not exist yet, the method adds as many streams as needed.

This method checks for certain invalid conditions:

* An output node cannot have any output connections. If you call this method on an output node, the method returns E_FAIL.
* A node cannot be connected to itself. If *pDownstreamNode* specifies the same node as the method call, the method returns E_INVALIDARG.

However, if the method succeeds, it does not guarantee that the node connection is valid. It is possible to create a partial topology that the topology loader cannot resolve. If so, the [IMFTopoLoader::Load](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imftopoloader-load) method will fail.

To break an existing node connection, call [IMFTopologyNode::DisconnectOutput](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imftopologynode-disconnectoutput).

## See also

[IMFTopologyNode](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopologynode)

[Topologies](https://learn.microsoft.com/windows/desktop/medfound/topologies)