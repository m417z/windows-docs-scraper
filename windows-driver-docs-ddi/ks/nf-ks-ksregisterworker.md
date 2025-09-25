# KsRegisterWorker function

## Description

The **KsRegisterWorker** function handles clients registering for use of a thread. The function can create a new thread of the specified priority if there are currently no free threads available. This must be matched by a corresponding **KsUnregisterWorker** when thread use is completed. The function can only be called at PASSIVE_LEVEL.

```cpp
typedef PVOID PKSWORKER;
```

The worker routines function on opaque PKSWORKER objects that are created for each work item queued at one time.

## Parameters

### `WorkQueueType` [in]

Specifies the priority of the thread to create. This is usually either **CriticalWorkQueue**, **DelayedWorkQueue**, or **HyperCriticalWorkQueue**.

### `Worker` [out]

Location to put the opaque context that must be used when scheduling a work item. This contains the queue type and is used to synchronize completion of work items.

## Return value

The **KsRegisterWorker** function returns STATUS_SUCCESS if a worker was initialized, or if unsuccessful the function returns a thread or parameter error.