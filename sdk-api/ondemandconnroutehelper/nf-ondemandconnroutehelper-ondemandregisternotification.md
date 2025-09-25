# OnDemandRegisterNotification function

## Description

The **OnDemandRegisterNotification** function allows an application to register to be notified when the Route Requests cache is modified. For example, this allows the system to recycle cached connections when a Route Request is added or removed from the cache.

## Parameters

### `callback` [in]

A pointer to a function of type **ONDEMAND_NOTIFICATION_CALLBACK** to receive the notifications.

### `callbackContext` [in, optional]

A pointer to a memory location containing optional context to be passed to the callback.

### `registrationHandle` [out]

A pointer to a HANDLE to receive a handle to the registration in case of success.

## Return value

Returns S_OK on success.

## Remarks

The **ONDEMAND_NOTIFICATION_CALLBACK** function is defined as:

``` syntax
typedef void (WINAPI *ONDEMAND_NOTIFICATION_CALLBACK) (PVOID);
```

## See also

[OnDemandUnregisterNotification](https://learn.microsoft.com/windows/desktop/api/ondemandconnroutehelper/nf-ondemandconnroutehelper-ondemandunregisternotification)