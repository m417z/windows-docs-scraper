# CommitMode enumeration

## Description

Defines the action to take when committing changes to the data collector set.

## Constants

### `plaCreateNew:0x1`

Save the set. The set must not already exist.

The set is not saved if it is a trace session.

### `plaModify:0x2`

Update a previously saved set.

### `plaCreateOrModify:0x3`

Save the set. If the set already exists, update the set.

The set is not saved if it is a trace session.

### `plaUpdateRunningInstance:0x10`

Apply the updated property values to the currently running data set.

### `plaFlushTrace:0x20`

Flush the buffers for an Event Tracing for Windows trace session. This action applies only to sets that contain trace data collectors.

### `plaValidateOnly:0x1000`

Perform validation only on the set.

## Remarks

All commit modes validate the set.

## See also

[IDataCollectorSet::Commit](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorset-commit)