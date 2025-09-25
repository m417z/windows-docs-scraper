# _KBUGCHECK_TRIAGE_DUMP_DATA structure

## Description

The **_KBUGCHECK_TRIAGE_DUMP_DATA** structure describes dump data used in conjunction with the [*KBUGCHECK_REASON_CALLBACK_ROUTINE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kbugcheck_reason_callback_routine) callback routine.

## Members

### `DataArray`

A pointer to a [_KBUGCHECK_TRIAGE_DUMP_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_ktriage_dump_data_array) structure. This is the method the callback uses to provide the triage block data array that it created.

### `Flags`

Flags which are passed into the callback.

```cpp
KB_TRIAGE_DUMP_DATA_FLAG_BUGCHECK_ACTIVE 0x00000001
```

Indicates the callback is invoked during a bugcheck. Currently, this flag is expected to always be set.

### `MaxVirtMemSize`

The maximum virtual memory size in bytes the callback is allowed to add to the dump. The cumulative size of the regions described in the data array should not exceed this size.

### `BugCheckCode`

This value informs the callback which bugcheck code that was passed to KeBugcheckEx. The callback routine can use this information to decide whether to add any memory to the crash dump file. For a full list of bug check codes, see the Bugcodes.h header file included in the WDK.

### `BugCheckParameter1`

Bug Check Parameter 1. The bug check parameters inform the callback the bugcheck parameters that were passed to KeBugcheckEx.

### `BugCheckParameter2`

Bug Check Parameter 2. The bug check parameters inform the callback the bugcheck parameters that were passed to KeBugcheckEx.

### `BugCheckParameter3`

Bug Check Parameter 3. The bug check parameters inform the callback the bugcheck parameters that were passed to KeBugcheckEx.

### `BugCheckParameter4`

Bug Check Parameter 4. The bug check parameters inform the callback the bugcheck parameters that were passed to KeBugcheckEx.

## Remarks

The driver receives a structure of this type as a parameter to its [*KBUGCHECK_REASON_CALLBACK_ROUTINE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kbugcheck_reason_callback_routine) callback routine.

From the callback routine, the driver calls the [**KeAddTriageDumpDataBlock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keaddtriagedumpdatablock) function to modify a dump data array.

## See also

[Writing a Bug Check Callback Routine](https://learn.microsoft.com/windows-hardware/drivers/kernel/writing-a-bug-check-callback-routine).