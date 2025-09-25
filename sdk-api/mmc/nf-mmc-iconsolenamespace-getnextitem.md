# IConsoleNameSpace::GetNextItem

## Description

The **IConsoleNameSpace2::GetNextItem** method enables the snap-in to retrieve the handle to the next item in the scope view.

## Parameters

### `item` [in]

A handle to an item in the scope pane.

### `pItemNext` [out]

A pointer to the handle to the next item in the scope pane that has been returned.

### `pCookie` [out]

A pointer to the cookie of the next item that has been returned.

## Return value

This method can return one of these values.

## Remarks

If there is no item next to the given item, **NULL** is returned.

## See also

[IConsoleNameSpace](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsolenamespace)

[IConsoleNameSpace2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsolenamespace2)