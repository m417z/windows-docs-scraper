# NVME_SECURE_ERASE_SETTINGS enumeration

## Description

Contains values that specify whether or what type of a secure erase operation should be performed as part of a Format NVM command.

The secure erase applies to all user data, regardless of location. For example, user data within an exposed Logical Block Allocation (LBA), within a cache, or within deallocated LBAs.

## Constants

### `NVME_SECURE_ERASE_NONE`

No secure erase operation is requested.

### `NVME_SECURE_ERASE_USER_DATA`

All user data will be erased. Contents of the user data after the erase is indeterminate. For example, the user data may be zero filled or one filled. The controller may perform a cryptographic erase when **NVME_SECURE_ERASE_USER_DATA** is specified, if all user data is encrypted.

### `NVME_SECURE_ERASE_CRYPTOGRAPHIC`

All user data will be erased cryptographically. This is accomplished by deleting the encryption key.

## Remarks

Use this enumeration to specify values in the **SES** field of the [NVME_CDW10_FORMAT_NVM](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_cdw10_format_nvm) structure that is used in the [FORMAT NVM (FORMATNVM)](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_command) Admin command.

## See also