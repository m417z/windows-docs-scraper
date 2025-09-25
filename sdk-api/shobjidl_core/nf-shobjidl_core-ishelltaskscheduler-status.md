# IShellTaskScheduler::Status

## Description

Sets the release status and background thread timeout for the current task.

## Parameters

### `dwReleaseStatus` [in]

Type: **DWORD**

The following flag or 0.

#### ITSSFLAG_KILL_ON_DESTROY

Immediately cease execution of the current task when the [IShellTaskScheduler](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelltaskscheduler) instance is released.

### `dwThreadTimeout` [in]

Type: **DWORD**

Not used.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.