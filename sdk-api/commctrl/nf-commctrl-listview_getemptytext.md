# ListView_GetEmptyText macro

## Syntax

```cpp
BOOL ListView_GetEmptyText(
  [in]      HWND  hwnd,
  [in, out] PWSTR pszText,
  [in]      UINT  cchText
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Gets the text meant for display when the list-view control appears empty. Use this macro or send the [LVM_GETEMPTYTEXT](https://learn.microsoft.com/windows/desktop/Controls/lvm-getemptytext) message explicitly.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `pszText` [in, out]

Type: **[PWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to a null-terminated, Unicode buffer of size specified by *cchText* to receive the text. The caller is responsible for allocating the buffer.

### `cchText` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The size of the buffer pointed to by *pszText*, including the terminating **NULL**.