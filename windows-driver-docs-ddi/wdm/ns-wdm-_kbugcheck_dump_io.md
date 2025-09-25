# _KBUGCHECK_DUMP_IO structure

## Description

The **KBUGCHECK_DUMP_IO** structure describes an I/O operation on the crash dump file.

## Members

### `Offset`

Specifies the current offset in the crash dump file, or -1 if the crash dump file is being written sequentially.

### `Buffer`

Pointer to a buffer that contains the current data to be written to the dump file.

### `BufferLength`

Specifies the length of the buffer, in bytes, that is specified by the **Buffer** member.

### `Type`

Specifies the [KBUGCHECK_DUMP_IO_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_kbugcheck_dump_io_type) value that signifies the type of data to be written to the dump file.

## Remarks

For information about how this structure is used, see [Writing a Bug Check Callback Routine](https://learn.microsoft.com/windows-hardware/drivers/kernel/writing-a-bug-check-callback-routine).

## See also

[Writing a Bug Check Callback Routine](https://learn.microsoft.com/windows-hardware/drivers/kernel/writing-a-bug-check-callback-routine)

[KBUGCHECK_DUMP_IO_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_kbugcheck_dump_io_type)