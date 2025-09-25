# MMC_SORT_DATA structure

## Description

The
MMC_SORT_DATA structure is introduced in MMC 1.2.

The
MMC_SORT_DATA structure contains the column sort data of a single column in a column set. This data is persisted in memory by MMC. A pointer to an array of these structures is held in the pSortData member of the
[MMC_SORT_SET_DATA](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_sort_set_data) structure.

## Members

### `nColIndex`

A zero-based index value of the column.

### `dwSortOptions`

Sort options to be used during the sort operation. This value can be a combination of the following:

#### RSI_DESCENDING = 0x0001

The sort should be in descending order. The default is to sort in ascending order.

#### RSI_NOSORTICON = 0x0002

Instructs MMC to remove the sort arrow icon. This option is useful when the snap-in performs a custom sort operation.

### `ulReserved`

Reserved for future use.

## See also

[CCF_COLUMN_SET_ID](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/ccf-column-set-id)

[MMC_SORT_SET_DATA](https://learn.microsoft.com/windows/desktop/api/mmc/ns-mmc-mmc_sort_set_data)

[Using Column Persistence](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/using-column-persistence)