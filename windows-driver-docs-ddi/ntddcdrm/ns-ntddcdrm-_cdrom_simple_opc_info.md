# _CDROM_SIMPLE_OPC_INFO structure

## Description

The **CDROM_SIMPLE_OPC_INFO** structure is the only input for the [IOCTL_CDROM_SEND_OPC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_send_opc_information) I/O control code.

## Members

### `RequestType`

The request type defined in the [CDROM_OPC_INFO_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ne-ntddcdrm-_cdrom_opc_info_type) enumeration.

### `Exclude0`

Exclude layer 0 from OPC.

### `Exclude1`

Exclude layer 1 from OPC.

## Remarks

The [IOCTL_CDROM_SEND_OPC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_send_opc_information) IOCTL is a wrapper for the SEND OPC INFORMATION command of the Multimedia Commands (MMC) specification. The **Exclude0** and **Exclude1** fields of the **CDROM_SIMPLE_OPC_INFO** structure map directly to the corresponding SEND OPC INFORMATION fields.

## See also

[CDROM_OPC_INFO_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ne-ntddcdrm-_cdrom_opc_info_type)

[CDROM_SIMPLE_OPC_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ns-ntddcdrm-_cdrom_simple_opc_info)

[IOCTL_CDROM_SEND_OPC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddcdrm/ni-ntddcdrm-ioctl_cdrom_send_opc_information)