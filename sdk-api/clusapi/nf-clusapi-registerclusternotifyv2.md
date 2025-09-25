# RegisterClusterNotifyV2 function

## Description

Registers an
event type with a notification port by adding the notification key to the event type.

## Parameters

### `hChange` [in]

A handle to a notification port that is created with the
[CreateClusterNotifyPortV2](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-createclusternotifyportv2) function.

### `Filter` [in]

A [NOTIFY_FILTER_AND_TYPE](https://learn.microsoft.com/windows/desktop/api/clusapi/ns-clusapi-notify_filter_and_type) structure that specifies the event type to create.

### `hObject` [in]

A handle to the [failover cluster object](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-objects)
that is affected by the event as specified in the *dwFilterType* parameter. The type of handle
depends on the value of *dwFilterType*.

### `dwNotifyKey` [in]

The notification key that is returned from the
[GetClusterNotify](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusternotify) function when the requested event
occurs.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails, the function returns a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[Failover Cluster Management Function](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-management-functions)