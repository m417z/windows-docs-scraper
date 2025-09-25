## Description

Defines constants that specify options around type of COM apartment for a new [DispatcherQueueController](https://learn.microsoft.com/uwp/api/windows.system.dispatcherqueuecontroller).

## Constants

### `DQTAT_COM_NONE:0`

No COM threading apartment type specified.

### `DQTAT_COM_ASTA:1`

Specifies an application single-threaded apartment (ASTA) COM threading apartment.

### `DQTAT_COM_STA:2`

Specifies a single-threaded apartment (STA) COM threading apartment.

## Remarks

This value is relevant when [DispatcherQueueOptions.threadType](https://learn.microsoft.com/windows/desktop/api/dispatcherqueue/ns-dispatcherqueue-dispatcherqueueoptions) is **DQTYPE_THREAD_DEDICATED**. Use **DQTAT_COM_NONE** when **DispatcherQueueOptions.threadType** is **DQTYPE_THREAD_CURRENT**.

Also see Remarks for [CreateDispatcherQueueController](https://learn.microsoft.com/windows/win32/api/dispatcherqueue/nf-dispatcherqueue-createdispatcherqueuecontroller).

Introduced in Windows 10, version 1709.

## See also

[CreateDispatcherQueueController](https://learn.microsoft.com/windows/desktop/api/dispatcherqueue/nf-dispatcherqueue-createdispatcherqueuecontroller)

[DispatcherQueueOptions](https://learn.microsoft.com/windows/desktop/api/dispatcherqueue/ns-dispatcherqueue-dispatcherqueueoptions)