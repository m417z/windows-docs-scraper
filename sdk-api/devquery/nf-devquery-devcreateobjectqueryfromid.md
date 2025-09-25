## Description

Creates a device query to retrieve properties based on the specified query parameters and object ID.

## Parameters

### `ObjectType` [in]

A value from the [DEV_OBJECT_TYPE](https://learn.microsoft.com/windows/win32/api/devquerydef/ne-devquerydef-dev_object_type) enumeration that determines the object type that this query should operate on.

### `pszObjectId` [in]

The string identifier for the object the query should operate on.

### `QueryFlags` [in]

A combination of [DEV_QUERY_FLAGS](https://learn.microsoft.com/windows/win32/api/devquerydef/ne-devquerydef-dev_query_flags) values that are combined by using a bitwise OR operation.

### `cRequestedProperties` [in]

The number of [DEVPROPCOMPKEY](https://learn.microsoft.com/windows-hardware/drivers/install/devpropcompkey) structures provided in *pRequestedProperties*. If [DevQueryFlagAllProperties](https://learn.microsoft.com/windows/win32/api/devquerydef/ne-devquerydef-dev_query_flags) is specified, this must be set to 0.

### `pRequestedProperties` [in, optional]

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

When a client wants to retrieve data about a specific object given its identity, use this function rather than [DevCreateObjectQuery](https://learn.microsoft.com/windows/win32/api/devquery/nf-devquery-devcreateobjectquery) with a filter. This function is more efficient.

For more information, see the remarks section of [DevCreateObjectQuery](https://learn.microsoft.com/windows/win32/api/devquery/nf-devquery-devcreateobjectquery), which also
apply to this function.

## Examples

In the following example, the **PDEV_QUERY_RESULT_CALLBACK** method is implemented to print out status messages when the query state changes, when items have been added to, updated, or removed from the query result. Next, a simple query scenario is implemented where **DevCreateObjectQueryFromId** is called with the object ID specified by the variable **InterfacePath**.

```cpp
void WINAPI
Example1Callback(
    HDEVQUERY hDevQuery,
    PVOID pContext,
    const DEV_QUERY_RESULT_ACTION_DATA *pActionData
    )
{
    UNREFERENCED_PARAMETER(hDevQuery);
    UNREFERENCED_PARAMETER(pContext);

    switch (pActionData->Action)
    {
    case DevQueryResultStateChange:
        if (pActionData->Data.State == DevQueryStateEnumCompleted)
        {
            wprintf(L"Enumeration of current system state complete.\n");
        }
        else if (pActionData->Data.State == DevQueryStateAborted)
        {
            wprintf(L"Query has aborted. No further results will be received.\n");
            // Communicate back to the creator of the query that it has aborted
            // so it can handle that appropriately, such as by recreating the
            // query
        }
        break;

    case DevQueryResultAdd:
        wprintf(L"Object '%ws' has been added to the result set.\n",
                pActionData->Data.DeviceObject.pszObjectId);
        break;

    case DevQueryResultUpdate:
        wprintf(L"Object '%ws' was updated.\n",
                pActionData->Data.DeviceObject.pszObjectId);
        break;

    case DevQueryResultRemove:
        wprintf(L"Object '%ws' has been removed from the result set.\n",
                pActionData->Data.DeviceObject.pszObjectId);
        break;
    }
}

void
Example1(PCWSTR InterfacePath)
{
    DEVPROPCOMPKEY RequestedProperties[] =
    {
        { DEVPKEY_DeviceInterface_Enabled, DEVPROP_STORE_SYSTEM, NULL },
        { DEVPKEY_DeviceInterface_FriendlyName, DEVPROP_STORE_SYSTEM, NULL }
    };

    HDEVQUERY hDevQuery = NULL;
    HRESULT hr = DevCreateObjectQueryFromId(DevObjectTypeDeviceInterface,
                                            InterfacePath,
                                            DevQueryFlagUpdateResults,
                                            RTL_NUMBER_OF(RequestedProperties),
                                            RequestedProperties,
                                            0,
                                            NULL,
                                            Example1Callback,
                                            NULL,
                                            &hDevQuery);

    if (FAILED(hr))
    {
        wprintf(L"Failed to create query. hr = 0x%08x\n", hr);
        goto exit;
    }

    // do other work while the query monitors system state in the background

  exit:

    if (hDevQuery != NULL)
    {
        DevCloseObjectQuery(hDevQuery);
    }

    return;
}

```

## See also

[DevCreateObjectQuery](https://learn.microsoft.com/windows/win32/api/devquery/nf-devquery-devcreateobjectquery)