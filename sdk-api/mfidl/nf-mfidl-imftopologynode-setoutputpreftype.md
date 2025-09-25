# IMFTopologyNode::SetOutputPrefType

## Description

Sets the preferred media type for an output stream on this node.

## Parameters

### `dwOutputIndex` [in]

Zero-based index of the output stream.

### `pType` [in]

Pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface of the media type.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOTIMPL** | This node is an output node. |

## Remarks

The preferred type is a hint for the topology loader.

Do not call this method after loading a topology or setting a topology on the Media Session. Changing the preferred type on a running topology can cause connection errors.

If no output stream exists at the specified index, the method creates new streams up to and including the specified index number.

Output nodes cannot have outputs. If this method is called on an output node, it returns E_NOTIMPL

## See also

[IMFTopologyNode](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopologynode)

[Topologies](https://learn.microsoft.com/windows/desktop/medfound/topologies)