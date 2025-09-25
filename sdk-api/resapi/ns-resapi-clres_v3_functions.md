# CLRES_V3_FUNCTIONS structure

## Description

Contains pointers to all [Resource API](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-api) version 3.0 entry
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

#### - ResourceControl

Not supported starting with Windows Server 2016.

**Windows Server 2012 R2:** Pointer to the [ResourceControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-presource_control_routine) entry
point.

#### - ResourceTypeControl

Not supported starting with Windows Server 2016.

**Windows Server 2012 R2:** Pointer to the [ResourceTypeControl](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-presource_type_control_routine) entry
point.

## See also

[Resource DLL Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dll-structures)