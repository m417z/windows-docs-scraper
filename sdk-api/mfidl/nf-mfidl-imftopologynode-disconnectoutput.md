# IMFTopologyNode::DisconnectOutput

## Description

Disconnects an output stream on this node.

## Parameters

### `dwOutputIndex` [in]

Zero-based index of the output stream to disconnect.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The *dwOutputIndex* parameter is out of range. |
| **MF_E_NOT_FOUND** | The specified output stream is not connected to another node. |

## Remarks

If the specified output stream is connected to another node, this method breaks the connection.

## See also

[IMFTopologyNode](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopologynode)

[Topologies](https://learn.microsoft.com/windows/desktop/medfound/topologies)