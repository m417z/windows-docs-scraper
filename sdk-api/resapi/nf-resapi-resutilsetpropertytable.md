# ResUtilSetPropertyTable function

## Description

Sets properties in the
[cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database) based on a
[property list](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/property-lists) from a
[property table.](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/property-tables).

## Parameters

### `hkeyClusterKey` [in]

Cluster database key identifying the location of the properties to set.

### `pPropertyTable` [in]

Pointer to an array of
[RESUTIL_PROPERTY_ITEM](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-resutil_property_item) structures describing the
properties to set.

### `Reserved`

Reserved.

### `bAllowUnknownProperties` [in]

Indicates whether [unknown properties](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/unknown-properties) should be
accepted. This parameter is set to **TRUE** if they should be accepted, and
**FALSE** if not.

### `pInPropertyList` [in]

Pointer to the input buffer containing a property list.

### `cbInPropertyListSize` [in]

Size in bytes of the input buffer pointed to by *cbInPropertyList*.

### `pOutParams` [out, optional]

Pointer to a [parameter block](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/parameter-blocks) to hold returned data.
If specified, parameters are only written if they differ from those in the input buffer.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails, the function returns a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following are possible error
codes.

| Return code | Description |
| --- | --- |
| **ERROR_BAD_ARGUMENTS** | One or more of the input parameters were invalid. |
| **ERROR_INSUFFICIENT_BUFFER** | The size of the input buffer specified in *cbInPropertyListSize* is too small. |
| **ERROR_INVALID_DATA** | The input buffer pointed to by *pInPropertyList* is **NULL**, a property name is not valid, or a property value is too small. |
| **ERROR_INVALID_PARAMETER** | The syntax, format, or type of a property in the property table pointed to by *pPropertyTable* is incorrect, or a property is [read-only](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/read-only-properties) and cannot be set. |

## Remarks

If a value specified in the property table already exists in the cluster database, the value is not written.
For information on forcing all values to be written, see
[ResUtilSetPropertyTableEx](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilsetpropertytableex).

Do not call **ResUtilSetPropertyTable** from the following resource DLL entry
point functions.

* [Close](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pclose_routine)
* [Offline](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-poffline_routine)
* [Online](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-ponline_routine)
* [Open](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-popen_routine)
* [Terminate](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pterminate_routine)

**ResUtilSetPropertyTable** can be safely called from any other resource DLL
entry point function or from a worker thread. For more information, see
[Function Calls to Avoid in Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/function-calls-to-avoid-in-resource-dlls).

## See also

[RESUTIL_PROPERTY_ITEM](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-resutil_property_item)

[ResUtilSetPropertyTableEx](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilsetpropertytableex)