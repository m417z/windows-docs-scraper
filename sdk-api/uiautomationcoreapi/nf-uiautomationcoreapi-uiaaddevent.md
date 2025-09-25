# UiaAddEvent function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Adds a listener for events on a node in the UI Automation tree.

## Parameters

### `hnode` [in]

Type: **HUIANODE**

The node to add an event listener to.

### `eventId` [in]

Type: **EVENTID**

The identifier of the event to listen for. For a list of event IDs, see [Event Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-event-ids).

### `pCallback` [in]

Type: **[UiaEventCallback](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/nc-uiautomationcoreapi-uiaeventcallback)***

The address of the application-defined [UiaEventCallback](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/nc-uiautomationcoreapi-uiaeventcallback) callback function that is called when the event is raised.

### `scope` [in]

Type: **[TreeScope](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/ne-uiautomationclient-treescope)***

A value from the [TreeScope](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/ne-uiautomationclient-treescope) enumerated type indicating the scope of events to be handled; that is, whether they are on the element itself,
or on its ancestors and children.

### `pProperties` [in]

Type: **PROPERTYID***

The address of an array that contains the identifiers of the properties to monitor for change events, when *eventId* is the EVENTID derived from AutomationPropertyChanged_Event_GUID; otherwise this parameter is **NULL**. For a list of property IDs, see [Property Identifiers](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-entry-propids).

### `cProperties` [in]

Type: **int**

The count of elements in the *pProperties* array.

### `pRequest` [in]

Type: **[UiaCacheRequest](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/ns-uiautomationcoreapi-uiacacherequest)***

The address of a [UiaCacheRequest](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/ns-uiautomationcoreapi-uiacacherequest) structure that defines the cache request in effect for nodes that are returned with events.

### `phEvent` [out]

Type: **HUIEVENT***

When this function returns, contains
a pointer to the event that is added.
This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.

## See also

[UiaLookupId](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/nf-uiautomationcoreapi-uialookupid)