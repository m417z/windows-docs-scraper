# IOfflineFilesCache::Synchronize

## Description

Synchronizes files and directories in the Offline Files cache with their corresponding copies in the
applicable network shared folders.

## Parameters

### `hwndParent` [in]

Identifies the parent window for any user interface elements displayed. This parameter is ignored if the
**OFFLINEFILES_SYNC_CONTROL_FLAG_INTERACTIVE** flag is not set in the *dwSyncControl*
parameter.

### `rgpszPaths` [in]

Array of pointers, each to a fully qualified UNC path of a file or directory to be synchronized.

### `cPaths` [in]

Number of paths in the *rgpszPaths* array.

### `bAsync` [in]

Indicates if the operation is to be performed asynchronously. If this parameter is
**TRUE**, the operation is placed on a separate thread in the system thread pool and the
function returns immediately. If this parameter is **FALSE**, the function returns when
the operation is complete.

### `dwSyncControl` [in]

Flags to control the behavior of the entire sync operation. Behaviors such as sync direction (in, out), the
pinning of LNK targets, as well as the pinning of new files are controlled through these flags. The following
list describes the meaning of each flag.

#### OFFLINEFILES_SYNC_CONTROL_FLAG_FILLSPARSE (0x00000001)

Fill sparse files in the cache. Setting this flag results in an enumeration of the local copies in the
cache. Any sparsely cached files that are found are filled so that they are no longer sparse. Sparsely cached
files are not available for offline use. For more information, see the
[IOfflineFilesFileItem::IsSparse](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesfileitem-issparse)
method.

#### OFFLINEFILES_SYNC_CONTROL_FLAG_SYNCIN (0x00000002)

Sync remote changes from the server to the local cache. Setting this flag automatically sets the
**OFFLINEFILES_SYNC_CONTROL_FLAG_FILLSPARSE** flag as well.

#### OFFLINEFILES_SYNC_CONTROL_FLAG_SYNCOUT (0x00000004)

Sync local changes from the local cache to the server.

#### OFFLINEFILES_SYNC_CONTROL_FLAG_PINNEWFILES (0x00000008)

Pin new files found on the server inside pinned directories. This flag is ignored if the
**OFFLINEFILES_SYNC_CONTROL_FLAG_SYNCIN** flag is not set.

#### OFFLINEFILES_SYNC_CONTROL_PINLINKTARGETS (0x00000010)

Applicable only if the **OFFLINEFILES_SYNC_CONTROL_FLAG_PINNEWFILES** flag is set. Normally, when a shell
link (type LNK) is pinned, its target is not automatically pinned. When this flag is set, pinning a LNK
file automatically pins its target if the target is a file. If the target is a directory, the target is
never pinned automatically.

#### OFFLINEFILES_SYNC_CONTROL_FLAG_PINFORUSER (0x00000020)

Applicable only if the **OFFLINEFILES_SYNC_CONTROL_FLAG_PINNEWFILES** flag is set. Pins the items for the
calling user. This is the flag typically set for a caller of this function. It is important to note that
Offline Files does not support a true per-user notion of pinning. When an item is pinned for a user, it is
pinned for all users of that machine. However, the ability to access that pinned file depends on the user's
access rights to that file computed while online.

#### OFFLINEFILES_SYNC_CONTROL_FLAG_PINFORUSER_POLICY (0x00000040)

Applicable only if the **OFFLINEFILES_SYNC_CONTROL_FLAG_PINNEWFILES** flag is set. Pins the items for
per-user policy. This differs from the **OFFLINEFILES_SYNC_CONTROL_FLAG_PINFORUSER** flag in that this flag
cannot be modified by the user through the Offline Files user interface. Internally, Offline Files sets this
flag when items are pinned by its Group Policy extension.

#### OFFLINEFILES_SYNC_CONTROL_FLAG_PINFORALL (0x00000080)

Applicable only if the **OFFLINEFILES_SYNC_CONTROL_FLAG_PINNEWFILES** flag is set. Pins the items for all
users of the local machine. While the pinned state applies to all users, the ability to access a pinned file
depends on the user's access rights to that file computed while online.

#### OFFLINEFILES_SYNC_CONTROL_FLAG_PINFORREDIR (0x00000100)

Applicable only if the **OFFLINEFILES_SYNC_CONTROL_FLAG_PINNEWFILES** flag is set. Pins the items for
purposes of folder redirection for the calling user. Windows Folder Redirection sets this flag when
pinning redirected folders.

#### OFFLINEFILES_SYNC_CONTROL_FLAG_LOWPRIORITY (0x00000200)

This flag is reserved for future use.

#### OFFLINEFILES_SYNC_CONTROL_FLAG_ASYNCPROGRESS (0x00000400)

Progress is reported to the progress interface asynchronously with the actual operations. For more
information about behavior, see the "Asynchronous Progress Notifications" section. If this flag is not set,
progress is reported synchronously with each operation.

#### OFFLINEFILES_SYNC_CONTROL_FLAG_INTERACTIVE (0x00000800)

Set this flag if the operation is allowed to display user interface elements as necessary. An example is
the system's credential-request dialog. If this flag is set, the value in hwndParent is used as the parent
for any user interface elements displayed.

#### OFFLINEFILES_SYNC_CONTROL_FLAG_CONSOLE (0x00001000)

This flag is ignored if the **OFFLINEFILES_SYNC_CONTROL_FLAG_INTERACTIVE** flag is not set. If the
**OFFLINEFILES_SYNC_CONTROL_FLAG_INTERACTIVE** flag is set, this flag indicates that any UI produced should be
directed to the console window associated with the process invoking the operation.

#### OFFLINEFILES_SYNC_CONTROL_FLAG_SKIPSUSPENDEDDIRS (0x00002000)

Set this flag if you want the sync operation to not sync suspended directory trees. It is recommended
that this flag is set when the sync operation has not been invoked interactively and intentionally by a
user.

#### OFFLINEFILES_SYNC_CONTROL_FLAG_BACKGROUND (0x00010000)

Set this flag if you want the sync operation to avoid sharing violations in the event that an
application wishes to open a file that is currently open for the sync operation. When that scenario occurs
and this flag is set, the sync operation will "back off" and not finish for that particular
file at that time. This flag is primarily used by the Offline Files service for internal operations.

#### OFFLINEFILES_SYNC_CONTROL_FLAG_NONEWFILESOUT (0x00020000)

This flag is ignored if the **OFFLINEFILES_SYNC_CONTROL_FLAG_SYNCOUT** flag is not set. If the
**OFFLINEFILES_SYNC_CONTROL_FLAG_SYNCOUT** flag is set, this flag indicates that new files that exist only on the client will not be created on the server.

If, rather than providing an implementation of
[IOfflineFilesSyncConflictHandler](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilessyncconflicthandler), you
want all sync conflicts to be resolved in a "keep local", "keep remote" or
"keep latest" manner, set one (and only one) of the following flag values. Note that these
flag values are ignored if the *pISyncConflictHandler* parameter is not **NULL**.

#### OFFLINEFILES_SYNC_CONTROL_CR_KEEPLOCAL (0x10000000)

Synchronize the local copy to the server.

#### OFFLINEFILES_SYNC_CONTROL_CR_KEEPREMOTE (0x20000000)

Synchronize the remote copy to the local cache.

#### OFFLINEFILES_SYNC_CONTROL_CR_KEEPLATEST (0x30000000)

Keep the copy with the latest last-change time. This resolution is sometimes called "last writer wins."

### `pISyncConflictHandler` [in]

An [IOfflineFilesSyncConflictHandler](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilessyncconflicthandler)
interface pointer to a conflict handler implementation. If provided, the sync operation calls the conflict
handler to resolve sync conflicts as they are encountered during the operation. The handler receives a code
describing the type of conflict then returns a code indicating if the conflict has been resolved or some other
action to be taken by the sync operation. This parameter is optional and can be **NULL**. If this parameter is **NULL**,
the default action is taken in the Offline Files service. Normally this results in the conflict being recorded in
the user's sync conflict store for later presentation in Sync Center.

### `pIProgress` [in]

Interface to an event sink that will receive progress events during the operation. This parameter is optional and can be **NULL**.

### `pSyncId` [in]

A unique ID applied to this sync operation. This ID will be included with all published events
([IOfflineFilesEvents](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesevents)) related to this operation. This
parameter is optional and can be **NULL**.

## Return value

Returns **S_OK** if successful, or an error value otherwise.

Returns `HRESULT_FROM_WIN32(ERROR_CANCELLED)` if the operation is canceled.

Monitor [IOfflineFilesSyncProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilessyncprogress) events to
detect failures associated with individual files.

## Remarks

If the *bAsync* parameter is **TRUE**, the caller is required to provide an event interface through the *pIProgress* parameter. The **Synchronize** method will increment the reference count on the event interface at the start of the operation and decrement the reference count when the operation has completed. It is therefore recommended that the event sink implementation increment the reference count of its hosting module so that the module remains in memory throughout the operation.

If a sync operation is canceled while in progress, files that have been synchronized up to that point remain synchronized.

If only one path is provided in the *rgpszPaths* parameter and that path is to a single file, the return value indicates the result of that single synchronization operation. Otherwise, the caller must implement the progress callback methods in the following list and monitor the [IOfflineFilesSyncProgress::SyncItemResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilessyncprogress-syncitemresult) method to obtain the result for each processed file and directory.

| Progress Events Interface | Method | Description |
| --- | --- | --- |
| [IOfflineFilesProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesprogress) | [Begin](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesprogress-begin) | Called at the start of the operation. |
| [IOfflineFilesSyncProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilessyncprogress) | [SyncItemBegin](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilessyncprogress-syncitembegin) | Called at the start of processing for each file. |
| [IOfflineFilesSyncProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilessyncprogress) | [SyncItemResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilessyncprogress-syncitemresult) | Called after each file is synchronized. |
| [IOfflineFilesProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesprogress) | [QueryAbort](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesprogress-queryabort) | Called periodically during the sync operation to detect a request for cancellation. |
| [IOfflineFilesProgress](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesprogress) | [End](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesprogress-end) | Called at the end of the operation. |

If the calling code also listens for published sync events, the Sync ID may be specified through the
*pSyncId* parameter. The same ID value is transmitted through the [SyncBegin](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesevents-syncbegin),
[SyncFileResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesevents-syncfileresult), and [SyncEnd](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesevents-syncend) published events
([IOfflineFilesEvents](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilesevents)) generated from this operation.

## See also

[IOfflineFilesCache](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nn-cscobj-iofflinefilescache)

[IOfflineFilesEvents2::BackgroundSyncBegin](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesevents2-backgroundsyncbegin)

[IOfflineFilesEvents2::BackgroundSyncEnd](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesevents2-backgroundsyncend)

[IOfflineFilesFileItem::IsSparse](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesfileitem-issparse)