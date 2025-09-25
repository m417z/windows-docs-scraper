# ListView_GetGroupInfoByIndex macro

## Syntax

```cpp
LRESULT ListView_GetGroupInfoByIndex(
  [in]      HWND     hwnd,
  [in]      int      iIndex,
  [in, out] PLVGROUP pgrp
);
```

## Return value

Type: **[LRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns 1 if successful, or 0 otherwise.

## Description

Gets information on a specified group. Use this macro or send the [LVM_GETGROUPINFOBYINDEX](https://learn.microsoft.com/windows/desktop/controls/lvm-getgroupinfobyindex) message explicitly.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `iIndex` [in]

Type: **int**

The index of the group.

### `pgrp` [in, out]

Type: **PLVGROUP**

A pointer to an [LVGROUP](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvgroup) structure to receive information on the group specified by *iIndex*. The calling application is responsible for allocating memory for the structure and any buffers in the structure, such as, the one pointed to by **pszHeader**. Set any contingent members of the structure, such as, **cchHeader**—the size of the buffer pointed to by **pszHeader** in **WCHAR****s**, including the terminating **NULL**. Set **cbSize** to the size of **LVGROUP** in bytes.

The message receiver is responsible for setting the structure members with information for the group specified by *iIndex*.