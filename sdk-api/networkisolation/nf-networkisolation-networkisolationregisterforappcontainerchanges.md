# NetworkIsolationRegisterForAppContainerChanges function

## Description

The **NetworkIsolationRegisterForAppContainerChanges** function is used to register for the delivery of notifications regarding changes to an app container.

## Parameters

### `flags` [in]

Type: **DWORD**

A bitmask value of control flags which specify when to receive notifications. May contain one or more of the following flags.

| Value | Meaning |
| --- | --- |
| **INET_FIREWALL_AC_NONE**<br><br>0x00 | No notifications will be delivered. |
| **INET_FIREWALL_AC_PACKAGE_ID_ONLY**<br><br>0x01 | Notifications will be delivered when an app container is created with a package identifier. |
| **INET_FIREWALL_AC_BINARY**<br><br>0x02 | Notifications will be delivered when an app container is created with a binary path. |
| **INET_FIREWALL_AC_MAX**<br><br>0x04 | Maximum value for testing purposes. |

### `callback` [in]

Type: **[PAC_CHANGES_CALLBACK_FN](https://learn.microsoft.com/windows/desktop/api/networkisolation/nc-networkisolation-pac_changes_callback_fn)**

Function pointer that will be invoked when a notification is ready for delivery.

### `context` [in, optional]

Type: **PVOID**

Optional context pointer. This pointer is passed to the *callback* function along with details of the change.

### `registrationObject` [out]

Type: **HANDLE***

Handle to the newly created registration.

## Return value

Type: **DWORD**

Returns ERROR_SUCCESS if successful, or an error value otherwise.

## See also

[NetworkIsolationUnregisterForAppContainerChanges](https://learn.microsoft.com/previous-versions/windows/desktop/api/netfw/nf-netfw-networkisolationunregisterforappcontainerchanges)

[PAC_CHANGES_CALLBACK_FN](https://learn.microsoft.com/windows/desktop/api/networkisolation/nc-networkisolation-pac_changes_callback_fn)