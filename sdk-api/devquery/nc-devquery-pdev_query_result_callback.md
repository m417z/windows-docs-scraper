## Description

The function prototype required of callback functions that will receive DevQuery query results.

## Parameters

### `hDevQuery`

Handle for the query associated with the callback.

### `pContext`

The optional context value provided by the client during query creation.

### `pActionData`

A [DEV_QUERY_RESULT_ACTION_DATA](https://learn.microsoft.com/windows/win32/api/devquerydef/ns-devquerydef-dev_query_result_action_data) structure that provides information about the change to the query state or the action applied to the result set. The data in this structure will be freed once the callback returns.

## Remarks

Only one callback function is ever active for a given query. If the same callback function is passed to multiple queries, it is possible for the callback functions to execute concurrently, because they can be invoked for different queries.

You can only call [DevCloseObjectQuery](https://learn.microsoft.com/windows/win32/api/devquery/nf-devquery-devcloseobjectquery) on the *hDevQuery* handle from the callback if the [DevQueryFlagAsyncClose](https://learn.microsoft.com/windows/win32/api/devquerydef/ne-devquerydef-dev_query_flags) flag was specified when the query was created. If **DevQueryFlagAsyncClose** was not specified, calling **DevCloseObjectQuery** on a query from inside its own callback will result in a deadlock.

## See also