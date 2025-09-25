# _BTHX_HCI_READ_WRITE_CONTEXT structure

## Description

The **BTHX_HCI_READ_WRITE_CONTEXT** structure is used by [IOCTL_BTHX_HCI_READ](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthxddi/ni-bthxddi-ioctl_bthx_read_hci) and [IOCTL_BTHX_HCI_WRITE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthxddi/ni-bthxddi-ioctl_bthx_write_hci) for input and output.

## Members

### `DataLen`

The length of data contained in the **Data** field, in bytes.

### `Type`

The type of packetized data.

### `Data`

Actual data to be read/written.

## Remarks

The **BTHX_HCI_READ_WRITE_CONTEXT** structure is an input parameter to [IOCTL_BTHX_HCI_WRITE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthxddi/ni-bthxddi-ioctl_bthx_write_hci) and specifies the type of packet associated with the write. It also specifies the data to be written in the **Data** member.

This structure is also used as an output parameter for [IOCTL_BTHX_HCI_READ](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthxddi/ni-bthxddi-ioctl_bthx_read_hci) and specifies the type of packet and the data associated with the read.

This structure is packed to 1-byte boundary.

## See also

- [IOCTL_BTHX_HCI_WRITE](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthxddi/ni-bthxddi-ioctl_bthx_write_hci)
- [IOCTL_BTHX_HCI_READ](https://learn.microsoft.com/windows-hardware/drivers/ddi/bthxddi/ni-bthxddi-ioctl_bthx_read_hci)