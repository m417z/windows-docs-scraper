## Description

The SFFDISK\_DEVICE\_COMMAND\_DATA structure specifies the operation performed by an [**IOCTL\_SFFDISK\_DEVICE\_COMMAND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/sffdisk/ni-sffdisk-ioctl_sffdisk_device_command) request.

## Members

### `HeaderSize`

The length, in bytes, of the header structure. The size does not include any data concatenated at the end. The caller should initialize this field to **sizeof** (SFFDISK\_DEVICE\_COMMAND\_DATA).

### `Flags`

Reserved.

### `Command`

Contains an enumeration value of type [**SFFDISK\_DCMD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/sffdisk/ne-sffdisk-sffdisk_dcmd) that defines the type of operation. Typical operations include retrieval of the card's security level, device commands, and locking (or unlocking) the interface channel as a preliminary action to a series of commands.

### `ProtocolArgumentSize`

The length in bytes of the device command arguments that immediately follow this header structure. This data begins at the address indicated by the **Data** member. Device command arguments are specific to the protocol of the device.

### `DeviceDataBufferSize`

Defines the length, in bytes, of the data transfer.

### `Information`

On output, this member contains an operation-dependent status value.

### `Data[0]`

Buffer that contains the command arguments.

## Remarks

The following diagram indicates the layout of the data submitted with an [**IOCTL\_SFFDISK\_DEVICE\_COMMAND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/sffdisk/ni-sffdisk-ioctl_sffdisk_device_command) request. The caller of this request stores this data at the location indicated by the **Data** member of the SFFDISK\_DEVICE\_COMMAND\_DATA structure:

![Diagram illustrating the format of device command data](https://learn.microsoft.com/windows-hardware/drivers/ddi/sffdisk/images/ns-sffdisk-sffdisk_device_command_data.png "Diagram illustrating the format of device command data")

The format of the protocol arguments depends on the protocol that the device uses. For an SD storage device, the protocol arguments section will contain an [**SDCMD\_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/sddef/ns-sddef-_sdcmd_descriptor).

## See also

[**IOCTL\_SFFDISK\_DEVICE\_COMMAND**](https://learn.microsoft.com/windows-hardware/drivers/ddi/sffdisk/ni-sffdisk-ioctl_sffdisk_device_command)