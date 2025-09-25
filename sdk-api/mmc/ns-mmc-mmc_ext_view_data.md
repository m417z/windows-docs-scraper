# MMC_EXT_VIEW_DATA structure

## Description

The
**MMC_EXT_VIEW_DATA** structure is introduced in MMC 2.0.

The
**MMC_EXT_VIEW_DATA** structure is used by a view extension when it adds a view to the result pane.

## Members

### `viewID`

GUID for the view; this value uniquely identifies the view and is used to restore the view.

### `pszURL`

URL to the HTML used in the result pane; this typically points to an HTML resource in the snap-in's DLL.

### `pszViewTitle`

Title of the view extension.

### `pszTooltipText`

This value is reserved for future use.

### `bReplacesDefaultView`

If **TRUE**, the **Standard** tab does not appear in the tab selector; otherwise, the **Standard** tab appears. There is usually no need to display the **Standard** tab if the view extension snap-in displays the list of the primary snap-in.

## Remarks

For an example of the
**MMC_EXT_VIEW_DATA** structure used in C++ code, see
[IViewExtensionCallback::AddView](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iviewextensioncallback-addview).

## See also

[Extending Views](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/extending-views)

[IViewExtensionCallback](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iviewextensioncallback)

[IViewExtensionCallback::AddView](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iviewextensioncallback-addview)

[View Extension Mechanism](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/view-extension-mechanism)