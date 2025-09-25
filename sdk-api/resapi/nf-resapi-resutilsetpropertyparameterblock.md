# ResUtilSetPropertyParameterBlock function

## Description

Sets properties in the [cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database) from a [parameter block](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/parameter-blocks).

## Parameters

### `hkeyClusterKey` [in]

Cluster database key identifying the location for the properties to set.

### `pPropertyTable` [in]

Pointer to an array of [RESUTIL_PROPERTY_ITEM](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-resutil_property_item) structures describing the properties to set.

### `Reserved` [in]

Reserved.

### `pInParams` [in]

Pointer to an input parameter block containing the data for the properties described in the [property table](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/property-tables) pointed to by *pPropertyTable*.

### `pInPropertyList` [in]

Pointer to the input buffer containing a [property list](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/property-lists) or **NULL**. If *pInPropertyList* is not **NULL**, any properties listed in the property list that are not listed in the property table are also set in the cluster database.

### `cbInPropertyListSize` [in]

Size in bytes of the input buffer pointed to by *pInPropertyList*.

### `pOutParams` [out, optional]

Pointer to a parameter block to receive data copied from the *pInParams* parameter.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following are possible error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The syntax, format, or type of a property in the property table pointed to by *pPropertyTable* is incorrect, or a property is read-only and cannot be updated. |
| **ERROR_BAD_ARGUMENTS** | One or more of the input parameters were invalid. |

## Remarks

If a value specified in the parameter block already exists in the cluster database, the value is not written. To force all values to be written, see [ResUtilSetPropertyParameterBlockEx](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilsetpropertyparameterblockex).

Do not call **ResUtilSetPropertyParameterBlock** from the following resource DLL entry point functions:

* [Close](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pclose_routine)
* [Offline](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-poffline_routine)
* [Online](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-ponline_routine)
* [Open](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-popen_routine)
* [Terminate](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pterminate_routine)

**ResUtilSetPropertyParameterBlock** can be safely called from any other resource DLL entry point function or from a worker thread. For more information, see [Function Calls to Avoid in Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/function-calls-to-avoid-in-resource-dlls).

## See also

[RESUTIL_PROPERTY_ITEM](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-resutil_property_item)