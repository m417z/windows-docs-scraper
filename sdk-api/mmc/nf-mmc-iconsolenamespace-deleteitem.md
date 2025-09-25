# IConsoleNameSpace::DeleteItem

## Description

The **IConsoleNameSpace2::DeleteItem** method [IConsoleNameSpace](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsolenamespace) enables the snap-in to delete a single item from the scope pane.

## Parameters

### `hItem` [in]

A handle to the item whose child items are to be deleted from the scope pane. If the second argument to **IConsoleNameSpace2::DeleteItem** is set to **TRUE**, the item is also deleted.

### `fDeleteThis` [in]

If **TRUE**, the item specified by hItem is also deleted; otherwise, it is not.

## Return value

This method can return one of these values.

## See also

[IConsoleNameSpace](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsolenamespace)

[IConsoleNameSpace2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsolenamespace2)