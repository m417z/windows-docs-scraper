# ENG_TIME_FIELDS structure

## Description

The ENG_TIME_FIELDS structure is used by the [EngQueryLocalTime](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engquerylocaltime) function to return the local time.

## Members

### `usYear`

Specifies the current calendar year. The range is [1601,...].

### `usMonth`

Specifies the current calendar month. The range is [1,12].

### `usDay`

Specifies the current calendar day. The range is [1,31].

### `usHour`

Specifies the current hour. The range is [0,23].

### `usMinute`

Specifies the current minute. The range is [0,59].

### `usSecond`

Specifies the current second. The range is [0,59].

### `usMilliseconds`

Specifies the current millisecond. The range is [0,999].

### `usWeekday`

Specifies the current day. The range is [0,6], where 0 is Sunday and 6 is Saturday.

## Remarks

The driver is responsible for allocating the ENG_TIME_FIELDS structure and passing its pointer to **EngQueryLocalTime**.

## See also

[EngQueryLocalTime](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-engquerylocaltime)