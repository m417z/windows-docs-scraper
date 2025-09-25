# ListView_SetItemIndexState macro

## Syntax

```cpp
HRESULT ListView_SetItemIndexState(
  [in] HWND        hwndLV,
  [in] LVITEMINDEX *plvii,
  [in] UINT        data,
  [in] UINT        mask
);
```

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns one of the following values of type **HRESULT**.

| Return code | Description |
|---|---|
| E_FAIL | The state could not be set. |
| E_UNEXPECTED | The list-view control was not ready for the operation. |
| S_OK | The operation was successful. |

## Description

Sets the state of a specified list-view item. Use this macro or send the [LVM_SETITEMINDEXSTATE](https://learn.microsoft.com/windows/desktop/Controls/lvm-setitemindexstate) message explicitly.

## Parameters

### `hwndLV` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `plvii` [in]

Type: **[LVITEMINDEX](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvitemindex)***

A pointer to an [LVITEMINDEX](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvitemindex) structure for the item. The caller is responsible for allocating this structure and setting the members.

### `data` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The state to set on the item as one or more (as a bitwise combination) of the [List-View Item States](https://learn.microsoft.com/windows/desktop/Controls/list-view-item-states) flags.

### `mask` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The valid bits of the state specified by parameter *data*. For more information, see the *stateMask* member of the [LVITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvitema)) structure.