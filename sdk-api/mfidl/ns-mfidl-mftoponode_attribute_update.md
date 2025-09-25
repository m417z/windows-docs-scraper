# MFTOPONODE_ATTRIBUTE_UPDATE structure

## Description

Specifies a new attribute value for a topology node.

## Members

### `NodeId`

The identifier of the topology node to update. To get the identifier of a topology node, call [IMFTopologyNode::GetTopoNodeID](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imftopologynode-gettoponodeid).

### `guidAttributeKey`

GUID that specifies the attribute to update.

### `attrType`

Attribute type, specified as a member of the [MF_ATTRIBUTE_TYPE](https://learn.microsoft.com/windows/desktop/api/mfobjects/ne-mfobjects-mf_attribute_type) enumeration.

### `u32`

Attribute value (unsigned 32-bit integer). This member is used when **attrType** equals **MF_ATTRIBUTE_UINT32**.

### `u64`

Attribute value (unsigned 32-bit integer). This member is used when **attrType** equals **MF_ATTRIBUTE_UINT64**. See Remarks.

### `d`

Attribute value (floating point). This member is used when **attrType** equals **MF_ATTRIBUTE_DOUBLE**.

## Remarks

Due to an error in the structure declaration, the **u64** member is declared as a 32-bit integer, not a 64-bit integer. Therefore, any 64-bit value passed to the [IMFTopologyNodeAttributeEditor::UpdateNodeAttributes](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imftopologynodeattributeeditor-updatenodeattributes) method is truncated to 32 bits.

## See also

[IMFTopologyNodeAttributeEditor::UpdateNodeAttributes](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imftopologynodeattributeeditor-updatenodeattributes)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)

[TOPOID](https://learn.microsoft.com/windows/desktop/medfound/topoid)