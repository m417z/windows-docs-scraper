# EC_SUBSCRIPTION_RUNTIME_STATUS_ACTIVE_STATUS enumeration

## Description

The **EC_SUBSCRIPTION_RUNTIME_STATUS_ACTIVE_STATUS** enumeration specifies the status of a subscription or an event source with respect to a subscription.

## Constants

### `EcRuntimeStatusActiveStatusDisabled:1`

The subscription or event source is disabled.

### `EcRuntimeStatusActiveStatusActive`

The subscription or event source is running.

### `EcRuntimeStatusActiveStatusInactive`

The subscription or event source is inactive. You can query the System event log to see the error events sent by the Event Collector service. Use the [EC_SUBSCRIPTION_RUNTIME_STATUS_INFO_ID](https://learn.microsoft.com/windows/win32/api/evcoll/ne-evcoll-ec_subscription_runtime_status_info_id) values to obtain information on why the subscription or source is inactive.

### `EcRuntimeStatusActiveStatusTrying`

The subscription or event source is trying to connect for the first time or is retrying after a problem. When an active subscription runs into a problem, it will retry several times.