# ISyncMgrResolutionHandler::KeepItems

## Description

Keeps the Shell items that are passed in.

## Parameters

### `pArray` [in]

Type: **[ISyncMgrConflictResolutionItems](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrconflictresolutionitems)***

A pointer to an array of[ISyncMgrConflictResolutionItems](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrconflictresolutionitems). The array will contain more than one item if method [ISyncMgrResolutionHandler::QueryAbilities](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrresolutionhandler-queryabilities) returned SYNCMGR_RA_KEEP_MULTIPLE in parameter *pdwAbilities*.

### `pFeedback` [out]

Type: **[SYNCMGR_RESOLUTION_FEEDBACK](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_resolution_feedback)***

When this method returns, contains a [SYNCMGR_RESOLUTION_FEEDBACK](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_resolution_feedback) value.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The [SYNCMGR_RESOLUTION_FEEDBACK](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_resolution_feedback) value returned in *pFeedback* determines how the next conflict is resolved. If this method fails, an error message is displayed and the user is asked how to proceed.