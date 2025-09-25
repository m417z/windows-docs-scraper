# TextRange_Move function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Moves the text range the specified number of units requested by the client.

## Parameters

### `hobj` [in]

Type: **HUIATEXTRANGE**

A text range object.

### `unit` [in]

Type: **[TextUnit](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/ne-uiautomationcore-textunit)**

The unit, such as Page, Line, or Word.

### `count` [in]

Type: **int**

The number of units to move. Positive numbers move the range forward,
and negative numbers move the range backward.

### `pRetVal` [out]

Type: **int***

When this function returns, contains
the number of units actually moved.
This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.