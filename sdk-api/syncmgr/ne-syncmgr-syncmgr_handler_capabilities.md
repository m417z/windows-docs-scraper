# SYNCMGR_HANDLER_CAPABILITIES enumeration

## Description

Specifies the capabilities of a handler regarding the actions that can be performed against it.

## Constants

### `SYNCMGR_HCM_NONE:0`

No capability flags are set.

### `SYNCMGR_HCM_PROVIDES_ICON:0x1`

The handler returns a valid object from [ISyncMgrHandler::GetObject](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-getobject) when that method is called with the SYNCMGR_OBJECTID_Icon flag. The object returned from **ISyncMgrHandler::GetObject** must implement [IExtractIcon](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iextracticona). Generally, this value should not be returned if possible.

### `SYNCMGR_HCM_EVENT_STORE:0x2`

The handler returns a valid object from [ISyncMgrHandler::GetObject](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-getobject) when that method is called with the SYNCMGR_OBJECTID_EventStore flag. The object returned from **ISyncMgrHandler::GetObject** must implement [ISyncMgrEventStore](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgreventstore).

### `SYNCMGR_HCM_CONFLICT_STORE:0x4`

The handler returns a valid object from [ISyncMgrHandler::GetObject](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-getobject) when that method is called with the SYNCMGR_OBJECTID_ConflictStore flag. The object returned from **ISyncMgrHandler::GetObject** must implement [ISyncMgrConflictStore](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrconflictstore).

### `SYNCMGR_HCM_SUPPORTS_CONCURRENT_SESSIONS:0x10`

If a handler sets this flag in the mask returned from the handler's [ISyncMgrHandler::GetCapabilities](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-getcapabilities) method, it indicates that the handler plans to create multiple simultaneous synchronization sessions using [ISyncMgrSessionCreator::CreateSession](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrsessioncreator-createsession). This is useful for handlers that implement a background synchronization architecture in which the handler simply signals another process to perform the synchronization rather than performing the synchronization in its [ISyncMgrHandler::Synchronize](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-synchronize) method directly. This allows synchronization engines to report progress, conflicts, and events (through [ISyncMgrSyncCallback](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrsynccallback)) when synchronization requests come from sources other than Sync Center. For example, this could be the result of a data change notification or through application-specific UI. If more than one session is synchronizing the same item, then the progress for that item will be reported as indeterminate.

### `SYNCMGR_HCM_CAN_BROWSE_CONTENT:0x10000`

The handler returns a valid object from [ISyncMgrHandler::GetObject](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-getobject) when that method is called with the SYNCMGR_OBJECTID_BrowseContent flag. If this value is set, the **Browse Content** task is added to the handler's shortcut menu. The object returned from **ISyncMgrHandler::GetObject** must implement [ISyncMgrUIOperation](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgruioperation).

### `SYNCMGR_HCM_CAN_SHOW_SCHEDULE:0x20000`

The handler returns a valid object from [ISyncMgrHandler::GetObject](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-getobject) when that method is called with the SYNCMGR_OBJECTID_ShowSchedule flag. If this value is set, the **Show Schedule** task is added to the handler's shortcut menu. The object returned from **ISyncMgrHandler::GetObject** must implement [ISyncMgrUIOperation](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgruioperation). This value is used by [ISyncMgrScheduleWizardUIOperation](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrschedulewizarduioperation).

### `SYNCMGR_HCM_QUERY_BEFORE_ACTIVATE:0x100000`

The handler returns a valid object from [ISyncMgrHandler::GetObject](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-getobject) when that method is called with the SYNCMGR_OBJECTID_QueryBeforeActivate flag. The object returned from **ISyncMgrHandler::GetObject** must implement [ISyncMgrUIOperation](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgruioperation).

### `SYNCMGR_HCM_QUERY_BEFORE_DEACTIVATE:0x200000`

The handler returns a valid object from [ISyncMgrHandler::GetObject](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-getobject) when that method is called with the SYNCMGR_OBJECTID_QueryBeforeDeactivate flag. The object returned from **ISyncMgrHandler::GetObject** must implement [ISyncMgrUIOperation](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgruioperation).

### `SYNCMGR_HCM_QUERY_BEFORE_ENABLE:0x400000`

The handler returns a valid object from [ISyncMgrHandler::GetObject](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-getobject) when that method is called with the SYNCMGR_OBJECTID_QueryBeforeEnable flag. The object returned from **ISyncMgrHandler::GetObject** must implement [ISyncMgrUIOperation](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgruioperation).

### `SYNCMGR_HCM_QUERY_BEFORE_DISABLE:0x800000`

The handler returns a valid object from [ISyncMgrHandler::GetObject](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-getobject) when that method is called with the SYNCMGR_OBJECTID_QueryBeforeDisable flag. The object returned from **ISyncMgrHandler::GetObject** must implement [ISyncMgrUIOperation](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgruioperation).

### `SYNCMGR_HCM_VALID_MASK:0xf30017`

A mask used to determine valid [SYNCMGR_HANDLER_CAPABILITIES](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_handler_capabilities) flags. Compare against the value retrieved by [ISyncMgrHandler::GetCapabilities](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-getcapabilities) to verify valid results.

## Remarks

Sync Center queries the handler for its capabilities through [ISyncMgrHandler::GetCapabilities](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-getcapabilities) whenever the [ISyncMgrControl::UpdateHandler](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrcontrol-updatehandler) or [ISyncMgrControl::UpdateHandlerCollection](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrcontrol-updatehandlercollection) method is called.