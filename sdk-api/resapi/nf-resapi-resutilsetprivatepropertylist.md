# ResUtilSetPrivatePropertyList function

## Description

Sets the [private properties](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/private-properties) of a [cluster object](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-objects).

## Parameters

### `hkeyClusterKey` [in]

[Cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database) key identifying the location of the properties to set.

### `pInPropertyList` [in]

Pointer to an input buffer containing a [property list](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/property-lists) with the names and values of the properties to set.

### `cbInPropertyListSize` [in]

Pointer to the size in bytes of the input buffer pointed to by *pInPropertyList*.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following are possible error codes.

| Return code | Description |
| --- | --- |
| **ERROR_BAD_ARGUMENTS** | One or more of the input parameters were invalid. |
| **ERROR_INVALID_DATA** | There was a problem with the length of a property's data. |
| **ERROR_INSUFFICIENT_BUFFER** | The input buffer pointed to by *pInPropertyList* was NULL. |
| **ERROR_INVALID_PARAMETER** | The syntax of a property name was invalid. |

## Remarks

The properties that are set in the **ResUtilSetPrivatePropertyList** utility function are placed in the portion of the cluster database below the specified key for the object exactly as specified by the names in the property list. If the name of a property contains backslash characters (\\), each string preceding a backslash character is interpreted as a subkey name, and the last string following the last backslash character is interpreted as the value name.

Do not call **ResUtilSetPrivatePropertyList** from the following resource DLL entry point functions:

* [Close](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pclose_routine)
* [Offline](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-poffline_routine)
* [Online](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-ponline_routine)
* [Open](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-popen_routine)
* [Terminate](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pterminate_routine)

**ResUtilSetPrivatePropertyList** can be safely called from any other resource DLL entry point function or from a worker thread. For more information, see [Function Calls to Avoid in Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/function-calls-to-avoid-in-resource-dlls).

## See also

[ResUtilVerifyPrivatePropertyList](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilverifyprivatepropertylist)