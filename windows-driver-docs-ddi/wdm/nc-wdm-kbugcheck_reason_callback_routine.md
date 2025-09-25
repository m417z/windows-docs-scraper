## Description

Driver-implemented callback functions that the system executes when it issues a bug check.

See [**KBUGCHECK_CALLBACK_REASON**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_kbugcheck_callback_reason) for information on available callback types.

## Parameters

### `Reason` [in]

An enumeration of type [**KBUGCHECK_CALLBACK_REASON**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_kbugcheck_callback_reason) that specifies the reason for the call to the callback routine.

### `Record` [in]

A pointer to the [**KBUGCHECK_REASON_CALLBACK_RECORD**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_kbugcheck_reason_callback_record) structure that the driver supplied when it registered this callback. For more information, see the description of the *CallbackRecord* parameter in [**KeRegisterBugCheckReasonCallback**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keregisterbugcheckreasoncallback).

### `ReasonSpecificData` [in, out]

Pointer to a buffer that contains a structure of type determined by the table below. Certain members of this structure are filled in by the operating system before it calls the callback routine, and other members must be filled in by the callback routine. For more information, see [Writing a Bug Check Callback Routine](https://learn.microsoft.com/windows-hardware/drivers/kernel/writing-a-bug-check-callback-routine).

| Value | Data structure |
|---|---|
| **KbCallbackSecondaryDumpData** | [**KBUGCHECK_SECONDARY_DUMP_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_kbugcheck_secondary_dump_data) |
| **KbCallbackDumpIo** | [**KBUGCHECK_DUMP_IO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_kbugcheck_dump_io) |
| **KbCallbackAddPages** | [**KBUGCHECK_ADD_PAGES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_kbugcheck_add_pages) |
| **KbCallbackSecondaryMultiPartDumpData** | [**KBUGCHECK_SECONDARY_DUMP_DATA_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_kbugcheck_secondary_dump_data_ex) |
| **KbCallbackRemovePages** | [**KBUGCHECK_REMOVE_PAGES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_kbugcheck_remove_pages) |
| **KbCallbackTriageDumpData** | [**KBUGCHECK_TRIAGE_DUMP_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_kbugcheck_triage_dump_data) |

### `ReasonSpecificDataLength` [in]

Specifies the size, in bytes, of the buffer that the *ReasonSpecificData* parameter points to.

## Remarks

For information about how to implement this callback routine, see [Writing a Bug Check Callback Routine](https://learn.microsoft.com/windows-hardware/drivers/kernel/writing-a-bug-check-callback-routine).

For sample code that shows how to write data to the crash dump file, see [DMF_CrashDump](https://github.com/Microsoft/DMF/blob/master/Dmf/Modules.Library/Dmf_CrashDump.md).

## See also

[**KBUGCHECK_ADD_PAGES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_kbugcheck_add_pages)

[KBUGCHECK_CALLBACK_REASON](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_kbugcheck_callback_reason)

[KBUGCHECK_REASON_CALLBACK_RECORD](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[KeRegisterBugCheckReasonCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keregisterbugcheckreasoncallback)

[KeDeregisterBugCheckReasonCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kederegisterbugcheckreasoncallback)

[Writing a Bug Check Callback Routine](https://learn.microsoft.com/windows-hardware/drivers/kernel/writing-a-bug-check-callback-routine).