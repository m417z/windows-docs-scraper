# EcDeleteSubscription function

## Description

The **EcDeleteSubscription** function deletes an existing subscription that is specified by the *SubscriptionName* parameter.

The function fails if the security descriptor of the subscription does not permit delete access for the calling process.

If the subscription is active at the moment this API is called, then the subscription is deactivated.

## Parameters

### `SubscriptionName` [in]

The subscription to be deleted.

### `Flags` [in]

Reserved, must be 0.

## Return value

This function returns BOOL.

## See also

[Windows Event Collector Functions](https://learn.microsoft.com/windows/desktop/WEC/windows-event-collector-functions)