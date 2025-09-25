# ListView_EnableGroupView macro

## Syntax

```cpp
int ListView_EnableGroupView(
   HWND hwnd,
   BOOL fEnable
);
```

## Return value

Type: **int**

Returns one of the following values:

| Return code | Description |
|---|---|
| 0 | The ability to display list-view items as a group is already enabled or disabled. |
| 1 | The state of the control was successfully changed. |
| -1 | The operation failed. |

## Description

Enables or disables whether the items in a list-view control display as a group. You can use this macro or send the [LVM_ENABLEGROUPVIEW](https://learn.microsoft.com/windows/desktop/Controls/lvm-enablegroupview) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `fEnable`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**BOOL**
**TRUE**
**FALSE**

## Remarks

To use **ListView_EnableGroupView**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).