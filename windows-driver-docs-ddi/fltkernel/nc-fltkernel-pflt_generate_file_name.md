# PFLT_GENERATE_FILE_NAME callback function

## Description

A minifilter driver that provides file names for the filter manager's name cache can register a routine of type *PFLT_GENERATE_FILE_NAME* as the minifilter driver's *GenerateFileNameCallback* routine.

## Parameters

### `Instance` [in]

Opaque instance pointer for the minifilter driver instance that this callback routine is registered for.

### `FileObject` [in]

A pointer to a file object for the file whose name is being requested.

### `CallbackData` [in, optional]

A pointer to the callback data structure for the operation during which this name is being requested. This parameter is **NULL** when [FltGetFileNameInformationUnsafe](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilenameinformationunsafe) is called to retrieve the name of the file.

### `NameOptions` [in]

[FLT_FILE_NAME_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-file-name-options) value that specifies the name format, query method, and flags for this file name information query.

### `CacheFileNameInformation` [out]

A pointer to a Boolean value specifying whether this name can be cached. Set to **TRUE** on output if the name can be cached; set to **FALSE** otherwise.

### `FileName` [out]

A pointer to a filter manager-allocated [FLT_NAME_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_name_control) structure to receive the file name on output.

## Return value

This callback routine returns STATUS_SUCCESS or an appropriate NTSTATUS value.

## Remarks

A minifilter driver that provides file names for the filter manager's name cache can register a routine of type *PFLT_GENERATE_FILE_NAME* as the minifilter driver's *GenerateFileNameCallback* routine.

To register this callback routine, the minifilter driver stores the address of a routine of type *PFLT_GENERATE_FILE_NAME* in the *GenerateFileNameCallback* member of the [FLT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_registration) structure that the minifilter driver passes as a parameter to [FltRegisterFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter).

The filter manager calls this callback routine to allow the minifilter driver to intercept file name requests by other minifilter drivers above it in the minifilter driver instance stack. Using this callback routine and the [PFLT_NORMALIZE_NAME_COMPONENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_normalize_name_component) callback routine, the minifilter driver can provide its own file name information.

To determine which file name format is being requested, call [FltGetFileNameFormat](https://learn.microsoft.com/previous-versions/ff543030(v=vs.85)) on the *NameOptions* parameter.

Prior to Windows 8, this callback routine is called only for opened file names and short file names. When the filter manager receives a request for a normalized file name, it calls this callback routine to request the opened file name. Then it calls the minifilter driver's [PFLT_NORMALIZE_NAME_COMPONENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_normalize_name_component) callback to normalize each component in the file name.

Starting with Windows 8, this callback routine is also called for normalized names. When the filter manager receives a request for a normalized file name, it calls this callback routine with FLT_FILE_NAME_NORMALIZED specified in the *NameOptions* parameter. If the minifilter returns STATUS_SUCCESS from this callback, the minifilter’s [PFLT_NORMALIZE_NAME_COMPONENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_normalize_name_component) callback will not be called. If the minifilter returns a failure code (such as STATUS_NOT_SUPPORTED), the filter manager will call this callback routine again, requesting the opened file name. The filter manager will then call the minifilter driver’s *PFLT_NORMALIZE_NAME_COMPONENT* callback to normalize each component in the file name.

When this callback routine is invoked, the minifilter driver generates its own file name information, based on the file system's file name information for the file. To get the file system's file name information for a file, call [FltGetFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilenameinformation), [FltGetFileNameInformationUnsafe](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilenameinformationunsafe), or [FltGetDestinationFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetdestinationfilenameinformation).

For opened file names, the generated file name information should include volume information. For a remote file, it should include share information as well.

The following is an example of an opened file name for a remote file:

```
\Device\LanManRedirector\MyServer\MyShare\Docume~1\MyUser\My Documents\TestRe~1.txt:stream1
```

For more information about file name formats, see the reference entries for [FLT_FILE_NAME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_file_name_information) and [FltParseFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltparsefilenameinformation).

After it generates the file name information, the minifilter driver must call [FltCheckAndGrowNameControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcheckandgrownamecontrol) to check whether the [FLT_NAME_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_name_control) structure that the *FileName* parameter points to contains a name buffer that is large enough to hold the generated file name. If the name buffer is too small, **FltCheckAndGrowNameControl** replaces it with a larger one. The minifilter driver then stores the file name information into the name buffer and returns.

## See also

[FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[FLT_FILE_NAME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_file_name_information)

[FLT_FILE_NAME_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-file-name-options)

[FLT_NAME_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_name_control)

[FLT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_registration)

[FltCheckAndGrowNameControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcheckandgrownamecontrol)

[FltGetDestinationFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetdestinationfilenameinformation)

[FltGetFileNameFormat](https://learn.microsoft.com/previous-versions/ff543030(v=vs.85))

[FltGetFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilenameinformation)

[FltGetFileNameInformationUnsafe](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetfilenameinformationunsafe)

[FltGetFileNameQueryMethod](https://learn.microsoft.com/previous-versions/ff543040(v=vs.85))

[FltParseFileName](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltparsefilename)

[FltParseFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltparsefilenameinformation)

[FltPurgeFileNameInformationCache](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltpurgefilenameinformationcache)

[FltRegisterFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter)

[PFLT_NORMALIZE_CONTEXT_CLEANUP](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_normalize_context_cleanup)

[PFLT_NORMALIZE_NAME_COMPONENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_normalize_name_component)

[PFLT_NORMALIZE_NAME_COMPONENT_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_normalize_name_component_ex)