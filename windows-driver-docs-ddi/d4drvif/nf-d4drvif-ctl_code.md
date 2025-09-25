# CTL_CODE macro

## Description

The **d4drvif.h** CTL_CODE macro defines IOCTLs for the DOT4 virtual printer port protocol that enables a multi-function printing device to simultaneously send and receive data packets on a single physical channel.

## Parameters

### `DeviceType`

Contains the value for **FILE_DEVICE_DOT4** (0x3a).

### `Function`

Contains the IOCTL Function value (IOCTL_DOT4_USER_BASE base value of 2049 + IOCTL-specific value of 0-9).

### `Method`

Contains the method codes for how buffers are passed for I/O and FS controls:

| Method code | Value |
| --- | --- |
| METHOD_BUFFERED | 0 |
| METHOD_IN_DIRECT | 1 |
| METHOD_OUT_DIRECT | 2 |
| METHOD_NEITHER | 3 |

### `Access`

Contains the access check values:

| Method code | Value |
| --- | --- |
| FILE_ANY_ACCESS | 0x0000 |
| FILE_READ_ACCESS | 0x0001 |
| FILE_WRITE_ACCESS | 0x0002 |

## Remarks

## See also