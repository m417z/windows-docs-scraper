# EcEnumNextSubscription function

## Description

The **EcEnumNextSubscription** function continues the enumeration of the subscriptions registered on the local machine.

## Parameters

### `SubscriptionEnum` [in]

The handle to the enumerator object that is returned from the [EcOpenSubscriptionEnum](https://learn.microsoft.com/windows/desktop/api/evcoll/nf-evcoll-ecopensubscriptionenum) function.

### `SubscriptionNameBufferSize` [in]

The size of the user-supplied buffer (in chars) to store the subscription name.

### `SubscriptionNameBuffer` [in]

The user-supplied buffer to store the subscription name.

### `SubscriptionNameBufferUsed` [out]

The size of the user-supplied buffer that is used by the function on successful return, or the size that is necessary to store the subscription name when the function fails with **ERROR_INSUFFICIENT_BUFFER**.

## Return value

This function returns BOOL.

## See also

[Windows Event Collector Functions](https://learn.microsoft.com/windows/desktop/WEC/windows-event-collector-functions)