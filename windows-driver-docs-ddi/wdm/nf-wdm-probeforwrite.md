# ProbeForWrite function

## Description

> [!WARNING]
> The **ProbeForWrite** function is not recommended for use in current software, and is included for historical compatibility only. Use [**ProbeForRead**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-probeforread) instead when validating user buffers. See Remarks for more info.

The **ProbeForWrite** routine checks that a user-mode buffer actually resides in the user-mode portion of the address space, is writable, and is correctly aligned.

## Parameters

### `Address` [in, out]

Specifies the beginning of the user-mode buffer.

### `Length` [in]

Specifies the length, in bytes, of the user-mode buffer. See additional information in the Remarks section.

### `Alignment` [in]

Specifies the required alignment, in bytes, of the beginning of the user-mode buffer.

## Remarks

This function typically provides no substantial benefit over [**ProbeForRead**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-probeforread) because a robust driver must always be prepared to handle protection changes in the user mode virtual address space, including protection changes that remove write permission to a buffer passed to a driver after a **ProbeForWrite** call has executed. Because **ProbeForWrite** accesses each page in the supplied buffer, performance may be reduced due to the overhead of accessing each page, especially if the supplied buffer describes a large region of virtual address space. In addition, because **ProbeForWrite** writes to each page, the same buffer may not be used safely with multiple concurrent driver requests. For these reasons, new driver code should always use **ProbeForRead** instead.

The following table outlines the properties of each kernel mode buffer probing routine:

|Behavior|**ProbeForRead**|**ProbeForWrite**|
|-|-|-|
|Confirms that buffer describes a region in user mode address space, if the length is non-zero|x|x|
|Confirms that buffer base address and length do not wrap past maximum pointer value|x|x|
|Confirms that buffer is aligned to requested alignment boundary, if the length is non-zero|x|x|
|Confirms that buffer is initially writable (may change at any time if user mode application reprotects its address space)| |x|
|Accesses each page in the buffer (additional overhead)| |x|
|Modifies each page in the buffer (may cause unexpected behavior if same buffer is used in parallel with multiple driver requests)| |x|

Historically, on certain processors which did not honor read only permissions for kernel mode code, there were meaningful functional differences between **ProbeForWrite** and **ProbeForRead**. In these cases, the operating system previously relied on **ProbeForWrite** performing an explicit paging writability check. This distinction is no longer meaningful for any processors that are supported by Windows NT 4.0 or later.

### Legacy remarks

Kernel-mode drivers may use **ProbeForWrite** to validate write access to buffers allocated in user space. It is most commonly used during METHOD_NEITHER I/O to validate the user buffer pointed to by **Irp->UserBuffer**.

If the specified range of memory is not a valid user-mode address range or is not writable (no access, read-only, and so on), **ProbeForWrite** raises the STATUS_ACCESS_VIOLATION exception. If the beginning of the address range is not aligned on the byte boundary that is specified by *Alignment*, **ProbeForWrite** raises the STATUS_DATATYPE_MISALIGNMENT exception.

Drivers must call **ProbeForWrite** inside a **try/except** block. If the routine raises an exception, the driver should complete the IRP with the appropriate error. Note that subsequent accesses by the driver to the user-mode buffer must also be encapsulated within a **try/except** block: a malicious application could have another thread deleting, substituting, or changing the protection of user address ranges at any time (even after or during a call to **ProbeForRead** or **ProbeForWrite**). For more information, see [Handling Exceptions](https://learn.microsoft.com/windows-hardware/drivers/kernel/handling-exceptions).

Do not use this routine on kernel-mode addresses; it will raise an exception.

If **Irp->RequestorMode** = **KernelMode**, the **Irp->AssociatedIrp.SystemBuffer** and **Irp->UserBuffer** fields do not contain user-mode addresses, and a call to **ProbeForWrite** to probe a buffer pointed to by either field will raise an exception.

If *Length* = 0, **ProbeForWrite** does no checking of the address. In this case, the routine does not raise an exception for an address that is misaligned or is outside the range of valid user addresses.

## See also

[ProbeForRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-probeforread)