## Description

Destroys a subscription. Note that this routine waits for any in-progress callbacks to return before completing.

> [!CAUTION]
> Do not call the routine from its subscription's callback. Doing so will crash the program.

## Parameters

### `subscription`

Supplies a handle to the target subscription to be destroyed.

## Return value

Returns an **HRESULT**.

## Remarks

## See also

[SubscribeActivityCoordinatorPolicy](https://learn.microsoft.com/windows/win32/api/activitycoordinator/nf-activitycoordinator-subscribeactivitycoordinatorpolicy)

[ACTIVITY_COORDINATOR_CALLBACK](https://learn.microsoft.com/windows/win32/api/activitycoordinatortypes/nc-activitycoordinatortypes-activity_coordinator_callback)