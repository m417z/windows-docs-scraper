## Description

Defines constants that specify options around threading affinity for a new [DispatcherQueueController](https://learn.microsoft.com/uwp/api/windows.system.dispatcherqueuecontroller).

## Constants

### `DQTYPE_THREAD_DEDICATED:1`

Specifies that the [DispatcherQueue](https://learn.microsoft.com/uwp/api/windows.system.dispatcherqueue) for the [DispatcherQueueController](https://learn.microsoft.com/uwp/api/windows.system.dispatcherqueuecontroller) will be created on a dedicated thread.

### `DQTYPE_THREAD_CURRENT:2`

Specifies that the [DispatcherQueue](https://learn.microsoft.com/uwp/api/windows.system.dispatcherqueue) for the [DispatcherQueueController](https://learn.microsoft.com/uwp/api/windows.system.dispatcherqueuecontroller) will be created on the caller's thread.

## Remarks

See Remarks for [CreateDispatcherQueueController](https://learn.microsoft.com/windows/win32/api/dispatcherqueue/nf-dispatcherqueue-createdispatcherqueuecontroller).

Introduced in Windows 10, version 1709.

## See also

[CreateDispatcherQueueController](https://learn.microsoft.com/windows/win32/api/dispatcherqueue/nf-dispatcherqueue-createdispatcherqueuecontroller)

[DispatcherQueueOptions](https://learn.microsoft.com/windows/win32/api/dispatcherqueue/ns-dispatcherqueue-dispatcherqueueoptions)