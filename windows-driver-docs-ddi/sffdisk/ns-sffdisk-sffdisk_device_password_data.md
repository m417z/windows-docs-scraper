## Description

The SFFDISK\_DEVICE\_PASSWORD\_DATA structure is used in conjunction with an [**IOCTL\_SFFDISK\_DEVICE\_PASSWORD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/sffdisk/ni-sffdisk-ioctl_sffdisk_device_password) to change the password on a Secure Digital (SD) card.

## Members

### `Size`

The size, in bytes, of this structure.

### `Reserved`

Reserved.

### `Command`

Contains a structure of type [**SFFDISK\_DPCMD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/sffdisk/ne-sffdisk-sffdisk_dpcmd) that defines the type of operation.

### `Information`

On output, this member contains the return value for the operation.

### `PasswordLength`

The length, in bytes, of the current password.

### `NewPasswordLength`

The length, in bytes, of the new password.

### `Data[0]`

Buffer that the caller uses to pass in both the old and the new password. The current (old) password is at the beginning of the buffer and is immediately followed by the new password.

## See also

[**IOCTL\_SFFDISK\_DEVICE\_PASSWORD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/sffdisk/ni-sffdisk-ioctl_sffdisk_device_password)