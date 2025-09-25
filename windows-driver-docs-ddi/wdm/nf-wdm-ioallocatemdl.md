# IoAllocateMdl function

## Description

The **IoAllocateMdl** routine allocates a memory descriptor list (MDL) large enough to map a buffer, given the buffer's starting address and length. Optionally, this routine associates the MDL with an IRP.

## Parameters

### `VirtualAddress` [in, optional]

Pointer to the base virtual address of the buffer the MDL is to describe.

### `Length` [in]

Specifies the length, in bytes, of the buffer that the MDL is to describe. For more information, see the following Remarks section.

### `SecondaryBuffer` [in]

Indicates whether the buffer is a primary or secondary buffer. This parameter determines how the MDL is to be linked to the IRP. All buffers except the first buffer described by an MDL in an IRP are considered secondary buffers. This field must be **FALSE** if no IRP is associated with the MDL. For more information, see the following Remarks section.

### `ChargeQuota` [in]

Reserved for system use. Drivers must set this parameter to **FALSE**.

### `Irp` [in, out, optional]

Pointer to an IRP to be associated with the MDL. If the *Irp* pointer is non-**NULL**, the allocated MDL is associated with the specified IRP's MDL list, according to the value of *SecondaryBuffer*.

## Return value

**IoAllocateMdl** returns a pointer to an MDL, or, if the MDL cannot be allocated, it returns **NULL**.

## Remarks

**IoAllocateMdl** can be used by a driver that needs to break a buffer into pieces, each mapped by a separate MDL, or to map a driver-allocated buffer. The driver should call [MmBuildMdlForNonPagedPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmbuildmdlfornonpagedpool) with the MDL allocated by this call to set up an MDL describing a driver-allocated buffer in nonpaged pool.

The *Length* parameter specifies the size of the buffer that is to be described by the MDL. In Windows Server 2003, Windows XP, and Windows 2000, the maximum buffer size, in bytes, that this routine can allocate is PAGE_SIZE * (65535 - **sizeof**(MDL)) / **sizeof**(ULONG_PTR). In Windows Vista and Windows Server 2008, the maximum buffer size is (2 gigabytes - PAGE_SIZE). Starting in Windows 7 and Windows Server 2008 R2, the maximum buffer size is (4 gigabytes - PAGE_SIZE).

If the *SecondaryBuffer* parameter is **FALSE**, the routine updates *Irp*->**MdlAddress** to point to the new MDL. If *SecondaryBuffer* is **TRUE**, the routine adds the MDL to the end of the MDL chain that *Irp*->**MdlAddress** points to.

For more information about MDLs, see [Using MDLs](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-mdls).

## See also

[IoBuildPartialMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildpartialmdl)

[IoFreeMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iofreemdl)

[MmBuildMdlForNonPagedPool](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmbuildmdlfornonpagedpool)