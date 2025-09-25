# IPackageDebugSettings::RegisterForPackageStateChanges

## Description

Register for package state-change notifications.

## Parameters

### `packageFullName` [in]

The package full name.

### `pPackageExecutionStateChangeNotification` [in]

Package state-change notifications are delivered by the [OnStateChanged](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipackageexecutionstatechangenotification-onstatechanged) function on *pPackageExecutionStateChangeNotification*.

### `pdwCookie` [out]

A unique registration identifier for the current listener. Use this identifier to unregister for package state-change notifications by using the [UnregisterForPackageStateChanges](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipackagedebugsettings-unregisterforpackagestatechanges) method.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Notifications are raised when the package enters the running,
suspending, and
suspended states.

## See also

[IPackageDebugSettings](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ipackagedebugsettings)

[IPackageExecutionStateChangeNotification](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ipackageexecutionstatechangenotification)

[UnregisterForPackageStateChanges](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipackagedebugsettings-unregisterforpackagestatechanges)