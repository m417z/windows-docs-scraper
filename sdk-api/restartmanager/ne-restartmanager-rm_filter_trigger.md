# RM_FILTER_TRIGGER enumeration

## Description

Describes the restart or shutdown actions for an application or service.

## Constants

### `RmFilterTriggerInvalid:0`

An invalid filter trigger.

### `RmFilterTriggerFile`

Modifies the shutdown or restart actions for an application identified by its executable filename.

### `RmFilterTriggerProcess`

Modifies the shutdown or restart actions for an application identified by a [RM_UNIQUE_PROCESS](https://learn.microsoft.com/windows/desktop/api/restartmanager/ns-restartmanager-rm_unique_process) structure.

### `RmFilterTriggerService`

Modifies the shutdown or restart actions for a service identified by a service short name.

## See also

[RM_FILTER_INFO](https://learn.microsoft.com/windows/desktop/api/restartmanager/ns-restartmanager-rm_filter_info)