# ComponentStatistics structure

## Description

Represents statistical information about a COM+ component hosted in a particular process.

## Members

### `NumInstances`

The number of instances of the component in the hosting process.

### `NumBoundReferences`

The number of client references bound to an instance of this component.

### `NumPooledObjects`

The number of instances of the component in the hosting process's object pool.

### `NumObjectsInCall`

The number of instances of the component that are currently servicing a call.

### `AvgResponseTimeInMs`

A rolling average of the time it takes an instance of this component to service a call.

### `NumCallsCompletedRecent`

The number of calls to instances of this component that have completed (successfully or not) in a recent time period (for comparison with **NumCallsFailedRecent**).

### `NumCallsFailedRecent`

The number of calls to instances of this component that have failed in a recent time period (for comparison with **NumCallsCompletedRecent**).

### `NumCallsCompletedTotal`

The total number of calls to instances of this component that have completed (successfully or not) throughout the lifetime of the hosting process. This data is not currently available, and this member is always set to DATA_NOT_AVAILABLE (0xFFFFFFFF).

### `NumCallsFailedTotal`

The total number of calls to instances of this component that have failed throughout the lifetime of the hosting process. This data is not currently available, and this member is always set to DATA_NOT_AVAILABLE (0xFFFFFFFF).

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