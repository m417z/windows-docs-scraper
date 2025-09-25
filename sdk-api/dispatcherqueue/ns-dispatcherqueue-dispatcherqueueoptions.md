## Description

Represents options around threading affinity and type of COM apartment for a new [DispatcherQueueController](https://learn.microsoft.com/uwp/api/windows.system.dispatcherqueuecontroller).

## Members

### `dwSize`

Size of this **DispatcherQueueOptions** structure.

### `threadType`

Thread affinity for a new [DispatcherQueueController](https://learn.microsoft.com/uwp/api/windows.system.dispatcherqueuecontroller).

### `apartmentType`

Specifies whether to initialize the COM apartment on the new thread as an application single-threaded apartment (ASTA) or a single-threaded apartment (STA). This field is relevant only if **threadType** is **DQTYPE_THREAD_DEDICATED**. Use **DQTAT_COM_NONE** when **DispatcherQueueOptions.threadType** is **DQTYPE_THREAD_CURRENT**.

## Remarks

Introduced in Windows 10, version 1709.

## See also

[CreateDispatcherQueueController](https://learn.microsoft.com/windows/desktop/api/dispatcherqueue/nf-dispatcherqueue-createdispatcherqueuecontroller)