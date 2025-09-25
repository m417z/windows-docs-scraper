## Description

The **STORAGE_SANITIZE_METHOD** enumeration identifies the sanitize method for an NVMe device.

## Constants

### `StorageSanitizeMethodDefault`

Perform the default sanitize operation. Currently, the default is to perform a Crypto Erase sanitize operation.

### `StorageSanitizeMethodBlockErase`

Perform a Block Erase sanitize operation.

### `StorageSanitizeMethodCryptoErase`

Perform a Crypto Erase sanitize operation.

## Remarks

**STORAGE_SANITIZE_METHOD** applies to NVMe devices only. It is specified in a[**STORAGE_REINITIALIZE_MEDIA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-storage_reinitialize_media) structure, which is optionally provided to [**IOCTL_STORAGE_REINITIALIZE_MEDIA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_reinitialize_media).

## See also

[**IOCTL_STORAGE_REINITIALIZE_MEDIA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_reinitialize_media)

[**STORAGE_REINITIALIZE_MEDIA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ns-ntddstor-storage_reinitialize_media)