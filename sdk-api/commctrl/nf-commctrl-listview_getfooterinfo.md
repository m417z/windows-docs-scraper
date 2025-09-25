# ListView_GetFooterInfo macro

## Syntax

```cpp
BOOL ListView_GetFooterInfo(
  [in]      HWND           hwnd,
  [in, out] LPLVFOOTERINFO plvfi
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE**.

## Description

Gets information on the footer of a specified list-view control. Use this macro or send the [LVM_GETFOOTERINFO](https://learn.microsoft.com/windows/desktop/Controls/lvm-getfooterinfo) message explicitly.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `plvfi` [in, out]

Type: **LPLVFOOTERINFO**

A pointer to a [LVFOOTERINFO](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvfooterinfo) structure to receive information depending on the value of the **mask** member. The calling application is responsible for allocating this structure and setting the **mask** member.