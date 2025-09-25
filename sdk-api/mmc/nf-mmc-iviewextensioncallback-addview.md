# IViewExtensionCallback::AddView

## Description

The
AddView method adds a view to the result pane. This method is implemented by MMC and is called by view extensions. For more information, see
[Extending Views](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/extending-views).

## Parameters

### `pExtViewData` [in]

A pointer to an
[MMC_EXT_VIEW_DATA](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_ext_view_data) structure, which contains information about the view being added to the result pane. The bReplacesDefaultView member of the
**MMC_EXT_VIEW_DATA** structure determines if the standard view is removed when adding the new view.

## Return value

If successful, the return value is S_OK. Other return values indicate an error code.

## See also

[Extending Views](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/extending-views)

[IExtendView](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iextendview)

[IExtendView::GetViews](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iextendview-getviews)

[MMC_EXT_VIEW_DATA](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_ext_view_data)

[View Extension Mechanism](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/view-extension-mechanism)