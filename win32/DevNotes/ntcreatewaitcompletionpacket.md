# NtCreateWaitCompletionPacket function

Creates a wait completion packet object with the specified access rights and attributes.

## Parameters

### WaitCompletionPacketHandle [out]

A pointer to a variable that receives the wait completion packet handle.

### DesiredAccess [in]

The desired types of access for the wait completion packet.

### ObjectAttributes [in]

A pointer to an object attributes structure.

## Return value

An NTSTATUS code. For more information, see [Using NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) functions. The API is exported from ntdll.dll.

## Requirements

| Requirement | Value |
|-----------------------------------|-------------------------------------------------------------------------------------------------------|
| DLL | ntdll.dll |