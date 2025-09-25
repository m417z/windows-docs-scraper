# _FLT_REGISTRATION structure

## Description

The FLT_REGISTRATION structure is passed as a parameter to [FltRegisterFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter).

## Members

### `Size`

The size, in bytes, of the FLT_REGISTRATION structure. Minifilter drivers must set this member to **sizeof**(FLT_REGISTRATION).

### `Version`

The revision level of the FLT_REGISTRATION structure. Minifilter drivers must set this member to FLT_REGISTRATION_VERSION.

### `Flags`

A bitmask of minifilter registration flags. This member can be **NULL** or a combination of the following.

| Value | Meaning |
| --- | --- |
| **FLTFL_REGISTRATION_DO_NOT_SUPPORT_SERVICE_STOP** | If this flag is set, the minifilter is not unloaded in response to service stop requests, even if the **FilterUnloadCallback** member is not **NULL**. |
| **FLTFL_REGISTRATION_SUPPORT_NPFS_MSFS** | If this flag is set, the minifilter will support filtering of named pipe and mailslot requests. This flag was introduced in Windows 8. |
| **FLTFL_REGISTRATION_SUPPORT_DAX_VOLUME** | If this flag is set, the minifilter will support attaching to a direct access (DAX) volume. This will indicate to Filter Manager that the minifilter will filter the DAX volume. This flag was introduced in Windows 10, version 1607. |

### `ContextRegistration`

 A variable-length array of [FLT_CONTEXT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_context_registration) structures, one for each context type that the minifilter uses. The last element in the array must be {FLT_CONTEXT_END}. This member is optional and can be **NULL**.

### `OperationRegistration`

A variable-length array of [FLT_OPERATION_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_operation_registration) structures, one for each type of I/O for which the minifilter registers preoperation ([PFLT_PRE_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_pre_operation_callback)) and postoperation ([PFLT_POST_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_post_operation_callback)) callback routines. The last element in the array must be {IRP_MJ_OPERATION_END}. This member is optional and can be **NULL**.

### `FilterUnloadCallback`

A pointer to a routine of type [PFLT_FILTER_UNLOAD_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_filter_unload_callback) to be registered as the minifilter's *FilterUnloadCallback* routine. This member is optional and can be **NULL**. Note that if **NULL** is specified for this routine, then the filter can never be unloaded.

### `InstanceSetupCallback`

A pointer to a routine of type [PFLT_INSTANCE_SETUP_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_instance_setup_callback) to be registered as the minifilter's *InstanceSetupCallback* routine. This member is optional and can be **NULL**. Note that if **NULL** is specified for this routine, the attachment is always made.

### `InstanceQueryTeardownCallback`

A pointer to a routine of type [PFLT_INSTANCE_QUERY_TEARDOWN_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_instance_query_teardown_callback) to be registered as the minifilter's *InstanceQueryTeardownCallback* routine. This member is optional and can be **NULL**. Note that if **NULL** is specified for this routine, then instances will never be manually detached.

### `InstanceTeardownStartCallback`

A pointer to a routine of type [PFLT_INSTANCE_TEARDOWN_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_instance_teardown_callback) to be registered as the minifilter's *InstanceTeardownStartCallback* routine. This member is optional and can be **NULL**.

### `InstanceTeardownCompleteCallback`

A pointer to a routine of type [PFLT_INSTANCE_TEARDOWN_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_instance_teardown_callback) to be registered as the minifilter's *InstanceTeardownCompleteCallback* routine. This member is optional and can be **NULL**.

### `GenerateFileNameCallback`

A pointer to a routine of type [PFLT_GENERATE_FILE_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_generate_file_name) to be registered as the minifilter's *GenerateFileNameCallback* routine. This member is optional and can be **NULL**.

### `NormalizeNameComponentCallback`

A pointer to a routine of type [PFLT_NORMALIZE_NAME_COMPONENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_normalize_name_component) to be registered as the minifilter's *NormalizeNameComponentCallback* routine. This member is optional and can be **NULL**.

