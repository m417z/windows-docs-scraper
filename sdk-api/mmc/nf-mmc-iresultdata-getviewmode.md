# IResultData::GetViewMode

## Description

The **IResultData::GetViewMode** method enables the snap-in to retrieve a view mode for the result view pane. Be aware that view modes only apply to list views.

## Parameters

### `lViewMode` [out]

A pointer to the view mode to be retrieved. It can be one of the following:

#### MMCLV_VIEWSTYLE_ICON

Items are displayed as title strings under their large (32x32) icon representations. Subitems and headers are not displayed.

#### MMCLV_VIEWSTYLE_REPORT

Items are displayed as title strings to the right of their small (16x16) icon representations. Items are tabulated under the header in the 0 (zero) position of the zero-based index on the left side of the result view pane. Subsequent headers are produced from left to right and corresponding subitems are placed beneath each. To enter the report mode, you must have already called
[IConsole::SetHeader](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa814793(v=vs.85)).

#### MMCLV_VIEWSTYLE_SMALLICON

Items are displayed as title strings under their small (16x16) icon representations. Subitems and headers are not displayed.

#### MMCLV_VIEWSTYLE_LIST

Items are displayed as title strings to the right of their small (16x16) icon representations. Subitems and headers are not displayed.

#### MMCLV_VIEWSTYLE_FILTERED

The list view is displayed as a filtered view. Each list view column has an associated column filter. For more information about filtered views, see
[Adding Filtered Views](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/adding-filtered-views).

This parameter must not be **NULL**.

## Return value

This method can return one of these values.

## Remarks

This method provides the same functionality for both virtual and nonvirtual list views.

## See also

[IResultData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iresultdata)

[IResultData2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iresultdata2)

[IResultData::SetViewMode](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iresultdata-setviewmode)