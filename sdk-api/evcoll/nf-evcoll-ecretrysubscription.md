# EcRetrySubscription function

## Description

The **EcRetrySubscription** function is used to retry connecting to the event source of a subscription that is not connected.

## Parameters

### `SubscriptionName` [in]

The name of the subscription to which to connect.

### `EventSourceName` [in]

The name of the event source of the subscription. This parameter is optional and can be **NULL**. This parameter must be **NULL** when the subscription is source initiated. If this parameter is **NULL**, the entire subscription will be retried.

### `Flags` [in]

Reserved. Must be **NULL**.

## Return value

This function returns BOOL.

## Remarks

To retry a subscription for all the event sources of a subscription, use the [EcSaveSubscription](https://learn.microsoft.com/windows/desktop/api/evcoll/nf-evcoll-ecsavesubscription) function instead of calling **EcRetrySubscription** on each event source individually.

#### Examples

For example code using the **EcRetrySubscription** function, see [Retrying an Event Collector Subscription](https://learn.microsoft.com/windows/desktop/WEC/retrying-an-event-collector-subscription).

## See also

[Windows Event Collector Functions](https://learn.microsoft.com/windows/desktop/WEC/windows-event-collector-functions)