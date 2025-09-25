# FSRTL_PER_FILEOBJECT_CONTEXT structure

## Description

The OS uses the opaque **FSRTL_PER_FILEOBJECT_CONTEXT** structure to track file system filter-driver-defined context information structures for a file object.

## Members

### `Links`

Link for this structure in the list of all per-file-object context structures associated with the same file object. [**FsRtlInsertPerFileObjectContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlinsertperfileobjectcontext) inserts this member into the list of all per-file-object context structures for the file object.

### `OwnerId`

A pointer to a filter-driver-allocated variable that uniquely identifies the owning filter of the per-file-object context structure. The format of this variable is filter-driver-specific. Filter writers should choose a value that is both meaningful and convenient, such as the address of the filter's device object or driver object. Note that the value of this member can't be NULL.

### `InstanceId`

A pointer to a filter-driver-allocated variable that can be used to distinguish among per-file-object context structures created by the same filter driver. The format of this variable is filter-driver-specific. Filter writers should choose a value that is both meaningful and convenient, such as the address of the file object itself. Note that the value of this member can be NULL.

## Remarks

File system filter drivers can use the opaque **FSRTL_PER_FILEOBJECT_CONTEXT** structure to maintain context information for a file object. This structure can be used as-is or embedded in a driver-defined, per-file-object context structure.

Each file object can have one per-file-object context structure list associated with it. Each member of this list (that is, a particular per-file-object context structure) is owned by a filter driver. From the perspective of a filter driver, each filter driver can associate multiple per-file-object context structures for the same file object.

Each filter-defined per-file-object context structure must include an initialized FSRTL_PER_FILEOBJECT_CONTEXT structure. The FSRTL_PER_FILEOBJECT_CONTEXT structure can be allocated from paged or nonpage pool and must be initialized using the [**FsRtlInitPerFileObjectContext**](https://learn.microsoft.com/previous-versions/ff546170(v=vs.85)) macro.

To insert a FSRTL_PER_FILEOBJECT_CONTEXT structure or a filter-defined per-file-object context structure (containing an initialized FSRTL_PER_FILEOBJECT_CONTEXT structure) into the list of all context structures for a file object, use the [**FsRtlInsertPerFileObjectContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlinsertperfileobjectcontext) function.

After a FSRTL_PER_FILEOBJECT_CONTEXT or per-file-object context structure has been associated with a file object, it can be retrieved by calling [**FsRtlLookupPerFileObjectContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtllookupperfileobjectcontext) or removed by calling [**FsRtlRemovePerFileObjectContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlremoveperfileobjectcontext) (based upon the values of **OwnerId** and **InstanceId**).

File system minifilter drivers must not use the following functions:

* [**FsRtlInitPerFileObjectContext**](https://learn.microsoft.com/previous-versions/ff546170(v=vs.85))
* [**FsRtlInsertPerFileObjectContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlinsertperfileobjectcontext)
* [**FsRtlLookupPerFileObjectContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtllookupperfileobjectcontext)
* [**FsRtlRemovePerFileObjectContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlremoveperfileobjectcontext)

Instead, minifilters can use the following functions to associate context information with a file object:

* [**FltAllocateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext)
* [**FltDeleteContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletecontext)
* [**FltSetStreamHandleContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetstreamhandlecontext)
* [**FltDeleteStreamHandleContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletestreamhandlecontext)
* [**FltGetStreamHandleContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetstreamhandlecontext)
* [**FltReleaseContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext)

File system minifilter drivers must not use the **FsRtl*Xxx*PerFileObjectContext** functions. Instead, minifilters can use the **Flt*Xxx*Context** functions to associate context information with a file object. For a complete list, see the **FSRTL_PER_FILEOBJECT_CONTEXT** topic.

## See also

[**DEVICE_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[**DRIVER_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object)

[**FILE_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object)

[**FltAllocateContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext)

[**FltDeleteContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletecontext)

[**FltDeleteStreamHandleContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletestreamhandlecontext)

[**FltGetStreamHandleContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetstreamhandlecontext)

[**FltReleaseContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext)

[**FltSetStreamHandleContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetstreamhandlecontext)

[**FsRtlInitPerFileObjectContext**](https://learn.microsoft.com/previous-versions/ff546170(v=vs.85))

[**FsRtlInsertPerFileObjectContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlinsertperfileobjectcontext)

[**FsRtlLookupPerFileObjectContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtllookupperfileobjectcontext)

[**FsRtlRemovePerFileObjectContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlremoveperfileobjectcontext)