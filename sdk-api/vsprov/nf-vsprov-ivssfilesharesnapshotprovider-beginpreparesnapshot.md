# IVssFileShareSnapshotProvider::BeginPrepareSnapshot

## Description

VSS calls this method for each shadow copy that is added to the shadow copy set.

## Parameters

### `SnapshotSetId` [in]

Shadow copy set identifier.

### `SnapshotId` [in]

Identifier of the shadow copy to be created.

### `pwszSharePath` [in]

The file share path.

### `lNewContext` [in]

The context for the shadow copy set. This context consists of a bitmask of [_VSS_VOLUME_SNAPSHOT_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_volume_snapshot_attributes) values.

### `ProviderId` [in]

The provider ID.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | The shadow copy was successfully created. |
| **E_ACCESSDENIED** | The caller does not have sufficient backup privileges or is not an administrator. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_OBJECT_NOT_FOUND** | The specified volume was not found. |
| **VSS_E_PROVIDER_VETO** | Provider error. The provider logged the error in the event log. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_UNSUPPORTED_CONTEXT** | The specified context is not supported. |
| **VSS_E_VOLUME_NOT_SUPPORTED_BY_PROVIDER** | The provider does not support the specified volume. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## See also

[IVssFileShareSnapshotProvider](https://learn.microsoft.com/windows/desktop/api/vsprov/nn-vsprov-ivssfilesharesnapshotprovider)