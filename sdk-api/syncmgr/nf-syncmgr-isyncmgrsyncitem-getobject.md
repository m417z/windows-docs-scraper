# ISyncMgrSyncItem::GetObject

## Description

Creates a specific type of object related to the item.

## Parameters

### `rguidObjectID` [in]

Type: **REFGUID**

A GUID identifying the type of object to create. One of the following values as defined in shlguid.h.

#### SYNCMGR_OBJECTID_BrowseContent

An object implementing the [ISyncMgrUIOperation](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgruioperation) interface that shows UI that allows the user to browse the contents of the item.

Sync Center only requests this object if the [SYNCMGR_ICM_CAN_BROWSE_CONTENT](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_item_capabilities) capability flag is set in the mask retrieved by [GetCapabilities](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrsyncitem-getcapabilities).

#### SYNCMGR_OBJECTID_ConflictStore

An object implementing the [ISyncMgrConflictStore](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrconflictstore) interface that allows an item to provide conflicts. These conflicts are shown in the Sync Center Conflicts folder. The conflict store should include conflicts only for the item. To include conflicts for all of a handler's items, Sync Center calls [GetObject](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-getobject).

Sync Center only requests this object if the [SYNCMGR_ICM_CONFLICT_STORE](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_item_capabilities) capability flag is set in the mask retrieved by [GetCapabilities](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrsyncitem-getcapabilities).

#### SYNCMGR_OBJECTID_EventStore

An object implementing the [ISyncMgrEventStore](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgreventstore) interface that allows an item to provide its own source of events. These events are shown in the Sync Results folder. The event store should include only events for the item. To include events for all of a handler's items, Sync Center calls [GetObject](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-getobject).

Sync Center only requests this object if the [SYNCMGR_ICM_EVENT_STORE](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_item_capabilities) capability flag is set in the mask retrieved by [GetCapabilities](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrsyncitem-getcapabilities).

An item is not required to provide an event store. The default event store provided by Sync Center can be used if it meets the item's requirements.

#### SYNCMGR_OBJECTID_Icon

An icon extraction object that implements the [IExtractIcon](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iextracticona) interface used to display an icon for the item. This object should only be provided if the item obtains its icon dynamically at run time. The preferred mechanism for providing the icon is to register the icon as the DefaultIcon in the registry.

Sync Center only requests this object if the [SYNCMGR_ICM_PROVIDES_ICON](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_item_capabilities) capability flag is set in the mask retrieved by [GetCapabilities](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrsyncitem-getcapabilities).

#### SYNCMGR_OBJECTID_QueryBeforeDelete

An object implementing the [ISyncMgrUIOperation](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgruioperation) interface that displays UI when the user selects the item in the handler's folder then selects the **Delete** task. Before requesting this object, Sync Center creates both a separate thread for this operation and a new instance of the item.

Sync Center only requests this object if the [SYNCMGR_ICM_CAN_DELETE](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_item_capabilities) and [SYNCMGR_ICM_QUERY_BEFORE_DELETE](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_item_capabilities) capability flags are set in the mask retrieved by [GetCapabilities](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrsyncitem-getcapabilities).

#### SYNCMGR_OBJECTID_QueryBeforeEnable

An object implementing the [ISyncMgrUIOperation](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgruioperation) interface that displays UI when the user selects the item in the Sync Center folder then selects the **Enable** task. Before requesting this object, Sync Center creates both a separate thread for this operation and a new instance of the item.

Sync Center only requests this object if the [SYNCMGR_ICM_QUERY_BEFORE_ENABLE](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_item_capabilities) capability flag is set and the [SYNCMGR_IPM_PREVENT_ENABLE](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_item_policies) policy flag is not.

#### SYNCMGR_OBJECTID_QueryBeforeDisable

An object implementing the [ISyncMgrUIOperation](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgruioperation) interface that displays UI when the user selects the item in the handler's folder then selects the **Disable** task. Before requesting this object, Sync Center creates both a separate thread for this operation and a new instance of the item.

Sync Center only requests this object if the [SYNCMGR_ICM_QUERY_BEFORE_DELETE](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_item_capabilities) capability flag is set and the [SYNCMGR_IPM_PREVENT_DISABLE](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_item_policies) policy flag is not.

### `riid` [in]

Type: **REFIID**

The IID of the requested interface. This is dependent on the object type named in *rguidObjectID*.

### `ppv` [out]

Type: **void****

When this method returns, contains the address of a pointer to the requested interface.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise. Returns E_INVALIDARG if the item does not support the requested type of object.

## Remarks

The item can implement the requested interface on its handler or it can implement it on a different object.

#### Examples

The following example shows an implementation of this method.

```cpp
STDMETHODIMP CMyDeviceSyncItem::GetObject(__in REFGUID   rguidObjectID,
                                          __in REFIID    riid,
                                          __out void   **ppv)
{
    HRESULT hr = E_INVALIDARG;
    *ppv = NULL;

    if (rguidObjectID == SYNCMGR_OBJECTID_QueryBeforeDelete)
    {
        hr = _CreateQueryBeforeDeleteObject(riid, ppv);
    }
    else if (rguidObjectID == SYNCMGR_OBJECTID_EventStore)
    {
        hr = _CreateEventStore(_pszItemID, riid, ppv);
    }

    return hr;
}

```