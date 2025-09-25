# MI_Datetime structure

## Description

Represents a union of [MI_Timestamp](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_timestamp) and [MI_Interval](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_interval).

## Members

### `isTimestamp`

If **isTimestamp** is nonzero, timestamp is used. If **isTimestamp** is 0, interval is used.

### `u`

### `u.timestamp`

If **isTimestamp** is nonzero, **MI_Datetime** is used to represent an absolute date/time.

### `u.interval`

If **isTimestamp** is nonzero, **MI_Datetime** is used to represent a relative date/time from when it is needed.