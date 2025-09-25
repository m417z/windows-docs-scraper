# EC_SUBSCRIPTION_RUNTIME_STATUS_INFO_ID enumeration

## Description

The **EC_SUBSCRIPTION_RUNTIME_STATUS_INFO_ID** enumeration specifies the values used to get the status of a subscription or the status of a particular event source with respect to a subscription.

 The values are used in the [EcGetSubscriptionRunTimeStatus](https://learn.microsoft.com/windows/desktop/api/evcoll/nf-evcoll-ecgetsubscriptionruntimestatus) function.

## Constants

### `EcSubscriptionRunTimeStatusActive:0`

Get the status of an active or inactive subscription or an event source. This will return an unsigned 32-bit integer value from the [EC_SUBSCRIPTION_RUNTIME_STATUS_ACTIVE_STATUS](https://learn.microsoft.com/windows/win32/api/evcoll/ne-evcoll-ec_subscription_runtime_status_active_status) enumeration.

### `EcSubscriptionRunTimeStatusLastError`

Get the last error status of a subscription or an event source. This will return an [EcVarTypeUInt32](https://learn.microsoft.com/windows/desktop/api/evcoll/ns-evcoll-ec_variant) value.

### `EcSubscriptionRunTimeStatusLastErrorMessage`

Get the last error message for a subscription or an event source. This will return an [EcVarTypeString](https://learn.microsoft.com/windows/desktop/api/evcoll/ns-evcoll-ec_variant) value.

### `EcSubscriptionRunTimeStatusLastErrorTime`

Get the time that the last error occurred for a subscription or an event source. This will return an [EcVarTypeDateTime](https://learn.microsoft.com/windows/desktop/api/evcoll/ns-evcoll-ec_variant) value.

### `EcSubscriptionRunTimeStatusNextRetryTime`

Get the next time that the subscription or an event source will try to run (after an error). This will return an [EcVarTypeDateTime](https://learn.microsoft.com/windows/desktop/api/evcoll/ns-evcoll-ec_variant) value.

### `EcSubscriptionRunTimeStatusEventSources`

Get the event sources for the subscription. For collector initiated subscriptions, this list will be identical to the one in the subscription's configuration. For source initiated subscriptions, this list will be the set of event sources that collector has heard from in the last 30 days. This list is persistent across reboots of the event collector. This will return an [EcVarTypeString](https://learn.microsoft.com/windows/desktop/api/evcoll/ns-evcoll-ec_variant) value.

### `EcSubscriptionRunTimeStatusLastHeartbeatTime`

Get the last time that a heartbeat (a signal used to signify the subscription is working) occurred for a subscription or an event source. This will return an [EcVarTypeDateTime](https://learn.microsoft.com/windows/desktop/api/evcoll/ns-evcoll-ec_variant) value.

### `EcSubscriptionRunTimeStatusInfoIdEND`