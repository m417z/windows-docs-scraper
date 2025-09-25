# ISyncMgrHandler::GetObject

## Description

Creates a specific type of object related to the handler.

## Parameters

### `rguidObjectID` [in]

Type: **REFGUID**

A GUID identifying the type of object to create. One of the following values as defined in shlguid.h.

#### SYNCMGR_OBJECTID_BrowseContent

An object implementing the [ISyncMgrUIOperation](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgruioperation) interface that shows the UI that enables the user to browse the contents of the item managed by the handler, such as a folder, device, computer on a network, or an application.

Sync Center only requests this object if the [SYNCMGR_HCM_CAN_BROWSE_CONTENT](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_handler_capabilities) capability flag is set in the mask retrieved by [GetCapabilities](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-getcapabilities).

#### SYNCMGR_OBJECTID_ConflictStore

An object implementing the [ISyncMgrConflictStore](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgrconflictstore) interface that enables a handler to provide conflicts. These conflicts are shown in the Sync Center Conflicts folder. The conflict store should include conflicts for the handler as well as conflicts for all of its items. To include conflicts for only a specific item, Sync Center calls [GetObject](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrsyncitem-getobject).

Sync Center only requests this object if the [SYNCMGR_HCM_CONFLICT_STORE](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_handler_capabilities) capability flag is set in the mask retrieved by [GetCapabilities](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-getcapabilities).

#### SYNCMGR_OBJECTID_EventLinkClick

An object implementing the [ISyncMgrEventLinkUIOperation](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgreventlinkuioperation) interface that implements the click action for a link provided on an event displayed in the Sync Results folder.

#### SYNCMGR_OBJECTID_EventStore

An object implementing the [ISyncMgrEventStore](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgreventstore) interface that allows a handler to provide its own source of events. These events are shown in the Sync Results folder. The event store should include events for the handler as well as for all of its items. To include only events for a specific item, Sync Center calls [GetObject](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrsyncitem-getobject). The event store is asked to delete the handler's events the next time the handler is synchronized. The default event store purges its events when the user logs off.

Sync Center only requests this object if the [SYNCMGR_HCM_EVENT_STORE](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_handler_capabilities) capability flag is set in the mask retrieved by [GetCapabilities](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-getcapabilities).

A handler is not required to provide an event store. The default event store provided by Sync Center can be used if it meets the handler's requirements.

#### SYNCMGR_OBJECTID_Icon

An icon extraction object that implements the [IExtractIcon](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iextracticona) interface used to display an icon for the handler. This object should only be provided if the handler obtains its icon dynamically at run time. The preferred mechanism for providing the icon is to register the icon as the DefaultIcon in the registry.

Sync Center only requests this object if the [SYNCMGR_HCM_PROVIDES_ICON](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_handler_capabilities) capability flag is set in the mask retrieved by [GetCapabilities](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-getcapabilities).

#### SYNCMGR_OBJECTID_QueryBeforeActivate

An object implementing the [ISyncMgrUIOperation](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgruioperation) interface that displays the UI that enables the user to configure a handler. This UI is shown when the user selects the handler in the Sync Setup folder, then selects the **Setup** task. Before requesting this object, Sync Center creates a separate thread for this operation and a new instance of the handler.

Sync Center only requests this object if the [SYNCMGR_HCM_QUERY_BEFORE_ACTIVATE](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_handler_capabilities) capability flag is set in the mask retrieved by [GetCapabilities](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-getcapabilities) and the [SYNCMGR_HPM_PREVENT_ACTIVATE](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_handler_policies) policy flag is not set in the mask retrieved by [GetPolicies](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-getpolicies).

#### SYNCMGR_OBJECTID_QueryBeforeDeactivate

An object implementing the [ISyncMgrUIOperation](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgruioperation) interface that displays the UI when the user selects the handler in the Sync Center folder, then selects the **Delete** task. Before requesting this object, Sync Center creates a separate thread for this operation and a new instance of the handler.

Sync Center only requests this object if the [SYNCMGR_HCM_QUERY_BEFORE_DEACTIVATE](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_handler_capabilities) capability flag is set in the mask retrieved by [GetCapabilities](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-getcapabilities) and the [SYNCMGR_HPM_PREVENT_DEACTIVATE](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_handler_policies) policy flag is not set in the mask retrieved by [GetPolicies](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-getpolicies).

#### SYNCMGR_OBJECTID_QueryBeforeEnable

An object implementing the [ISyncMgrUIOperation](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgruioperation) interface that displays the UI when the user selects the handler in the Sync Center folder and then selects the **Enable** task. Before requesting this object, Sync Center creates a separate thread for this operation and a new instance of the handler.

Sync Center only requests this object if the [SYNCMGR_HCM_CAN_ENABLE](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_handler_capabilities) and [SYNCMGR_HCM_QUERY_BEFORE_ENABLE](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_handler_capabilities) capability flags are set in the mask retrieved by [GetCapabilities](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-getcapabilities).

#### SYNCMGR_OBJECTID_QueryBeforeDisable

An object implementing the [ISyncMgrUIOperation](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgruioperation) interface that displays the UI when the user selects the handler in the Sync Center folder and then selects the **Disable** task. Before requesting this object, Sync Center creates both a separate thread for this operation and a new instance of the handler.

Sync Center only requests this object if the [SYNCMGR_HCM_CAN_DISABLE](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_handler_capabilities) and [SYNCMGR_HCM_QUERY_BEFORE_DISABLE](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_handler_capabilities) capability flags are set in the mask retrieved by [GetCapabilities](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-getcapabilities).

#### SYNCMGR_OBJECTID_ShowSchedule

An object implementing the [ISyncMgrUIOperation](https://learn.microsoft.com/windows/desktop/api/syncmgr/nn-syncmgr-isyncmgruioperation) interface that displays the UI that enables the user to configure the schedule for the handler. Before requesting this object, Sync Center creates a separate thread for this operation and a new instance of the handler.

Sync Center only requests this object if the [SYNCMGR_HCM_CAN_SHOW_SCHEDULE](https://learn.microsoft.com/windows/desktop/api/syncmgr/ne-syncmgr-syncmgr_handler_capabilities) capability flag is set in the mask retrieved by [GetCapabilities](https://learn.microsoft.com/windows/desktop/api/syncmgr/nf-syncmgr-isyncmgrhandler-getcapabilities).

### `riid` [in]

Type: **REFIID**

The IID of the requested interface. This depends on the object type named in *rguidObjectID*.

### `ppv` [out]

Type: **void****

When this method returns, contains the address of a pointer to the requested interface.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise. Returns E_NOTIMPL if the handler does not support the requested type of object.

## Remarks

The handler can implement the requested interface on itself or it can implement it on a different object.

#### Examples

The following example shows an implementation of this method.

```cpp
STDMETHODIMP CMyDeviceHandler::GetObject( __in REFGUID   rguidObjectID,
                                          __in REFIID    riid,
                                          __out void   **ppv)
{
    HRESULT hr = E_NOTIMPL;
    *ppv = NULL;

    if (rguidObjectID == SYNCMGR_OBJECTID_QueryBeforeActivate)
    {
        hr = _CreateSetupObject(riid, ppv);
    }
    else if (rguidObjectID == SYNCMGR_OBJECTID_EventStore)
    {
        hr = _CreateEventStore(NULL, riid, ppv);
    }

    return hr;
}

```