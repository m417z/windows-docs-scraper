# OFFLINEFILES_OP_RESPONSE enumeration

## Description

Specifies whether to continue, retry, or stop processing items.

## Constants

### `OFFLINEFILES_OP_CONTINUE:0`

Continue processing items.

### `OFFLINEFILES_OP_RETRY`

Repeat processing of this item.

### `OFFLINEFILES_OP_ABORT`

Stop processing now.

## See also

[IOfflineFilesSimpleProgress::ItemBegin](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilessimpleprogress-itembegin)

[IOfflineFilesSimpleProgress::ItemResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilessimpleprogress-itemresult)

[IOfflineFilesSyncProgress::SyncItemBegin](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilessyncprogress-syncitembegin)

[IOfflineFilesSyncProgress::SyncItemResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilessyncprogress-syncitemresult)