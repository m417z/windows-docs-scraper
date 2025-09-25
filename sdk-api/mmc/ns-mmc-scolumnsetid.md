# SColumnSetID structure

## Description

The
**SColumnSetID** structure is introduced in MMC 1.2.

The
**SColumnSetID** structure is used by the
[CCF_COLUMN_SET_ID](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/ccf-column-set-id) clipboard format.

The
**SColumnSetID** structure contains an array of bytes that represent the node ID.

## Members

### `dwFlags`

Reserved for future use. Must be 0.

### `cBytes`

The count of bytes in the **id** array.

### `id`

The bytes that contains the column set ID.

## Remarks

For details on using the
**SColumnSetID** structure with the CCF_COLUMN_SET_ID clipboard format, see
[CCF_COLUMN_SET_ID](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/ccf-column-set-id).

## See also

[CCF_COLUMN_SET_ID](https://learn.microsoft.com/previous-versions/windows/desktop/mmc/ccf-column-set-id)