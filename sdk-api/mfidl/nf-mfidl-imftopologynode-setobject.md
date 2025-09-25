# IMFTopologyNode::SetObject

## Description

Sets the object associated with this node.

## Parameters

### `pObject` [in]

A pointer to the object's **IUnknown** interface. Use the value **NULL** to clear an object that was previous set.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

All node types support this method, but the object pointer is not used by every node type.

| Node type | Object pointer |
| --- | --- |
| Source node. | Not used. |
| Transform node. | [IMFTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imftransform) or [IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate) interface. |
| Output node | [IMFStreamSink](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfstreamsink) or [IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate) interface. |
| Tee node. | Not used. |

If the object supports **IPersist**, **IPersistStorage**, or **IPersistPropertyBag**, the method gets the object's CLSID and sets the [MF_TOPONODE_TRANSFORM_OBJECTID](https://learn.microsoft.com/windows/desktop/medfound/mf-toponode-transform-objectid-attribute) attribute on the node.

## See also

[IMFTopologyNode](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopologynode)

[Topologies](https://learn.microsoft.com/windows/desktop/medfound/topologies)