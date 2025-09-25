# ISyncMgrSyncCallback::ReportEvent

## Description

Provides an event to add to the Sync Results folder for an item being synchronized.

## Parameters

### `pszItemID` [in]

Type: **LPCWSTR**

A pointer to a buffer that contains the unique ID of the item currently being synchronized. This string is of maximum length MAX_SYNCMGR_ID including the terminating **null** character.

### `nLevel` [in]

Type: **[SYNCMGR_EVENT_LEVEL](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_event_level)**

A value from the [SYNCMGR_EVENT_LEVEL](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_event_level) enumeration declaring the type of event involved.

### `nFlags` [in]

Type: **[SYNCMGR_EVENT_FLAGS](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_event_flags)**

Not used.

### `pszName` [in]

Type: **LPCWSTR**

A pointer to a buffer that contains the name of the event.

### `pszDescription` [in]

Type: **LPCWSTR**

A pointer to a buffer that contains a description of the event.

### `pszLinkText` [in]

Type: **LPCWSTR**

A pointer to a buffer that contains the text to be used in a hyperlink to the item. This parameter can be **NULL**

### `pszLinkReference` [in]

Type: **LPCWSTR**

A pointer to a buffer that contains the URL of the item. This parameter can be **NULL**

### `pszContext` [in]

Type: **LPCWSTR**

Handler-specific data to associate with the event.

### `pguidEventID` [out]

Type: **GUID***

When this method returns, contains a pointer to a unique ID for the event.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For the handler to provide more details to the user about the sync result, the property sheet for individual sync results reported by the handler can be extended.

This method replaces [LogError](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrsynchronizecallback-logerror).

The event is stored only in memory, so all events are cleared when the user logs off or shuts down. This is one reason to implement a custom [ISyncMgrEventStore](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgreventstore), which can provide its events from anywhere, including a file, over the network, or the registry. The sync results folder, however, shows events provided both by the internal event store and by custom event stores provided by sync handlers.

#### Examples

The following example shows the usage of [ISyncMgrSyncCallback::ReportProgress](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrsynccallback-reportprogress) by the [Synchronize](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-synchronize) method.

```cpp
STDMETHODIMP CMyDeviceHandler::Synchronize(...)
{
    ...
    // Get the event receiver interface.
    ISyncMgrEventReceiver *pEventReceiver = NULL;
    hr = pCallback->QueryInterface(IID_ISyncMgrEventReceiver,
                                   (void **) &pEventReceiver);

    ...

    // Start synchronizing the sync item.

    ...

    // Generate a GUID for this item.
    // Construct a string to display in the Sync Results folder.
    // Store the information about this event so we can display more details.
    // Report the event to Sync Center.
    hr = pEventReceiver->ReportEvent(pszItemID,
                                     SYNCMGR_EL_INFORMATION,
                                     SYNCMGR_EF_NONE,
                                     pszEventName,
                                     pszEventDescription,
                                     NULL,
                                     NULL,
                                     NULL,
                                     &guidEventID);
    ...
}

```