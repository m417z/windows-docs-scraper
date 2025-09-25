# SHChangeNotification_Unlock function

## Description

Unlocks shared memory for a change notification.

## Parameters

### `hLock` [in]

Type: **HANDLE**

A handle to the memory lock. This is the handle returned by [SHChangeNotification_Lock](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shchangenotification_lock) when it locked the memory.

## Return value

Type: **BOOL**

Returns **TRUE** on success; otherwise, **FALSE**.