# _BTHX_HCI_PACKET_TYPE enumeration

## Description

The BTHX_HCI_PACKET_TYPE enumeration lists the different types of packets being sent from the Bluetooth stack to the transport driver.

## Constants

### `HciPacketCommand`

The packet represents a command.

### `HciPacketAclData`

The packet represents ACL data.

### `HciPacketEvent`

The packet represents an event.

## Remarks

The IOCTL_BTHX_READ_HCI and IOCTL_BTHX_WRITE_HCI IOCTLs are used to read/write data to/from the transport driver. The BTHX_HCI_PACKET_TYPE enumeration is used to specify with which type of packet the read/write is associated.

## See also

[IOCTL_BTHX_READ_HCI](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthxddi/ni-bthxddi-ioctl_bthx_read_hci)

[IOCTL_BTHX_WRITE_HCI](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthxddi/ni-bthxddi-ioctl_bthx_write_hci)