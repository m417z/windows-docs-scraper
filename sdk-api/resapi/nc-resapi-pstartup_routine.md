# PSTARTUP_ROUTINE callback function

## Description

Loads a [resource DLL](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dlls), returning a structure
containing a function table and a version number. The **PSTARTUP_ROUTINE**
type defines a pointer to this function.

## Parameters

### `ResourceType` [in]

Type of resource being started.

### `MinVersionSupported` [in]

Minimum version of the [Resource API](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-api) supported by the
[Cluster service](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-service).

### `MaxVersionSupported` [in]

Maximum version of the Resource API supported by the Cluster service.

### `SetResourceStatus` [in]

Pointer to a callback function that the resource DLL should call to update its status after returning
**ERROR_IO_PENDING** from [Online](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-ponline_routine) or
[Offline](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-poffline_routine). For more information see
[SetResourceStatus](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pset_resource_status_routine).

### `LogEvent` [in]

Pointer to a callback function that the resource DLL should call to report events for the
[resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources). For more information see
[LogEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-plog_event_routine).

### `FunctionTable` [out]

Pointer to a [CLRES_FUNCTION_TABLE](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-clres_function_table) structure
that describes the Resource API version and the specific names for the entry points.

## Return value

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The request was successful. |
| **ERROR_REVISION_MISMATCH**<br><br>1306 (0x51A) | The resource DLL does not support a version that falls in the range identified by the *MinVersionSupported* and *MaxVersionSupported* parameters. |

If the operation was not successful, *Startup* should
return one of the [system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The *Startup* entry-point function returns a function table
that describes both the supported interface version of the Resource API and the entry points for all other
functions required by the supported version of the Resource API.

At present, only Resource API version 1.0 is supported.

If your resource supports more than one version of the Resource API, return a function table for the latest
version. The version number should be less than or equal to the *MaxVersionSupported*
parameter. If the version of the function table pointed to by the *FunctionTable*
parameter is not within range, your resource cannot be loaded successfully.

For more information see [Implementing Startup](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/implementing-startup).

#### Examples

See [Implementing Startup](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/implementing-startup).

## See also

[Resource DLL Entry-Point Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dll-entry-point-functions)