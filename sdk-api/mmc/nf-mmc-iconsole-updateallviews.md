# IConsole::UpdateAllViews

## Description

Called by a snap-in when there is a content change in the result pane. This method can be called either by
[IComponent](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponent) or
[IComponentData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponentdata).

## Parameters

### `lpDataObject` [in]

A pointer to a user-supplied data object.

### `data` [in]

A user-defined value, for example a pointer to the modified content.

### `hint` [in]

A user-defined value, for example information about the type of content change.

## Return value

This method can return one of these values.

## Remarks

This method sends an [MMCN_VIEW_CHANGE](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/mmcn-view-change) notification to all instances of
[IComponent](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponent) associated with the snap-in instance calling this method. The *lpDataObject*, *data*, and *hint* parameters are passed as the *lpDataObject* arg, and param for the
[IComponent::Notify](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent-notify) method.

This method should be called from the
[IConsole](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsole) interface pointer obtained through the snap-in
[IComponentData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponentdata) implementation.

## See also

[IConsole](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsole)

[IToolbar](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-itoolbar)