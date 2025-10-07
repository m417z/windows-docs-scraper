# FsRtlEnterFileSystem function

The **FsRtlEnterFileSystem** macro temporarily disables the delivery of normal kernel-mode asynchronous procedure calls (APC). Special kernel-mode APCs are still delivered.

## Parameters

None

## Return value

This function doesn't return a value.

## Remarks

Every file system driver entry point routine must call **FsRtlEnterFileSystem** immediately before acquiring a resource required in performing a file I/O request and call [**FsRtlExitFileSystem**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsrtlexitfilesystem) immediately afterward. This ensures that the routine can't be suspended while running and thus block other file I/O requests.

Every successful call to **FsRtlEnterFileSystem** must be matched by a subsequent call to [**FsRtlExitFileSystem**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsrtlexitfilesystem).

File system filter drivers can disable delivery of normal kernel APCs by calling **FsRtlEnterFileSystem** or [**KeEnterCriticalRegion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keentercriticalregion) prior to [**IoCallDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver) only if [**FsRtlExitFileSystem**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsrtlexitfilesystem) or [**KeLeaveCriticalRegion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keleavecriticalregion) is in the same dispatch routine. They shouldn't call **FsRtlEnterFileSystem** or **KeEnterCriticalRegion** prior to **IoCallDriver** and then call **FsRtlExitFileSystem** or **KeLeaveCriticalRegion** in the *completion routine* of the IRP. Driver Verifier has a rule to help catch this condition.

File system filter drivers should disable normal kernel APCs before acquiring any resource. File system filter drivers acquire resources with the following routines:

* [**ExAcquireResourceExclusive**](https://learn.microsoft.com/windows-hardware/drivers/kernel/mmcreatemdl)
* [**ExAcquireResourceExclusiveLite**](https://learn.microsoft.com/previous-versions/ff544351(v=vs.85))
* [**ExAcquireResourceShared**](https://learn.microsoft.com/windows-hardware/drivers/kernel/mmcreatemdl)
* [**ExAcquireResourceSharedLite**](https://learn.microsoft.com/previous-versions/ff544363(v=vs.85))
* [**ExAcquireSharedStarveExclusive**](https://learn.microsoft.com/previous-versions/ff544367(v=vs.85))
* [**ExAcquireSharedWaitForExclusive**](https://learn.microsoft.com/previous-versions/ff544370(v=vs.85))

As an alternative to **FsRtlEnterFileSystem**, minifilter drivers can use the [**FltAcquireResourceExclusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltacquireresourceexclusive), [**FltAcquireResourceShared**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltacquireresourceshared), and [**FltReleaseResource**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleaseresource) routines, which properly handle APCs when acquiring and releasing a resource.

## Requirements

| Requirement type | Requirement |
| ---------------- | ----------- |
| Header | *Ntifs.h* (include *Ntifs.h*) |
| IRQL | <= APC_LEVEL |

## See also

[**ExAcquireResourceExclusive**](https://learn.microsoft.com/windows-hardware/drivers/kernel/mmcreatemdl)

[**ExAcquireResourceExclusiveLite**](https://learn.microsoft.com/previous-versions/ff544351(v=vs.85))

[**ExAcquireResourceShared**](https://learn.microsoft.com/windows-hardware/drivers/kernel/mmcreatemdl)

[**ExAcquireResourceSharedLite**](https://learn.microsoft.com/previous-versions/ff544363(v=vs.85))

[**ExAcquireSharedWaitForExclusive**](https://learn.microsoft.com/previous-versions/ff544370(v=vs.85))

[**ExAcquireSharedStarveExclusive**](https://learn.microsoft.com/previous-versions/ff544367(v=vs.85))

[**ExReleaseResource**](https://learn.microsoft.com/windows-hardware/drivers/kernel/mmcreatemdl)

[**ExReleaseResourceLite**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleaseresourcelite)

[**ExTryToAcquireFastMutex**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff545647(v=vs.85))

[**FltAcquireResourceExclusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltacquireresourceexclusive)

[**FltAcquireResourceShared**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltacquireresourceshared)

[**FltReleaseResource**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleaseresource)

[**FsRtlExitFileSystem**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsrtlexitfilesystem)

[**IoCallDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver)

[**KeEnterCriticalRegion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keentercriticalregion)

[**KeRaiseIrqlToDpcLevel**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keraiseirqltodpclevel)