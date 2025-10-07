# NtCancelWaitCompletionPacket function

Cancels an active wait completion association if it has not been picked up from the completion port.

## Parameters

### WaitCompletionPacketHandle [in]

A handle to a wait completion packet.

### RemoveSignaledPacket [in]

a boolean which determines whether this function will attempt to cancel a packet from an IO completion object queue.

## Return value

An NTSTATUS code. For more information, see [Using NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

| Value | Description |
|-------|-------------|
| STATUS_SUCCESS | Success |
| STATUS_PENDING | The wait completion may be pending and the packet cannot be immediately reused. |
| STATUS_CANCELLED | The packet has already been completed or if has never been associated. |

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions. The API is exported from ntdll.dll.

## Requirements

| Requirement | Value |
|-----------------------------------|-------------------------------------------------------------------------------------------------------|
| DLL | ntdll.dll |