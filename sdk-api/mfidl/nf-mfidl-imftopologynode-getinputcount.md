# IMFTopologyNode::GetInputCount

## Description

Retrieves the number of input streams that currently exist on this node.

## Parameters

### `pcInputs` [out]

Receives the number of input streams.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The input streams may or may not be connected to output streams on other nodes. To get the node that is connected to a specified input stream, call [IMFTopologyNode::GetInput](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imftopologynode-getinput).

The [IMFTopologyNode::ConnectOutput](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imftopologynode-connectoutput) and [IMFTopologyNode::SetInputPrefType](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imftopologynode-setinputpreftype) methods add new input streams as needed.

## See also

[IMFTopologyNode](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopologynode)

[Topologies](https://learn.microsoft.com/windows/desktop/medfound/topologies)