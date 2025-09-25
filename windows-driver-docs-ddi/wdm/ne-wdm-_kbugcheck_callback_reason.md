# _KBUGCHECK_CALLBACK_REASON enumeration

## Description

The **KBUGCHECK_CALLBACK_REASON** enumeration type specifies the situations in which a bug-check callback executes.

## Constants

### `KbCallbackInvalid`

Reserved for system use. Do not use.

### `KbCallbackReserved1`

Reserved for system use. Do not use.

### `KbCallbackSecondaryDumpData`

The callback function provides data to append to the secondary data area of the crash dump file when the system issues a bug check. For more information about this type of callback, see [Implementing a KbCallbackSecondaryDumpData Callback Routine](https://learn.microsoft.com/windows-hardware/drivers/kernel/writing-a-bug-check-callback-routine#implementing-a-kbcallbacksecondarydumpdata-callback-routine).

### `KbCallbackDumpIo`

Specifies that the system should call the callback function each time it writes data to a crash dump file. Drivers for devices that monitor the system state can use this type of callback. For more information about this type of callback, see [Implementing a KbCallbackDumpIo Callback Routine](https://learn.microsoft.com/windows-hardware/drivers/kernel/writing-a-bug-check-callback-routine#implementing-a-kbcallbackdumpio-callback-routine).

### `KbCallbackAddPages`

The callback function adds one or more pages of driver-specific data to the primary section of the crash dump file when the operating system issues a bug check. For more information about this type of callback, see [Implementing a KbCallbackAddPages Callback Routine](https://learn.microsoft.com/windows-hardware/drivers/kernel/writing-a-bug-check-callback-routine#implementing-a-kbcallbackaddpages-callback-routine).

### `KbCallbackSecondaryMultiPartDumpData`

Specifies that the callback is executed to get the amount of data the driver wants to store in the dump file. This enumeration value is supported in Windows Server 2008 and later versions of Windows.

### `KbCallbackRemovePages`

The callback function removes one or more pages of driver-supplied data from the crash dump file. For more information, see **[KBUGCHECK_REMOVE_PAGES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_kbugcheck_remove_pages)**.

### `KbCallbackTriageDumpData`

Specifies that the callback is executed to add virtual memory ranges the driver wants to preserve in the carved minidump file. This enumeration value is supported starting in Windows 10, version 1809 and Windows Server 2019. For more information about this type of callback, see [Implementing a KbCallbackTriageDumpData Callback Routine](https://learn.microsoft.com/windows-hardware/drivers/kernel/writing-a-bug-check-callback-routine#implementing-a-kbcallbacktriagedumpdata-callback-routine).

### `KbCallbackReserved2`

Reserved for system use. Do not use.

### `KbCallbackReserved3`

Reserved for system use. Do not use.

## Remarks

A driver uses this enumeration to specify the type of [*KBUGCHECK_REASON_CALLBACK_ROUTINE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kbugcheck_reason_callback_routine) callback routine to register when it calls the [**KeRegisterBugCheckReasonCallback**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keregisterbugcheckreasoncallback) function.

For information about how this enumeration is used, see [Writing a Bug Check Callback Routine](https://learn.microsoft.com/windows-hardware/drivers/kernel/writing-a-bug-check-callback-routine).

## See also

[Writing a Bug Check Callback Routine](https://learn.microsoft.com/windows-hardware/drivers/kernel/writing-a-bug-check-callback-routine)

[KBUGCHECK_REASON_CALLBACK_RECORD](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[KeRegisterBugCheckReasonCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keregisterbugcheckreasoncallback)