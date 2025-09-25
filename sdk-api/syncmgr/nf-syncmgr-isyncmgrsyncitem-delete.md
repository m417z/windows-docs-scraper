# ISyncMgrSyncItem::Delete

## Description

Deletes a sync item.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Sync Center calls this method when the user selects the item in the handler's folder and launches its **Delete** task, but only if the item has set the [SYNCMGR_ICM_CAN_DELETE](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_handler_policies) flag. If the handler supports the [SYNCMGR_OBJECTID_QueryBeforeDeactivate](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrsyncitem-getobject) object, this method is only called if the UI operation was successful.

If the handler does not need to perform any actions when it is activated, it can return either S_OK or E_NOTIMPL.