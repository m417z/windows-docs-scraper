# CLRES_V4_FUNCTIONS structure

## Description

Contains pointers to all [Resource API](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-api) version 4.0 entry
points, except [StartupEx](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pstartup_ex_routine).

## Members

### `Open`

Pointer to the [OpenV2](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-popen_v2_routine) entry point.

### `Close`

Pointer to the [Close](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pclose_routine) entry point.

### `Online`

Pointer to the [OnlineV2](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-ponline_v2_routine) entry point.

### `Offline`

Pointer to the [OfflineV2](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-poffline_v2_routine) entry point.

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

### `BeginResourceControl`

Pointer to the [BeginResourceControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pbegin_rescall_routine) entry
point.

### `BeginResourceTypeControl`

Pointer to the [BeginResourceTypeControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pbegin_restypecall_routine) entry
point.

### `Cancel`

Pointer to the [Cancel](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pcancel_routine) entry point.

### `BeginResourceControlAsUser`

Pointer to the [BeginResourceControlAsUser](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pbegin_rescall_as_user_routine) entry point.

### `BeginResourceTypeControlAsUser`

Pointer to the [BeginResourceTypeControlAsUser](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pbegin_restypecall_as_user_routine) entry point.

## See also

[Resource DLL Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dll-structures)