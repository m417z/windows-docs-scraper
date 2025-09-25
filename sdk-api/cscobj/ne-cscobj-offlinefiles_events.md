# OFFLINEFILES_EVENTS enumeration

## Description

Event identifier codes describing events to be received or excluded by an event sink. Used with the [IOfflineFilesEventsFilter::GetIncludedEvents](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefileseventsfilter-getincludedevents) and [IOfflineFilesEventsFilter::GetExcludedEvents](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefileseventsfilter-getexcludedevents) methods.

## Constants

### `OFFLINEFILES_EVENT_CACHEMOVED:0`

This value is reserved for future use.

### `OFFLINEFILES_EVENT_CACHEISFULL`

This value is reserved for future use.

### `OFFLINEFILES_EVENT_CACHEISCORRUPTED`

This value is reserved for future use.

### `OFFLINEFILES_EVENT_ENABLED`

This value is reserved for future use.

### `OFFLINEFILES_EVENT_ENCRYPTIONCHANGED`

This value is reserved for future use.

### `OFFLINEFILES_EVENT_SYNCBEGIN`

Represents the [IOfflineFilesEvents::SyncBegin](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesevents-syncbegin) event method.

### `OFFLINEFILES_EVENT_SYNCFILERESULT`

Represents the [IOfflineFilesEvents::SyncFileResult](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesevents-syncfileresult) event method.

### `OFFLINEFILES_EVENT_SYNCCONFLICTRECADDED`

Represents the [IOfflineFilesEvents::SyncConflictRecAdded](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesevents-syncconflictrecadded) event method.

### `OFFLINEFILES_EVENT_SYNCCONFLICTRECUPDATED`

Represents the [IOfflineFilesEvents::SyncConflictRecUpdated](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesevents-syncconflictrecupdated) event method.

### `OFFLINEFILES_EVENT_SYNCCONFLICTRECREMOVED`

Represents the [IOfflineFilesEvents::SyncConflictRecRemoved](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesevents-syncconflictrecremoved) event method.

### `OFFLINEFILES_EVENT_SYNCEND`

Represents the [IOfflineFilesEvents::SyncEnd](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesevents-syncend) event method.

### `OFFLINEFILES_EVENT_BACKGROUNDSYNCBEGIN`

Represents the [IOfflineFilesEvents2::BackgroundSyncBegin](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesevents2-backgroundsyncbegin) event method.

### `OFFLINEFILES_EVENT_BACKGROUNDSYNCEND`

Represents the [IOfflineFilesEvents2::BackgroundSyncEnd](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesevents2-backgroundsyncend) event method.

### `OFFLINEFILES_EVENT_NETTRANSPORTARRIVED`

Represents the [IOfflineFilesEvents::NetTransportArrived](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesevents-nettransportarrived) event method.

### `OFFLINEFILES_EVENT_NONETTRANSPORTS`

Represents the [IOfflineFilesEvents::NoNetTransports](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesevents-nonettransports) event method.

### `OFFLINEFILES_EVENT_ITEMDISCONNECTED`

Represents the [IOfflineFilesEvents::ItemDisconnected](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesevents-itemdisconnected) event method.

### `OFFLINEFILES_EVENT_ITEMRECONNECTED`

Represents the [IOfflineFilesEvents::ItemReconnected](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesevents-itemreconnected) event method.

### `OFFLINEFILES_EVENT_ITEMAVAILABLEOFFLINE`

Represents the [IOfflineFilesEvents::ItemAvailableOffline](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesevents-itemavailableoffline) event method.

### `OFFLINEFILES_EVENT_ITEMNOTAVAILABLEOFFLINE`

Represents the [IOfflineFilesEvents::ItemNotAvailableOffline](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesevents-itemnotavailableoffline) event method.

### `OFFLINEFILES_EVENT_ITEMPINNED`

Represents the [IOfflineFilesEvents::ItemPinned](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesevents-itempinned) event method.

### `OFFLINEFILES_EVENT_ITEMNOTPINNED`

