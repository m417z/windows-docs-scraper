# CLRES_V1_FUNCTIONS structure

## Description

Contains pointers to all [Resource API](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-api) version 1.0 entry
points except [Startup](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pstartup_routine).

## Members

### `Open`

Pointer to the [Open](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-popen_routine) entry point.

### `Close`

Pointer to the [Close](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pclose_routine) entry point.

### `Online`

Pointer to the [Online](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-ponline_routine) entry point.

### `Offline`

Pointer to the [Offline](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-poffline_routine) entry point.

### `Terminate`

Pointer to the [Terminate](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pterminate_routine) entry point.

### `LooksAlive`

Pointer to the [LooksAlive](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-plooks_alive_routine) entry point.

### `IsAlive`

Pointer to the [IsAlive](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pis_alive_routine) entry point.

### `Arbitrate`

Pointer to the [Arbitrate](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-parbitrate_routine) entry point.

### `Release`

Pointer to the [Release](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-prelease_routine) entry point.

### `ResourceControl`

Pointer to the [ResourceControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-presource_control_routine) entry
point.

### `ResourceTypeControl`

Pointer to the [ResourceTypeControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-presource_type_control_routine) entry
point.

## Remarks

The **CLRES_V1_FUNCTIONS** structure is the function
table that is returned by the [Startup](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pstartup_routine) function in
[Resource API](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-api) 1.0.
[Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dlls) that support multiple
[resource types](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-types) must provide one function table for each
resource type. All function pointers must be non-NULL except for the following entry points:

* [Arbitrate](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-parbitrate_routine)
* [Release](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-prelease_routine)
* [ResourceControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-presource_control_routine)
* [ResourceTypeControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-presource_type_control_routine)

For more information, see
[Implementing Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/implementing-resource-dlls).

To create a function table for version 1.0 of the Resource API, use the
[CLRES_V1_FUNCTION_TABLE](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nf-resapi-clres_v1_function_table) macro.

## See also

[Arbitrate](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-parbitrate_routine)

[CLRES_V1_FUNCTION_TABLE](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nf-resapi-clres_v1_function_table)

[Close](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pclose_routine)

[IsAlive](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pis_alive_routine)

[LooksAlive](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-plooks_alive_routine)

[Offline](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-poffline_routine)

[Online](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-ponline_routine)

[Open](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-popen_routine)

[Release](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-prelease_routine)

**ResourceControl**

[ResourceTypeControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-presource_type_control_routine)

[Startup](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pstartup_routine)

[Terminate](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pterminate_routine)