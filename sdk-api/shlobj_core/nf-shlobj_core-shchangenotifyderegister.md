# SHChangeNotifyDeregister function

## Description

Unregisters the client's window process from receiving [SHChangeNotify](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shchangenotify) messages.

## Parameters

### `ulID`

Type: **ULONG**

A value of type **ULONG** that specifies the registration ID returned by [SHChangeNotifyRegister](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shchangenotifyregister).

## Return value

Type: **BOOL**

Returns **TRUE** if the specified client was found and removed; otherwise **FALSE**.

## Remarks

See the [Change Notify Watcher Sample](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd940348(v=vs.85)) in the Windows Software Development Kit (SDK) for a full example that demonstrates the use of this function.

The **NTSHChangeNotifyDeregister** function, which is no longer available for use as of Windows Vista, was equivalent to **SHChangeNotifyDeregister**.