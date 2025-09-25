# REPAIR_STATUS enumeration

## Description

The **REPAIR_STATUS** enumeration describes the result of a helper class attempting a repair option.

## Constants

### `RS_NOT_IMPLEMENTED:0`

The helper class does not have a repair option implemented.

### `RS_REPAIRED`

The helper class has repaired a problem.

### `RS_UNREPAIRED`

The helper class has attempted to repair a problem but validation indicates the repair operation has not succeeded.

### `RS_DEFERRED`

The helper class is unable to perform the repair at this time.

### `RS_USER_ACTION`

The helper class needs the user to perform an action before the repair can continue.