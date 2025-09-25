# ResUtilSetUnknownProperties function

## Description

Stores a [cluster object's](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-objects) unknown properties in the [cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database).

## Parameters

### `hkeyClusterKey` [in]

[Cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database) key identifying the location of the properties to set.

### `pPropertyTable` [in]

Pointer to a [property table](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/property-tables) specifying properties that should NOT be set by this function.

### `pInPropertyList` [in]

Pointer to a [property list](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/property-lists). Any properties that appear in this list and that do NOT appear in *pInPropertyList* are set.

### `cbInPropertyListSize` [in]

Pointer to the size in bytes of the input buffer pointed to by *pInPropertyList*.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

**ResUtilSetUnknownProperties** only sets the properties listed in *pInPropertyList* that are NOT listed in *pPropertyTable*.

Use the [ResUtilAddUnknownProperties](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutiladdunknownproperties) to create the property list and [ResUtilGetAllProperties](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetallproperties) to retrieve [unknown properties](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/unknown-properties).

Do not call **ResUtilSetUnknownProperties** from the following resource DLL entry point functions:

* [Close](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pclose_routine)
* [Offline](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-poffline_routine)
* [Online](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-ponline_routine)
* [Open](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-popen_routine)
* [Terminate](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pterminate_routine)

**ResUtilSetUnknownProperties** can be safely called from any other resource DLL entry point function or from a worker thread. For more information, see [Function Calls to Avoid in Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/function-calls-to-avoid-in-resource-dlls).

## See also

[ResUtilAddUnknownProperties](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutiladdunknownproperties)

[ResUtilGetAllProperties](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetallproperties)