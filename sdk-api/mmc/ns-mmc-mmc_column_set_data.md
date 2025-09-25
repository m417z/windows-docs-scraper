# MMC_COLUMN_SET_DATA structure

## Description

The
MMC_COLUMN_SET_DATA structure is introduced in MMC 1.2.

The
MMC_COLUMN_SET_DATA structure is used with setting and retrieving list view column sets whose data is persisted in memory by MMC. The
MMC_COLUMN_SET_DATA structure contains information about the number of columns in a particular column set as well as a pointer to persisted column data of the column set.

## Members

### `cbSize`

The size of the
MMC_COLUMN_SET_DATA structure.

### `nNumCols`

The number of columns in the column set.

### `pColData`

A pointer to an array of
[MMC_COLUMN_DATA](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_column_data) structures that contains the persisted column set data.

## See also

[CCF_COLUMN_SET_ID](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/ccf-column-set-id)

[IColumnData](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icolumndata)

[IColumnData::GetColumnConfigData](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icolumndata-getcolumnconfigdata)

[IColumnData::SetColumnConfigData](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icolumndata-setcolumnconfigdata)

[Using Column Persistence](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/using-column-persistence)