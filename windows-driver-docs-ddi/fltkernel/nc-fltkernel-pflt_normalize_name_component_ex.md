# PFLT_NORMALIZE_NAME_COMPONENT_EX callback function

## Description

A minifilter driver that provides file names for the filter manager's name cache can register a routine of type PFLT_NORMALIZE_NAME_COMPONENT_EX as the minifilter driver's *NormalizeNameComponentExCallback* callback routine.

## Parameters

### `Instance` [in]

Opaque instance pointer for the minifilter driver instance that this callback routine is registered for.

### `FileObject` [in]

Pointer to the file object for the file whose name is being requested or the file that is the target of the [IRP_MJ_SET_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-set-information) operation if the FLTFL_NORMALIZE_NAME_DESTINATION_FILE_NAME flag is set. See the *Flags* parameter below for more information.

### `ParentDirectory` [in]

Pointer to a [UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string) structure that contains the name of the parent directory for this name component.

### `VolumeNameLength` [in]

Length, in bytes, of the parent directory name that is stored in the structure that the *ParentDirectory* parameter points to.

### `Component` [in]

Pointer to a UNICODE_STRING structure that contains the name component to be expanded.

### `ExpandComponentName` [out]

Pointer to a [FILE_NAMES_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_names_information) structure that receives the expanded (normalized) file name information for the name component.

### `ExpandComponentNameLength` [in]

Length, in bytes, of the buffer that the *ExpandComponentName* parameter points to.

### `Flags` [in]

Name normalization flags. FLTFL_NORMALIZE_NAME_CASE_SENSITIVE specifies that the name to be normalized is case-sensitive. FLTFL_NORMALIZE_NAME_DESTINATION_FILE_NAME specifies that the callback routine has been called to service an [FltGetDestinationFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetdestinationfilenameinformation) routine call. If the FLTFL_NORMALIZE_NAME_DESTINATION_FILE_NAME flag is set, *FileObject* represents the file/directory that is the target of the IRP_MJ_SET_INFORMATION operation. If the FLTFL_NORMALIZE_NAME_DESTINATION_FILE_NAME flag is not set, *FileObject* represents the file/directory whose name is being requested.

### `NormalizationContext` [in, out]

Pointer to minifilter driver-provided context information to be passed in any subsequent calls to this callback routine that are made to normalize the remaining components in the same file name path.

## Return value

This callback routine returns STATUS_SUCCESS or an appropriate NTSTATUS value. If the name component that the *Component* parameter specifies does not exist in the parent directory that the *ParentDirectory* parameter specifies, this callback routine should return STATUS_NO_SUCH_FILE. If this callback routine issues an IRP_MN_QUERY_DIRECTORY (FileNamesInformation) request to the parent directory, the file system returns the correct status code. In this situation, this callback can simply return the status code that the file system returns.

## Remarks

A minifilter driver that provides file names for the filter manager's name cache can register a routine of type PFLT_NORMALIZE_NAME_COMPONENT_EX as the minifilter driver's *NormalizeNameComponentExCallback* callback routine.

The principal difference between the *NormalizeNameComponentExCallback* callback routine and the *NormalizeNameComponentCallback* callback routine (of type [PFLT_NORMALIZE_NAME_COMPONENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_normalize_name_component)) is that the *NormalizeNameComponentExCallback* callback routine supports the additional *FileObject* parameter. The file object (*FileObject*) can be used by the minifilter driver to retrieve the [TXN_PARAMETER_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_txn_parameter_block) structure for the operation that the file/directory is participating in by calling the [IoGetTransactionParameterBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iogettransactionparameterblock) routine. The TXN_PARAMETER_BLOCK structure can be used by the minifilter driver to issue its own create requests in the context of the transaction that this file object is participating in.

To register this callback routine, the minifilter driver stores the address of a routine of type PFLT_NORMALIZE_NAME_COMPONENT_EX in the **NormalizeNameComponentExCallback** member of the [FLT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_registration) structure that the minifilter driver passes as a parameter to [FltRegisterFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter).

The filter manager calls this callback routine to query the minifilter driver for the normalized names for components in the file name path whose names the minifilter driver has modified. If the file name path contains more than one such component, the filter manager can call this callback routine multiple times in the process of normalizing all the components in the path. The minifilter driver can use the *NormalizationContext* parameter to pass context information to subsequent calls to this callback routine.

If the minifilter driver uses the *NormalizationContext* parameter, it should also register a normalization context cleanup callback routine. For more information, see the reference entry for [PFLT_NORMALIZE_CONTEXT_CLEANUP](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_normalize_context_cleanup).

## See also

[FILE_NAMES_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_file_names_information)

[FLT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_registration)

[FltGetDestinationFileNameInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetdestinationfilenameinformation)

[FltRegisterFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter)

[IRP_MJ_SET_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-set-information)

[IoGetTransactionParameterBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iogettransactionparameterblock)

[PFLT_GENERATE_FILE_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_generate_file_name)

[PFLT_NORMALIZE_CONTEXT_CLEANUP](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_normalize_context_cleanup)

[PFLT_NORMALIZE_NAME_COMPONENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_normalize_name_component)

[TXN_PARAMETER_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_txn_parameter_block)

[UNICODE_STRING](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_unicode_string)