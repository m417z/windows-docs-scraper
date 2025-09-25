## Description

Specifies an app-defined callback function that notifies the app when the app is entering or leaving a suspended state.

## Parameters

### `Quiesced`

Type: **BOOLEAN**

**TRUE** if the app is entering the suspended state; **FALSE** if the app is leaving the suspended state.

### `Context` [in]

Type: **PVOID**

A pointer to data that the app can save when suspending and use upon resuming. This value is supplied by the [RegisterAppStateChangeNotification](https://learn.microsoft.com/windows/desktop/api/appnotify/nf-appnotify-registerappstatechangenotification) function. This is commonly a "this" pointer.