# RDV_TASK_STATUS enumeration

## Description

Used with the [IRDVTaskPluginNotifySink::OnTaskStateChange](https://learn.microsoft.com/windows/desktop/TermServ/irdvtaskpluginnotifysink-ontaskstatechange) method to indicate the status of a task.

## Constants

### `RDV_TASK_STATUS_UNKNOWN:0`

The task state cannot be determined.

### `RDV_TASK_STATUS_SEARCHING`

Searching for applicable tasks.

### `RDV_TASK_STATUS_DOWNLOADING`

Downloading tasks.

### `RDV_TASK_STATUS_APPLYING`

Performing tasks.

### `RDV_TASK_STATUS_REBOOTING`

Rebooting. The task may or may not be complete.

### `RDV_TASK_STATUS_REBOOTED`

Reboot completed. The task may or may not be complete.

### `RDV_TASK_STATUS_SUCCESS`

Task completed successfully.

### `RDV_TASK_STATUS_FAILED`

Task failed.

### `RDV_TASK_STATUS_TIMEOUT`

Task did not finish in the allotted time.

## See also

[IRDVTaskPluginNotifySink::OnTaskStateChange](https://learn.microsoft.com/windows/desktop/TermServ/irdvtaskpluginnotifysink-ontaskstatechange)