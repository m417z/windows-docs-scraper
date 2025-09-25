# IMFWorkQueueServicesEx::BeginRegisterPlatformWorkQueueWithMMCSSEx

## Description

Registers a platform work queue with Multimedia Class Scheduler Service (MMCSS) using the specified
class and task id.

## Parameters

### `dwPlatformWorkQueue` [in]

The id of one of the standard platform work queues.

### `wszClass` [in]

The MMCSS class which the work queue should be registered with.

### `dwTaskId` [in]

 The task id which the work queue should be registered with. If *dwTaskId* is 0, a new MMCSS bucket will be created.

### `lPriority` [in]

The priority.

### `pCallback` [in]

Standard callback used for async operations in Media Foundation.

### `pState` [in]

Standard state used for async operations in Media Foundation.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFWorkQueueServicesEx](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfworkqueueservicesex)