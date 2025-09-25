# NVME_COMMAND_EFFECTS_LOG structure

## Description

Contains information that describes the commands that the controller supports and the effects of those commands on the state of the NVM subsystem.

The Command Effects log page is 4096 bytes in size. There is one [NVME_COMMAND_EFFECTS_DATA](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command_effects_data) structure per Admin command and one per I/O command (based on the I/O Command Set selected in the **CSS** field of the [NVME_CONTROLLER_CONFIGURATION](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_controller_configuration) structure).

## Members

### `ACS`

A [NVME_COMMAND_EFFECTS_DATA](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command_effects_data) structure that describes the Admin commands that the controller supports and the effects of those commands.

### `IOCS`

A [NVME_COMMAND_EFFECTS_DATA](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command_effects_data) structure that describes the I/O commands that the controller supports and the effects of those commands.

### `Reserved`

## Remarks

## See also