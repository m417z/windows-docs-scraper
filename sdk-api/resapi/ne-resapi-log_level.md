# LOG_LEVEL enumeration

## Description

Represents the severity of the log event passed to the
[LogEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-plog_event_routine) callback function.

## Constants

### `LOG_INFORMATION`

The event is informational.

### `LOG_WARNING`

The event is reporting a failure that might have happened, but it is uncertain whether a failure really did
occur.

### `LOG_ERROR`

The event affects a single component, but other components are not affected and the integrity of the rest
of the [node](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes) is not compromised.

### `LOG_SEVERE`

The event is reporting a severe failure that affects multiple components, or the integrity of the entire
system is compromised or believed to be compromised.

## See also

[Failover Cluster Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-enumerations)

[LogEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-plog_event_routine)