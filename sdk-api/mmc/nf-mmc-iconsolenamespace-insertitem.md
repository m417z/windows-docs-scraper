# IConsoleNameSpace::InsertItem

## Description

The **IConsoleNameSpace2::InsertItem** method enables the snap-in to insert a single item into the scope view.

## Parameters

### `item` [in, out]

A pointer to a
[SCOPEDATAITEM](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-scopedataitem) structure that specifies the attributes of the new scope item. On return, the
ID member of the structure contains the item identifier assigned by MMC for the newly inserted item. Be aware that this value is the **HSCOPEITEM** handle of the inserted item. The snap-in should store this value in order to later manipulate the inserted item by calling methods such as
[IConsoleNameSpace2::GetItem](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iconsolenamespace-getitem).

## Return value

This method can return one of these values.

## See also

[IConsoleNameSpace](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsolenamespace)

[IConsoleNameSpace2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsolenamespace2)