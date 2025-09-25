## Description

Creates a device query to retrieve properties based on the specified query parameters and extended parameters.

## Parameters

### `ObjectType` [in]

A value from the [DEV_OBJECT_TYPE](https://learn.microsoft.com/windows/win32/api/devquerydef/ne-devquerydef-dev_object_type) enumeration that determines the object type that this query should operate on.

### `QueryFlags` [in]

A combination of [DEV_QUERY_FLAGS](https://learn.microsoft.com/windows/win32/api/devquerydef/ne-devquerydef-dev_query_flags) values that are combined by using a bitwise OR operation.

### `cRequestedProperties` [in]

The number of [DEVPROPCOMPKEY](https://learn.microsoft.com/windows-hardware/drivers/install/devpropcompkey) structures provided in *pRequestedProperties*. If [DevQueryFlagAllProperties](https://learn.microsoft.com/windows/win32/api/devquerydef/ne-devquerydef-dev_query_flags) is specified, this must be set to 0.

### `pRequestedProperties` [in]

Optionally provides an array of **DEVPROPCOMPKEY** structures that specify the properties that should be retrieved for objects in the
query’s result set when *pCallback* is called to notify the query of an addition of an object to its result set.
If [DevQueryFlagUpdateResults](https://learn.microsoft.com/windows/win32/api/devquerydef/ne-devquerydef-dev_query_flags) was specified in *QueryFlags*, the query will be notified
if the value of any of these properties changes for any object in the query’s result set.

The *LocaleName* field of the **DEVPROPCOMPKEY** structure is ignored and must be set to NULL.

If *cRequestedProperties* is 0, this must be NULL.

### `cFilterExpressionCount` [in]

The number of [DEVPROP_FILTER_EXPRESSION](https://learn.microsoft.com/windows/win32/api/devfiltertypes/ns-devfiltertypes-devprop_filter_expression) structures provided in *pFilter*.

### `pFilter` [in, optional]

Optionally provides an array of **DEVPROP_FILTER_EXPRESSION** structures that specify filter criteria for what objects should be part
of the query’s result set. If *cFilterExpressionCount* is 0, this must be NULL.

### `cExtendedParameterCount` [in]

Reserved for system usage. Must be set to 0.

### `pExtendedParameters` [in, optional]

Reserved for system usage. Must be set to NULL.

### `pCallback` [in]

A [PDEV_QUERY_RESULT_CALLBACK](https://learn.microsoft.com/windows/win32/api/devquery/nc-devquery-pdev_query_result_callback) callback function that results for this query should be sent to.

### `pContext` [in, optional]

Caller-supplied context. This value is passed to the callback function unmodified.

### `phDevQuery` [out]

Pointer that receives the handle representing the query. If **DevQueryFlagsUpdateResults** is specified, then the query will receive
updates until the handle is closed. Call [DevCloseObjectQuery](https://learn.microsoft.com/windows/win32/api/devquery/nf-devquery-devcloseobjectquery) to close this handle to stop the query.

## Return value

S_OK is returned if a query was successfully created; otherwise, an appropriate error value.

## Remarks

For more information, see the remarks and examples sections of [DevCreateObjectQuery](https://learn.microsoft.com/windows/win32/api/devquery/nf-devquery-devcreateobjectquery), which also
apply to this function.

## See also

[DevCreateObjectQuery](https://learn.microsoft.com/windows/win32/api/devquery/nf-devquery-devcreateobjectquery)