# INameSpaceTreeControl::AppendRoot

## Description

Appends a Shell item to the list of roots in a tree.

## Parameters

### `psiRoot` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

Pointer to the Shell item that is being appended.

### `grfEnumFlags` [in]

Type: **[SHCONTF](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_shcontf)**

Enumerates the qualities of the root and all of its children. One or more of the values of type [SHCONTF](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_shcontf). These flags can be combined using a bitwise OR.

### `grfRootStyle` [in]

Type: **NSTCROOTSTYLE**

Specifies the style of the root that is being appended. One or more of the following values:

#### NSTCRS_VISIBLE (0x0000)

The root is visible as well as the items. Mutually exclusive with NSTCRS_HIDDEN.

#### NSTCRS_HIDDEN (0x0001)

The root is hidden so that the children only are visible. Mutually exclusive with NSTCRS_VISIBLE.

#### NSTCRS_EXPANDED (0x0002)

The root is expanded upon initialization.

### `pif` [in]

Type: **[IShellItemFilter](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitemfilter)***

Pointer to the [IShellItemFilter](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitemfilter) that enables you to filter which items in the tree are displayed. If supplied, every item is customizable with a [SHCONTF](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_shcontf) flag. This value can be **NULL** if no filter is required.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.