# SelectionItemPattern_Select function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Selects an element in a selection container.

## Parameters

### `hobj` [in]

Type: **HUIAPATTERNOBJECT**

The control pattern object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.

## Remarks

All other elements are deselected.
To select an element without deselecting others, use [SelectionItemPattern_AddToSelection](https://learn.microsoft.com/windows/desktop/api/uiautomationcoreapi/nf-uiautomationcoreapi-selectionitempattern_addtoselection).