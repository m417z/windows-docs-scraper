# NVME_STATUS_GENERIC_COMMAND_CODES enumeration

## Description

Contains values that indicate a status associated with the command that is generic across many different types of commands.

These status codes are of the **NVME_STATUS_TYPE_GENERIC_COMMAND** [Status Code Type](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_status_types) and are posted by the controller in a [Completion Queue entry](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_completion_entry) when a command is completed. The codes indicate that the command specified by the Command and Submission Queue identifiers in the completion queue entry has completed.

## Constants

### `NVME_STATUS_SUCCESS_COMPLETION`

The command completed successfully.

### `NVME_STATUS_INVALID_COMMAND_OPCODE`

The associated command opcode field is not valid.

### `NVME_STATUS_INVALID_FIELD_IN_COMMAND`

An invalid or unsupported field is specified in the command parameters.

### `NVME_STATUS_COMMAND_ID_CONFLICT`

The command identifier is already in use.

> [!NOTE]
> The number of commands that are searched for an ID conflict is implementation specific.

### `NVME_STATUS_DATA_TRANSFER_ERROR`

Indicates an error transferring the data or metadata associated with a command.

### `NVME_STATUS_COMMAND_ABORTED_DUE_TO_POWER_LOSS_NOTIFICATION`

Indicates that the command was aborted due to a power loss notification.

### `NVME_STATUS_INTERNAL_DEVICE_ERROR`

The command was not completed successfully due to an internal error. Details on the internal device error are returned as an asynchronous event.

### `NVME_STATUS_COMMAND_ABORT_REQUESTED`

The command was aborted due to a Command Abort command being received that specified the Submission Queue Identifier and Command Identifier of this command.

### `NVME_STATUS_COMMAND_ABORTED_DUE_TO_SQ_DELETION`

The command was aborted due to a Delete I/O Submission Queue request received for the Submission Queue to which the command was submitted.

### `NVME_STATUS_COMMAND_ABORTED_DUE_TO_FAILED_FUSED_COMMAND`

The command was aborted due to the other command in a fused operation failing.

### `NVME_STATUS_COMMAND_ABORTED_DUE_TO_FAILED_MISSING_COMMAND`

The command was aborted due to the companion fused command not being found as the subsequent Submission Queue entry.

### `NVME_STATUS_INVALID_NAMESPACE_OR_FORMAT`

The namespace or the format of that namespace is invalid.

### `NVME_STATUS_COMMAND_SEQUENCE_ERROR`

The command was aborted due to a protocol violation in a multi-command sequence. For example, a violation of the Security Send and Security Receive sequencing rules in the TCG Storage Synchronous Interface Communications protocol.

### `NVME_STATUS_INVALID_SGL_LAST_SEGMENT_DESCR`

The command includes an invalid SGL Last Segment or SGL Segment descriptor. This may occur when the SGL segment pointed to by an SGL Last Segment descriptor contains an SGL Segment descriptor or an SGL Last Segment descriptor or an SGL Segment descriptor. This may occur when an SGL Last Segment descriptor contains an invalid length (for example, a length of zero or one that is not a multiple of 16).

### `NVME_STATUS_INVALID_NUMBER_OF_SGL_DESCR`

There is an SGL Last Segment descriptor or an SGL Segment descriptor in a location other than the last descriptor of a segment based on the length indicated.

### `NVME_STATUS_DATA_SGL_LENGTH_INVALID`

This may occur if the length of a Data SGL is too short. This may occur if the length of a Data SGL is too long and the controller does not support SGL transfers longer than the amount of data to be transferred as indicated in the SGL Support (**SGLS**) field of the [Identify Controller (NVME_IDENTIFY_CONTROLLER_DATA)](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_controller_data) data structure.

### `NVME_STATUS_METADATA_SGL_LENGTH_INVALID`

This may occur if the length of a Metadata SGL is too short. This may occur if the length of a Metadata SGL is too long and the controller does not support SGL transfers longer than the amount of data to be transferred as indicated in the SGL Support (**SGLS**) field of the [Identify Controller (NVME_IDENTIFY_CONTROLLER_DATA)](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_controller_data) data structure.

### `NVME_STATUS_SGL_DESCR_TYPE_INVALID`

The type of an SGL Descriptor is a type that is not supported by the controller.

### `NVME_STATUS_INVALID_USE_OF_CONTROLLER_MEMORY_BUFFER`

The attempted use of the Controller Memory Buffer is not supported by the controller.

### `NVME_STATUS_PRP_OFFSET_INVALID`

The Offset field for a PRP entry is invalid. This may occur when there is a PRP entry with a non-zero offset after the first entry.

### `NVME_STATUS_ATOMIC_WRITE_UNIT_EXCEEDED`

The length specified exceeds the atomic write unit size.

### `NVME_STATUS_OPERATION_DENIED`

The command was denied due to lack of access rights.

### `NVME_STATUS_SGL_OFFSET_INVALID`

The offset specified in a descriptor is invalid.

### `NVME_STATUS_RESERVED`

Reserved.

### `NVME_STATUS_HOST_IDENTIFIER_INCONSISTENT_FORMAT`

The NVM subsystem detected the simultaneous use of 64-bit and 128-bit Host Identifier values on different controllers.

### `NVME_STATUS_KEEP_ALIVE_TIMEOUT_EXPIRED`

The Keep Alive Timer expired.

### `NVME_STATUS_KEEP_ALIVE_TIMEOUT_INVALID`

The Keep Alive Timeout value specified is invalid.

### `NVME_STATUS_COMMAND_ABORTED_DUE_TO_PREEMPT_ABORT`

The command was aborted due to a Reservation Acquire command with the Reservation Acquire Action (RACQA) set to 010b (Preempt and Abort).

### `NVME_STATUS_SANITIZE_FAILED`

The most recent sanitize operation failed and no recovery action has been successfully completed.

### `NVME_STATUS_SANITIZE_IN_PROGRESS`

The requested function (e.g., command) is prohibited while a sanitize operation is in progress.

### `NVME_STATUS_SGL_DATA_BLOCK_GRANULARITY_INVALID`

The Address alignment or Length granularity for an SGLData Block descriptor is invalid.

### `NVME_STATUS_NVM_LBA_OUT_OF_RANGE`

The command references an LBA that exceeds the size of the namespace.

### `NVME_STATUS_NVM_CAPACITY_EXCEEDED`

Execution of the command has caused the capacity of the namespace to be exceeded. This error occurs when the Namespace Utilization exceeds the Namespace Capacity.

### `NVME_STATUS_NVM_NAMESPACE_NOT_READY`

The namespace is not ready to be accessed. The Do Not Retry bit indicates whether re-issuing the command at a later time may succeed.

### `NVME_STATUS_NVM_RESERVATION_CONFLICT`

The command was aborted due to a conflict with a reservation held on the accessed namespace.

### `NVME_STATUS_FORMAT_IN_PROGRESS`

The namespace is currently being formatted. The Do Not Retry bit will be cleared to ‘0’ to indicate that the command may succeed if it is resubmitted.

## Remarks

## See also