# GetNotifyEventHandle function

## Description

Retrieves a handle to a notification event.

## Parameters

### `hChange` [in]

A handle to the notification port that received the notification event.

### `lphTargetEvent` [out]

The handle to the notification event.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails, the function returns a system error code.

## See also

[Failover Cluster Management Function](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-management-functions)