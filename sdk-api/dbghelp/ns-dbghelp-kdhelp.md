# KDHELP structure

## Description

Information that is used by kernel debuggers to trace through user-mode callbacks in a thread's kernel stack.

## Members

### `Thread`

The address of the kernel thread object, as provided in the WAIT_STATE_CHANGE packet.

### `ThCallbackStack`

The offset in the thread object to the pointer to the current callback frame in the kernel stack.

### `NextCallback`

The address of the next callback frame.

### `FramePointer`

The address of the saved frame pointer, if applicable.

### `KiCallUserMode`

The address of the kernel function that calls out to user mode.

### `KeUserCallbackDispatcher`

The address of the user-mode dispatcher function.

### `SystemRangeStart`

The lowest kernel-mode address.

### `ThCallbackBStore`

**Intel Itanium:** The offset in the thread object to a pointer to the current callback backing store frame in the kernel stack.

### `KiUserExceptionDispatcher`

The address of the user-mode exception dispatcher function.

**DbgHelp 6.1 and earlier:** This member is not supported.

### `StackBase`

The address of the stack base.

### `StackLimit`

The stack limit.

### `Reserved`

This member is reserved for use by the operating system.

## Remarks

This structure supersedes the **KDHELP** structure. For more information, see
[Updated Platform Support](https://learn.microsoft.com/windows/desktop/Debug/updated-platform-support). **KDHELP** is defined as follows in Dbghelp.h.

```cpp
#if !defined(_IMAGEHLP_SOURCE_) && defined(_IMAGEHLP64)
#define KDHELP KDHELP64
#define PKDHELP PKDHELP64
#else
typedef struct _KDHELP {
    DWORD   Thread;
    DWORD   ThCallbackStack;
    DWORD   NextCallback;
    DWORD   FramePointer;
    DWORD   KiCallUserMode;
    DWORD   KeUserCallbackDispatcher;
    DWORD   SystemRangeStart;
    DWORD   ThCallbackBStore;
    DWORD   KiUserExceptionDispatcher;
    DWORD   StackBase;
    DWORD   StackLimit;
    DWORD   Reserved[5];
} KDHELP, *PKDHELP;
#endif
```

## See also

[STACKFRAME64](https://learn.microsoft.com/windows/desktop/api/dbghelp/ns-dbghelp-stackframe)