# MmSecureVirtualMemoryEx function

## Description

This routine probes the requested address range and protects the specified address range from having its protection made more restrictive and being deleted.

## Parameters

### `Address`

Pointer to the base address to probe and secure.

### `Size`

Specifies the size, in bytes, of the range to secure.

### `ProbeMode`

Specifies the most restrictive page protection that is allowed. Use PAGE_READWRITE to specify that the address range must remain both readable and writable, or use PAGE_READONLY to specify that the address range must only remain readable.

|ProbeMode|Meaning|
|--- |--- |
|PAGE_READWRITE|Protection cannot be changed to PAGE_NOACCESS or PAGE_READONLY. All other protection changes are allowed.|
|PAGE_READONLY|Protection cannot be changed to PAGE_NOACCESS. All other protection changes are allowed.|

### `Flags`

Specifies one or more of the following flags:

|Flag|Description|
|--- |--- |
|**MM_SECURE_EXCLUSIVE**|Securing only succeeds if there are no other secures already pinned anywhere onto the VAD in question.|
|**MM_SECURE_NO_CHANGE**|Once applied, no protection changes are allowed for the supplied virtual address region. The region can still be deleted if the process is exiting.|
|**MM_SECURE_USER_MODE_ONLY**|The protection specified by this securing will only be applied to subsequent calls from user mode that are trying to change the protection (kernel mode callers will bypass this securing).|
|**MM_SECURE_NO_INHERIT**|If the process is cloned, then unlike the parent process, VAD of the child process will not be secured.|

## Return value

Returns a value resembling a handle to be used only to unsecure the range.

If the range could not be locked because of protection problems, noncommitted memory or invalid parameters, this routine returns NULL.

## Remarks

Use **MmSecureVirtualMemoryEx** instead of [**MmSecureVirtualMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-mmsecurevirtualmemory) if you need to specify **MM_SECURE_NO_CHANGE** so that no protection change will be allowed on the supplied view.

The return value from this function can only be used with [**MmUnsecureVirtualMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-mmunsecurevirtualmemory). The driver calls that routine to return the range to a normal state.

## See also

- [**MmSecureVirtualMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-mmsecurevirtualmemory)
- [**MmUnsecureVirtualMemory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-mmunsecurevirtualmemory)