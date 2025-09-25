# DockPattern_SetDockPosition function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Docks the UI Automation element at the requested *dockPosition* within a docking container.

## Parameters

### `hobj` [in]

Type: **HUIAPATTERNOBJECT**

The *control pattern* object.

### `dockPosition` [in]

Type: **[DockPosition](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-dockposition)**

The location to dock the control to.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.