# _PHY_CONFIGURATION_PACKET structure

## Description

The PHY_CONFIGURATION_PACKET structure contains a raw PHY configuration packet.

## Members

### `PCP_Phys_ID`

Specifies the node address of the root. This member contains bits 0-5 of byte 0 of the packet.

### `PCP_Packet_ID`

This member must be PHY_PACKET_ID_CONFIGURATION to indicate it is a PHY configuration packet. This member contains bits 6-7 of byte 0 of the packet.

### `PCP_Gap_Count`

If the **PCP_Set_Gap_Count** bit is set, the PHY register gap_count field is set to this value. This member contains bits 0-5 of byte 1 of the packet.

### `PCP_Set_Gap_Count`

If this bit is set, the PHY register gap_count field is set to **PCP_Gap_Count**. This member contains bit 6 of byte 1 of the packet.

### `PCP_Force_Root`

If set, the caller becomes the root node. This member contains bit 7 of byte 1 of the packet.

### `PCP_Reserved1`

Reserved. This member contains bits 0-7 of byte 2 of the packet.

### `PCP_Reserved2`

Reserved. This member contains bits 0-7 of byte 3 of the packet.

### `PCP_Inverse`

Specifies the logical inverse of the first quadlet of the packet.

## Remarks

For an explanation of the function of the PHY configuration packet, see the IEEE 1394 specification.

## See also

[REQUEST_SEND_PHY_CONFIG_PACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class)