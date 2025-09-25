# IOfflineFilesCache::Pin

## Description

Pins files, directories, and network shared folders. Pinning is called "Always Available Offline" in the Windows user interface.

When a file is pinned, it is cached in the local Offline Files store. Unlike files that are automatically cached, pinned files are protected from automatic eviction when additional cache space is needed.

## Parameters

### `hwndParent` [in]

Identifies the parent window for any user interface elements displayed. This parameter is ignored if the **OFFLINEFILES_PIN_CONTROL_FLAG_INTERACTIVE** flag is not set in the *dwPinControlFlags* parameter.

### `rgpszPaths` [in]

Array of pointers, each to a fully qualified UNC path of a file or directory to be pinned.

### `cPaths` [in]

Number of paths in *rgpszPaths*.

### `bDeep` [in]

If one or more of the paths provided refers to a directory or shared folder, this argument indicates whether all children (files and subdirectories) are to be pinned as well. If this parameter is **TRUE**, all children are pinned recursively. If this parameter is **FALSE**, only the directory itself is pinned, not its children. When the next synchronization operation occurs, all children are pinned recursively.

### `bAsync` [in]

Indicates if the operation is to be performed asynchronously. If this parameter is **TRUE**, the operation is scheduled for asynchronous operation and the function returns immediately. If this parameter is **FALSE**, the function returns when the operation is complete.

### `dwPinControlFlags` [in]

Controls behavior of the pin operation. May be one or more of the following flags.

#### OFFLINEFILES_PIN_CONTROL_FLAG_FILL (0x00000001)

Fills the item in addition to pinning it. This results in the item being fully cached as part of the pin operation. If this flag is not set, the item is only pinned and must wait to be filled by some other means of synchronization. Note that the Offline Files service periodically fills files in the background. If immediate offline availability is not necessary, it may be better (performance-wise) to not set this flag and let the service fill the file in the background.

#### OFFLINEFILES_PIN_CONTROL_PINLINKTARGETS (0x00000010)

Normally, when a shell link (type LNK) is pinned, its target is not automatically pinned. When this flag is set, pinning a LNK file automatically pins its target if the target is a file. If the target is a directory, the target is never pinned automatically.

#### OFFLINEFILES_PIN_CONTROL_FLAG_FORUSER (0x00000020)

Pins the items for the calling user. This is the flag typically set for a caller of this function. It is important to note that Offline Files does not support a true per-user notion of pinning. When an item is pinned for a user, it is pinned for all users of that machine. An item that is pinned with this flag can be unpinned by any user who has access to that file. The ability to access that pinned file depends on the user's access rights to that file computed while online.

#### OFFLINEFILES_PIN_CONTROL_FLAG_FORUSER_POLICY (0x00000040)

Pins the items for per-user policy. This differs from the "FORUSER" flag in that this flag cannot be modified by the user through the Offline Files user interface. Internally, Offline Files sets this flag when items are pinned by its Group Policy extension.

#### OFFLINEFILES_PIN_CONTROL_FLAG_FORALL (0x00000080)

Pins the items for all users of the local machine. While the pinned state applies to all users, the ability to access a pinned file depends on the user's access rights to that file computed while online.

#### OFFLINEFILES_PIN_CONTROL_FLAG_FORREDIR (0x00000100)

Pins the items for purposes of folder redirection for the calling user. Windows Folder Redirection sets this flag when pinning redirected folders.

#### OFFLINEFILES_PIN_CONTROL_FLAG_LOWPRIORITY (0x00000200)

Reserved for future use.

#### OFFLINEFILES_PIN_CONTROL_FLAG_ASYNCPROGRESS (0x00000400)

Progress is reported to the progress interface asynchronously with respect to the actual operations. See the section Asynchronous Progress Notifications for details on behavior. If this flag is not set, progress is reported synchronously with each operation.

#### OFFLINEFILES_PIN_CONTROL_FLAG_INTERACTIVE (0x00000800)

Set this flag if the operation is allowed to display user interface elements as necessary. An example is the system's credential-request dialog. If this flag is set, the value in hwndParent is used as the parent for any user interface elements displayed.

#### OFFLINEFILES_PIN_CONTROL_FLAG_CONSOLE (0x00001000)

This flag is ignored if the "interactive" flag is not set. If the "interactive" flag is set, this flag indicates that any UI produced should be directed to the console window associated with the process invoking the operation.

#### OFFLINEFILES_PIN_CONTROL_FLAG_BACKGROUND (0x00010000)

Set this flag if you want the pin operation to avoid sharing violations in the event that an application wishes to open a file that is currently open for the pin operation. When that scenario occurs and this flag is set, the pin operation will "back off" and not finish for that particular file at that time. This flag is primarily used by the Offline Files service for internal operations.

### `pIProgress` [in]

Interface to an event sink that will receive progress events during the operation. If events are not desired, this parameter may be **NULL**.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

Returns `HRESULT_FROM_WIN32(ERROR_CANCELLED)` if the operation is canceled.

## Remarks

If a pin operation involving multiple files is canceled while in progress, changes to files processed to that point are not rolled back.

If only one path is provided in the *rgpszPaths* parameter and that path is to a single file, the return value indicates the result of that single pin operation. Otherwise, the caller must implement the progress callback methods in the following list and monitor the [IOfflineFilesSyncProgress::SyncItemResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilessyncprogress-syncitemresult) method to obtain the result for each processed file and directory.

| Progress Events Interface | Method | Description |
| --- | --- | --- |
| [IOfflineFilesProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesprogress) | [Begin](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesprogress-begin) | Called at the start of the operation. |
| [IOfflineFilesSyncProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilessyncprogress) | [SyncItemBegin](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilessyncprogress-syncitembegin) | Called at the start of processing for each file. |
| [IOfflineFilesSyncProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilessyncprogress) | [SyncItemResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilessyncprogress-syncitemresult) | Called after each file is pinned. |
| [IOfflineFilesProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesprogress) | [QueryAbort](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesprogress-queryabort) | Called periodically during the sync operation to detect a request for cancellation. |
| [IOfflineFilesProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesprogress) | [End](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesprogress-end) | Called at the end of the operation. |

## See also

[IOfflineFilesCache](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilescache)