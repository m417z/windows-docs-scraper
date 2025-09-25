# IMFTopologyNodeAttributeEditor::UpdateNodeAttributes

## Description

Updates the attributes of one or more nodes in the current topology.

## Parameters

### `TopoId` [in]

Reserved.

### `cUpdates` [in]

The number of elements in the *pUpdates* array.

### `pUpdates` [in]

Pointer to an array of [MFTOPONODE_ATTRIBUTE_UPDATE](https://learn.microsoft.com/windows/desktop/api/mfidl/ns-mfidl-mftoponode_attribute_update) structures. Each element of the array updates one attribute on a node.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Currently the only attribute that can be updated is the [MF_TOPONODE_MEDIASTOP](https://learn.microsoft.com/windows/desktop/medfound/mf-toponode-mediastop-attribute) attribute. The method ignores any other attributes.

## See also

[IMFTopologyNodeAttributeEditor](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopologynodeattributeeditor)