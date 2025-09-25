# KBUGCHECK_REMOVE_PAGES structure

## Description

The **KBUGCHECK_REMOVE_PAGES** structure describes one or more pages of driver-supplied data to be removed by a [*KBUGCHECK_REASON_CALLBACK_ROUTINE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kbugcheck_reason_callback_routine) callback routine from the crash dump file.

## Members

### `Context`

Contains private context data for the exclusive use of the callback routine. The callback routine can set this member to any value. Typically, if the callback routine needs to be called more than one time, the routine sets this member to point to a driver-supplied buffer during the initial call. During subsequent calls, the callback routine can read the previous contents of this buffer and update its contents. Before the initial call to the callback routine, **Context** is **NULL**.

### `Flags`

Contains flags that describe the remove-page request. The callback routine must set the value of this member. Set this member to the bitwise OR of one or more of the following flag bits:

```cpp
KB_ADD_PAGES_FEATURE_SHIFT       4

KB_REMOVE_PAGES_FEATURE_SHIFT    4

KB_ADD_PAGES_FEATURE_MASK        (0xF << KB_ADD_PAGES_FEATURE_SHIFT)

KB_REMOVE_PAGES_FEATURE_MASK     (0xF << (KB_ADD_PAGES_FEATURE_SHIFT + KB_REMOVE_PAGES_FEATURE_SHIFT))
```

### `BugCheckCode`

Contains a bug check code, which specifies the reason for the bug check. The callback routine can use this information to decide whether to add any pages to the crash dump file. For a full list of bug check codes, see the Bugcodes.h header file included in the WDK.

### `Address`

Specifies the physical or virtual address of the page or pages that the callback routine requests be removed from the crash dump file.

### `Count`

Specifies the number of contiguous pages to remove from the crash dump file, starting from the virtual or physical address that is specified by the **Address** member. If **Count** > 1 and **Address** is a virtual address, the pages are contiguous in virtual memory space. If **Count** > 1 and **Address** is a physical address, the pages are contiguous in physical memory space. The callback routine can set this member to zero to indicate that it does not need to remove any pages from the crash dump file.

## Remarks

In a call to the [*KBUGCHECK_REASON_CALLBACK_ROUTINE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kbugcheck_reason_callback_routine) callback routine, the operating system sets the *Reason* parameter to **KbCallbackRemovePages**, and sets the *ReasonSpecificData* parameter to point to a **KBUGCHECK_REMOVE_PAGES** structure.

For more information about bug check callback routines, see [Writing a Bug Check Callback Routine](https://learn.microsoft.com/windows-hardware/drivers/kernel/writing-a-bug-check-callback-routine).

## See also