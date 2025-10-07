# IUIAutomation6::RemoveActiveTextPositionChangedEventHandler

## Description

Removes an active text position changed event handler.

> [!Important]
> Microsoft UI Automation clients should use the [IUIAutomationEventHandlerGroup interface](https://learn.microsoft.com/windows/win32/api/uiautomationclient/nn-uiautomationclient-iuiautomationeventhandlergroup) methods to register event listeners instead of individual event registration methods defined here and in the various [IUIAutomation interface](https://learn.microsoft.com/windows/win32/api/uiautomationclient/nn-uiautomationclient-iuiautomation) namespaces.

## Parameters

### `element` [in]

A pointer to the UI Automation element associated with the event handler.

### `handler` [in]

A pointer to the object that handles the active text position changed event.

## Return value

This method does not return a value.

## Remarks

Before implementing an event handler, you should be familiar with the threading issues described in [Understanding Threading Issues](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-threading).

Active text position is indicated by a navigation event within or between read-only text elements (such as web browsers, Portable Document Format (PDF) documents, or [EPUB](https://en.wikipedia.org/wiki/EPUB) documents) using bookmarks (or fragment identifiers to refer to a location within a resource). Examples include:

- Navigating to a bookmark within the same web page
- Navigating to a bookmark on a different web page
- Activating a link to a different location within the same PDF
- Activating a link to a different location within the same [EPUB](https://en.wikipedia.org/wiki/EPUB)

Use this event handler to sync the visual location of the bookmark/target with the focus location in a read-only text element, which can diverge when using bookmarks or fragment identifiers.

For example, when a same page anchor (`<a href="#C4">Jump to Chapter 4</a> ...<h1><a name="C4">Chapter 4</a></h1>`) is invoked, the visual location is updated, but the UI Automation client remains at the original location. This results in actions such as text reading or move next item commands starting from the original location, not the new location.

Similarly, activating a new page URI (with a fragment identifier: (`<a href="www.blah.com#C4">Jump to Chapter 4</a>`) loads the new page and jumps to the specified bookmark, but leaves the UI Automation clients at the top of the page.

For editable text elements, such as [Edit](https://learn.microsoft.com/windows/desktop/controls/edit-controls) and [Rich Edit](https://learn.microsoft.com/windows/win32/controls/rich-edit-controls) controls, you can listen for a SelectionChanged event.

It is possible for an event to be delivered to an event handler after the handler has been unsubscribed, if the event is received simultaneously with the request to unsubscribe the event. The best practice is to follow the Component Object Model (COM) standard and avoid destroying the event handler object until its reference count has reached zero. Destroying an event handler immediately after unsubscribing for events may result in an access violation if an event is delivered late.

## See also

[IUIAutomation6::AddActiveTextPositionChangedEventHandler](https://learn.microsoft.com/windows/win32/api/uiautomationclient/nf-uiautomationclient-iuiautomation6-addactivetextpositionchangedeventhandler), [IUIAutomation6 interface](https://learn.microsoft.com/windows/win32/api/uiautomationclient/nn-uiautomationclient-iuiautomation6)