# IComponentData::Initialize

## Description

The **IComponentData::Initialize** method provides an entry point to the console.

## Parameters

### `pUnknown` [in]

A pointer to the console IUnknown interface. This interface pointer can be used to call QueryInterface for
[IConsole2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsole2) and
[IConsoleNameSpace2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsolenamespace2).

## Return value

This method can return one of these values.

## Remarks

**IComponentData::Initialize** is called when a snap-in is created and has items to enumerate in the scope pane. The pointer to [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) that is passed in is used to make [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) calls to the console for interfaces such as
[IConsole2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsole2) and
[IConsoleNamespace2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsolenamespace2). The snap-in should also call
[IConsole2::QueryScopeImageList](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa814791(v=vs.85)) to get the image list for the scope pane and add images to be displayed on the scope pane side.

## See also

[IComponent](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponent)

[IComponentData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponentdata)

[IConsole2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsole2)