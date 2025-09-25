# RM_FILTER_INFO structure

## Description

Contains information about modifications to restart or shutdown actions. Add, remove, and list modifications to specified applications and services that have been registered with the Restart Manager session by using the [RmAddFilter](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmaddfilter), [RmRemoveFilter](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmremovefilter), and the [RmGetFilterList](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmgetfilterlist) functions.

## Members

### `FilterAction`

This member contains a [RM_FILTER_ACTION](https://learn.microsoft.com/windows/desktop/api/restartmanager/ne-restartmanager-rm_filter_action) enumeration value. Use the value **RmNoRestart**
to prevent the restart of the application or service. Use the value **RmNoShutdown** to prevent the shutdown and restart of the application or service.

### `FilterTrigger`

This member contains a [RM_FILTER_TRIGGER](https://learn.microsoft.com/windows/desktop/api/restartmanager/ne-restartmanager-rm_filter_trigger) enumeration value. Use the value **RmFilterTriggerFile** to modify the restart or shutdown actions of an application referenced by the executable's full path filename. Use the value **RmFilterTriggerProcess** to modify the restart or shutdown actions of an application referenced by a [RM_UNIQUE_PROCESS](https://learn.microsoft.com/windows/desktop/api/restartmanager/ns-restartmanager-rm_unique_process) structure. Use the value **RmFilterTriggerService**
to modify the restart or shutdown actions of a service referenced by the short service name.

### `cbNextOffset`

The offset in bytes to the next structure.

### `strFilename`

If the value of **FilterTrigger** is **RmFilterTriggerFile**, this member contains a pointer to a string value that contains the application filename.

### `Process`

If the value of **FilterTrigger** is **RmFilterTriggerProcess**, this member is a [RM_PROCESS_INFO](https://learn.microsoft.com/windows/desktop/api/restartmanager/ns-restartmanager-rm_process_info) structure for the application.

### `strServiceShortName`

If the value of **FilterTrigger** is **RmFilterTriggerService** this member is a pointer to a string value that contains the short service name.

## See also

[RM_FILTER_TRIGGER](https://learn.microsoft.com/windows/desktop/api/restartmanager/ne-restartmanager-rm_filter_trigger)

[RmGetFilterList](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmgetfilterlist)