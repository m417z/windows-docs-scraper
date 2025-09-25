# _PCMCIA_SOCKET_INFORMATION structure

## Description

The PCMCIA_SOCKET_INFORMATION structure is used in conjunction with the [IOCTL_SOCKET_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpcm/ni-ntddpcm-ioctl_socket_information) request to retrieve socket configuration and state data.

## Members

### `Socket`

Indicates the socket number.

### `TupleCrc`

Contains a 16-bit CRC that is concatenated with the PCMCIA prefix, the manufacturer-name string, the product-name string, and the instance value for the card to produce the device ID for a PC Card or CardBus card. For more information about PCMCIA device IDs, see [Identifiers for PCMCIA Devices](https://learn.microsoft.com/windows-hardware/drivers/install/identifiers-for-pcmcia-devices).

### `Manufacturer`

Indicates the manufacturer of the PC Card or CardBus card.

### `Identifier`

Contains the device ID of the PC Card or CardBus card.

### `DriverName`

Contains the name of the PC Card or CardBus card device driver.

### `DeviceFunctionId`

Indicates the type of PC Card or CardBus card. This value can be one of the following.

| PC Card Type | Meaning |
| --- | --- |
| PCCARD_TYPE_MULTIFUNCTION | Multifunction card. |
| PCCARD_TYPE_MEMORY | Memory card. |
| PCCARD_TYPE_SERIAL | Serial port card. |
| PCCARD_TYPE_PARALLEL | Parallel port card. |
| PCCARD_TYPE_ATA | Disk controller card. |
| PCCARD_TYPE_VIDEO | Video controller card. |
| PCCARD_TYPE_NETWORK | Network controller card. |
| PCCARD_TYPE_AIMS | Auto-increment mass storage card. |
| PCCARD_TYPE_SCSI_BRIDGE | SCSI bridge card. |
| PCCARD_TYPE_SECURITY | Security card. |
| PCCARD_TYPE_MULTIFUNCTION3 | Multifunction 3.0 PC Card. |
| PCCARD_TYPE_FLASH_MEMORY | Flash memory card. |
| PCCARD_TYPE_MODEM | Modem card. |

### `Reserved`

Reserved.

### `CardInSocket`

Indicates that there is a card present in the socket.

### `CardEnabled`

Indicates that the card is enabled.

### `ControllerType`

Indicates the controller type. Some common controller types are defined in the [PCMCIA_CONTROLLER_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpcm/ne-ntddpcm-_pcmcia_controller_class) enumeration.

## See also

[IOCTL_SOCKET_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpcm/ni-ntddpcm-ioctl_socket_information)