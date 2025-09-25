# IDebugControl2::GetDebuggeeType

## Description

The **GetDebuggeeType** method describes the nature of the current target.

## Parameters

### `Class` [out]

Receives the class of the current target. It will be set to one of the values in the following table.

| Value | Description |
| --- | --- |
| DEBUG_CLASS_UNINITIALIZED | There is no current target. |
| DEBUG_CLASS_KERNEL | The current target is a kernel-mode target. |
| DEBUG_CLASS_USER_WINDOWS | The current target is a user-mode target. |

### `Qualifier` [out]

Provides more details about the type of the target. Its interpretation depends on the value of *Class*. When class is DEBUG_CLASS_UNINITIALIZED, *Qualifier* returns zero. The following values are applicable for kernel-mode targets.

| Value | Description |
| --- | --- |
| DEBUG_KERNEL_CONNECTION | The current target is a live kernel being debugged in the standard way (using a COM port, 1394 bus, or named pipe). |
| DEBUG_KERNEL_LOCAL | The current target is the local kernel. |
| DEBUG_KERNEL_EXDI_DRIVER | The current target is a live kernel connected using eXDI drivers. |
| DEBUG_KERNEL_SMALL_DUMP | The current target is a kernel-mode Small Memory Dump file. |
| DEBUG_KERNEL_DUMP | The current target is a kernel-mode Kernel Memory Dump file. |
| DEBUG_KERNEL_FULL_DUMP | The current target is a kernel-mode Complete Memory Dump file. |

The following values are applicable for user-mode targets.

| Value | Description |
| --- | --- |
| DEBUG_USER_WINDOWS_PROCESS | The current target is a user-mode process on the same computer as the [debugger engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/introduction). |
| DEBUG_USER_WINDOWS_PROCESS_SERVER | The current target is a user-mode process connected using a process server. |
| DEBUG_USER_WINDOWS_SMALL_DUMP | The current target is a user-mode Minidump file. |
| DEBUG_USER_WINDOWS_DUMP | The current target is a Full User-Mode Dump file. |

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |