# NVME_STATUS_MEDIA_ERROR_CODES enumeration

## Description

Contains values that indicate an error associated with the NVM media or indicate a data integrity type error.

These status codes are of the **NVME_STATUS_TYPE_MEDIA_ERROR** [Status Code Type](https://learn.microsoft.com/windows/win32/api/nvme/ne-nvme-nvme_status_types) and are posted by the controller in a [Completion Queue entry](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_completion_entry) when a command is completed.

## Constants

### `NVME_STATUS_NVM_WRITE_FAULT`

The write data could not be committed to the media.

### `NVME_STATUS_NVM_UNRECOVERED_READ_ERROR`

The read data could not be recovered from the media.

### `NVME_STATUS_NVM_END_TO_END_GUARD_CHECK_ERROR`

The command was aborted due to an end-to-end guard check failure.

### `NVME_STATUS_NVM_END_TO_END_APPLICATION_TAG_CHECK_ERROR`

The command was aborted due to an end-to-end application tag check failure.

### `NVME_STATUS_NVM_END_TO_END_REFERENCE_TAG_CHECK_ERROR`

The command was aborted due to an end-to-end reference tag check failure.

### `NVME_STATUS_NVM_COMPARE_FAILURE`

The command failed due to a miscompare during a Compare command.

### `NVME_STATUS_NVM_ACCESS_DENIED`

Access to the namespace and/or Logical Block Address (LBA) range is denied due to lack of access rights. For more information, see the [TCG Storage Interface Interactions Specification (SIIS)](https://trustedcomputinggroup.org).

### `NVME_STATUS_NVM_DEALLOCATED_OR_UNWRITTEN_LOGICAL_BLOCK`

The command failed due to an attempt to read from an LBA range containing a deallocated or unwritten logical block.

## Remarks

## See also