# NVME_STATUS_COMMAND_SPECIFIC_CODES enumeration

## Description

Contains values indicating status that is specific to a particular command.

These status codes are of the **NVME_STATUS_TYPE_COMMAND_SPECIFIC** [Status Code Type](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_status_types) and are posted by the controller in a [Completion Queue entry](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_completion_entry) when a command is completed.

## Constants

### `NVME_STATUS_COMPLETION_QUEUE_INVALID`

The Completion Queue identifier specified in the Create I/O Submission Queue command does not exist.

### `NVME_STATUS_INVALID_QUEUE_IDENTIFIER`

Indicates the following status for these commands:

- Create I/O Submission Queue: The creation of the I/O Submission Queue failed due to an invalid queue identifier specified as part of the command. An invalid queue identifier is one that is currently in use or one that is outside the range supported by the controller.
- Delete I/O Submission Queue: The queue identifier specified in the command is invalid. This error is also indicated if the Admin Completion Queue identifier is specified.
- Create I/O Completion Queue: The creation of the I/O Completion Queue failed due to an invalid queue identifier specified as part of the command. An invalid queue identifier is one that is currently in use or one that is outside the range supported by the controller.
- Delete I/O Completion Queue: The queue identifier specified in the command is invalid. This error is also indicated if the Admin Completion Queue identifier is specified.

### `NVME_STATUS_MAX_QUEUE_SIZE_EXCEEDED`

Indicates the following status for the Create I/O Submission Queue and Create I/O Completion Queue commands:

The host attempted to create an I/O Completion Queue with an invalid number of entries. For example, a value of zero or a value which exceeds the maximum supported by the controller specified in the **MQES** field of the [NVME_CONTROLLER_CAPABILITIES](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_controller_capabilities) structure.

### `NVME_STATUS_ABORT_COMMAND_LIMIT_EXCEEDED`

The number of concurrently outstanding Abort commands has exceeded the limit indicated in the **ACL** field of the [Identify Controller data structure](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_controller_data).

### `NVME_STATUS_ASYNC_EVENT_REQUEST_LIMIT_EXCEEDED`

The number of concurrently outstanding Asynchronous Event Request commands has been exceeded.

### `NVME_STATUS_INVALID_FIRMWARE_SLOT`

The firmware slot indicated in the Firmware Commit command is invalid or read only. This error is indicated if the firmware slot exceeds the number supported.

### `NVME_STATUS_INVALID_FIRMWARE_IMAGE`

The firmware image specified for activation in the Firmware Commit command is invalid and not loaded by the controller.

### `NVME_STATUS_INVALID_INTERRUPT_VECTOR`

The creation of the I/O Completion Queue failed due to an invalid interrupt vector specified as part of the Create I/O Completion Queue command.

### `NVME_STATUS_INVALID_LOG_PAGE`

The log page indicated in the Get Log Page command is invalid. This error condition is also returned if a reserved log page is requested.

### `NVME_STATUS_INVALID_FORMAT`

Indicates the following status for the Format NVM command: The format specified is invalid.

This may be due to various conditions, including:

