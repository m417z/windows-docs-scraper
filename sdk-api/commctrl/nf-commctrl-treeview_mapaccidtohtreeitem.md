# TreeView_MapAccIDToHTREEITEM macro

## Syntax

```cpp
HTREEITEM TreeView_MapAccIDToHTREEITEM(
   HWND hwnd,
   UINT id
);
```

## Return value

Type: **HTREEITEM**

Returns the **HTREEITEM** to which the specified accessibility ID is mapped.

## Description

Maps an accessibility ID to an **HTREEITEM**. You can use this macro or send the [TVM_MAPACCIDTOHTREEITEM](https://learn.microsoft.com/windows/desktop/Controls/tvm-mapaccidtohtreeitem) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `id`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The accessibility ID to map to an **HTREEITEM**.

## Remarks

To use **TreeView_MapAccIDToHTREEITEM**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).

**Note** The accessibility ID is not the same as that mentioned in [IAccessibleObject](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-iaccessibleobject). This is a unique ID used for treeview items as long as treeitems do not exceed the max limit of **UINT**.