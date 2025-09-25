# IMFTopologyNode::GetOutputCount

## Description

Retrieves the number of output streams that currently exist on this node.

## Parameters

### `pcOutputs` [out]

Receives the number of output streams.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The output streams may or may not be connected to input streams on other nodes. To get the node that is connected to a specific output stream on this node, call [IMFTopologyNode::GetOutput](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imftopologynode-getoutput).

The [IMFTopologyNode::ConnectOutput](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imftopologynode-connectoutput) and [IMFTopologyNode::SetOutputPrefType](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imftopologynode-setoutputpreftype) methods add new input streams as needed.

## See also

[IMFTopologyNode](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopologynode)

[Topologies](https://learn.microsoft.com/windows/desktop/medfound/topologies)