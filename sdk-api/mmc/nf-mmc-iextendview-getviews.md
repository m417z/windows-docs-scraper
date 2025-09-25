# IExtendView::GetViews

## Description

The
GetViews method retrieves information about the extended view and adds extended views to the result pane.

View extensions use the
[IViewExtensionCallback](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iviewextensioncallback) interface methods to provide information about the extended view. A pointer to the
IViewExtensionCallback interface is provided as a parameter of the **IExtendView::GetViews** method.

## Parameters

### `pDataObject` [in]

A pointer to the snap-in data object.

### `pViewExtensionCallback` [in]

A pointer to the
[IViewExtensionCallback](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iviewextensioncallback) interface. The view extension snap-in uses the
IViewExtensionCallback interface to add information about the extended view. The snap-in can also call the
[IViewExtensionCallback::AddView](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iviewextensioncallback-addview) method multiple times to add multiple extended views. The value in pViewExtensionCallback is valid only during the call to **IExtendView::GetViews**; view extension snap-ins must not save this pointer for later use.

## Return value

If successful, the return value is S_OK. Other return values indicate an error code.

## Remarks

For more information and a C++ code example for **IExtendView::GetViews**, see
[Extending a Primary Snap-in's View](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/extending-a-primary-snap-ins-view).

## See also

[Extending Views](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/extending-views)

[Extending a Primary Snap-in's View](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/extending-a-primary-snap-ins-view)

[IViewExtensionCallback](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iviewextensioncallback)

[IViewExtensionCallback::AddView](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iviewextensioncallback-addview)