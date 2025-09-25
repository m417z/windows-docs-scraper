# IResultData::SetViewMode

## Description

The **IResultData::SetViewMode** method enables the snap-in to set the view mode in which the result view pane displays its items. Be aware that view modes apply only to list views.

## Parameters

### `lViewMode` [in]

A value that specifies the view mode to be set in the result pane. It can be one of the following values:

#### MMCLV_VIEWSTYLE_ICON

Items are displayed as title strings under their large (32x32) icon representations. Subitems and headers are not displayed.

#### MMCLV_VIEWSTYLE_REPORT

Items are displayed as title strings to the right of their small (16x16) icon representations. Items are tabulated under the header in the zero position of the zero-based index on the left side of the result view pane. Subsequent headers are produced from left to right and corresponding subitems are placed beneath each. To enter the report mode, you must have already called
[IConsole::SetHeader](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa814793(v=vs.85)).

#### MMCLV_VIEWSTYLE_SMALLICON

Items are displayed as title strings under their small (16x16) icon representations. Subitems and headers are not displayed.

#### MMCLV_VIEWSTYLE_LIST

Items are displayed as title strings to the right of their small (16x16) icon representations. Subitems and headers are not displayed.

#### MMCLV_VIEWSTYLE_FILTERED

Allows a snap-in to programmatically set the view mode to filtered view. For more information about filtered views, see
[Adding Filtered Views](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/adding-filtered-views).

This parameter must not be **NULL**.

## Return value

This method can return one of these values.

## Remarks

This method provides the same functionality for both virtual and non-virtual list views. For more information about a scenario where you could use **IResultData::SetViewMode**, see
[Using List Views: Implementation Details](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/using-list-views-implementation-details).

## See also

[IResultData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iresultdata)

[IResultData2](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iresultdata2)

[IResultData::GetViewMode](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-iresultdata-getviewmode)