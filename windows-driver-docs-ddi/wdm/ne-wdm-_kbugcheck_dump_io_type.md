# _KBUGCHECK_DUMP_IO_TYPE enumeration

## Description

The **KBUGCHECK_DUMP_IO_TYPE** enumeration type identifies the type of a section of data within a crash dump file.

## Constants

### `KbDumpIoInvalid`

Reserved for system use. Do not use.

### `KbDumpIoHeader`

Specifies that crash dump data is header information.

### `KbDumpIoBody`

Specifies that the crash dump data is part of the main body of the crash dump, such as the memory state at the time of the bug check.

### `KbDumpIoSecondaryData`

Specifies that the crash dump data is data returned by a KbCallbackSecondaryDumpData routine.

### `KbDumpIoComplete`

Specifies that the crash dump data has been completely written.

## Remarks

**KBUGCHECK_DUMP_IO_TYPE** values are used in the **Type** member of [KBUGCHECK_DUMP_IO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_kbugcheck_dump_io) to specify the type of data in an I/O operation on the crash dump file.

 For more information about this type of callback, see "Implementing KbCallbackDumpIo Callback Routine" in [Writing a Bug Check Callback Routine](https://learn.microsoft.com/windows-hardware/drivers/kernel/writing-a-bug-check-callback-routine).

## See also

[Writing a Bug Check Callback Routine](https://learn.microsoft.com/windows-hardware/drivers/kernel/writing-a-bug-check-callback-routine)

[KBUGCHECK_DUMP_IO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_kbugcheck_dump_io)