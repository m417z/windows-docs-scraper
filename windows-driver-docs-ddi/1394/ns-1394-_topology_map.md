# _TOPOLOGY_MAP structure

## Description

The TOPOLOGY_MAP structure is used to store an IEEE 1394 bus topology map. The relations between devices are found in the port members of the entries in **TOP_Self_ID_Array**.

## Members

### `TOP_Length`

Specifies the length in quadlets of the topology map.

### `TOP_CRC`

Specifies the CRC value for the topology map.

### `TOP_Generation`

Specifies the bus reset generation for which the topology map was created.

### `TOP_Node_Count`

Specifies the number of nodes in the topology map.

### `TOP_Self_ID_Count`

Specifies the number of entries in **TOP_Self_ID_Array**.

### `TOP_Self_ID_Array`

Pointer to an array of [SELF_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ns-1394-_self_id) and [SELF_ID_MORE](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ns-1394-_self_id_more) structures (the two structures are the same size).

## Remarks

All data will be in big-endian format.

## See also

[REQUEST_GET_SPEED_TOPOLOGY_MAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class)