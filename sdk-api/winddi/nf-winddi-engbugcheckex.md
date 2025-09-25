# EngBugCheckEx function

## Description

The **EngBugCheckEx** function brings down the system in a controlled manner when the caller discovers an unrecoverable error that would corrupt the system if the caller continued to run.

## Parameters

### `BugCheckCode` [in]

Specifies a value that indicates the reason for the bug check.

### `P1` [in]

Pointer to a value that supplies additional information, such as the address and data where a memory-corruption error occurred. The value depends on the value of the *BugCheckCode* parameter.

### `P2` [in]

Pointer to a value that supplies additional information, such as the address and data where a memory-corruption error occurred. The value depends on the value of the *BugCheckCode* parameter.

### `P3` [in]

Pointer to a value that supplies additional information, such as the address and data where a memory-corruption error occurred. The value depends on the value of the *BugCheckCode* parameter.

### `P4` [in]

Pointer to a value that supplies additional information, such as the address and data where a memory-corruption error occurred. The value depends on the value of the *BugCheckCode* parameter.

## Return value

None

## Remarks

A bug check is a system-detected error that causes an immediate, controlled shutdown of the system. When a graphics driver discovers an unrecoverable error, it should generate a bug check.

A graphics driver should call **EngBugCheckEx** *only* in the event of a fatal, unrecoverable error that could corrupt the system. Whenever possible, all graphics drivers should log an error and continue to run. For example, if a driver is unable to allocate required resources, it should log an error so that the system continues to run; it must not generate a bug check.

**EngBugCheckEx** can be useful in the early stages of developing a graphics driver, or while it is undergoing testing. In these circumstances, the *BugCheckCode* value passed to this function should be distinct from those codes already in use by Windows or its drivers. For a list of these codes, see [Bug Check Codes](https://learn.microsoft.com/windows-hardware/drivers/debugger/bug-check-code-reference2).

However, even during driver development, this routine is of only limited use, because it results in a complete system shutdown. A more effective debugging method is to attach a kernel debugger to the system and then use routines that send messages to the debugger or break into the debugger. For more information, see [Using Debugging Code in a Driver](https://learn.microsoft.com/windows-hardware/drivers/devtest/using-debugging-code-in-a-driver).