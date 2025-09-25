# _ROOTHUB_30PORT_INFO_EX structure

## Description

Provides extended USB 3.0 port information about speed.

## Members

### `Info`

A [ROOTHUB_30PORT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucxroothub/ns-ucxroothub-_roothub_30port_info) structure.

### `MaxSpeedsCount`

Maximum number of speeds.

### `SpeedsCount`

The count of bus speeds supported.

### `Speeds`

A pointer to a **USB_DEVICE_CAPABILITY_SUPERSPEEDPLUS_SPEED** structure that describes the USB 3.1capability's sublink speed attributes. For structure declaration, see Usbspec.h