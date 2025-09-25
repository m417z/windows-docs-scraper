# TextRange_MoveEndpointByUnit function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Moves an endpoint of the range the specified number of units.

## Parameters

### `hobj` [in]

Type: **HUIATEXTRANGE**

A text range object.

### `endpoint` [in]

Type: **TextPatternRangeEndpoint**

The endpoint to move (either the start or the end).

### `unit` [in]

Type: **[TextUnit](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-textunit)**

The unit, such as Page, Line, or Word.

### `count` [in]

Type: **int**

The number of units to move. A positive value moves the range forward; a negative value
moves it backward.

### `pRetVal` [out]

Type: **int***

When this function returns, contains
the number of units the endpoint actually moved.
This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.