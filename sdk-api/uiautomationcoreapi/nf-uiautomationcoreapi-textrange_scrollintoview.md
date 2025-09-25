# TextRange_ScrollIntoView function

## Description

**Note** This function is deprecated. Client applications should use the Microsoft UI Automation Component Object Model (COM) interfaces instead.

Scrolls the text so the specified range is visible in the viewport.

## Parameters

### `hobj` [in]

Type: **HUIATEXTRANGE**

The text range to scroll.

### `alignToTop` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

TRUE to align the top of the text range with the top of the viewport;
FALSE to align the bottom of the text range with the bottom of the viewport.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK if successful or an error value otherwise.