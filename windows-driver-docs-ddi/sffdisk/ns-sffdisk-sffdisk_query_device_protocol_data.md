## Description

The SFFDISK\_QUERY\_DEVICE\_PROTOCOL\_DATA structure is used in conjunction with the [**IOCTL\_SFFDISK\_QUERY\_DEVICE\_PROTOCOL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/sffdisk/ni-sffdisk-ioctl_sffdisk_query_device_protocol) request to report protocol data.

## Members

### `Size`

The size, in bytes, of this structure.

### `Reserved`

Reserved.

### `ProtocolGUID`

On output, this member contains a GUID that uniquely identifies the protocol.

## See also

[**IOCTL\_SFFDISK\_QUERY\_DEVICE\_PROTOCOL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/sffdisk/ni-sffdisk-ioctl_sffdisk_query_device_protocol)