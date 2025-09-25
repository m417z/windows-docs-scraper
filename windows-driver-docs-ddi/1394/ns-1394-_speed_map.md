# _SPEED_MAP structure

## Description

The SPEED_MAP structure is stores an IEEE 1394 bus speed map.

## Members

### `SPD_Length`

Specifies the number of quadlets in the speed map.

### `SPD_CRC`

Specifies the CRC value for the speed map.

### `SPD_Generation`

Specifies the generation count for the bus reset that corresponds to this speed map.

### `SPD_Speed_Code`

Specifies an array of speed codes. Currently, the possible values are:

SCODE_100_RATE

SCODE_200_RATE

SCODE_400_RATE

## Remarks

The SPEED_MAP structure describes the maximum speed that devices on the bus can attain. All values in this structure are recorded in big-endian format.

## See also

[REQUEST_GET_SPEED_TOPOLOGY_MAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class)