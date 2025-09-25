# NVME_STATUS_TYPES enumeration

## Description

Contains values indicating the type of status code that is posted by the controller in a completion queue entry when a command is completed.

## Constants

### `NVME_STATUS_TYPE_GENERIC_COMMAND`

Indicates that the command specified by the Command and Submission Queue identifiers in the completion queue entry has completed. These status values are generic across all command types, and include such conditions as success, opcode not supported, and invalid field.

One of the status codes in the [NVME_STATUS_GENERIC_COMMAND_CODES](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_status_generic_command_codes) enumeration.

### `NVME_STATUS_TYPE_COMMAND_SPECIFIC`

Indicates a status value that is specific to a particular command opcode. These values may indicate additional processing is required. Status values such as invalid firmware image or exceeded maximum number of queues is reported with this type.

One of the status codes in the [NVME_STATUS_COMMAND_SPECIFIC_CODES](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_status_command_specific_codes) enumeration.

### `NVME_STATUS_TYPE_MEDIA_ERROR`

A status value that indicates a media specific error occurred in the NVM, or a data integrity error.

One of the status codes in the [NVME_STATUS_MEDIA_ERROR_CODES](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_status_media_error_codes) enumeration.

### `NVME_STATUS_TYPE_VENDOR_SPECIFIC`

Indicates a vendor specific status code.

## Remarks

When a command is completed, a value from this enumeration is posted by the controller in the **SCT** field of a [NVME_COMMAND_STATUS](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command_status) structure in the **Status** field of a [Completion Queue entry](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_completion_entry).

## See also

- [Completion Queue entry](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_completion_entry)