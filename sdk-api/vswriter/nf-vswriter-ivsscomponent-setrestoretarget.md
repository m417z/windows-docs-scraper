# IVssComponent::SetRestoreTarget

## Description

The
**SetRestoreTarget** method sets the restore target (in terms of the
[VSS_RESTORE_TARGET](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_restore_target) enumeration) for the current component.

Only a writer can call this method, and only during a restore operation.

## Parameters

### `target` [in]

A value from
[VSS_RESTORE_TARGET](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_restore_target) containing the restore target information.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully set the item. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_BAD_STATE** | The caller is not in the correct state (either backup or restore) for the operation. |

## Remarks

The restore target set by
**SetRestoreTarget** applies to all files in the component and any nonselectable subcomponents.

## See also

[IVssComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscomponent)