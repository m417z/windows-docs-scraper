# IComponent::GetDisplayInfo

## Description

The **IComponent::GetDisplayInfo** method retrieves display information for an item in the result pane.

## Parameters

### `pResultDataItem` [in, out]

A pointer to a
[RESULTDATAITEM](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-resultdataitem) structure. On input, the mask member specifies the type of data required and the lParam member identifies the item of interest. When called for a virtual list, the nIndex member identifies the desired virtual item and the lParam member is zero.

## Return value

This method can return one of these values.

## Remarks

For virtual lists, MMC calls the
GetDisplayInfo method only for items that are currently visible in the result pane. This means that
GetDisplayInfo does not get called for an item until it appears in the result pane.

It is safe to reallocate the memory allocated for members of pResultDataItem only in the following situations:

* The item is deleted.
* [IComponent::Destroy](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent-destroy) is called.
* GetDisplayInfo is called again for that item.

## See also

[IComponent](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponent)

[IComponentData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponentdata)

[IConsole2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsole2)