# SelectionItemPattern_RemoveFromSelection function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Removes an element from the selection in a selection container.

## Parameters

### `hobj` [in]

Type: **HUIAPATTERNOBJECT**

The control pattern object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.

## Remarks

The function has no effect if an attempt is made to remove the last selected element in a control that requires at
least one element to be selected.