# ApplicationProcessStatistics structure

## Description

Represents statistical information about a process hosting COM+ applications.

## Members

### `NumCallsOutstanding`

The number of calls currently outstanding in tracked components in the process.

### `NumTrackedComponents`

The number of distinct tracked components instantiated in the process.

### `NumComponentInstances`

The number of component instances in the process.

### `AvgCallsPerSecond`

A rolling average of the number of calls this process is servicing per second.

### `Reserved1`

This member is reserved and set to DATA_NOT_AVAILABLE (0xFFFFFFFF).

### `Reserved2`

This member is reserved and set to DATA_NOT_AVAILABLE (0xFFFFFFFF).

### `Reserved3`

This member is reserved and set to DATA_NOT_AVAILABLE (0xFFFFFFFF).

### `Reserved4`

This member is reserved and set to DATA_NOT_AVAILABLE (0xFFFFFFFF).

## See also

[IGetAppTrackerData](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-igetapptrackerdata)