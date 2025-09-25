# WSB_OB_STATUS_ENTRY_PAIR_TYPE enumeration

## Description

The **WSB_OB_STATUS_ENTRY_PAIR_TYPE** enumeration indicates the type of the parameter value contained in the [WSB_OB_STATUS_ENTRY_VALUE_TYPE_PAIR](https://learn.microsoft.com/windows/win32/api/wsbonline/ns-wsbonline-wsb_ob_status_entry_value_type_pair) structure.

## Constants

### `WSB_OB_ET_UNDEFINED:0`

The value type is undefined.

### `WSB_OB_ET_STRING:1`

The value type is string.

### `WSB_OB_ET_NUMBER:2`

The value type is integer.

### `WSB_OB_ET_DATETIME:3`

The value type is datetime which represents an instant in time, typically expressed as a date and time of day. All time-related values are specified in Coordinated Universal Time (UTC) format.

### `WSB_OB_ET_TIME:4`

The value type is time. All time-related values are specified in UTC format.

### `WSB_OB_ET_SIZE:5`

The value type is size.

### `WSB_OB_ET_MAX:6`

The maximum enumeration value for this enumeration.

## See also

[Cloud Backup Provider API Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/wsb/windows-server-backup-api-enumerations)