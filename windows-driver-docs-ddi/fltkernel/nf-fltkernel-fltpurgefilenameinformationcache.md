# FltPurgeFileNameInformationCache function

## Description

**FltPurgeFileNameInformationCache** purges from the Filter Manager's name cache all file name information structures that were generated from names provided by the given minifilter driver instance.

## Parameters

### `Instance` [in]

Opaque instance (PFLT_INSTANCE) pointer for the minifilter driver instance whose names are to be purged. This parameter is required and cannot be **NULL**.

### `FileObject` [in, optional]

Optional pointer to a file object for which all names are to be purged. If this parameter is **NULL**, all names for the minifilter driver instance specified by the *Instance* parameter are purged.

## Return value

**FltPurgeFileNameInformationCache** returns STATUS_SUCCESS or an appropriate NTSTATUS value.

## Remarks

A minifilter driver that provides file names for the Filter Manager's name cache can call **FltPurgeFileNameInformationCache** to purge the names provided for a given minifilter driver instance. This is most commonly done when a name-providing filter unloads.

The file name information structures are not freed until all references are released.

## See also

[FLT_NAME_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_name_control)

[FltCheckAndGrowNameControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcheckandgrownamecontrol)

[FltGetFileNameFormat](https://learn.microsoft.com/previous-versions/ff543030(v=vs.85))

[FltGetFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilenameinformation)

[FltGetFileNameInformationUnsafe](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilenameinformationunsafe)

[FltGetFileNameQueryMethod](https://learn.microsoft.com/previous-versions/ff543040(v=vs.85))

[PFLT_GENERATE_FILE_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_generate_file_name)

[PFLT_NORMALIZE_CONTEXT_CLEANUP](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_normalize_context_cleanup)

[PFLT_NORMALIZE_NAME_COMPONENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_normalize_name_component)