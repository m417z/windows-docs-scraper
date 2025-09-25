# CLRES_CALLBACK_FUNCTION_TABLE structure

## Description

Represents a function table for the [StartupEx](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pstartup_ex_routine) callback function.

## Members

### `LogEvent`

A pointer to the [LogEvent](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-plog_event_routine) entry point.

### `SetResourceStatusEx`

A pointer to the [SetResourceStatusEx](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pset_resource_status_routine_ex) entry point.

### `SetResourceLockedMode`

A pointer to the [SetResourceLockedMode](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pset_resource_locked_mode_routine) entry point.

### `SignalFailure`

A pointer to the [SignalFailure](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-psignal_failure_routine) entry point.

### `SetResourceInMemoryNodeLocalProperties`

A pointer to the [SetResourceInMemoryNodeLocalProperties](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pset_resource_inmemory_nodelocal_properties_routine) entry point.

### `EndControlCall`

A pointer to the [EndControlCall](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pend_control_call) entry point.

**Windows Server 2012:** This member was added in Windows Server 2012 R2.

### `EndTypeControlCall`

A pointer to the [EndTypeControlCall](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pend_type_control_call) entry point.

**Windows Server 2012:** This member was added in Windows Server 2012 R2.

### `ExtendControlCall`

A pointer to the [ExtendControlCall](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pextend_res_control_call) entry point.

**Windows Server 2012 R2 and Windows Server 2012:** This member was added in Windows Server 2016.

### `ExtendTypeControlCall`

A pointer to the [ExtendResTypeControlCall](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pextend_res_type_control_call) entry point.

**Windows Server 2012 R2 and Windows Server 2012:** This member was added in Windows Server 2016.

### `RaiseResTypeNotification`

A pointer to the [RaiseResTypeNotification](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-praise_res_type_notification) entry point.

**Windows Server 2012 R2 and Windows Server 2012:** This member was added in Windows Server 2016.

### `ChangeResourceProcessForDumps`

A pointer to the [ChangeResourceProcessForDumps](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pchange_resource_process_for_dumps) entry point.

**Windows Server 2012 R2 and Windows Server 2012:** This member was added in Windows Server 2016.

### `ChangeResTypeProcessForDumps`

A pointer to the [ChangeResTypeProcessForDumps](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pchange_res_type_process_for_dumps) entry point.

**Windows Server 2012 R2 and Windows Server 2012:** This member was added in Windows Server 2016.

### `SetInternalState`

A pointer to the [SetInternalState](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-pset_internal_state) entry point.

**Windows Server 2012 R2 and Windows Server 2012:** This member was added in Windows Server 2016.

### `SetResourceLockedModeEx`

## See also

[Resource DLL Structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dll-structures)