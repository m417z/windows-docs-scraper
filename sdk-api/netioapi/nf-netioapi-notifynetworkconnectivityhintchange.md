## Description

Registers an application-defined callback function, to be called when the aggregate network connectivity level and cost hints change.

## Parameters

### `Callback` [in]

A function pointer of type [PNETWORK_CONNECTIVITY_HINT_CHANGE_CALLBACK](https://learn.microsoft.com/windows/win32/api/netioapi/nc-netioapi-pnetwork_connectivity_hint_change_callback), which points to your application-defined callback function. The callback function will be invoked when a network connectivity level or cost change occurs.

### `CallerContext` [in]

The user-specific caller context. This context will be supplied to the callback function.

### `InitialNotification` [in]

`True` if an initialization notification should be provided, otherwise `false`.

### `NotificationHandle` [out]

A pointer to a **HANDLE**. The function sets the value to a handle to the notification registration.

## Return value

If the function succeeds, the return value is **NO_ERROR**. Otherwise, an error code is returned.

## Remarks

To deregister for change notifications, call the **CancelMibChangeNotify2** function, passing the *NotificationHandle* parameter returned by **NotifyNetworkConnectivityHintChange**.

## See also

* [PNETWORK_CONNECTIVITY_HINT_CHANGE_CALLBACK](https://learn.microsoft.com/windows/win32/api/netioapi/nc-netioapi-pnetwork_connectivity_hint_change_callback)

* [CancelMibChangeNotify2](https://learn.microsoft.com/windows/win32/api/netioapi/nf-netioapi-cancelmibchangenotify2)