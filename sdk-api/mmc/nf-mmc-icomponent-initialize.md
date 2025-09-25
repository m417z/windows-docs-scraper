# IComponent::Initialize

## Description

The **IComponent::Initialize** method provides an entry point to the console. At this point, the snap-in should set up the toolbar. If the snap-in uses the default list view it should also set up the list view's headers and add images to be used in the result pane.

## Parameters

### `lpConsole` [in]

A pointer to the console
[IConsole](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsole2) interface.

## Return value

This method can return one of these values.

## Remarks

**IComponent::Initialize** is called when a snap-in is being created. The pointer to IConsole that is passed in is used to make QueryInterface calls to the console for interfaces such as
[IResultData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iresultdata). You can also call QueryInterface on the IConsole pointer to get an
[IConsole2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsole2) interface pointer.

## See also

[IComponent](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponent)

[IComponent::Destroy](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent-destroy)

[IConsole2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsole2)

[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)