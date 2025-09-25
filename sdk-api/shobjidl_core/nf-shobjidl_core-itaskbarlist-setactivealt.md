# ITaskbarList::SetActiveAlt

## Description

Marks a taskbar item as active but does not visually activate it.

## Parameters

### `hwnd`

Type: **HWND**

A handle to the window to be marked as active.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**SetActiveAlt** marks the item associated with *hwnd* as the currently active item for the window's process without changing the pressed state of any item. Any user action that would activate a different tab in that process will activate the tab associated with *hwnd* instead. The active state of the window's item is not guaranteed to be preserved when the process associated with *hwnd* is not active. To ensure that a given tab is always active, call **SetActiveAlt** whenever any of your windows are activated. Calling **SetActiveAlt** with a **NULL** *hwnd* clears this state.