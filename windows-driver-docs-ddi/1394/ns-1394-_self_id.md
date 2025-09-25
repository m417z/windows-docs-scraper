# _SELF_ID structure

## Description

The SELF_ID structure contains a raw packet zero self-ID packet.

## Members

### `SID_Phys_ID`

Specifies the device node number. This member contains bits 0-5 of byte 0 of the self-ID packet.

### `SID_Packet_ID`

Must be PHY_PACKET_ID_SELF_ID. This member contains bits 6-7 of byte 0 of the self-ID packet.

### `SID_Gap_Count`

Specifies the current value of the node's PHY_CONFIGURATION register's gap_count member. This member contains bits 0-5 of byte 1 of the self-ID packet.

### `SID_Link_Active`

One if the device's link and transaction layers are active, zero otherwise. This member contains bit 6 of byte 1 of the self-ID packet.

### `SID_Zero`

Always zero. This member contains bit 7 of byte 1 of the self-ID packet.

### `SID_Power_Class`

The possible power classes are:

POWER_CLASS_NOT_NEED_NOT_REPEAT

POWER_CLASS_SELF_POWER_PROVIDE_15W

POWER_CLASS_SELF_POWER_PROVIDE_30W

POWER_CLASS_SELF_POWER_PROVIDE_45W

POWER_CLASS_MAYBE_POWERED_UPTO_1W

POWER_CLASS_IS_POWERED_UPTO_1W_NEEDS_2W

POWER_CLASS_IS_POWERED_UPTO_1W_NEEDS_5W

POWER_CLASS_IS_POWERED_UPTO_1W_NEEDS_9W

This member contains bits 0-2 of byte 2 of the self-ID packet.

### `SID_Contender`

One if this node is a contender for bus or isochronous resource manager, zero otherwise. This member contains bit 3 of byte 2 of the self-ID packet.

### `SID_Delay`

Currently always zero. This member contains bits 4-5 of byte 2 of the self-ID packet.

### `SID_Speed`

Specifies the maximum data transfer rate that is supported by the node. This member must have one of the values specified in the following table.

| Value | Speed |
| --- | --- |
| 0 | S100 speed |
| 1 | S200 speed |
| 2 | S400 speed |
| 3 | Reserved (generally treated as S400/S800 speed) |

### `SID_More_Packets`

One if this packet will be followed by SELF_ID_MORE packets, zero otherwise. This member contains bit 0 of byte 3 of the self-ID packet.

### `SID_Initiated_Rst`

One if this node initiated the most recent bus reset, zero otherwise. This member contains bit 1 of byte 3 of the self-ID packet.

### `SID_Port3`

Byte 3 - Bits 2-3

### `SID_Port2`

Byte 3 - Bits 4-5

### `SID_Port1`

Specifies port status. Possible values are:

SELF_ID_CONNECTED_TO_CHILD

SELF_ID_CONNECTED_TO_PARENT

SELF_ID_NOT_CONNECTED

SELF_ID_NOT_PRESENT

Member **SID_Port1** contains bits 2-3 of byte 3 of the self-ID packet. Member **SID_Port2** contains bits 4-5 of byte 3 of the self-ID packet. Member **SID_Port3** contains bits 6-7 of byte 3 of the self-ID packet.

## Remarks

This structure corresponds to self ID packet 0, as described in the *P1394a* specification.

## See also

[TOPOLOGY_MAP](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ns-1394-_topology_map)