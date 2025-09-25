# _TAPE_CREATE_PARTITION structure (minitape.h)

## Description

The TAPE_CREATE_PARTITION structure is used in conjunction with the [IOCTL_TAPE_CREATE_PARTITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ni-ntddtape-ioctl_tape_create_partition) request to create a specified number of fixed, select, or initiator partitions of a given size on the tape media.

## Members

### `Method`

Indicates the method used to create the partitions. This member can have one of the following values:

| Method | Meaning |
| --- | --- |
| TAPE_FIXED_PARTITIONS | Partitions the tape based on the device's default definition of partitions. The **Count** and **Size** parameters are ignored. |
| TAPE_SELECT_PARTITIONS | Partitions the tape into the number of partitions specified by **Count**. The **Size** parameter is ignored. The size of the partitions is determined by the device's default partition size. For more specific information, refer to the documentation for your tape device. |
| TAPE_INITIATOR_PARTITIONS | Partitions the tape into the number and size of partitions specified by **Count** and **Size**, respectively, except for the last partition. The size of the last partition is the remainder of the tape. |

### `Count`

Indicates the number of partitions to create.

### `Size`

Indicates the size of each partition, in bytes.

## See also

[IOCTL_TAPE_CREATE_PARTITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ni-ntddtape-ioctl_tape_create_partition)

[TapeMiniCreatePartition](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_process_command_routine)