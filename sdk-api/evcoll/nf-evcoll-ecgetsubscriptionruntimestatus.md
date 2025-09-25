# EcGetSubscriptionRunTimeStatus function

## Description

The **EcGetSubscriptionRunTimeStatus** function retrieves the run time status information for an event source of a subscription or the subscription itself. The subscription is specified by its name. If the event source is **NULL**, then the status for the overall subscription is retrieved.

## Parameters

### `SubscriptionName` [in]

The name of the subscription to get the run time status information from.

### `StatusInfoId` [in]

An identifier that specifies which run time status information to get from the subscription. Specify a value from the [EC_SUBSCRIPTION_RUNTIME_STATUS_INFO_ID](https://learn.microsoft.com/windows/win32/api/evcoll/ne-evcoll-ec_subscription_runtime_status_info_id) enumeration. The **EcSubscriptionRunTimeStatusEventSources** value can be used to obtain the list of event sources associated with a subscription.

### `EventSourceName` [in]

The name of the event source to get the status from. Each subscription can have multiple event sources.

### `Flags` [in]

Reserved. Must be **NULL**.

### `StatusValueBufferSize` [in]

The size of the user-supplied buffer that will hold the run time status information.

### `StatusValueBuffer` [in]

The user-supplied buffer that will hold the run time status information. The buffer will hold the appropriate value depending on the [EC_SUBSCRIPTION_RUNTIME_STATUS_INFO_ID](https://learn.microsoft.com/windows/win32/api/evcoll/ne-evcoll-ec_subscription_runtime_status_info_id) value passed into the *StatusInfoId* parameter.

### `StatusValueBufferUsed` [out]

The size of the user supplied buffer that is used by the function on successful return, or the size that is necessary to store the property value when function fails with **ERROR_INSUFFICIENT_BUFFER**.

## Return value

This function returns BOOL.

## See also

[Windows Event Collector Functions](https://learn.microsoft.com/windows/desktop/WEC/windows-event-collector-functions)