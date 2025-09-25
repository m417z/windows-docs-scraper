# MI_Interval structure

## Description

**MI_Interval** represents an interval of time.

## Members

### `days`

The number of days in the interval. (0-99999999)

### `hours`

The remaining number of hours in the interval. (0-23)

### `minutes`

The remaining number of minutes in the interval. (0-59)

### `seconds`

The remaining number of seconds in the interval. (0-59)

### `microseconds`

The remaining number of microseconds in the interval. (0-999999)

### `__padding1`

Reserved. The **MI_Interval** structure is padded to have the same size as [MI_Timestamp](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_timestamp).

### `__padding2`

Reserved. The **MI_Interval** structure is padded to have the same size as [MI_Timestamp](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_timestamp).

### `__padding3`

Reserved. The **MI_Interval** structure is padded to have the same size as [MI_Timestamp](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_timestamp).