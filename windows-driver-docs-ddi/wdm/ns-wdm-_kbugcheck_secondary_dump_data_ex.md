# _KBUGCHECK_SECONDARY_DUMP_DATA_EX structure

## Description

The **KBUGCHECK_SECONDARY_DUMP_DATA_EX** structure describes multipart data to be written by [*KBUGCHECK_REASON_CALLBACK_ROUTINE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kbugcheck_reason_callback_routine) callback routine to the crash dump file.

## Members

### `InBuffer`

Pointer to a buffer that is allocated by the system.

### `InBufferLength`

Specifies the size of the buffer, in bytes, specified by the **InBuffer** member.

### `MaximumAllowed`

Specifies the maximum amount of data that the [*KBUGCHECK_REASON_CALLBACK_ROUTINE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kbugcheck_reason_callback_routine) routine can write to the crash dump file.

### `Guid`

Specifies a GUID that identifies the driver's crash dump data. (Drivers must use unique GUIDs to mark their crash dump data. Use the GuidGen.exe tool to generate GUIDs for your driver.

### `OutBuffer`

Pointer to the buffer where the driver writes its crash dump data, or **NULL**.

### `OutBufferLength`

Specifies the size of the buffer, in bytes, that was specified by the **OutBuffer** member.

### `Context`

Contains private context data for the exclusive use of the callback routine. The callback routine can set this member to any value. Typically, if the callback routine needs to be called more than one time, the routine sets this member to point to a driver-supplied buffer during the initial call. During subsequent calls, the callback routine can read the previous contents of this buffer and update its contents. Before the initial call to the callback routine, Context is NULL.

### `Flags`

Contains flags that describe the add-page request. The callback routine must set the value of this member. Set this member to the bitwise OR of one or more of the following flag bits:

#### KB_ADD_PAGES_FLAG_VIRTUAL_ADDRESS

Indicates that the **Address** member contains a virtual address.

#### KB_ADD_PAGES_FLAG_PHYSICAL_ADDRESS

Indicates that the **Address** member contains a physical address.

#### KB_ADD_PAGES_FLAG_ADDITIONAL_RANGES_EXIST

Indicates that the callback routine requests that it be called again so that it can add more pages.

The callback routine must set either the KB_ADD_PAGES_FLAG_VIRTUAL_ADDRESS flag or the KB_ADD_PAGES_FLAG_PHYSICAL_ADDRESS flag, but not both. On entry to the callback routine, **Flags** is initialized to zero.

### `DumpType`

One of the following dump types.

```cpp
    DUMP_TYPE_INVALID           = -1,
    DUMP_TYPE_UNKNOWN           = 0,
    DUMP_TYPE_FULL              = 1,
    DUMP_TYPE_SUMMARY           = 2,
    DUMP_TYPE_HEADER            = 3,
    DUMP_TYPE_TRIAGE            = 4,
    DUMP_TYPE_BITMAP_FULL       = 5,
    DUMP_TYPE_BITMAP_KERNEL     = 6,
    DUMP_TYPE_AUTOMATIC         = 7
```

### `BugCheckCode`

Contains a bug check code, which specifies the reason for the bug check. The callback routine can use this information to decide whether to add any pages to the crash dump file. For a full list of bug check codes, see the Bugcodes.h header file included in the WDK.

### `BugCheckParameter1`

Bug Check Parameter 1. The bug check parameters inform the callback the bugcheck parameters that were passed to KeBugcheckEx.

### `BugCheckParameter2`

Bug Check Parameter 2. The bug check parameters inform the callback the bugcheck parameters that were passed to KeBugcheckEx.

### `BugCheckParameter3`

Bug Check Parameter 3. The bug check parameters inform the callback the bugcheck parameters that were passed to KeBugcheckEx.

### `BugCheckParameter4`

Bug Check Parameter 4. The bug check parameters inform the callback the bugcheck parameters that were passed to KeBugcheckEx.

## Remarks

For more information about bug check callback routines, see [Writing a Bug Check Callback Routine](https://learn.microsoft.com/windows-hardware/drivers/kernel/writing-a-bug-check-callback-routine).

## See also

[Writing a Bug Check Callback Routine](https://learn.microsoft.com/windows-hardware/drivers/kernel/writing-a-bug-check-callback-routine).
[*KBUGCHECK_REASON_CALLBACK_ROUTINE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kbugcheck_reason_callback_routine)