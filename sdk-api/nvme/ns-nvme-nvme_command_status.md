# NVME_COMMAND_STATUS structure

## Description

Contains information about the status of a command.

This structure is used in the **Status** field of the [NVME_COMPLETION_ENTRY](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_completion_entry) and in the **Status** field of the [NVME_ERROR_INFO_LOG](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_error_info_log) to indicate the status of a command that has completed.

## Members

### `DUMMYSTRUCTNAME`

### `DUMMYSTRUCTNAME.P`

Indicates whether a Completion Queue entry is a new entry.

The Phase Tag (**P**) values for all Completion Queue entries should be initialized to ‘0’ by the host software prior to setting the **EN** field of the [NVME_CONTROLLER_CONFIGURATION](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_controller_configuration) to `1`.

When the controller places an entry in the Completion Queue, it will invert the phase tag to enable host software to identify a new entry. Specifically, for the first set of completion queue entries after **EN** is set to `1`, all Phase Tags are set to `1` when they are posted. For the second set of completion queue entries, when the controller has wrapped around to the top of the Completion Queue, all Phase Tags are cleared to `0` when they are posted. The value of the Phase Tag is inverted on each pass through the Completion Queue.

### `DUMMYSTRUCTNAME.SC`

Indicates a status code identifying any error or status information for the command.

### `DUMMYSTRUCTNAME.SCT`

A [NVME_STATUS_TYPES](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_status_types) value that indicates the type of status the controller is returning.

### `DUMMYSTRUCTNAME.Reserved`

### `DUMMYSTRUCTNAME.M`

Indicates whether there is additional status information for the command.

When this value is set to `1`, there is more status information for this command as part of the [Error Information log](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_error_info_log) that can be retrieved with the Get Log Page command.

When this value is cleared to `0`, there is no additional status information for this command.

### `DUMMYSTRUCTNAME.DNR`

Indicates whether the command will succeed if it is re-submitted.

When this value is set to `1`, it indicates that if the same command is re-submitted it is expected to fail.

When this value is cleared to `0`, it indicates that the same command may succeed if retried.

If a command is aborted due to a time limited error recovery, this field should be cleared to `0`. If the **SCT** and **SC** fields are cleared to `0h` then this field should be cleared to `0`.

### `AsUshort`

## Remarks

## See also

- [NVME_COMPLETION_ENTRY](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_completion_entry)
- [NVME_ERROR_INFO_LOG](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_error_info_log)