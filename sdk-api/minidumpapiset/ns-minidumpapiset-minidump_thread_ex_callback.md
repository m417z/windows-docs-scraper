# MINIDUMP_THREAD_EX_CALLBACK structure

## Description

Contains extended thread information for the
[MiniDumpCallback](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/nc-minidumpapiset-minidump_callback_routine) function when the callback type is
[ThreadExCallback](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/ne-minidumpapiset-minidump_callback_type).

## Members

### `ThreadId`

The identifier of the thread.

### `ThreadHandle`

A handle to the thread

### `Pad`

### `Context`

A
[CONTEXT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-arm64_nt_context) structure that contains the processor-specific data.

### `SizeOfContext`

The size of the returned processor-specific data in the **Context** member, in bytes.

### `StackBase`

The base address of the thread stack.

### `StackEnd`

The ending address of the thread stack.

### `BackingStoreBase`

**Intel Itanium:** The base address of the thread backing store.

### `BackingStoreEnd`

**Intel Itanium:** The ending address of the thread backing store.

## See also

[CONTEXT](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-arm64_nt_context)

[MINIDUMP_CALLBACK_INPUT](https://learn.microsoft.com/windows/win32/api/minidumpapiset/ns-minidumpapiset-minidump_callback_input)

[MiniDumpCallback](https://learn.microsoft.com/windows/desktop/api/minidumpapiset/nc-minidumpapiset-minidump_callback_routine)