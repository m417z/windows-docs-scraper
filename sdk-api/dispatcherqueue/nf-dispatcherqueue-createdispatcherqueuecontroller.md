## Description

Creates a [DispatcherQueueController](https://learn.microsoft.com/uwp/api/windows.system.dispatcherqueuecontroller). Use the created [DispatcherQueueController](https://learn.microsoft.com/uwp/api/windows.system.dispatcherqueuecontroller) to create and manage the lifetime of a [DispatcherQueue](https://learn.microsoft.com/uwp/api/windows.system.dispatcherqueue) to run queued tasks in priority order on the dispatcher queue's thread.

## Parameters

### `options` [in]

The threading affinity and type of COM apartment for the created [DispatcherQueueController](https://learn.microsoft.com/uwp/api/windows.system.dispatcherqueuecontroller). See remarks for details.

### `dispatcherQueueController` [out]

The created dispatcher queue controller.

**Important** The [DispatcherQueueController](https://learn.microsoft.com/uwp/api/windows.system.dispatcherqueuecontroller) is a WinRT object.

## Return value

**S_OK** for success; otherwise a failure code.

## Remarks

Introduced in Windows 10, version 1709.

If *options.threadType* is **DQTYPE_THREAD_DEDICATED**, then this function
creates a thread, initializes it with the specified COM apartment,
and associates a [DispatcherQueue](https://learn.microsoft.com/uwp/api/windows.system.dispatcherqueue) with that thread.
The dispatcher queue event loop runs on the new dedicated thread until the dispatcher queue is explicitly shut down.
To avoid thread and memory leaks,
call [DispatcherQueueController.ShutdownQueueAsync](https://learn.microsoft.com/uwp/api/windows.system.dispatcherqueuecontroller.shutdownqueueasync)
when you are finished with the dispatcher queue.

If *options.threadType* is **DQTYPE_THREAD_CURRENT**, then a
[DispatcherQueue](https://learn.microsoft.com/uwp/api/windows.system.dispatcherqueue) is created and associated with the current thread.
An error results if there is already a **DispatcherQueue** associated with the current thread.
The current thread must pump messages to allow the dispatcher queue to dispatch tasks.
Before the current thread exits, it must call
[DispatcherQueueController.ShutdownQueueAsync](https://learn.microsoft.com/uwp/api/windows.system.dispatcherqueuecontroller.shutdownqueueasync),
and continue pumping messages until the **IAsyncAction** completes.

This call does not return until the [DispatcherQueueController](https://learn.microsoft.com/uwp/api/windows.system.dispatcherqueuecontroller) and new thread (if any) are created.

**Important** The [DispatcherQueueController](https://learn.microsoft.com/uwp/api/windows.system.dispatcherqueuecontroller), and its associated [DispatcherQueue](https://learn.microsoft.com/uwp/api/windows.system.dispatcherqueue), are WinRT objects. See their documentation for usage details.

## See also

[DispatcherQueue](https://learn.microsoft.com/uwp/api/windows.system.dispatcherqueue)

[DispatcherQueueController](https://learn.microsoft.com/uwp/api/windows.system.dispatcherqueuecontroller)