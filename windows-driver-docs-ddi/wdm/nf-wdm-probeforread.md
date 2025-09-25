# ProbeForRead function

## Description

The **ProbeForRead** routine checks that a user-mode buffer actually resides in the user portion of the address space, and is correctly aligned.

## Parameters

### `Address` [in]

Specifies the beginning of the user-mode buffer.

### `Length` [in]

Specifies the length, in bytes, of the user-mode buffer.

### `Alignment` [in]

Specifies the required alignment, in bytes, of the beginning of the user-mode buffer.

## Remarks

If the specified range of memory is not within the user-mode address range, **ProbeForRead** raises the STATUS_ACCESS_VIOLATION exception. If the beginning of the address range is not aligned on the byte boundary that is specified by *Alignment*, **ProbeForRead** raises the STATUS_DATATYPE_MISALIGNMENT exception.

Kernel-mode drivers must use **ProbeForRead** to validate read access to buffers that are allocated in user space. It is most commonly used during METHOD_NEITHER I/O to validate the user buffer pointed to by **Irp -> UserBuffer**.

Drivers must call **ProbeForRead** inside a **try/except** block. If the routine raises an exception, the driver should complete the IRP with the appropriate error. Note that subsequent accesses by the driver to the user-mode buffer must also be encapsulated within a **try/except** block: a malicious application could have another thread deleting, substituting, or changing the protection of user address ranges at any time (even after or during a call to **ProbeForRead** or **ProbeForWrite**). For more information, see [Handling Exceptions](https://learn.microsoft.com/windows-hardware/drivers/kernel/handling-exceptions).

Do not use this routine on kernel-mode addresses; it will raise an exception.

If **Irp->RequestorMode** = **KernelMode**, the **Irp->AssociatedIrp.SystemBuffer** and **Irp->UserBuffer** fields do not contain user-mode addresses, and a call to **ProbeForRead** to probe a buffer pointed to by either field will raise an exception.

If *Length* = 0, **ProbeForRead** does no checking of the address. In this case, the routine does not raise an exception for an address that is misaligned or is outside the range of valid user addresses.

## See also

[ProbeForWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-probeforwrite)