# ISyncMgrResolutionHandler::KeepOther

## Description

Replaces the versions in conflict with a different Shell item that is usually a merged version of the originals.

## Parameters

### `psiOther` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

A pointer to the substitute [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem).

### `pFeedback` [out]

Type: **[SYNCMGR_RESOLUTION_FEEDBACK](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_resolution_feedback)***

When this method returns, contains a [SYNCMGR_RESOLUTION_FEEDBACK](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_resolution_feedback) value.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The specified Shell item that replaces the Shell item(s) in conflict may not have been one of those originally in conflict. It may be a merged copy, or a replacement copy.

The [SYNCMGR_RESOLUTION_FEEDBACK](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_resolution_feedback) value returned in *pFeedback* determines how the next conflict is resolved. If this method fails, an error message is displayed and the user is asked how to proceed.