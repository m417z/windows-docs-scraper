# IVssComponent::SetPreRestoreFailureMsg

## Description

The **SetPreRestoreFailureMsg**
method is used to create a message describing a failure in processing a
[PreRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-prerestore) event.

Only a writer can call this method, and only during a restore operation.

## Parameters

### `wszPreRestoreFailureMsg` [in]

A caller-allocated **NULL**-terminated wide character string containing the failure message describing an error that occurred
while processing a [PreRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-prerestore)
event.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully set the failure message. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_BAD_STATE** | The caller is not in the correct state (either backup or restore) for the operation. |

## Remarks

The failure message set by
**SetPreRestoreFailureMsg** applies to
all files in the component and any nonselectable subcomponents.

## See also

[IVssComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscomponent)

[IVssComponent::GetPostRestoreFailureMsg](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getpostrestorefailuremsg)

[IVssComponent::GetPreRestoreFailureMsg](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getprerestorefailuremsg)

[IVssComponent::SetPostRestoreFailureMsg](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-setpostrestorefailuremsg)