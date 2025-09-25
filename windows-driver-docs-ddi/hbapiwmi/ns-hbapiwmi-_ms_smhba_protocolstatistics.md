# _MS_SMHBA_PROTOCOLSTATISTICS structure

## Description

The MS_SMHBA_PROTOCOLSTATISTICS structure is used to report protocol traffic statistics on a port.

## Members

### `SecondsSinceLastReset`

The number of seconds since the statistics were last reset.

### `InputRequests`

The number of input requests.

### `OutputRequests`

The number of output requests.

### `ControlRequests`

The number of control requests.

### `InputMegabytes`

The number of megabytes of data that has been input.

### `OutputMegabytes`

The number of megabytes of data that has been output.

## Remarks

The statistics counters whose values are reported in the members of this structure are 64-bit signed integers that wrap to zero on exceeding 2**63-1. The statistics counters are not reset during normal operation. Therefore, traffic rates can be determined by the difference of counter values that are derived from two successive calls, with appropriate adjustments made for counter wrap. If an HBA does not support a specific statistic, it returns the value of -1 for the corresponding counter.