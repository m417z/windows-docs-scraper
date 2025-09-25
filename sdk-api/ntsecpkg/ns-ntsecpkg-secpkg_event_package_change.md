# SECPKG_EVENT_PACKAGE_CHANGE structure

## Description

The **SECPKG_EVENT_PACKAGE_CHANGE** structure contains information about changes in [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) availability. This structure is indirectly used by the
[RegisterNotification](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_register_notification) function. It is returned to a registered notification function when the function is registered to receive notifications for the *NotificationClass* parameter value NOTIFY_CLASS_PACKAGE_CHANGE.

## Members

### `ChangeType`

The type of change. One of the following values will be specified.

| Value | Meaning |
| --- | --- |
| **SECPKG_PACKAGE_CHANGE_LOAD** | A package was loaded. |
| **SECPKG_PACKAGE_CHANGE_UNLOAD** | A package was unloaded. |
| **SECPKG_PACKAGE_CHANGE_SELECT** | A new package became the preferred security package. |

### `PackageId`

The identifier of the security package.

### `PackageName`

The name of the security package.