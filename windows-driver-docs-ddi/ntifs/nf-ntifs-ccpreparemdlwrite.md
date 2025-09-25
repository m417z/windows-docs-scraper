# CcPrepareMdlWrite function

## Description

The **CcPrepareMdlWrite** routine provides direct access to cached file memory so that the caller can write data to the file.

## Parameters

### `FileObject` [in]

Pointer to a file object for the cached file.

### `FileOffset` [in]

Pointer to a variable that specifies the starting byte offset within the cached file where the data is to be written.

### `Length` [in]

Length in bytes of the data to be written to the system cache.

### `MdlChain` [out]

A chain of one or more memory descriptor lists (MDL) describing the pages to which the data is to be written.

### `IoStatus` [out]

Pointer to an IO_STATUS_BLOCK structure. If the call to **CcPrepareMdlWrite** succeeds, *IoStatus.Status* is set to STATUS_SUCCESS. Otherwise, it is set to an appropriate NTSTATUS error code. *IoStatus.Information* is set to the actual number of bytes that were successfully locked down in the MDL chain.

## Remarks

**CcPrepareMdlWrite** is similar to [CcCopyWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-cccopywrite), except that the data is not copied to the cached file. Instead, the physical pages to be overwritten in the system cache are locked in memory, and **CcPrepareMdlWrite** returns one or more memory descriptor lists (MDL) describing the specified byte range. These pages remain locked in memory until [CcMdlWriteComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccmdlwritecomplete) or [CcMdlWriteAbort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccmdlwriteabort) is called. Thus each call to **CcPrepareMdlWrite** must be followed by a call to **CcMdlWriteComplete** or **CcMdlWriteAbort**.

Note that the pages described by the MDL are locked in memory, but not mapped in system space. The caller can perform this mapping by calling [MmGetSystemAddressForMdlSafe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetsystemaddressformdlsafe).

Note that even if the call to **CcPrepareMdlWrite** fails, one or more MDLs may have been allocated. The caller can examine the value of *IoStatus.Information* to determine whether this has occurred. If it has, the caller must call [CcMdlWriteComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccmdlwritecomplete) to free the allocated MDLs.

If any failure occurs, **CcPrepareMdlWrite** raises a status exception for that particular failure. For example, if a pool allocation failure occurs, **CcPrepareMdlWrite** raises a STATUS_INSUFFICIENT_RESOURCES exception; if an I/O error occurs, **CcPrepareMdlWrite** raises the status exception of the I/O error. Therefore, to gain control if a failure occurs, the driver should wrap the call to **CcPrepareMdlWrite** in a **try-except** or **try-finally** statement.

To cache a file, use [CcInitializeCacheMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccinitializecachemap).

## See also

[CcCopyWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-cccopywrite)

[CcInitializeCacheMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccinitializecachemap)

[CcMdlWriteAbort](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccmdlwriteabort)

[CcMdlWriteComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ccmdlwritecomplete)

[IoAllocateMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioallocatemdl)

[IoBuildPartialMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iobuildpartialmdl)

[MmGetMdlByteCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetmdlbytecount)

[MmGetMdlByteOffset](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetmdlbyteoffset)

[MmGetMdlPfnArray](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetmdlpfnarray)

[MmGetMdlVirtualAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetmdlvirtualaddress)

[MmGetSystemAddressForMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetsystemaddressformdl)

[MmGetSystemAddressForMdlSafe](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetsystemaddressformdlsafe)

[MmInitializeMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mminitializemdl)

[MmMapLockedPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmmaplockedpages)

[MmPrepareMdlForReuse](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmpreparemdlforreuse)

[MmProbeAndLockPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmprobeandlockpages)

[MmUnlockPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmunlockpages)

[MmUnmapLockedPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmunmaplockedpages)