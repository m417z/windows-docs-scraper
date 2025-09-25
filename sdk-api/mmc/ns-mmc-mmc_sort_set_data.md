# MMC_SORT_SET_DATA structure

## Description

The
MMC_SORT_SET_DATA structure is introduced in MMC 1.2.

The
MMC_SORT_SET_DATA structure is used with setting and retrieving list view column sets whose sort data is stored persistently. The
MMC_SORT_SET_DATA structure contains information about the number of columns in a particular column set for which persistent sort data is being set or retrieved, as well as a pointer to an array of
MMC_SORT_DATA structures that actually hold the sort data.

## Members

### `cbSize`

Size of the
MMC_SORT_SET_DATA structure.

### `nNumItems`

The number of columns in the column set for which persistent sort data is being set or retrieved. This value can be one of the following:

#### 0

No columns in the column set are sorted. The snap-in can set nNumItems to this value to persist the fact that the list view is not sorted. In this case, the pSortData member should be set to **NULL**.

#### 1

One column in the column set is sorted. Be aware that only single-column sorting is allowed in MMC 1.2.

### `pSortData`

A pointer to an array of
[MMC_SORT_DATA](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_sort_data) structures that hold the actual sort data. Should be set to **NULL** if nNumItems is set to 0.

## Remarks

MMC 1.2 only supports single-column sorting, so the nNumItems member of the
MMC_SORT_SET_DATA structure cannot be greater than 1. Otherwise,
[IColumnData::SetColumnSortData](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icolumndata-setcolumnsortdata) will return S_FALSE.

Sorting is disabled on hidden columns. Columns can be hidden or displayed using the
[IColumnData::SetColumnConfigData](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icolumndata-setcolumnconfigdata) method.

The user can hide columns using the Choose Columns dialog.

## See also

[CCF_COLUMN_SET_ID](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/ccf-column-set-id)

[MMC_SORT_DATA](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_sort_data)

[Using Column Persistence](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/using-column-persistence)