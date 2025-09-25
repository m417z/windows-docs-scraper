# IConsole2::Expand

## Description

The **IConsole2::Expand** method enables the snap-in to expand or collapse an item in the scope pane.

## Parameters

### `hItem` [in]

A handle to the item to expand.

### `bExpand` [in]

A value that specifies whether to expand or collapse the item. **TRUE** expands the item. **FALSE** collapses the item.

## Return value

This method can return one of these values.

## Remarks

The **IConsole2::Expand** method is the programmatic equivalent of the user clicking on the plus or minus sign to expand or collapse an item in the scope pane. That is, this method causes a visible expansion or collapse of an item in the scope pane. Be aware that this method does not change the selection in the scope pane and does not affect the result pane.

When this method is called, MMC expands or collapses the item specified by *hItem* based on the value set for *bExpand*. MMC then sends an expand notification to the snap-in of each child item. MMC does so by calling each child snap-in's
[IComponentData::Notify](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponentdata-notify) method with event set to [MMCN_EXPAND](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-expand), *lpDataObject* set as a pointer to the data object for *hItem*, arg set as **TRUE** or **FALSE** based on *bExpand*, and *param* set as *hItem*. Be aware that *hItem* is the **HSCOPEITEM** handle that you specified in your call to **IConsole2::Expand**.

The **IConsole2::Expand** method applies only to a particular view. This means that it applies only to the instance of the snap-in's
[IComponent](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponent) object that corresponds to the snap-in item that appears in a specific multiple-document interface (MDI) window within the console. Be aware that each MDI window within the console represents a different view and that an instance of a snap-in within an MDI window corresponds to an
**IComponent** object for that snap-in.

Therefore, the snap-in should only call this method on the
**IConsole2** interface pointer associated with an
**IComponent** object, that is, an
**IConsole2** interface pointer retrieved by calling [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) on the **IConsole** interface pointer returned by
[IComponent::Initialize](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent-initialize).

To enumerate the child items of an item in the namespace without visibly expanding the item, the snap-in should use the
[IConsoleNameSpace2::Expand](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iconsolenamespace2-expand) method.

## See also

[IConsole2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsole2)

[IConsoleNameSpace2::Expand](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iconsolenamespace2-expand)