# ListView_MapIDToIndex macro

## Syntax

```cpp
UINT ListView_MapIDToIndex(
   HWND hwnd,
   UINT id
);
```

## Return value

Type: **[UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the most current index.

## Description

Maps the ID of an item to an index. You can use this macro or send the [LVM_MAPIDTOINDEX](https://learn.microsoft.com/windows/desktop/controls/lvm-mapidtoindex) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `id`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A **UINT** that contains the unique ID of an item.

## Remarks

List-view controls internally track items by index. This can present problems because indexes can change during the control's existence.

You can use this macro to tag an item with an ID when you create the item.
You use this ID to guarantee uniqueness during the existence of the list-view control.

To uniquely identify an item, take the index that returns from a call, such as [IComponent::GetDisplayInfo](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent-getdisplayinfo), and call [LVM_MAPINDEXTOID](https://learn.microsoft.com/windows/desktop/Controls/lvm-mapindextoid). The return value is a unique ID.

If you need to know the index of an item after creating an ID, call
[LVM_MAPIDTOINDEX](https://learn.microsoft.com/windows/desktop/controls/lvm-mapidtoindex) with the unique ID and it returns the most current index.

**Note** In a multithreaded environment, you can only be sure the correct index is returned
on the thread that hosts the list-view control, not on background threads.

To use **ListView_MapIDToIndex**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).