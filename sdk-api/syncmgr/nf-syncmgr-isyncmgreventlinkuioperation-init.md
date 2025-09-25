# ISyncMgrEventLinkUIOperation::Init

## Description

Enables Sync Center to provide the event to link to so [ISyncMgrUIOperation::Run](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgruioperation-run) knows which event to operate upon.

## Parameters

### `rguidEventID` [in]

Type: **REFGUID**

A reference to the event ID that is being stored. This parameter is the same as what is returned from the [GetEventID](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrevent-geteventid) method of the *pEvent* parameter.

### `pEvent` [in]

Type: **[ISyncMgrEvent](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrevent)***

A pointer to the [ISyncMgrEvent](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrevent) object for [Run](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgruioperation-run) to use. This is the event object that owns the link.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The event ID is the ID that the handler is given when [ReportEvent](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrsynccallback-reportevent) is called, or is the ID provided by the handler when the event is obtained from the custom event store.

If you call [ReportEvent](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrsynccallback-reportevent), your events will be stored only until the user logs off or until the handler is synchronized again.

The interface that is used to implement custom event stores is [ISyncMgrEventStore](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgreventstore).

The [ISyncMgrEvent](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrevent) provided in the *pEvent* parameter is not the same object that came from a custom event store.