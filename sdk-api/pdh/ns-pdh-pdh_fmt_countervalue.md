# PDH_FMT_COUNTERVALUE structure

## Description

The
**PDH_FMT_COUNTERVALUE** structure contains the computed value of the counter and its status.

## Members

### `CStatus`

Counter status that indicates if the counter value is valid. Check this member before using the data in a calculation or displaying its value. For a list of possible values, see
[Checking PDH Interface Return Values](https://learn.microsoft.com/windows/desktop/PerfCtrs/checking-pdh-interface-return-values).

### `longValue`

The computed counter value as a **LONG**.

### `doubleValue`

The computed counter value as a **DOUBLE**.

### `largeValue`

The computed counter value as a **LONGLONG**.

### `AnsiStringValue`

The computed counter value as a **LPCSTR**. Not supported.

### `WideStringValue`

The computed counter value as a **LPCWSTR**. Not supported.

## Remarks

You specify the data type of the computed counter value when you call [PdhGetFormattedCounterValue](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetformattedcountervalue) or [PdhCalculateCounterFromRawValue](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhcalculatecounterfromrawvalue) to compute the counter's value.

## See also

[PdhCalculateCounterFromRawValue](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhcalculatecounterfromrawvalue)

[PdhGetFormattedCounterValue](https://learn.microsoft.com/windows/desktop/api/pdh/nf-pdh-pdhgetformattedcountervalue)