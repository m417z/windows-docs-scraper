# IVssFileShareSnapshotProvider::Query

## Description

Gets an enumeration of [VSS_SNAPSHOT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_snapshot_prop) structures for all file share snapshots that are available to the application server.

## Parameters

### `QueriedObjectId` [in]

Reserved for system use. The value of this parameter must be GUID_NULL.

### `eQueriedObjectType` [in]

Reserved for system use. The value of this parameter must be VSS_OBJECT_NONE.

### `eReturnedObjectsType` [in]

Reserved for system use. The value of this parameter must be VSS_OBJECT_SNAPSHOT.

### `ppEnum` [out]

The address of an [IVssEnumObject](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssenumobject) interface pointer,
which is initialized on return. Callers must release the interface. This parameter is required and cannot be null.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | The query operation was successful. |
| **E_ACCESSDENIED** | The caller does not have sufficient backup privileges or is not an administrator. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_PROVIDER_VETO** | Provider error. The provider logged the error in the event log. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |

## Remarks

This method is typically called in response to requester generated snapshot query operations.

Calling the [IVssEnumObject::Next](https://learn.microsoft.com/windows/desktop/api/vss/nf-vss-ivssenumobject-next) method on the
[IVssEnumObject](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssenumobject) interface that is returned though the
*ppEnum* parameter will return
[VSS_OBJECT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_object_prop) structures containing a
[VSS_SNAPSHOT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_snapshot_prop) structure for each shadow copy.

## See also

[IVssFileShareSnapshotProvider](https://learn.microsoft.com/windows/desktop/api/vsprov/nn-vsprov-ivssfilesharesnapshotprovider)