- Specifying an invalid Logical Block Address (LBA) Format number.
- Enabling protection information when there is not sufficient metadata per LBA.
- Invalid security state. For more information, see the [TCG Storage Interface Interactions Specification (SIIS)](https://trustedcomputinggroup.org).

### `NVME_STATUS_FIRMWARE_ACTIVATION_REQUIRES_CONVENTIONAL_RESET`

Indicates the following status for the Firmware Commit command:

The firmware commit was successful, however, activation of the firmware image requires a conventional reset. If a Function Level Reset (FLR) or controller reset occurs prior to a conventional reset, the controller shall continue operation with the currently executing firmware image.

### `NVME_STATUS_INVALID_QUEUE_DELETION`

Indicates the following status for the Delete I/O Completion Queue command:

It is invalid to delete the Specified I/O Completion Queue. The typical reason for this error condition is that there is an associated I/O Submission Queue that has not been deleted.

### `NVME_STATUS_FEATURE_ID_NOT_SAVEABLE`

The Feature Identifier specified in the Set Features command does not support a saveable value.

### `NVME_STATUS_FEATURE_NOT_CHANGEABLE`

The Feature Identifier specified in the Set Features command may not be changed.

### `NVME_STATUS_FEATURE_NOT_NAMESPACE_SPECIFIC`

The Feature Identifier specified in the Set Features command is not namespace specific. The Feature Identifier settings apply across all namespaces.

### `NVME_STATUS_FIRMWARE_ACTIVATION_REQUIRES_NVM_SUBSYSTEM_RESET`

Indicates status for the Firmware Commit command.

### `NVME_STATUS_FIRMWARE_ACTIVATION_REQUIRES_RESET`

Indicates the following status for the Firmware Commit command:

The firmware commit was successful, however, activation of the firmware image requires an NVM Subsystem Reset. If any other type of reset occurs prior to an NVM Subsystem Reset, the controller shall continue operation with the currently executing firmware image.

### `NVME_STATUS_FIRMWARE_ACTIVATION_REQUIRES_MAX_TIME_VIOLATION`

Indicates the following status for the Firmware Commit command:

The image specified if activated immediately would exceed the Maximum Time for Firmware Activation (MFTA) value reported in Identify Controller. To activate the firmware, the Firmware Commit command needs to be reissued and the image activated using a reset.

### `NVME_STATUS_FIRMWARE_ACTIVATION_PROHIBITED`

Indicates the following status for the Firmware Commit command:

The specified image is being prohibited from activation by the controller for vendor specific reasons. For example, the controller does not support down revision firmware.

### `NVME_STATUS_OVERLAPPING_RANGE`

Indicates the following status for these commands:

- Firmware Commit: This error is indicated if the firmware image has overlapping ranges.
- Set Features: This error is indicated if the LBA Range Type data structure has overlapping ranges.
- Firmware Image Download: This error is indicated if the firmware image has overlapping ranges.

### `NVME_STATUS_NAMESPACE_INSUFFICIENT_CAPACITY`

Indicates the following status for the Namespace Management command:

Creating the namespace requires more free space than is currently available. The Command Specific Information field of the Error Information Log specifies the total amount of NVM capacity required to create the namespace in bytes.

### `NVME_STATUS_NAMESPACE_IDENTIFIER_UNAVAILABLE`

Indicates the following status for the Namespace Management command:

The number of namespaces supported has been exceeded.

### `NVME_STATUS_NAMESPACE_ALREADY_ATTACHED`

Indicates the following status for the Namespace Attachment command:

The controller is already attached to the namespace specified.

### `NVME_STATUS_NAMESPACE_IS_PRIVATE`

Indicates the following status for the Namespace Attachment command:

The controller is not attached to the namespace. The request to attach the controller could not be completed because the namespace is private and is already attached to one controller.

### `NVME_STATUS_NAMESPACE_NOT_ATTACHED`

Indicates the following status for the Namespace Attachment command:

The controller is not attached to the namespace. The request to detach the controller could not be completed.

### `NVME_STATUS_NAMESPACE_THIN_PROVISIONING_NOT_SUPPORTED`

### `NVME_STATUS_CONTROLLER_LIST_INVALID`

Indicates the following status for the Namespace Attachment command:

The controller list provided is invalid.

### `NVME_STATUS_DEVICE_SELF_TEST_IN_PROGRESS`

Indicates status for the Device Self-test command.

### `NVME_STATUS_BOOT_PARTITION_WRITE_PROHIBITED`

Indicates status for the Firmware Commit command.

### `NVME_STATUS_INVALID_CONTROLLER_IDENTIFIER`

Indicates status for the Virtualization Management command.

### `NVME_STATUS_INVALID_SECONDARY_CONTROLLER_STATE`

Indicates status for the Virtualization Management command

### `NVME_STATUS_INVALID_NUMBER_OF_CONTROLLER_RESOURCES`

Indicates status for the Virtualization Management command.

### `NVME_STATUS_INVALID_RESOURCE_IDENTIFIER`

Indicates status for the Virtualization Management command.

### `NVME_STATUS_STREAM_RESOURCE_ALLOCATION_FAILED`

Indicates status for the Streams Directive command.

### `NVME_STATUS_NVM_CONFLICTING_ATTRIBUTES`

Indicates the following status for these commands: Dataset Management, Read, Write

The attributes specified in the command are conflicting.

### `NVME_STATUS_NVM_INVALID_PROTECTION_INFORMATION`

Indicates the following status for these commands: Compare, Read, Write, Write Zeroes

The Protection Information settings specified in the command are invalid.

### `NVME_STATUS_NVM_ATTEMPTED_WRITE_TO_READ_ONLY_RANGE`

Indicates the following status for these commands: Dataset Management, Write, Write Uncorrectable, Write Zeroes

The controller may optionally report this status if a deallocate is attempted for a read only range.

## Remarks

## See also