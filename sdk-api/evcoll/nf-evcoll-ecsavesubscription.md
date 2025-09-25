# EcSaveSubscription function

## Description

The **EcSaveSubscription** function saves subscription configuration information. This function should be called whenever new values are added or updated to the subscription by the [EcSetSubscriptionProperty](https://learn.microsoft.com/windows/desktop/api/evcoll/nf-evcoll-ecsetsubscriptionproperty) method. If the subscription is enabled, the subscription will be activated when it is saved.

## Parameters

### `Subscription` [in]

The handle to the subscription object.

### `Flags` [in]

Reserved. Must be **NULL**.

## Return value

This function returns BOOL.

## Remarks

To retry a subscription for all the event sources of a subscription, use the **EcSaveSubscription** function instead of calling [EcRetrySubscription](https://learn.microsoft.com/windows/desktop/api/evcoll/nf-evcoll-ecretrysubscription) on each event source individually.

The subscription will be active only if the collector service is running. The service must be set to automatically start and run after the computer is booted.

#### Examples

For example code using the **EcSaveSubscription** function, see [Creating a Collector Initiated Subscription](https://learn.microsoft.com/windows/desktop/WEC/creating-an-event-collector-subscription) or [Creating a Source Initiated Subscription](https://learn.microsoft.com/windows/desktop/WEC/creating-a-source-initiated-subscription).

## See also

[Windows Event Collector Functions](https://learn.microsoft.com/windows/desktop/WEC/windows-event-collector-functions)