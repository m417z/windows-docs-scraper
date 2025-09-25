# MMC_COLUMN_DATA structure

## Description

The
MMC_COLUMN_DATA structure is introduced in MMC 1.2.

The
MMC_COLUMN_DATA structure contains the column data of a single column in a column set. The column data is persisted in memory by MMC. The
[MMC_COLUMN_SET_DATA](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_column_set_data) structure holds a pointer to an array of
MMC_COLUMN_DATA structures.

## Members

### `nColIndex`

A zero-based index value of the column.

### `dwFlags`

A flag that is defined, HDI_HIDDEN (= 0x0001), which indicates that the column is hidden. The default value for the field is 0, indicating that the column is visible.

### `nWidth`

Width of the column.

### `ulReserved`

Not currently used.

## Remarks

By setting the dwFlags member of the
MMC_COLUMN_DATA structure, a snap-in can hide or show columns in a column set in calls to
[IColumnData::SetColumnConfigData](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icolumndata-setcolumnconfigdata). However, column "0" of a column set cannot be hidden. This is to ensure that result pane icons are properly inserted in the first column and that the MMC_VERB_RENAME console verb functions properly.

## See also

[CCF_COLUMN_SET_ID](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/ccf-column-set-id)

[MMC_COLUMN_SET_DATA](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_column_set_data)

[Using Column Persistence](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/using-column-persistence)