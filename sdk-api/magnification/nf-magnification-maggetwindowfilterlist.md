# MagGetWindowFilterList function

## Description

Retrieves the list of windows that are magnified or excluded from magnification.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The magnification window.

### `pdwFilterMode` [out]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The filter mode, as set by [MagSetWindowFilterList](https://learn.microsoft.com/previous-versions/windows/desktop/api/magnification/nf-magnification-magsetwindowfilterlist).

### `count` [in]

Type: **int**

The number of windows to retrieve, or 0 to retrieve a count of windows in the filter list.

### `pHWND` [out]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The list of window handles.

## Return value

Type: **int**

Returns the count of window handles in the filter list, or -1 if the *hwnd* parameter is not valid.

## Remarks

First call the method with a *count* of 0 to retrieve the count of windows in the filter list. Use the retrieved count to allocate
sufficient memory for the retrieved list of window handles.

This function requires Windows Display Driver Model (WDDM)-capable video cards.

## See also

[MagSetWindowFilterList](https://learn.microsoft.com/previous-versions/windows/desktop/api/magnification/nf-magnification-magsetwindowfilterlist)