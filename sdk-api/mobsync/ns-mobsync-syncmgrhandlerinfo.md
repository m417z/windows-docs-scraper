# SYNCMGRHANDLERINFO structure

## Description

Provides information about the handler for use in the [ISyncMgrSynchronize::GetHandlerInfo](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-gethandlerinfo) method.

## Members

### `cbSize`

Type: **DWORD**

The size of the structure in bytes.

### `hIcon`

Type: **HICON**

The icon for the handler.

### `SyncMgrHandlerFlags`

Type: **DWORD**

The value of the [SYNCMGRHANDLERFLAGS](https://learn.microsoft.com/windows/desktop/api/mobsync/ne-mobsync-syncmgrhandlerflags) enumeration.

### `wszHandlerName`

Type: **WCHAR[MAX_SYNCMGRHANDLERNAME]**

The name to use for the handler.

## See also

[ISyncMgrSynchronize::GetHandlerInfo](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-gethandlerinfo)

[SYNCMGRHANDLERFLAGS](https://learn.microsoft.com/windows/desktop/api/mobsync/ne-mobsync-syncmgrhandlerflags)