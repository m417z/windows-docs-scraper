# IConsoleNameSpace::GetChildItem

## Description

The **IConsoleNameSpace2::GetChildItem** method enables the snap-in to get the handle to a child item in the scope pane.

## Parameters

### `item` [in]

A handle to a parent item in the scope pane.

### `pItemChild` [out]

A pointer to the handle that identifies the child item in the scope pane that has been returned.

### `pCookie` [out]

A pointer to the cookie associated with the child item that has been returned.

## Return value

This method can return one of these values.

## Remarks

If the handle to the child item is not obtained, **NULL** is returned.

## See also

[IConsoleNameSpace](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsolenamespace)

[IConsoleNameSpace2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsolenamespace2)