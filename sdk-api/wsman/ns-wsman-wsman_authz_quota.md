# WSMAN_AUTHZ_QUOTA structure

## Description

Reports quota information on a per-user basis for authorization plug-ins.

## Members

### `maxAllowedConcurrentShells`

Specifies the maximum number of concurrent shells that a user is allowed to create.

### `maxAllowedConcurrentOperations`

Specifies the maximum number of concurrent operations that a user is allowed to perform. Only top-level operations are counted. Simple operations such as get, put, and delete are counted as one operation each. More complex operations are also counted as one. For example, the enumeration operation and any associated operations that are related to enumeration are counted as one operation.

### `timeslotSize`

Time-slot length for determining the maximum number of operations per time slot. This value is specified in units of seconds.

### `maxAllowedOperationsPerTimeslot`

Specifies the maximum number of operations allowed per time slot. This value is used to throttle both top-level and follow-on operations.