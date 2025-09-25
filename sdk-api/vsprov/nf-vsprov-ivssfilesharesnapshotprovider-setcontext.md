# IVssFileShareSnapshotProvider::SetContext

## Description

Sets the context for the subsequent shadow copy-related operations.

## Parameters

### `lContext` [in]

The context to be set. The context must be one of the supported values of [_VSS_SNAPSHOT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_snapshot_context) or a supported combination of [_VSS_VOLUME_SNAPSHOT_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_volume_snapshot_attributes) and **_VSS_SNAPSHOT_CONTEXT** values.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | The context was set successfully. |
| **E_ACCESSDENIED** | The caller does not have sufficient backup privileges or is not an administrator. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_BAD_STATE** | The context is frozen and cannot be changed. |

## Remarks

The default context for VSS shadow copies is VSS_CTX_BACKUP.

**Windows XP:** The only supported context is the default context, VSS_CTX_BACKUP. Therefore, calling
[SetContext](https://learn.microsoft.com/windows/desktop/api/vsprov/nf-vsprov-ivsssoftwaresnapshotprovider-setcontext) under Windows XP returns
E_NOTIMPL.

For more information about how the context that is set by
[SetContext](https://learn.microsoft.com/windows/desktop/api/vsprov/nf-vsprov-ivsssoftwaresnapshotprovider-setcontext) affects
how a shadow copy is created and managed, see
[Implementation Details for
Creating Shadow Copies](https://learn.microsoft.com/windows/desktop/VSS/implementation-details-for-creating-shadow-copies).

For a complete discussion of the permitted shadow copy contexts, see
[_VSS_SNAPSHOT_CONTEXT](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_snapshot_context) and
[_VSS_VOLUME_SNAPSHOT_ATTRIBUTES](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_volume_snapshot_attributes).

## See also

[IVssFileShareSnapshotProvider](https://learn.microsoft.com/windows/desktop/api/vsprov/nn-vsprov-ivssfilesharesnapshotprovider)