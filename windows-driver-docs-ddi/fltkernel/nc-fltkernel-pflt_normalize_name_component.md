# PFLT_NORMALIZE_NAME_COMPONENT callback function

## Description

A minifilter driver that provides file names for the filter manager's name cache can register a routine of type PFLT_NORMALIZE_NAME_COMPONENT as the minifilter driver's *NormalizeNameComponentCallback* routine.

## Parameters

### `Instance` [in]

Opaque instance pointer for the minifilter driver instance that this callback routine is registered for.

### `ParentDirectory` [in]

Pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains the name of the parent directory for this name component.

### `VolumeNameLength` [in]

Length, in bytes, of the parent directory name stored in the structure that the *ParentDirectory* parameter points to.

### `Component` [in]

Pointer to a UNICODE_STRING structure that contains the name component to be expanded.

### `ExpandComponentName` [out]

Pointer to a [FILE_NAMES_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_names_information) structure that receives the expanded (normalized) file name information for the name component.

### `ExpandComponentNameLength` [in]

Length, in bytes, of the buffer that the *ExpandComponentName* parameter points to.

### `Flags` [in]

Name normalization flags. FLTFL_NORMALIZE_NAME_CASE_SENSITIVE specifies that the name to be normalized is case-sensitive. FLTFL_NORMALIZE_NAME_DESTINATION_FILE_NAME specifies that the callback routine has been called to service a [FltGetDestinationFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetdestinationfilenameinformation) routine call.

### `NormalizationContext` [in, out]

Pointer to minifilter driver-provided context information to be passed in any subsequent calls to this callback routine that are made to normalize the remaining components in the same file name path.

## Return value

This callback routine returns STATUS_SUCCESS or an appropriate NTSTATUS value. If the name component that the *Component* parameter specifies does not exist in the parent directory that the *ParentDirectory* parameter specifies, this callback routine should return STATUS_NO_SUCH_FILE. If this callback routine issues an IRP_MN_QUERY_DIRECTORY (FileNamesInformation) request to the parent directory, the file system returns the correct status code. In this situation, this callback can simply return the status code that the file system returns.

## Remarks

A minifilter driver that provides file names for the filter manager's name cache can register a routine of type PFLT_NORMALIZE_NAME_COMPONENT as the minifilter driver's *NormalizeNameComponentCallback* routine.

To register this callback routine, the minifilter driver stores the address of a routine of type PFLT_NORMALIZE_NAME_COMPONENT in the **NormalizeNameComponentCallback** member of the [FLT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_registration) structure that the minifilter driver passes as a parameter to [FltRegisterFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter).

The filter manager calls this callback routine to query the minifilter driver for the normalized names for components in the file name path whose names the minifilter driver has modified. If the file name path contains more than one such component, the filter manager can call this callback routine multiple times in the process of normalizing all the components in the path. The minifilter driver can use the *NormalizationContext* parameter to pass context information to subsequent calls to this callback routine.

If the minifilter driver uses the *NormalizationContext* parameter, it should also register a normalization context cleanup callback routine. For more information, see the reference entry for [PFLT_NORMALIZE_CONTEXT_CLEANUP](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_normalize_context_cleanup).

## See also

[FILE_NAMES_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_names_information)

[FLT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_registration)

[FltRegisterFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter)

[PFLT_GENERATE_FILE_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_generate_file_name)

[PFLT_NORMALIZE_CONTEXT_CLEANUP](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_normalize_context_cleanup)

[PFLT_NORMALIZE_NAME_COMPONENT_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_normalize_name_component_ex)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)