# NtAssociateWaitCompletionPacket function

Creates a wait completion association for the target object.

## Parameters

### WaitCompletionPacketHandle [in]

A handle to a wait completion packet which describes the association. This object must not be in use.

### IoCompletionHandle [in]

A handle to an IO completion object which will receive a notification when the object becomes signaled.

### TargetObjectHandle [in]

A handle to a waitable object for which notifications are to be received.

### KeyContext [in]

Supplies the key context that is returned during a call to [NtRemoveIoCompletion](https://learn.microsoft.com/windows/win32/devnotes/ntremoveiocompletion).

### ApcContext [in]

The apc context that is returned during a call to **NtRemoveIoCompletion**.

### IoStatus [in]

The IoStatus->Status data that is returned during a call to **NtRemoveIoCompletion**.

### IoStatusInformation [in]

The IoStatus->Information data that is returned during a call to NtRemoveIoCompletion.

### AlreadySignaled [out]

An optional pointer to a boolean variable that receives an indication of whether the target object was already signaled at the time of the association when this function succeeds.

## Return value

An NTSTATUS code. For more information, see [Using NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

When the object is signaled, a packet is queued to the supplied completion port and the supplied values will be conveyed to a caller of [NtRemoveIoCompletion](https://learn.microsoft.com/windows/win32/devnotes/ntremoveiocompletion). When the packet is picked up, the association must be reestablished by calling this function again. An error is returned if the wait completion packet is already in use for an association.

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions. The API is exported from ntdll.dll.

## Requirements

| Requirement | Value |
|-----------------------------------|-------------------------------------------------------------------------------------------------------|
| DLL | ntdll.dll |