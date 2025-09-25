# _MPIO_TIMERS_COUNTERS structure

## Description

The MPIO_TIMERS_COUNTERS structure controls the timer counters that affect all devices whose controlling DSMs do not implement independent timer counter settings. To query or set the global counters, the request must be directed to the MPIO control object by using its WMI instance name.

## Members

### `PathVerifyEnabled`

An unsigned 32-bitfield that is used as a flag. This field indicates whether path verification must be performed by MPIO on all paths periodically.

### `PathVerificationPeriod`

An unsigned 32-bitfield that is used to indicate the periodicity (in seconds) with which MPIO has been requested to perform path verification. This field is valid if *PathVerifyEnabled* is **TRUE**.

### `PDORemovePeriod`

An unsigned 32-bitfield that controls the amount of time (in seconds) that the pseudo-LUN remains in system memory, even after losing all its path information.

### `RetryCount`

An unsigned 32-bitfield that specifies the number of times a failed I/O can be retried.

### `RetryInterval`

An unsigned 32-bitfield that specifies the interval of time (in seconds) after which a failed request is retried.