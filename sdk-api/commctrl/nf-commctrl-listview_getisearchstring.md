# ListView_GetISearchString macro

## Syntax

```cpp
BOOL ListView_GetISearchString(
   HWND  hwndLV,
   LPSTR lpsz
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the number of characters in the incremental search string, or zero if the list-view control is not in incremental search mode.

## Description

Gets the incremental search string of a list-view control. You can use this macro or send the [LVM_GETISEARCHSTRING](https://learn.microsoft.com/windows/desktop/Controls/lvm-getisearchstring) message explicitly.

## Parameters

### `hwndLV`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `lpsz`

Type: **[LPSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to a buffer that receives the incremental search string. To just retrieve the length of the string, set *lpsz* to **NULL**.

## Remarks

The incremental search string is the character sequence that the user types while the list view has the input focus. Each time the user types a character, the system appends the character to the search string and then searches for a matching item. If the system finds a match, it selects the item and, if necessary, scrolls it into view.

A time-out period is associated with each character that the user types. If the time-out period elapses before the user types another character, the incremental search string is reset.

Make sure that the buffer is large enough to hold the string. If it is too small, an immediate invalid page fault will result.