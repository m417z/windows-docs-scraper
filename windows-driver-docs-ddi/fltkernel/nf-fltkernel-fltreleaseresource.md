## Description

The **FltReleaseResource** routine releases a specified resource owned by the current thread.

## Parameters

### `Resource` [in/out]

Pointer to the opaque [**ERESOURCE**](https://learn.microsoft.com/windows-hardware/drivers/kernel/eresource-structures) structure for the resource to be released.

## Return value

None.

## Remarks

FltReleaseResource releases a resource that was previously acquired by calling [**FltAcquireResourceExclusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltacquireresourceexclusive) or [**FltAcquireResourceShared**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltacquireresourceshared).

**FltReleaseResource** is a wrapper for [**ExReleaseResourceLite**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleaseresourcelite) that reenables normal kernel APC delivery.

Because FltReleaseResource reenables normal kernel APC delivery, it is not necessary to call [**KeEnterCriticalRegion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keentercriticalregion) or [**FsRtlEnterFileSystem**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsrtlenterfilesystem) after calling **FltReleaseResource**.

To acquire a resource for exclusive access, call [**FltAcquireResourceExclusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltacquireresourceexclusive).

To acquire a resource for shared access, call [**FltAcquireResourceShared**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltacquireresourceshared).

To delete a resource from the system's resource list, call [**ExDeleteResourceLite**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exdeleteresourcelite).

To initialize a resource for reuse, call [**ExReinitializeResourceLite**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreinitializeresourcelite).

For more information about ERESOURCE structures, see [Introduction to ERESOURCE Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-eresource-routines).