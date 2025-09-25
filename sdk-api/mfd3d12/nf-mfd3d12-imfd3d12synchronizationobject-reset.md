## Description

Resets the synchronization object state, allowing the allocator to reuse the synchronization object and the associated D3D12 resource.

## Return value

The handle is signaled when there are no longer any pending resource release or resource ready signals for the current resource. If the event handle has restricted access rights, the handle must have at least the [EVENT_MODIFY_STATE](https://learn.microsoft.com/windows/win32/sync/synchronization-object-security-and-access-rights) right.

## Remarks

## See also