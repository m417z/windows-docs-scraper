# SYNCMGRPROGRESSITEM structure

## Description

Provides status information while a synchronization is in progress. This structure is used with the [ISyncMgrSynchronizeCallback::Progress](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronizecallback-progress) method and corresponds to a single synchronization item.

## Members

### `cbSize`

Type: **DWORD**

The size of the structure, in bytes.

### `mask`

Type: **UINT**

Flags from the [SYNCMGRSTATUS](https://learn.microsoft.com/windows/desktop/api/mobsync/ne-mobsync-syncmgrstatus) enumeration that specify which members of this structure are used.

### `lpcStatusText`

Type: **LPCWSTR**

Status text.

### `dwStatusType`

Type: **DWORD**

One of the values from the [SYNCMGRSTATUS](https://learn.microsoft.com/windows/desktop/api/mobsync/ne-mobsync-syncmgrstatus) enumeration.

### `iProgValue`

Type: **int**

An integer that indicates the progress value.

### `iMaxValue`

Type: **int**

An integer that indicates the maximum progress value.

## See also

[ISyncMgrSynchronizeCallback::Progress](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronizecallback-progress)