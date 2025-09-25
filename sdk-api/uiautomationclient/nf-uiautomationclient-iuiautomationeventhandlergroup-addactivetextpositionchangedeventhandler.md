# IUIAutomationEventHandlerGroup::AddActiveTextPositionChangedEventHandler

## Description

Registers a method (in an event handler group) that handles when the active text position changes.

**Important** Microsoft UI Automation clients should use the handler group methods to register event listeners instead of individual event registration methods defined in the various [IUIAutomation](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomation) namespaces.

## Parameters

### `scope` [in]

The scope of events to be handled; that is, whether they are on the element itself, or on its ancestors and descendants.

### `cacheRequest` [in]

A pointer to a cache request, or **NULL** if no caching is wanted.

### `handler` [in]

A pointer to the object that handles the active text position changed event.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Before implementing an event handler, you should be familiar with the threading issues described in [Understanding Threading Issues](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-threading).

Active text position is indicated by a navigation event within or between read-only text elements (such as web browsers, Portable Document Format (PDF) documents, or [EPUB](https://en.wikipedia.org/wiki/EPUB) documents) using bookmarks (or fragment identifiers to refer to a location within a resource). Examples include:

* Navigating to a bookmark within the same web page
* Navigating to a bookmark on a different web page
* Activating a link to a different location within the same PDF
* Activating a link to a different location within the same [EPUB](https://en.wikipedia.org/wiki/EPUB)

Use this event handler to sync the visual location of the bookmark/target with the focus location in a read-only text element, which can diverge when using bookmarks or fragment identifiers.

 For example, when a same page anchor (`<a href=”#C4”>Jump to Chapter 4</a> ... <h1><a name="C4">Chapter 4</a></h1>`)
is invoked, the visual location is updated, but the UI Automation client remains at the original location. This results in actions such as text reading or move next item commands starting from the original location, not the new location.

Similarly, activating a new page URI (with a fragment identifier: (`<a href=”www.blah.com#C4”>Jump to Chapter 4</a>`)) loads the new page and jumps to the specified bookmark, but leaves the UI Automation clients at the top of the page.

For editable text elements, such as [Edit](https://learn.microsoft.com/windows/desktop/controls/edit-controls) and [Rich Edit](https://learn.microsoft.com/windows/desktop/controls/rich-edit-controls) controls, you can listen for a SelectionChanged event.

## See also

[IUIAutomationEventHandlerGroup](https://learn.microsoft.com/windows/desktop/api/uiautomationclient/nn-uiautomationclient-iuiautomationeventhandlergroup)