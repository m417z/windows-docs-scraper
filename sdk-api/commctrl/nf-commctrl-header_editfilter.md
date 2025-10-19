# Header_EditFilter macro

## Syntax

```cpp
int Header_EditFilter(
   HWND            hwnd,
   int             i,
   fDi<no_pop></no_pop>scardChanges fDiscardChanges
);
```

## Return value

Type: **int**

Returns an integer that indicates **TRUE**(1) or **FALSE**(0).

## Description

Moves the input focus to the edit box when a filter button has the focus.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the header control.

### `i`

Type: **int**

A value specifying the column to edit.

### `fDiscardChanges`

Type: **fDiscardChanges**

A flag that specifies how to handle the user's editing changes. Use this flag to specify what to do if the user is in the process of editing the filter when the message is sent.

| Value | Meaning |
| --- | --- |
| **TRUE** | Discard the changes made by the user. |
| **FALSE** | Accept the changes made by the user. |

## See also

[HDM_EDITFILTER](https://learn.microsoft.com/windows/desktop/Controls/hdm-editfilter)