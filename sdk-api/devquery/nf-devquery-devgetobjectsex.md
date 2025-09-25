## Description

Synchronously retrieves a set of [DEV_OBJECT](https://learn.microsoft.com/windows/win32/api/devquerydef/ns-devquerydef-dev_object) structures based on the supplied requested properties, extended parameters, and filter criteria.

## Parameters

### `ObjectType` [in]

A value from the [DEV_OBJECT_TYPE](https://learn.microsoft.com/windows/win32/api/devquerydef/ne-devquerydef-dev_object_type) enumeration that determines the object type that this query should operate on.

### `QueryFlags` [in]

A combination of [DEV_QUERY_FLAGS](https://learn.microsoft.com/windows/win32/api/devquerydef/ne-devquerydef-dev_query_flags) values that are combined by using a bitwise OR operation. It is not valid to pass either **DevQueryFlagUpdateResults** or **DevQueryFlagAsyncClose** to this function.

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

### `cExtendedParameterCount` [in]

Reserved for system usage. Must be set to 0.

### `pExtendedParameters` [in, optional]

Reserved for system usage. Must be set to NULL.

### `pcObjectCount` [out]

The number of **DEV_OBJECT** structures returned in ppObjects.

### `ppObjects` [out]

Pointer that receives the newly allocated array of **DEV_OBJECT** results. Callers must free the pointer using [DevFreeObjects](https://learn.microsoft.com/windows/win32/api/devquery/nf-devquery-devfreeobjects). If no objects are enumerated, NULL will be returned.

## Return value

S_OK is returned if the function successfully evaluated the search criteria and returned matching objects; otherwise, an appropriate error value.

## Remarks

This function is an efficient way to synchronously enumerate objects while retrieving their properties. The array of objects that are returned must be freed using **DevFreeObjects**. If a requested property does not exist for an object that meets the filter criteria, then the **DEVPROPERTY** entry in the **DEV_OBJECT** for that property will have a type of [DEVPROP_TYPE_EMPTY](https://learn.microsoft.com/windows-hardware/drivers/install/devprop-type-empty).

Before using this function, consider how much data may be returned in the array and how long the call can block. It may be better to use the [DevCreateObjectQueryEx](https://learn.microsoft.com/windows/win32/api/devquery/nf-devquery-devcreateobjectqueryex) function, which allows the data to be consumed piecemeal and asynchronously.

The following example demonstrates the usage of **DevGetObjectsEx** to retrieve the set of **DEV_OBJECT** that matches a set of **DEVPROP_FILTER_EXPRESSION** structures.

```cpp
void
Example1()
{
    HRESULT hr = S_OK;
    ULONG ObjectCount = 0;
    const DEV_OBJECT* ObjectList = NULL;
    DEVPROP_BOOLEAN DevPropTrue = DEVPROP_TRUE;
    DEVPROPCOMPKEY RequestedProperties[] =
    {
        { DEVPKEY_Device_InstanceId, DEVPROP_STORE_SYSTEM, NULL }
    };
    DEVPROP_FILTER_EXPRESSION ObjectFilter[] =
    {
        {
            DEVPROP_OPERATOR_AND_OPEN, {0}
        },
        {
            DEVPROP_OPERATOR_EQUALS,
            {
                { DEVPKEY_DeviceInterface_Enabled, DEVPROP_STORE_SYSTEM, NULL },
                DEVPROP_TYPE_BOOLEAN,
                sizeof(DevPropTrue),
                (void*)&DevPropTrue
            }
        },
        {
            DEVPROP_OPERATOR_OR_OPEN, {0}
        },
        {
            DEVPROP_OPERATOR_EQUALS,
            {
                { DEVPKEY_DeviceInterface_ClassGuid, DEVPROP_STORE_SYSTEM, NULL },
                DEVPROP_TYPE_GUID,
                sizeof(GUID),
                (void*)&GUID_DEVINTERFACE_MOUSE
            }
        },
        {
            DEVPROP_OPERATOR_EQUALS,
            {
                { DEVPKEY_DeviceInterface_ClassGuid, DEVPROP_STORE_SYSTEM, NULL },
                DEVPROP_TYPE_GUID,
                sizeof(GUID),
                (void*)&GUID_DEVINTERFACE_KEYBOARD
            }
        },
        {
            DEVPROP_OPERATOR_OR_CLOSE, {0}
        },
        {
            DEVPROP_OPERATOR_AND_CLOSE, {0}
        }
    };

    hr = DevGetObjectsEx(DevObjectTypeDeviceInterface,
                         DevQueryFlagNone,
                         RTL_NUMBER_OF(RequestedProperties),
                         RequestedProperties,
                         RTL_NUMBER_OF(ObjectFilter),
                         ObjectFilter,
                         0,
                         NULL,
                         &ObjectCount,
                         &ObjectList);

    if (FAILED(hr))
    {
        wprintf(L"Failed to retrieve objects. hr = 0x%08x\n", hr);
        goto exit;
    }

    for (ULONG i = 0; i < ObjectCount; i++)
    {
        wprintf(L"Retrieved object '%ws'\n",
                ObjectList[i].pszObjectId);
    }

  exit:

    if (ObjectList != NULL)
    {
        DevFreeObjects(ObjectCount, ObjectList);
    }

    return;
}
```

## See also

[DevCreateObjectQuery](https://learn.microsoft.com/windows/win32/api/devquery/nf-devquery-devcreateobjectquery)