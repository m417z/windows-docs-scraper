# _TAPE_WMI_OPERATIONS structure (minitape.h)

## Description

The tape miniclass driver passes this structure to its [TapeMiniWMIControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_process_command_routine) routine to indicate which WMI operation must be performed by the device.

## Members

### `Method`

Indicates the operation to be performed by the tape device. The operations allowed are as follows:

#### TAPE_CHECK_FOR_DRIVE_PROBLEM

If the tape drive supports commands to return specific device errors, such as tape alerts, the minidriver's [TapeMiniWMIControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_process_command_routine) routine should execute the TAPE_QUERY_DEVICE_ERROR_DATA method Otherwise, it should execute the TAPE_QUERY_IO_ERROR_DATA method.

#### TAPE_QUERY_DEVICE_ERROR_DATA

Returns specific device errors, such as tape alerts. Not all tape drives support this method.

#### TAPE_QUERY_IO_ERROR_DATA

Returns general I/O error data, such as read/write errors, based on the I/O error count. All tape drives support this method.

### `DataBufferSize`

Indicates the size in bytes of the buffer in which the tape minidriver returns the results of the operation.

### `DataBuffer`

Pointer to a buffer in which the tape minidriver returns the results of the operation. The first **sizeof**(ULONG) bytes of **DataBuffer** contain a value of type [TAPE_DRIVE_PROBLEM_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ne-ntddtape-_tape_drive_problem_type), followed by **DataBufferSize** - **sizeof**(ULONG) bytes of tape data.

## See also

[TAPE_DRIVE_PROBLEM_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddtape/ne-ntddtape-_tape_drive_problem_type)

[TapeMiniWMIControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nc-minitape-tape_process_command_routine)