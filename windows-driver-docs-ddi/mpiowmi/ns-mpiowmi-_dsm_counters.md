# _DSM_COUNTERS structure

## Description

The DSM_COUNTERS structure holds the various timer counters that are applicable to all LUNs that are controlled by the DSM.

## Members

### `PathVerifyEnabled`

An unsigned 32-bitfield that is used as a flag. This field indicates if path verification must be performed by MPIO periodically on all paths that expose devices that are controlled by this particular DSM.

### `PathVerificationPeriod`

An unsigned 32-bitfield that is used to indicate the periodicity (in seconds) with which MPIO has been requested to perform path verification. This field is only honored if *PathVerifyEnabled* is **TRUE**.

### `PDORemovePeriod`

An unsigned 32-bitfield that controls the amount of time (in seconds) that the pseudo-LUN will continue to remain in system memory, even after losing all its path information.

### `RetryCount`

An unsigned 32-bitfield that specifies the number of times a failed I/O will be retried.

### `RetryInterval`

An unsigned 32-bitfield that specifies the interval of time (in seconds) after which a failed request is retried.

### `Reserved32`

Should be zero.

### `Reserved64`

Should be zero.