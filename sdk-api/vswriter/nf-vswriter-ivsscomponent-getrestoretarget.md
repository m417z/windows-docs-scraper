# IVssComponent::GetRestoreTarget

## Description

The
**GetRestoreTarget** method returns the restore target (in terms of the
[VSS_RESTORE_TARGET](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_restore_target) enumeration) for the current component.

Either a writer or a requester can call this method. It can be called only during a restore operation.

## Parameters

### `pTarget` [out]

The address of a caller-allocated variable that receives a
[VSS_RESTORE_TARGET](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_restore_target) enumeration value that specifies the restore target.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned the attribute value. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_OBJECT_NOT_FOUND** | The specified item was not found. |

## See also

[IVssComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscomponent)