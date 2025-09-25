# KBUGCHECK_CALLBACK_RECORD structure

## Description

The KBUGCHECK_CALLBACK_RECORD structure is an opaque structure that is used by the KeRegisterBugCheckCallback and KeDeregisterBugCheckCallback routines.

## Members

### `Entry`

### `CallbackRoutine`

### `Buffer`

### `Length`

### `Component`

### `Checksum`

### `State`

The **KBUGCHECK_CALLBACK_RECORD** structure is used for bookkeeping by the KeRegisterBugCheckReasonCallback and KeDeregisterBugCheckReasonCallback routines.

The structure must be allocated in resident memory, such as nonpaged pool. Use the KeInitializeCallbackRecord routine to initialize the structure before using it.

For more information about how this structure is used, see [Writing a Bug Check Callback Routine](https://learn.microsoft.com/windows-hardware/drivers/kernel/writing-a-bug-check-callback-routine).

## See also

[Writing a Bug Check Callback Routine](https://learn.microsoft.com/windows-hardware/drivers/kernel/writing-a-bug-check-callback-routine).