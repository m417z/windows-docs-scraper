# SHChangeNotification_Lock function

## Description

Locks the shared memory associated with a Shell change notification event.

## Parameters

### `hChange` [in]

Type: **HANDLE**

A handle to a window received as a *wParam* in the specified Shell change notification message.

### `dwProcId`

Type: **DWORD**

The process ID (*lParam* in the message callback).

### `pppidl` [out, optional]

Type: **PIDLIST_ABSOLUTE****

The address of a pointer to a PIDLIST_ABSOLUTE that, when this function returns successfully, receives the list of affected PIDLs.

### `plEvent` [out, optional]

Type: **LONG***

A pointer to a LONG value that, when this function returns successfully, receives the Shell change notification ID of the event that took place.

## Return value

Type: **HANDLE**

Returns a handle (HLOCK) to the locked memory. Pass this value to [SHChangeNotification_Unlock](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shchangenotification_unlock) when finished.