# _FLT_OPERATION_REGISTRATION structure

## Description

The FLT_OPERATION_REGISTRATION structure is used to register operation callback routines.

## Members

### `MajorFunction`

Major function code specifying the type of I/O operation. This member is required and cannot be **NULL**. For more information about additional operations, see [FLT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_parameters).

### `Flags`

Bitmask of flags specifying when to call the preoperation ([PFLT_PRE_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_pre_operation_callback)) and postoperation ([PFLT_POST_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_post_operation_callback)) callback routines for cached I/O or paging I/O operations. This member is optional and can be zero.

| Flag | Description |
| ---- | ----------- |
| FLTFL_OPERATION_REGISTRATION_SKIP_PAGING_IO (0x00000001) | A minifilter sets this flag for read or write operations to specify that its preoperation and postoperation callback routines should not be called for paging I/O operations. This flag applies only to IRP-based I/O operations. It is ignored for I/O operations that are not IRP-based. |
| FLTFL_OPERATION_REGISTRATION_SKIP_CACHED_IO (0x00000002) | A minifilter sets this flag for read or write operations to specify that its preoperation and postoperation callback routines should not be called for cached I/O operations. This flag applies to fast I/O as well as IRP-based reads and writes because all fast I/O is cached. |
| FLTFL_OPERATION_REGISTRATION_SKIP_NON_DASD_IO (0x00000004) | A minifilter sets this flag so that *all* operations issued on a non-DASD volume handle will be skipped. Note that the minifilter's callback for this operation will be bypassed. |
| FLTFL_OPERATION_REGISTRATION_SKIP_NON_CACHED_NON_PAGING_IO (0x00000008) | A minifilter sets this flag so that read or write operations that are not cached nor paging will be skipped. Note that the minifilter's callback for this operation will be bypassed. This flag is relevant for IRP_MJ_READ and IRP_MJ_WRITE requests only. |

### `PreOperation`

Pointer to a [PFLT_PRE_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_pre_operation_callback)-typed routine to be registered as the preoperation callback routine for this type of I/O operation. This member is optional and can be **NULL**.

### `PostOperation`

Pointer to a [PFLT_POST_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_post_operation_callback)-typed routine to be registered as the postoperation callback routine for this type of I/O operation. This member is optional and can be **NULL**.

### `Reserved1`

Reserved for system use. Minifilters must set this member to **NULL**.

## Remarks

When a minifilter calls [**FltRegisterFilter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter) from its [**DriverEntry**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_initialize) routine, it can register a preoperation callback ([PFLT_PRE_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_pre_operation_callback)) routine and a postoperation callback ([PFLT_POST_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_post_operation_callback)) routine for each type of I/O operation that it must handle.

To register these callback routines, the minifilter creates a variable-length array of FLT_OPERATION_REGISTRATION structures and stores a pointer to the array in the **OperationRegistration** member of the [FLT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_registration) structure that the minifilter passes as the *Registration* parameter of [**FltRegisterFilter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter). The last element of this array must be {IRP_MJ_OPERATION_END}.

The minifilter must create a separate FLT_OPERATION_REGISTRATION structure for each type of I/O operation that it handles. In this structure, the minifilter specifies the entry points of its callback routines in the structure's **PreOperation** and **PostOperation** members.

A minifilter can register a preoperation callback routine for a given type of I/O operation without registering a postoperation callback and vice versa.

File systems do not receive IRP_MJ_POWER or IRP_MJ_DEVICE_CHANGE requests. Minifilters cannot register preoperation or postoperation callback routines for these operations.

A minifilter cannot register a postoperation callback routine for IRP_MJ_SHUTDOWN.

A single preoperation or postoperation callback routine can be used to process more than one type of I/O operation. However, the callback routine must be registered separately for each type of I/O operation.

## See also

[FLT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_registration)

[**FltRegisterFilter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter)

[PFLT_POST_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_post_operation_callback)

[PFLT_PRE_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_pre_operation_callback)