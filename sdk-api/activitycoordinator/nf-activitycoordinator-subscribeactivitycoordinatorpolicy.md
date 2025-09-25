## Description

Creates a subscription that delivers coordination notifications to the supplied callback based on the policy's configuration. Upon notification, the supplied callback is executed with the supplied context. A notification with the current state will be delivered immediately on a separate thread and may be delivered before this call returns. Changes made to the policy after subscribing do not affect the subscription. A single policy can be used to create many subscriptions with unique policy configurations. Notifications are serialized.

## Parameters

### `policy`

Supplies a handle to the target policy.

### `callback`

Supplies the callback to be executed for all coordination notifications from this subscription.

### `callbackContext`

Supplies the context to be passed to callback routine.

### `subscription`

Supplies a pointer to an **ACTIVITY_COORDINATOR_SUBSCRIPTION** handle that receives the created subscription handle.

## Return value

Returns an **HRESULT**.

## Remarks

>**Note** Do not perform your activity in this callback, since it will block delivery of future policy notifications for this subscription. This callback should be used to coordinate the starting and stopping of your activity in response to RUN/STOP notifications from the API.

>**Note** Do not block this callback for extended periods of time, since it will block [UnsubscribeActivityCoordinatorPolicy](https://learn.microsoft.com/windows/win32/api/activitycoordinator/nf-activitycoordinator-unsubscribeactivitycoordinatorpolicy) and may contribute to thread pool exhaustion.

>**Note** Calls to [UnsubscribeActivityCoordinatorPolicy](https://learn.microsoft.com/windows/win32/api/activitycoordinator/nf-activitycoordinator-unsubscribeactivitycoordinatorpolicy) from this callback will fail. Unsubscribing must occur outside the callback.

## See also

[UnsubscribeActivityCoordinatorPolicy](https://learn.microsoft.com/windows/win32/api/activitycoordinator/nf-activitycoordinator-unsubscribeactivitycoordinatorpolicy)

[ACTIVITY_COORDINATOR_CALLBACK](https://learn.microsoft.com/windows/win32/api/activitycoordinatortypes/nc-activitycoordinatortypes-activity_coordinator_callback)

[ACTIVITY_COORDINATOR_NOTIFICATION](https://learn.microsoft.com/windows/win32/api/activitycoordinatortypes/ne-activitycoordinatortypes-activity_coordinator_notification)