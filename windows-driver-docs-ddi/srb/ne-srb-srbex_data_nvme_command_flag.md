## Description

**SRBEX_DATA_NVME_COMMAND_FLAG** enumerates the properties of a particular SRBEX data NVMe command.

## Constants

### `SRBEX_DATA_NVME_COMMAND_FLAG_REQUIRE_DATA_TRANSFER_IN`

Data is being read in from the device. See Remarks.

### `SRBEX_DATA_NVME_COMMAND_FLAG_REQUIRE_DATA_TRANSFER_OUT`

Data is being written out to the device. See Remarks.

### `SRBEX_DATA_NVME_COMMAND_FLAG_PRP_SET_ALREADY`

By default, the system frames a physical region page (PRP) before sending the data transfer command to the device. The user sets this flag if they want to do the framing instead.

### `SRBEX_DATA_NVME_COMMAND_FLAG_SIGNATURE_ENABLED`

Reserved for system use; do not use.

### `SRBEX_DATA_NVME_COMMAND_FLAG_NO_POLLING`

Indicates to send the command with interrupt mode.

## See also

[**SRBEX_DATA_NVME_COMMAND_FLAG** (*storport.h*)](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-srbex_data_nvme_command_flag)