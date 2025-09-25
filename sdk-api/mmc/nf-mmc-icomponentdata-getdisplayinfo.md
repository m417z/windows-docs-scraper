# IComponentData::GetDisplayInfo

## Description

The **IComponentData::GetDisplayInfo** method retrieves display information for a scope item.

## Parameters

### `pScopeDataItem` [in, out]

A pointer to a
[SCOPEDATAITEM](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-scopedataitem) structure. On input, the structure mask member specifies the type of information required and the lParam member identifies the item of interest.

## Return value

This method can return one of these values.

## Remarks

It is safe to reallocate the memory allocated for members of the pScopeDataItem parameter only:

* When the scope item is deleted.
* When
  [IComponentData::Destroy](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponentdata-destroy) is called.
* When
  GetDisplayInfo is called again for that scope item.

## See also

[IComponent](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponent)

[IComponentData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponentdata)

[IConsole2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsole2)