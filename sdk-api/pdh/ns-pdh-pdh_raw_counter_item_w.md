# PDH_RAW_COUNTER_ITEM_W structure

## Description

The
**PDH_RAW_COUNTER_ITEM** structure contains the instance name and raw value of a counter.

## Members

### `szName`

Pointer to a null-terminated string that specifies the instance name of the counter. The string is appended to the end of this structure.

### `RawValue`

 A [PDH_RAW_COUNTER](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_raw_counter) structure that contains the raw counter value of the instance.

## See also

[PDH_RAW_COUNTER](https://learn.microsoft.com/windows/desktop/api/pdh/ns-pdh-pdh_raw_counter)

[PdhGetRawCounterArray](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetrawcounterarraya)