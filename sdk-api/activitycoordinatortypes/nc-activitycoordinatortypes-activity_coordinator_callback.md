## Description

A callback for all notifications from a subscription that are used to coordinate execution of an activity.

## Parameters

### `notification`

An [ACTIVITY_COORDINATOR_NOTIFICATION](https://learn.microsoft.com/windows/win32/api/activitycoordinatortypes/ne-activitycoordinatortypes-activity_coordinator_notification) indicating whether the activity should stop/pause or start/resume.

### `callbackContext`

Provides the context that was given when creating the subscription.

## Remarks

## See also

[SubscribeActivityCoordinatorPolicy](https://learn.microsoft.com/windows/win32/api/activitycoordinator/nf-activitycoordinator-subscribeactivitycoordinatorpolicy)

[UnsubscribeActivityCoordinatorPolicy](https://learn.microsoft.com/windows/win32/api/activitycoordinator/nf-activitycoordinator-unsubscribeactivitycoordinatorpolicy)

[ACTIVITY_COORDINATOR_NOTIFICATION](https://learn.microsoft.com/windows/win32/api/activitycoordinatortypes/ne-activitycoordinatortypes-activity_coordinator_notification)