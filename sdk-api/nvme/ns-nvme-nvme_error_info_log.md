# NVME_ERROR_INFO_LOG structure

## Description

Contains fields that specify the information in an Error Information log page.

The Error Information log page contains extended error information for a command that completed with an error or reported an error that is not specific to a particular command. Extended error information is provided when [More (**M**)](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command_status) is set to `1` in the **Status** field for the [Completion Queue Entry](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_completion_entry) associated with the command that completed with an error, or as part of an asynchronous event with an Error status type.

The Error Information log page is global to the controller. This error log may return the last *n* errors. If host software specifies a data transfer of the size of *n* error logs, then the error logs for the last *n* errors is returned. The ordering of the entries is based on the time when the error occurred, with the most recent error being returned as the first log.

The Error Information log page is a set of 64 byte entries; the number of supported entries is indicated in the [Identify Controller](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_identify_controller_data) data structure.

This structure is returned by the Get Log Page command. For more information, see [NVME_CDW10_GET_LOG_PAGE](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_get_log_page).

## Members

### `ErrorCount`

A 64-bit, incrementing error count, that indicates a unique identifier for this error.

The error count starts at `1h`, is incremented for each unique error log entry, and is retained across power off conditions. A value of `0h` indicates an invalid entry; this value may be used when there are lost entries or when there are fewer errors than the maximum number of entries the controller supports.

### `SQID`

Indicates the Submission Queue Identifier (SQID) of the command that the error information is associated with. If the error is not specific to a particular command then this field is set to `FFFFh`.

### `CMDID`

Indicates the Command Identifier (CMDID) of the command that the error is associated with. If the error is not specific to a particular command then this is set to `FFFFh`.

### `Status`

Indicates the Status Field for the command that completed.

The Status Field is located in bits 01:15. Bit 0 corresponds to the [Phase Tag (**P**)](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command_status) posted for the command. If the error is not specific to a particular command then this field reports the most applicable status value.

### `ParameterErrorLocation`

A **ParameterErrorLocation** structure containing fields that indicate the Byte and Bit of the command parameter that the error is associated with, if applicable.

If the parameter spans multiple bytes or bits, the location indicates the first byte and bit of the parameter. If the error is not specific to a particular command, this field is set to `FFFFh`.

### `ParameterErrorLocation.Byte`

Indicates the Byte in the command that contained the error.

This value is contained in bits 0:7 of the **ParameterErrorLocation** structure. Valid values are 0 to 63.

### `ParameterErrorLocation.Bit`

Indicates the Bit in the command that contained the error.

This value is contained in bits 8:10 of the **ParameterErrorLocation** structure. Valid values are 0 to 7.

### `ParameterErrorLocation.Reserved`

Bits 11:15 of the **ParameterErrorLocation** structure are reserved.

### `Lba`

Indicates the first Logical Block Address (LBA) that experienced the error condition, if applicable.

### `NameSpace`

Indicates the namespace that the error is associated with, if applicable.

### `VendorInfoAvailable`

When there is additional vendor specific error information available, this field provides the log page identifier associated with that page.

A value of `00h` indicates that no additional information is available. Valid values are in the range of `80h` to `FFh`.

### `Reserved0`

A reserved field.

### `CommandSpecificInfo`

Contains command specific information. If used, the command definition specifies the information returned.

### `Reserved1`

A reserved field.

## Remarks

## See also