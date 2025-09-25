## Description

Specifies the state of the query associated with a [DEV_QUERY_RESULT_ACTION_DATA](https://learn.microsoft.com/windows/win32/api/devquerydef/ns-devquerydef-dev_query_result_action_data) structure.

## Constants

### `DevQueryStateInitialized`

The initial state of a query.

### `DevQueryStateEnumCompleted`

The initial enumeration of objects based on the current state of the system is complete. If [DevQueryFlagUpdateResults](https://learn.microsoft.com/windows/win32/api/devquerydef/ne-devquerydef-dev_query_flags) was specified during query creation, then further callbacks may happen as the state of the system changes. However, if **DevQueryFlagUpdateResults** was not specified during query creation, then this is the last callback, except for **DevQueryStateClosed** if [DevQueryFlagAsyncClose](https://learn.microsoft.com/windows/win32/api/devquerydef/e-devquerydef-dev_query_flags) was specified during query creation.

### `DevQueryStateAborted`

An out-of-resource error has occurred, and a notification could not be delivered. No further callbacks will occur. The client must close the query and create a new query to recover from this situation.

### `DevQueryStateClosed`

This state change only occurs when **DevQueryFlagAsyncClose** is specified during query creation. It indicates that closing the query has been completed. No further callbacks will occur.

## Remarks

## See also