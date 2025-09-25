# TreeView_MapHTREEITEMToAccID macro

## Syntax

```cpp
UINT TreeView_MapHTREEITEMtoAccID(
   HWND      hwnd,
   HTREEITEM htreeitem
);
```

## Return value

Type: **[UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns an accessibility ID.

## Description

Maps an **HTREEITEM** to an accessibility ID. You can use this macro or send the [TVM_MAPHTREEITEMTOACCID](https://learn.microsoft.com/windows/desktop/Controls/tvm-maphtreeitemtoaccid) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the list-view control.

### `htreeitem`

Type: **HTREEITEM**

The value to be mapped.

## Remarks

To use **TreeView_MapHTREEITEMtoAccID**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).

**Note** The accessibility ID is not the same as that mentioned in [IAccessibleObject](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-iaccessibleobject). This is a unique ID used for treeview items as long as treeitems do not exceed the max limit of **UINT**.