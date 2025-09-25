# ApplicationProcessRecycleInfo structure

## Description

Represents details about the recycling of a process hosting COM+ applications.

## Members

### `IsRecyclable`

Indicates whether the process is one that can be recycled. For example, only COM+ server applications can be recycled, and applications running as Windows services cannot be recycled.

### `IsRecycled`

Indicates whether the process is a COM+ server application instance that has been recycled.

### `TimeRecycled`

The time at which the process was recycled. This member is meaningful only if **IsRecycled** is **TRUE**.

### `TimeToTerminate`

The time at which a recycled process will be forcibly terminated if it does not shut down on its own before this time. This member is meaningful only if **IsRecycled** is **TRUE**.

### `RecycleReasonCode`

A code that indicates the reason a process was recycled. This is usually one of the recycle reason code constants defined in Comsvcs.h (for example, CRR_RECYCLED_FROM_UI), but may be any code supplied by an administrative application in a call to [ICOMAdminCatalog2::RecycleApplicationInstances](https://learn.microsoft.com/windows/desktop/api/comadmin/nf-comadmin-icomadmincatalog2-recycleapplicationinstances). This member is meaningful only if **IsRecycled** is **TRUE**.

### `IsPendingRecycle`

Indicates whether a paused COM+ server application instance has met the conditions for automatic recycling. If so, the application instance will be recycled when it is resumed.

### `HasAutomaticLifetimeRecycling`

Indicates whether the process is an instance of a COM+ server application that has been configured for automatic recycling based on lifetime.

### `TimeForAutomaticRecycling`

The time at which the process will be automatically recycled. This member is meaningful only if **HasAutomaticLifetimeRecycling** is **TRUE**.

### `MemoryLimitInKB`

The recycling memory limit configured for a COM+ server application in kilobytes, or 0 if the application is not configured for automatic recycling based on memory usage.

### `MemoryUsageInKBLastCheck`

The memory usage of the process in kilobytes the last time this metric was calculated by the Tracker Server. This is set to DATA_NOT_AVAILABLE (0xFFFFFFFF) if the application is not configured for automatic recycling based on memory usage, or if memory usage has not yet been checked.

### `ActivationLimit`

The activation limit configured for a COM+ server application, or 0 if the application is not configured for automatic recycling based on activation count. This data is not currently available, and is always set to DATA_NOT_AVAILABLE (0xFFFFFFFF).

### `NumActivationsLastReported`

The total number of activations performed in a COM+ server application instance, or 0 if the process is not hosting a COM+ server application. This data is not currently available, and is always set to DATA_NOT_AVAILABLE (0xFFFFFFFF).

### `CallLimit`

The call limit configured for a COM+ server application, or zero if the application is not configured for automatic recycling based on number of calls. This data is not currently available, and is always set to DATA_NOT_AVAILABLE (0xFFFFFFFF).

### `NumCallsLastReported`

The total number of calls serviced by a COM+ server application instance, or 0 if the process is not hosting a COM+ server application. This data is not currently available, and is always set to DATA_NOT_AVAILABLE (0xFFFFFFFF).

## See also

[IGetAppTrackerData](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-igetapptrackerdata)