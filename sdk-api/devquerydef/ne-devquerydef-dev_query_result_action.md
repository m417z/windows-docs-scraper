## Description

Specifies the type of action associated with a [DEV_QUERY_RESULT_ACTION_DATA](https://learn.microsoft.com/windows/win32/api/devquerydef/ns-devquerydef-dev_query_result_action_data) structure.

## Constants

### `DevQueryResultStateChange`

The state of the query has changed. The *State* member of the **DEV_QUERY_RESULT_ACTION_DATA** structure contains the new state.

### `DevQueryResultAdd`

The object specified in *DeviceObject* member of the **DEV_QUERY_RESULT_ACTION_DATA** structure has been added to the client's result-set.

### `DevQueryResultUpdate`

The object specified in *DeviceObject* member of the **DEV_QUERY_RESULT_ACTION_DATA** structure has changed.

### `DevQueryResultRemove`

The object specified in *DeviceObject* member of the **DEV_QUERY_RESULT_ACTION_DATA** structure has been removed from the client's result-set.

## Remarks

## See also