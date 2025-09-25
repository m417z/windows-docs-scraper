# INameSpaceTreeControl::GetNextItem

## Description

Retrieves the next item in the tree according to which method is requested.

## Parameters

### `psi` [in, optional]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

The Shell item for which the next item is being retrieved. This value can be **NULL**.

### `nstcgi` [in]

Type: **NSTCGNI**

The type of the next item. This value can be one of the following flags:

#### NSTCGNI_NEXT (0)

The next sibling of the given item.

#### NSTCGNI_NEXTVISIBLE (1)

The next visible item in the tree that has any relationship to the given item. This includes a child (if there is one), the next sibling, or even one of the ancestor's siblings.

#### NSTCGNI_PREV (2)

The previous sibling item of the given item.

#### NSTCGNI_PREVVISIBLE (3)

The previous visible item that is a sibling item, sibling descendent item or a parent item.

#### NSTCGNI_PARENT (4)

The parent item of the given item.

#### NSTCGNI_CHILD (5)

The first child item of the given item.

#### NSTCGNI_FIRSTVISIBLE (6)

The absolute first visible item in the tree (not relative to the given item).

#### NSTCGNI_LASTVISIBLE (7)

The absolute last visible item in the tree (not relative to the given item).

### `ppsiNext` [out]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)****

The address of a pointer to the [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) that fits the criteria for the next item that was requested.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If there is no next item for the type selected, this function returns E_FAIL with **NULL** for the returned item, *ppsiNext*.