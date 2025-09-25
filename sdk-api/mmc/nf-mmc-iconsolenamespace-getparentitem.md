# IConsoleNameSpace::GetParentItem

## Description

The **IConsoleNameSpace2::GetParentItem** method enables the snap-in to retrieve the handle to a parent item in the scope view.

## Parameters

### `item` [in]

A handle to an item in the scope pane.

### `pItemParent` [out]

A pointer to the handle to the parent item that is returned.

### `pCookie` [out]

A pointer to the cookie associated with the parent item that is returned.

## Return value

This method can return one of these values.

## Remarks

If the given item has no parent, **NULL** is returned.

## See also

[IConsoleNameSpace](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsolenamespace)

[IConsoleNameSpace2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsolenamespace2)