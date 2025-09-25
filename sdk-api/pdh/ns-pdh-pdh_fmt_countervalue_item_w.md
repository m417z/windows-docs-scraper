# PDH_FMT_COUNTERVALUE_ITEM_W structure

## Description

The
**PDH_FMT_COUNTERVALUE_ITEM** structure contains the instance name and formatted value of a counter.

## Members

### `szName`

Pointer to a null-terminated string that specifies the instance name of the counter. The string is appended to the end of this structure.

### `FmtValue`

 A [PDH_FMT_COUNTERVALUE](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_fmt_countervalue) structure that contains the counter value of the instance.

## See also

[PDH_FMT_COUNTERVALUE](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_fmt_countervalue)

[PdhGetFormattedCounterArray](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetformattedcounterarraya)