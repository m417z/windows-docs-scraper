# IHeaderCtrl::InsertColumn

## Description

Adds a column to a default result pane.

## Parameters

### `nCol` [in]

A zero-based index of the column being inserted.

### `title` [in]

A value that specifies the string that represents the title of the column being inserted. This string can have a maximum length of **MAX_PATH** characters.

### `nFormat` [in]

A value that specifies the position of text within the column. For column zero, *nFormat* must be **LVCFMT_LEFT**. This value must be one of the following:

#### LVCFMT_LEFT

Text is left-aligned.

#### LVCFMT_CENTER

Text is center-aligned.

#### LVCFMT_RIGHT

Text is right-aligned.

**Note** To use the **LVCFMT_*** constants, include CommCtrl.h in your source file.

### `nWidth` [in]

A value that specifies the width of the column in pixels. This value must be one of the following:

#### MMCLV_AUTO

MMC automatically determines the width of the column based on its title string.

#### HIDE_COLUMN

Introduced in MMC 1.2. The column is inserted, but it is hidden. Be aware that the user can make the column visible when
[customizing a list view](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/how-column-configuration-data-is-used).

For snap-ins built with the MMC 1.2 SDK, but which are loaded in an older version of MMC, **HIDE_COLUMN** is interpreted as a zero width. The user can widen the column by dragging it with the mouse.

## Return value

This method can return one of these values.

## Remarks

MMC does not persist in memory any changes made to a column set due to the action of **IHeaderCtrl::InsertColumn**, so snap-ins must update persisted column configuration data after inserting columns into a column set. See
[IHeaderCtrl2 and Column Persistence](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/iheaderctrl2-and-column-persistence) for more information.

### Notes to Callers

Calls to
**InsertColumn** fail if any items have already been inserted into the result view.

## See also

[IHeaderCtrl](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iheaderctrl)

[IHeaderCtrl2 and Column Persistence](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/iheaderctrl2-and-column-persistence)