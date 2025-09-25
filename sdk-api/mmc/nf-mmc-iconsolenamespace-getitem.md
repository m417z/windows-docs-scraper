# IConsoleNameSpace::GetItem

## Description

The **IConsoleNameSpace2::GetItem** method enables the snap-in to retrieve some or all of a single scope item's attributes.

## Parameters

### `item` [in, out]

A pointer to a
[SCOPEDATAITEM](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-scopedataitem) structure that specifies the information to retrieve and receives information about the item. When the message is sent, the
ID member of the structure identifies the item and the mask member specifies the attributes to retrieve.

If mask specifies the **SDI_STATE** value, the **nState** member contains the item's state information.

## Return value

This method can return one of these values.

## See also

[IConsoleNameSpace](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsolenamespace)

[IConsoleNameSpace2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsolenamespace2)