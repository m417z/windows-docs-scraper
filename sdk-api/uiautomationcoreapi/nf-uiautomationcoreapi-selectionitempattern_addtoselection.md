# SelectionItemPattern_AddToSelection function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Adds an unselected element to a selection in a control.

## Parameters

### `hobj` [in]

Type: **HUIAPATTERNOBJECT**

The control pattern object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.

## Remarks

In a control that supports multiple selection, this function adds an item to the selection. In a single-selection control,
it deselects the currently selected item and selects the specified item.