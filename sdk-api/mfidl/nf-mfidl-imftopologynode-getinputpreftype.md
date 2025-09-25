# IMFTopologyNode::GetInputPrefType

## Description

Retrieves the preferred media type for an input stream on this node.

## Parameters

### `dwInputIndex` [in]

Zero-based index of the input stream.

### `ppType` [out]

Receives a pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface of the media type. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_FAIL** | This node does not have a preferred input type. |
| **E_INVALIDARG** | Invalid stream index. |
| **E_NOTIMPL** | This node is a source node. |

## Remarks

Source nodes cannot have inputs. If this method is called on a source node, it returns E_NOTIMPL.

The preferred input type provides a hint to the topology loader. In a fully resolved topology, there is no guarantee that every topology node will have a preferred input type. To get the actual media type for a node, you must get a pointer to the node's underlying object. (For more information, see [MF_TOPOLOGY_TYPE](https://learn.microsoft.com/windows/desktop/api/mfidl/ne-mfidl-mf_topology_type) enumeration.)

## See also

[IMFTopologyNode](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopologynode)

[Topologies](https://learn.microsoft.com/windows/desktop/medfound/topologies)