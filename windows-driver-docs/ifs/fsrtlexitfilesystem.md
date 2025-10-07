# FsRtlExitFileSystem function

The **FsRtlExitFileSystem** macro re-enables the delivery of normal kernel-mode APCs that a preceding call to [**FsRtlEnterFileSystem**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsrtlenterfilesystem) disabled.

## Parameters

None

## Return value

This function doesn't return a value.

## Remarks

Every file system driver entry point routine must call [**FsRtlEnterFileSystem**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsrtlenterfilesystem) immediately before acquiring a resource required in performing a file I/O request and call **FsRtlExitFileSystem** immediately afterward. This ensures that the routine can't be suspended while running and thus block other file I/O requests.

Every successful call to [**FsRtlEnterFileSystem**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsrtlenterfilesystem) must be matched by a subsequent call to **FsRtlExitFileSystem**.

Unlike local file systems and network redirectors, file system filter drivers should never disable delivery of normal kernel APCs (by calling [**FsRtlEnterFileSystem**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsrtlenterfilesystem) or [**KeEnterCriticalRegion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keentercriticalregion) or by raising to IRQL APC_LEVEL) across a call to [**IoCallDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver).

The only time when a file system filter driver should disable normal kernel APCs is immediately before calling [**ExAcquireResourceExclusive**](https://learn.microsoft.com/windows-hardware/drivers/kernel/mmcreatemdl), [**ExAcquireResourceExclusiveLite**](https://learn.microsoft.com/previous-versions/ff544351(v=vs.85)), [**ExAcquireResourceShared**](https://learn.microsoft.com/windows-hardware/drivers/kernel/mmcreatemdl), [**ExAcquireResourceSharedLite**](https://learn.microsoft.com/previous-versions/ff544363(v=vs.85)), or [**ExAcquireSharedStarveExclusive**](https://learn.microsoft.com/previous-versions/ff544367(v=vs.85)). After the filter driver calls [**ExReleaseResource**](https://learn.microsoft.com/windows-hardware/drivers/kernel/mmcreatemdl) or [**ExReleaseResourceLite**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleaseresourcelite), it should immediately re-enable delivery of normal kernel APCs. As an alternative to [**FsRtlEnterFileSystem**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsrtlenterfilesystem), minifilter drivers can use the [**FltAcquireResourceExclusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltacquireresourceexclusive), [**FltAcquireResourceShared**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltacquireresourceshared), and [**FltReleaseResource**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleaseresource) routines, which properly handle APCs when acquiring and releasing a resource.

It isn't necessary to disable normal kernel APCs before calling [**ExAcquireSharedWaitForExclusive**](https://learn.microsoft.com/previous-versions/ff544370(v=vs.85)) because this routine calls [**KeRaiseIrqlToDpcLevel**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keraiseirqltodpclevel), which disables both normal and special kernel APCs. It's also not necessary to do so before calling [**ExAcquireFastMutex**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff544337(v=vs.85)) or [**ExAcquireResourceExclusive**](https://learn.microsoft.com/windows-hardware/drivers/kernel/mmcreatemdl), because these routines disable normal kernel APCs.

## Requirements

| Requirement type | Requirement |
| ---------------- | ----------- |
| Header | *Ntifs.h* (include *Ntifs.h*) |
| IRQL | <= APC_LEVEL |

## See also

[**ExAcquireFastMutex**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff544337(v=vs.85))

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

[**FsRtlEnterFileSystem**](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsrtlenterfilesystem)

[**IoCallDriver**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver)

[**KeLeaveCriticalRegion**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-keleavecriticalregion)

[**KeRaiseIrqlToDpcLevel**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keraiseirqltodpclevel)