# SYNCMGRLOGERRORINFO structure

## Description

Provides error information for use in the [ISyncMgrSynchronizeCallback::LogError](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronizecallback-logerror) method.

## Members

### `cbSize`

Type: **DWORD**

The size of the structure.

### `mask`

Type: **DWORD**

The mask value. The synchronization manager handler implemented by your application can set any combination of the following bits to indicate which fields of **SYNCMGRLOGERRORINFO** it has filled in when calling [ISyncMgrSynchronizeCallback::LogError](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronizecallback-logerror).

#### SYNCMGRLOGERROR_ERRORFLAGS

The **dwSyncMgrErrorFlags** field is valid.

#### SYNCMGRLOGERROR_ERRORID

The **ErrorID** field is valid.

#### SYNCMGRLOGERROR_ITEMID

The **ItemID** field is valid.

### `dwSyncMgrErrorFlags`

Type: **DWORD**

Error flags. At this time only the following value is recognized.

#### SYNCMGRERRORFLAG_ENABLEJUMPTEXT

The [ISyncMgrSynchronize::ShowError](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronize-showerror) method should be called on this item.

### `ErrorID`

Type: **GUID**

An error identifier.

### `ItemID`

Type: **GUID**

The item where the error occurred.

## See also

[ISyncMgrSynchronizeCallback::LogError](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronizecallback-logerror)