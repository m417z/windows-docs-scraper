# RegisterAppStateChangeNotification function

## Description

Enables an app to register a callback function through which it can be notified that its library is going into or coming out of a suspended state. The app can use this information to perform any necessary operations, such as preserving state, that should be performed at that point.

## Parameters

### `Routine` [in]

A pointer to a callback function that is called when the app enters or leaves the suspended state. See [PAPPSTATE_CHANGE_ROUTINE](https://learn.microsoft.com/windows/desktop/api/appnotify/nc-appnotify-pappstate_change_routine) for more detail on this function.

### `Context` [in, optional]

App-specific context information that the app uses when going into or out of a suspended state. This is commonly a "this" pointer.

### `Registration` [out]

When this function returns successfully, this parameter receives the address of a pointer to a value that can be used to identify the registration. Store this value to use with [UnregisterAppStateChangeNotification](https://learn.microsoft.com/windows/desktop/api/appnotify/nf-appnotify-unregisterappstatechangenotification).

## Return value

A standard Win32 status code.

## See also

[UnregisterAppStateChangeNotification](https://learn.microsoft.com/windows/desktop/api/appnotify/nf-appnotify-unregisterappstatechangenotification)