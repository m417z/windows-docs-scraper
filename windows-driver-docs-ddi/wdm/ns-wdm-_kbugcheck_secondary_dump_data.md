# _KBUGCHECK_SECONDARY_DUMP_DATA structure

## Description

The **KBUGCHECK_SECONDARY_DUMP_DATA** structure describes a section of driver-supplied data to be written by KbCallbackSecondaryDumpData routine to the crash dump file.

## Members

### `InBuffer`

Pointer to a buffer that is allocated by the system.

### `InBufferLength`

Specifies the size of the buffer, in bytes, specified by the **InBuffer** member.

### `MaximumAllowed`

Specifies the maximum amount of data that the KbCallbackSecondaryDumpData routine can write to the crash dump file.

### `Guid`

Specifies a GUID that identifies the driver's crash dump data. (Drivers must use unique GUIDs to mark their crash dump data. Use the GuidGen.exe tool to generate GUIDs for your driver. This tool is included in the Microsoft Windows SDK.)

### `OutBuffer`

Pointer to the buffer where the driver writes its crash dump data, or **NULL**.

### `OutBufferLength`

Specifies the size of the buffer, in bytes, that was specified by the **OutBuffer** member.

## Remarks

For more information about how this structure is used, see [Writing a Bug Check Callback Routine](https://learn.microsoft.com/windows-hardware/drivers/kernel/writing-a-bug-check-callback-routine) and [KBUGCHECK_REASON_CALLBACK_ROUTINE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kbugcheck_reason_callback_routine) callback function.

## See also

[Writing a Bug Check Callback Routine](https://learn.microsoft.com/windows-hardware/drivers/kernel/writing-a-bug-check-callback-routine).