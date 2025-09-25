# IVssSoftwareSnapshotProvider::SetSnapshotProperty

## Description

Sets a property for a shadow copy.

## Parameters

### `SnapshotId` [in]

Shadow copy identifier. This parameter is required and cannot be GUID_NULL.

### `eSnapshotPropertyId` [in]

A [VSS_SNAPSHOT_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_snapshot_property_id) value that specifies the property to be set for the shadow copy.

### `vProperty` [in]

The value to be set for the property. See the [VSS_SNAPSHOT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_snapshot_prop) structure for valid data types and descriptions of the properties that can be set for a shadow copy.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | The property was set successfully. |
| **E_ACCESSDENIED** | The caller does not have sufficient backup privileges or is not an administrator. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_OBJECT_NOT_FOUND** | The specified shadow copy was not found. |

## See also

[IVssSoftwareSnapshotProvider](https://learn.microsoft.com/windows/desktop/api/vsprov/nn-vsprov-ivsssoftwaresnapshotprovider)