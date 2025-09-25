## Description

The **MmSecureVirtualMemory** routine secures a user-space memory address range so that it cannot be freed and its page protection cannot be made more restrictive.

## Parameters

### `Address` [in]

The beginning of the user virtual address range to secure.

### `Size` [in]

The size, in bytes, of the virtual address range to secure.

### `ProbeMode` [in]

Specifies the most restrictive page protection that is allowed. Use PAGE_READWRITE to specify that the address range must remain both readable and writable, or use PAGE_READONLY to specify that the address range must only remain readable.

| ProbeMode | Meaning |
|--|--|
| PAGE_READWRITE | Protection cannot be changed to PAGE_NOACCESS or PAGE_READONLY. All other protection changes are allowed. |
| PAGE_READONLY | Protection cannot be changed to PAGE_NOACCESS. All other protection changes are allowed. |

## Return value

On success, **MmSecureVirtualMemory** returns an opaque pointer value that the driver passes to the [MmUnsecureVirtualMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-mmunsecurevirtualmemory) routine to unsecure the memory address range. If the routine is unable to secure the memory address range, it returns **NULL**.

## Remarks

**MmSecureVirtualMemory** can be used to avoid certain race conditions on user-mode buffers. For example, if a driver checks to see if the buffer is writable, but then the originating user-mode process changes the buffer to be read-only before the driver can write to the buffer, then a race condition can result. The driver can use **MmSecureVirtualMemory** with PAGE_READWRITE probe mode to guarantee that the buffer will remain writable until the driver calls **[MmUnsecureVirtualMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-mmunsecurevirtualmemory)**. The routine also protects against the originating user-mode process freeing the buffer. Here are a few guidelines about calling these routines:

- Calling **MmSecureVirtualMemory** with PAGE_READONLY does not guarantee that the buffer will remain read-only. The read-only probe mode prevents the user from changing the protection of the buffer to PAGE_NOACCESS. It does *not* prevent changing the protection to PAGE_READWRITE (or PAGE_WRITECOPY, for mapped views).

- If a driver calls **MmSecureVirtualMemory** and does not call [MmUnsecureVirtualMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-mmunsecurevirtualmemory), the memory is automatically unsecured when the process terminates.

- If the driver calls [MmUnsecureVirtualMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-mmunsecurevirtualmemory), it must call it in the context of the process in which the memory was originally secured, and before that process terminates.

- Typically drivers need to reference the process when they secure the memory, then later call [KeStackAttachProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-kestackattachprocess) to switch to the context of that process before calling [MmUnsecureVirtualMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-mmunsecurevirtualmemory).

- To detect process termination drivers can use [PsSetCreateProcessNotifyRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-pssetcreateprocessnotifyroutine). Alternatively, the process can submit an IRP with a cancel routine that is invoked by the I/O manager when the process is exiting. In the cancel routine the driver can attach to the process and call [MmUnsecureVirtualMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-mmunsecurevirtualmemory).

While **MmSecureVirtualMemory** can be used to guarantee that reading or writing user memory will not raise an exception due to insufficient page permissions, it does not protect against other types of exceptions. For example, it does not protect against exceptions raised when the system finds a bad disk block in the page file. Therefore, drivers must still wrap all user memory accesses in a **try/except** block. Because of this, we recommend that drivers do not use this function. For more information, see [Handling Exceptions](https://learn.microsoft.com/windows-hardware/drivers/kernel/handling-exceptions).

## See also

[MmUnsecureVirtualMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-mmunsecurevirtualmemory)