### `NormalizeContextCleanupCallback`

A pointer to a routine of type [PFLT_NORMALIZE_CONTEXT_CLEANUP](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_normalize_context_cleanup) to be registered as the minifilter's *NormalizeContextCleanupCallback* routine. This member is optional and can be **NULL**.

### `TransactionNotificationCallback`

(Windows Vista and later only.) A pointer to a routine of type [PFLT_TRANSACTION_NOTIFICATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_transaction_notification_callback) to be registered as the minifilter's *TransactionNotificationCallback* routine. This member is optional and can be **NULL**.

### `NormalizeNameComponentExCallback`

(Windows Vista and later only.) A pointer to a routine of type [PFLT_NORMALIZE_NAME_COMPONENT_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_normalize_name_component_ex) to be registered as the minifilter driver's *NormalizeNameComponentExCallback* routine. This member is optional and can be **NULL**.

Compared to the *NormalizeNameComponentCallback* callback routine, the *NormalizeNameComponentExCallback* callback routine supports an additional file object parameter,  *FileObject* (of type PFILE_OBJECT). A minifilter driver can use this parameter to acquire additional information, such as that provided by the [TXN_PARAMETER_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_txn_parameter_block) structure.

A minifilter driver can simultaneously set both the *NormalizeNameComponentCallback* and *NormalizeNameComponentExCallback* members to **NULL**; however, a name provider minifilter driver must register either a *NormalizeNameComponentCallback* or *NormalizeNameComponentExCallback* callback routine, or both. For example, a name provider minifilter driver that has no use for the additional *FileObject* parameter can set the *NormalizeNameComponentExCallback* member to **NULL** and only provide a *NormalizeNameComponentCallback* callback routine.

A minifilter driver can provide both a *NormalizeNameComponentCallback* callback and a *NormalizeNameComponentExCallback* callback. In this case, starting with Windows Vista, the filter manager will use only the *NormalizeNameComponentExCallback* callback; for Windows operating systems prior to Windows Vista, the filter manager will use only the *NormalizeNameComponentCallback* callback. This allows the same minifilter driver binary to run under all versions of the operating system.

### `SectionNotificationCallback`

Pointer to a routine of type [PFLT_SECTION_CONFLICT_NOTIFICATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_section_conflict_notification_callback) to be registered as the minifilter's *SectionNotificationCallback* routine. This member is optional and can be **NULL**. This callback is called for notifications of I/O failures for sections created with [FltCreateSectionForDatascan](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcreatesectionfordatascan).

## Remarks

The FLT_REGISTRATION structure is used to provide information about a file system minifilter, such as a *FilterUnloadCallback* ([PFLT_FILTER_UNLOAD_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_filter_unload_callback)) routine and preoperation ([PFLT_PRE_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_pre_operation_callback)) and postoperation ([PFLT_POST_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_post_operation_callback)) callback routines, to the filter manager. The minifilter passes a pointer to this structure as the *Registration* parameter to [FltRegisterFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter).

## See also

[FLT_CONTEXT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_context_registration)

[FLT_OPERATION_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_operation_registration)

[FltRegisterFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter)

[PFLT_FILTER_UNLOAD_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_filter_unload_callback)

[PFLT_GENERATE_FILE_NAME](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_generate_file_name)

[PFLT_INSTANCE_QUERY_TEARDOWN_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_instance_query_teardown_callback)

[PFLT_INSTANCE_SETUP_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_instance_setup_callback)

[PFLT_INSTANCE_TEARDOWN_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_instance_teardown_callback)

[PFLT_NORMALIZE_CONTEXT_CLEANUP](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_normalize_context_cleanup)

[PFLT_NORMALIZE_NAME_COMPONENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_normalize_name_component)

[PFLT_NORMALIZE_NAME_COMPONENT_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_normalize_name_component_ex)

[PFLT_POST_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_post_operation_callback)

[PFLT_PRE_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_pre_operation_callback)

[PFLT_TRANSACTION_NOTIFICATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_transaction_notification_callback)