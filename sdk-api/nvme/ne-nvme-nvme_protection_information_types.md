# NVME_PROTECTION_INFORMATION_TYPES enumeration

## Description

Contains values that indicate whether end-to-end data protection is enabled, and if it is, specifies the type of protection information.

When end-to-end data protection is enabled, the host must specify the appropriate protection information in the Read, Write, or Compare commands.

## Constants

### `NVME_PROTECTION_INFORMATION_NOT_ENABLED`

Protection information is not enabled.

### `NVME_PROTECTION_INFORMATION_TYPE1`

Type 1 protection information is enabled.

### `NVME_PROTECTION_INFORMATION_TYPE2`

Type 2 protection information is enabled.

### `NVME_PROTECTION_INFORMATION_TYPE3`

Type 3 protection information is enabled.

## Remarks

Use this enumeration to specify values in the **PI** field of the [NVME_CDW10_FORMAT_NVM](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_format_nvm) structure that is used in the [FORMAT NVM (FORMATNVM)](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command) Admin command.

## See also

- [NVME_CDW10_FORMAT_NVM](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_format_nvm)