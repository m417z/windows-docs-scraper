# _FLT_RELATED_OBJECTS structure

## Description

The FLT_RELATED_OBJECTS structure contains opaque pointers for the objects associated with an operation.

## Members

### `Size`

Size, in bytes, of the FLT_RELATED_OBJECTS structure.

### `TransactionContext`

Opaque member that contains the transaction miniversion ID value if the **Transaction** member is not **NULL**. If **Transaction** is **NULL**, the value of **TransactionContext** is undefined.

### `Filter`

Opaque filter pointer for the minifilter driver whose callback routine is being called for the operation. This pointer uniquely identifies the minifilter driver and remains constant as long as the minifilter driver is loaded.

### `Volume`

Opaque volume pointer for the volume that is associated with the operation. This pointer uniquely identifies the volume and remains constant over the lifetime of the volume device stack.

### `Instance`

Opaque instance pointer for the minifilter driver instance that is associated with the operation. This pointer uniquely identifies the instance and remains constant as long as the instance is attached to a volume.

### `FileObject`

Pointer to the file object, if any, for the operation.

### `Transaction`

On Windows Vista and later, this member is an opaque transaction pointer to the transaction that is associated with the operation. The operation will be part of a transaction if the value of this member is not **NULL**. If the value of this member is **NULL**, the operation will not be part of a transaction. On Windows operating systems before Windows Vista, the value of this member will always be **NULL**.

## Remarks

The FLT_RELATED_OBJECTS structure is allocated by the filter manager and contains opaque pointers for the objects associated with an I/O operation or an instance setup or teardown operation.

The contents of the FLT_RELATED_OBJECTS structure are set by the filter manager. Minifilter drivers cannot directly modify the contents of this structure. However, if a minifilter driver modifies the target instance or target file object for an I/O operation in the [FLT_IO_PARAMETER_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_io_parameter_block) structure for the operation, the filter manager modifies the value of the corresponding **Instance** or **FileObject** member of the FLT_RELATED_OBJECTS structure that is passed to lower minifilter drivers. For more information, see [Modifying the Parameters for an I/O Operation](https://learn.microsoft.com/windows-hardware/drivers/ifs/modifying-the-parameters-for-an-i-o-operation).

A minifilter driver receives a pointer to an FLT_RELATED_OBJECTS structure as the *FltObjects* input parameter to the following callback routine types:

[PFLT_POST_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_post_operation_callback)

[PFLT_PRE_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_pre_operation_callback)

[PFLT_INSTANCE_SETUP_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_instance_setup_callback)

[PFLT_INSTANCE_QUERY_TEARDOWN_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_instance_query_teardown_callback)

[PFLT_INSTANCE_TEARDOWN_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_instance_teardown_callback)

To retrieve pointers to a minifilter driver's contexts for the objects in an FLT_RELATED_OBJECTS structure, call [FltGetContexts](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetcontexts).

**Note** `typedef CONST struct _FLT_RELATED_OBJECTS *PCFLT_RELATED_OBJECTS;`

## See also

[FLT_IO_PARAMETER_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_io_parameter_block)

[FLT_RELATED_CONTEXTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_related_contexts)

[FltDoCompletionProcessingWhenSafe](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdocompletionprocessingwhensafe)

[FltGetContexts](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetcontexts)

[PFLT_INSTANCE_QUERY_TEARDOWN_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_instance_query_teardown_callback)

[PFLT_INSTANCE_SETUP_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_instance_setup_callback)

[PFLT_INSTANCE_TEARDOWN_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_instance_teardown_callback)

[PFLT_POST_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_post_operation_callback)

[PFLT_PRE_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_pre_operation_callback)