Represents the [IOfflineFilesEvents::ItemNotPinned](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesevents-itemnotpinned) event method.

### `OFFLINEFILES_EVENT_ITEMMODIFIED`

Represents the [IOfflineFilesEvents::ItemModified](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesevents-itemmodified) event method.

### `OFFLINEFILES_EVENT_ITEMADDEDTOCACHE`

Represents the [IOfflineFilesEvents::ItemAddedToCache](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesevents-itemaddedtocache) event method.

### `OFFLINEFILES_EVENT_ITEMDELETEDFROMCACHE`

Represents the [IOfflineFilesEvents::ItemDeletedFromCache](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesevents-itemdeletedfromcache) event method.

### `OFFLINEFILES_EVENT_ITEMRENAMED`

Represents the [IOfflineFilesEvents::ItemRenamed](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesevents-itemrenamed) event method.

### `OFFLINEFILES_EVENT_DATALOST`

Represents the [IOfflineFilesEvents::DataLost](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesevents-datalost) event method.

### `OFFLINEFILES_EVENT_PING`

Represents the [IOfflineFilesEvents::Ping](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesevents-ping) event method.

### `OFFLINEFILES_EVENT_ITEMRECONNECTBEGIN`

Represents the [IOfflineFilesEvents2::ItemReconnectBegin](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesevents2-itemreconnectbegin) event method.

### `OFFLINEFILES_EVENT_ITEMRECONNECTEND`

Represents the [IOfflineFilesEvents2::ItemReconnectEnd](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesevents2-itemreconnectend) event method.

### `OFFLINEFILES_EVENT_CACHEEVICTBEGIN`

This value is reserved for future use.

### `OFFLINEFILES_EVENT_CACHEEVICTEND`

This value is reserved for future use.

### `OFFLINEFILES_EVENT_POLICYCHANGEDETECTED`

Represents the [IOfflineFilesEvents2::PolicyChangeDetected](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesevents2-policychangedetected) event method.

### `OFFLINEFILES_EVENT_PREFERENCECHANGEDETECTED`

Represents the [IOfflineFilesEvents2::PreferenceChangeDetected](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesevents2-preferencechangedetected) event method.

### `OFFLINEFILES_EVENT_SETTINGSCHANGESAPPLIED`

Represents the [IOfflineFilesEvents2::SettingsChangesApplied](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesevents2-settingschangesapplied) event method.

### `OFFLINEFILES_EVENT_TRANSPARENTCACHEITEMNOTIFY`

Represents the [IOfflineFilesEvents3::TransparentCacheItemNotify](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesevents3-transparentcacheitemnotify) event method.

**Windows Server 2008 and Windows Vista:** This value is not supported before Windows Server 2008 R2 and Windows 7.

### `OFFLINEFILES_EVENT_PREFETCHFILEBEGIN`

Represents the [IOfflineFilesEvents3::PrefetchFileBegin](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesevents3-prefetchfilebegin) event method.

**Windows Server 2008 and Windows Vista:** This value is not supported before Windows Server 2008 R2 and Windows 7.

### `OFFLINEFILES_EVENT_PREFETCHFILEEND`

Represents the [IOfflineFilesEvents3::PrefetchFileEnd](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefilesevents3-prefetchfileend) event method.

**Windows Server 2008 and Windows Vista:** This value is not supported before Windows Server 2008 R2 and Windows 7.

### `OFFLINEFILES_EVENT_PREFETCHCLOSEHANDLEBEGIN`

### `OFFLINEFILES_EVENT_PREFETCHCLOSEHANDLEEND`

### `OFFLINEFILES_NUM_EVENTS`

## See also

[IOfflineFilesEventsFilter::GetExcludedEvents](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefileseventsfilter-getexcludedevents)

[IOfflineFilesEventsFilter::GetIncludedEvents](https://learn.microsoft.com/previous-versions/windows/desktop/api/cscobj/nf-cscobj-iofflinefileseventsfilter-getincludedevents)