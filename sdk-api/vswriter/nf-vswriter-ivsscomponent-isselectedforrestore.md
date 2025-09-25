# IVssComponent::IsSelectedForRestore

## Description

The
**IsSelectedForRestore** method determines whether the current component has been selected to be restored.

Either a writer or a requester can call this method.

## Parameters

### `pbSelectedForRestore` [out]

The address of a caller-allocated variable that receives **true** if the component has been selected to be restored, or **false** otherwise.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully set the item. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_BAD_STATE** | The caller is not in the correct state (either backup or restore) for the operation. |

## Remarks

**IsSelectedForRestore** is relevant only under component mode.

If the component defines a component set,
**IsSelectedForRestore** refers both to the component and all of its subcomponents.

## See also

[IVssBackupComponents::SetSelectedForRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setselectedforrestore)

[IVssComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscomponent)