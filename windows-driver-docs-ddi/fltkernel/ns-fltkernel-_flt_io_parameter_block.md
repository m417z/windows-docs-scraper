# FLT_IO_PARAMETER_BLOCK structure

## Description

The **FLT_IO_PARAMETER_BLOCK** structure contains the parameters for the I/O operation represented by a [**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data) callback data structure.

## Members

### `IrpFlags`

A bitmask of flags that specify various aspects of the I/O operation. These flags are used only for IRP-based operations. The following table shows flag values.

| Value | Meaning |
| ----- | ------- |
| IRP_BUFFERED_IO | The operation is a buffered I/O operation. |
| IRP_CLOSE_OPERATION | The operation is a cleanup or close operation. |
| IRP_DEALLOCATE_BUFFER | The I/O Manager will free the buffer during the completion phase for the IRP. |
| IRP_INPUT_OPERATION | The operation is an input operation. |
| IRP_NOCACHE | The operation is a noncached I/O operation. |
| IRP_PAGING_IO | The operation is a paging I/O operation. |
| IRP_SYNCHRONOUS_API | The I/O operation is synchronous. |
| IRP_SYNCHRONOUS_PAGING_IO | The operation is a synchronous paging I/O operation. |
| IRP_MOUNT_COMPLETION | A volume mount is completed for the operation. |
| IRP_CREATE_OPERATION | The operation is a create or open operation. |
| IRP_READ_OPERATION | The I/O operation is for reading. |
| IRP_WRITE_OPERATION | The I/O operation is for writing. |
| IRP_DEFER_IO_COMPLETION | I/O completion of the operation is deferred. |
| IRP_ASSOCIATED_IRP | The operation is associated with a master IRP. |
| IRP_OB_QUERY_NAME | The operation is an asynchronous name query. |
| IRP_HOLD_DEVICE_QUEUE | Reserved. |
| IRP_UM_DRIVER_INITIATED_IO | The operation originated from a user-mode driver. |

### `MajorFunction`

The major function code for the I/O operation. Major function codes are used for IRP-based operations, fast I/O operations, and file system (FSFilter) callback operations. For more information about additional operations, see [**FLT_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_parameters).

### `MinorFunction`

The minor function code for the I/O operation. This member is optional and can be **NULL**. The value of the **MajorFunction** member determines the possible values. For more information about minor function codes, see [**FLT_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_parameters).

### `OperationFlags`

A bitmask of flags that specify various aspects of the I/O operation. These flags are used only for IRP-based operations. The Filter Manager copies these flags from the **Flags** member of the [**IO_STACK_LOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location) structure that is associated with the [**IRP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp). The following table shows the most commonly used flag values.

| Value | Meaning |
| ----- | ------- |
| SL_CASE_SENSITIVE | Used for [**IRP_MJ_CREATE**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create). If this flag is set, file name comparisons should be case-sensitive. |
| SL_EXCLUSIVE_LOCK | Used for [**IRP_MJ_LOCK_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-lock-control). If this flag is set, an exclusive byte-range lock is requested. Otherwise, a shared lock is requested. |
| SL_FAIL_IMMEDIATELY | Used for [**IRP_MJ_LOCK_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-lock-control). If this flag is set, the lock request should fail if it cannot be granted immediately. |
| SL_FORCE_ACCESS_CHECK | Used for [**IRP_MJ_CREATE**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create). If this flag is set, access checks must be performed even if the value of the IRP's **RequestorMode** member is **KernelMode**. |
| SL_FORCE_DIRECT_WRITE | Used for IRP_MJ_WRITE and IOCTL_DISK_COPY_DATA. If this flag is set, kernel-mode drivers can write to volume areas that they are normally blocked from writing to due to security reasons. This flag is checked both at the file system layer and storage stack layer. The SL_FORCE_DIRECT_WRITE flag is available in Windows Vista and later versions of Windows. |
| SL_INDEX_SPECIFIED | Used for [**IRP_MJ_DIRECTORY_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-directory-control), [**IRP_MJ_QUERY_EA**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-query-ea), and [**IRP_MJ_SET_QUOTA**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-set-quota). If this flag is set, the scan for directory, quota, or extended-attribute information should begin at the entry in the list whose index is specified. |
| SL_OPEN_PAGING_FILE | Used for [**IRP_MJ_CREATE**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create). If this flag is set, the file is a paging file. |
| SL_OPEN_TARGET_DIRECTORY | Used for [**IRP_MJ_CREATE**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create). If this flag is set, the file's parent directory should be opened. |
| SL_OVERRIDE_VERIFY_VOLUME | Used for [**IRP_MJ_DIRECTORY_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-directory-control), [**IRP_MJ_READ**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-read), and [**IRP_MJ_WRITE**](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-write). If this flag is set, the I/O operation should be performed even if the DO_VERIFY_VOLUME flag is set on the volume's device object. |
| SL_RESTART_SCAN | Used for [**IRP_MJ_DIRECTORY_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-directory-control), [**IRP_MJ_QUERY_EA**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-query-ea), and [**IRP_MJ_SET_QUOTA**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-set-quota). If this flag is set, the scan for directory, quota, or extended-attribute information should begin at the first entry in the directory or list. Otherwise, the scan should be resumed from the previous scan. |
| SL_RETURN_SINGLE_ENTRY | Used for [**IRP_MJ_DIRECTORY_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-directory-control), [**IRP_MJ_QUERY_EA**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-query-ea), and [**IRP_MJ_SET_QUOTA**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-set-quota). If this flag is set, the scan for directory, quota, or extended-attribute information should return only the first entry that is found. |
| SL_WATCH_TREE | Used for [**IRP_MJ_DIRECTORY_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-directory-control). If this flag is set, all subdirectories of this directory should also be watched. Otherwise, only the directory itself is to be watched. |
| SL_WRITE_THROUGH | Used for [**IRP_MJ_WRITE**](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-write). If this flag is set, the file data must be written through to persistent storage, not just written to the cache. |

### `Reserved`

Reserved for system use. Do not use.

### `TargetFileObject`

A file object pointer for the file or directory that is the target for this I/O operation.

### `TargetInstance`

An opaque instance pointer for the minifilter that is the target for this I/O operation.

### `Parameters`

An [**FLT_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_parameters) structure that contains the parameters for the I/O operation that are specified by the **MajorFunction** and **MinorFunction** members.

## Remarks

The **FLT_IO_PARAMETER_BLOCK** structure contains the parameters for the I/O operation that is represented by a callback data ([**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)) structure. The callback data structure contains a pointer to the FLT_IO_PARAMETER_BLOCK structure in its **Iopb** member.

A minifilter receives a pointer to the callback data structure as the *Data* or *CallbackData* input parameter to the following callback routine types:

* [**PFLT_POST_OPERATION_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_post_operation_callback)
* [**PFLT_PRE_OPERATION_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_pre_operation_callback)
* [**PFLT_COMPLETED_ASYNC_IO_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_completed_async_io_callback)
* [**PFLT_GENERATE_FILE_NAME**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_generate_file_name)

A minifilter's preoperation and postoperation callback routines can modify the contents of the FLT_IO_PARAMETER_BLOCK structure for the I/O operation, except for the **MajorFunction** and **Reserved** members. If it does, it must call [**FltSetCallbackDataDirty**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetcallbackdatadirty), unless it has also modified the **IoStatus** member of the callback data structure for the operation. Otherwise, the modified values are ignored.

When Filter Manager issues a preoperation or postoperation callback to a minifilter, [**FltObjects->FileObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_related_objects) and **TargetFileObject** (CallbackData->Iopb->TargetFileObject) are initially the same. If a minifilter modifies **TargetFileObject** or **TargetInstance**, its subsequent call to **FltSetCallbackDataDirty** from a preoperation callback will cause Filter Manager to replace **FltObjects->FileObject** and **FltObjects->Instance** before sending the operation to lower filters.

If a minifilter's preoperation callback routine modifies the parameters for an I/O operation, all minifilters below it in the minifilter instance stack will receive the modified parameters in their preoperation and postoperation callback routines.

The modified parameters are not received by the minifilter's own postoperation callback routine, or by any minifilters above that minifilter in the minifilter instance stack. In all cases, a minifilter's preoperation and postoperation callback routines receive the same input parameter values.

If a minifilter changes the value of the **TargetInstance** member, the new value must be a pointer to an instance of the same minifilter at the same altitude on a different volume. In addition, the new volume's device object must have a stack size that is greater than or equal to that of the original volume's device object.

To get the stack size for a volume device object, given an opaque instance pointer for an instance that is attached to the volume, do the following:

* Call **FltGetVolumeFromInstance** to get the volume pointer.
* Call **FltGetDeviceObject** to get a pointer to the volume device object. This pointer is returned in the *DeviceObject* parameter. The device object's stack size can be found in **DeviceObject->StackSize**.
* When the volume pointer is no longer needed, call **FltObjectDereference** to decrement its reference count.
* When the volume device object pointer is no longer needed, call **ObDereferenceObject** to decrement its reference count.

A minifilter can change the value of the **TargetFileObject** member. However, the new value must be a pointer to a file object for a file that resides on the same volume as the instance specified by the **TargetInstance** member.

A minifilter cannot safely change the value of the **MajorFunction** member. Instead, it must initiate a new I/O operation.

A minifilter can initiate an I/O operation by calling a support routine such as [**FltReadFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreadfile) or by calling [**FltAllocateCallbackData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecallbackdata) to allocate a callback data structure; initializing the I/O parameters in the **FLT_IO_PARAMETER_BLOCK** structure, and passing the callback data structure to [**FltPerformSynchronousIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltperformsynchronousio) or [**FltPerformAsynchronousIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltperformasynchronousio).

> [!NOTE]
>
> Use support routines wherever possible when initiating I/O operations. A minifilter should allocate its own callback data only if there is no support function for a particular I/O operation.

## See also

[**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[**FLT_IS_IRP_OPERATION**](https://learn.microsoft.com/previous-versions/ff544654(v=vs.85))

[**FltAllocateCallbackData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecallbackdata)

[**FltClearCallbackDataDirty**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltclearcallbackdatadirty)

[**FltDecodeParameters**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdecodeparameters)

[**FltIsCallbackDataDirty**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltiscallbackdatadirty)

[**FltReadFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreadfile)

[**FltSetCallbackDataDirty**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetcallbackdatadirty)

[**IO_STACK_LOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location)

[**IRP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)

[**FLT_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_parameters)

* [**FLT_PARAMETERS** for **IRP_MJ_ACQUIRE_FOR_MOD_WRITE**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-acquire-for-mod-write)
* [**FLT_PARAMETERS** for **IRP_MJ_ACQUIRE_FOR_SECTION_SYNCHRONIZATION**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-acquire-for-section-synchronization)
* [**FLT_PARAMETERS** for **IRP_MJ_CREATE**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-create)
* [**FLT_PARAMETERS** for **IRP_MJ_CREATE_MAILSLOT**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-create-mailslot)
* [**FLT_PARAMETERS** for **IRP_MJ_CREATE_NAMED_PIPE**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-create-named-pipe)
* [**FLT_PARAMETERS** for **IRP_MJ_DEVICE_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-device-control-and-irp-mj-internal-device-co)
* [**FLT_PARAMETERS** for **IRP_MJ_DIRECTORY_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-directory-control)
* [**FLT_PARAMETERS** for **IRP_MJ_FAST_IO_CHECK_IF_POSSIBLE**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-fast-io-check-if-possible)
* [**FLT_PARAMETERS** for **IRP_MJ_FILE_SYSTEM_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-file-system-control)
* [**FLT_PARAMETERS** for **IRP_MJ_INTERNAL_DEVICE_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-device-control-and-irp-mj-internal-device-co)
* [**FLT_PARAMETERS** for **IRP_MJ_LOCK_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-lock-control)
* [**FLT_PARAMETERS** for **IRP_MJ_MDL_READ**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-mdl-read)
* [**FLT_PARAMETERS** for **IRP_MJ_MDL_READ_COMPLETE**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-mdl-read-complete)
* [**FLT_PARAMETERS** for **IRP_MJ_MDL_WRITE_COMPLETE**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-mdl-write-complete)
* [**FLT_PARAMETERS** for **IRP_MJ_NETWORK_QUERY_OPEN**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-network-query-open)
* [**FLT_PARAMETERS** for **IRP_MJ_PNP**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-pnp)
* [**FLT_PARAMETERS** for **IRP_MJ_PREPARE_MDL_WRITE**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-prepare-mdl-write)
* [**FLT_PARAMETERS** for **IRP_MJ_QUERY_EA**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-query-ea)
* [**FLT_PARAMETERS** for **IRP_MJ_QUERY_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-query-information)
* [**FLT_PARAMETERS** for **IRP_MJ_QUERY_OPEN**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-query-open)
* [**FLT_PARAMETERS** for **IRP_MJ_QUERY_QUOTA**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-query-quota)
* [**FLT_PARAMETERS** for **IRP_MJ_QUERY_SECURITY**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-query-security)
* [**FLT_PARAMETERS** for **IRP_MJ_QUERY_VOLUME_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-query-volume-information)
* [**FLT_PARAMETERS** for **IRP_MJ_READ**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-read)
* [**FLT_PARAMETERS** for **IRP_MJ_RELEASE_FOR_MOD_WRITE**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-release-for-mod-write)
* [**FLT_PARAMETERS** for **IRP_MJ_RELEASE_FOR_SECTION_SYNCHRONIZATION**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-release-for-section-synchronization)
* [**FLT_PARAMETERS** for **IRP_MJ_SET_EA**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-set-ea)
* [**FLT_PARAMETERS** for **IRP_MJ_SET_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-set-information)
* [**FLT_PARAMETERS** for **IRP_MJ_SET_QUOTA**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-set-quota)
* [**FLT_PARAMETERS** for **IRP_MJ_SET_SECURITY**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-set-security)
* [**FLT_PARAMETERS** for **IRP_MJ_SET_VOLUME_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-set-volume-information)
* [**FLT_PARAMETERS** for **IRP_MJ_SYSTEM_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-system-control)
* [**FLT_PARAMETERS** for **IRP_MJ_VOLUME_MOUNT**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-volume-mount)
* [**FLT_PARAMETERS** for **IRP_MJ_WRITE**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-write)

[**IRP_MJ_CLEANUP**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-cleanup)

[**IRP_MJ_CLOSE**](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-close)

[**IRP_MJ_FLUSH_BUFFERS**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-flush-buffers)

[**IRP_MJ_SHUTDOWN**](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-shutdown)

[**PFLT_COMPLETED_ASYNC_IO_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_completed_async_io_callback)

[**PFLT_GENERATE_FILE_NAME**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_generate_file_name)

[**PFLT_POST_OPERATION_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_post_operation_callback)

[**PFLT_PRE_OPERATION_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_pre_operation_callback)