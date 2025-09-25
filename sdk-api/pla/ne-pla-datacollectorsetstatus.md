# DataCollectorSetStatus enumeration

## Description

Defines the running status of the data collector set.

## Constants

### `plaStopped:0`

The data collector set is not running.

### `plaRunning:1`

The data collector set is running.

### `plaCompiling:2`

The data collector set is performing data management. A running data collector set will transition from **plaRunning** to **plaCompiling** if the data manager is enabled.

### `plaPending:3`

The data collector has been set to run, but the service has not started it yet. Only computers that run operating systems prior to Windows Vista report this status.

### `plaUndefined:4`

Cannot determine the status but no error has occurred. Typically, this status is set for autologgers.

## See also

[IDataCollectorSet::Status](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-get_status)