# FltLockUserBuffer function

## Description

The **FltLockUserBuffer** routine locks the user buffer for a given I/O operation.

## Parameters

### `CallbackData` [in]

Pointer to the [**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data) callback data structure for the I/O operation.

## Return value

**FltLockUserBuffer** returns STATUS_SUCCESS if it successfully locks the user buffer (or if the buffer was already locked by a previous call to **FltLockUserBuffer**.) Otherwise, it returns an appropriate NTSTATUS value, such as one of the following:

| Return code | Description |
| ----------- | ----------- |
| STATUS_INSUFFICIENT_RESOURCES | **FltLockUserBuffer** encountered a pool allocation failure. This is an error code. |
| STATUS_INVALID_PARAMETER | An invalid parameter was encountered. For example, the I/O operation does not have an MDL parameter, or the IRP_MJ_READ or IRP_MJ_WRITE I/O operations have a minor code of IRP_MN_MDL. This is an error code. |

## Remarks

For best performance, filter drivers should not call **FltLockUserBuffer** unless absolutely necessary. The performance slowdown is not because of **FltLockUserBuffer** itself, but rather because of the performance penalty incurred by the subsequent call to [**MmGetSystemAddressForMdlSafe**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetsystemaddressformdlsafe); see later Remarks for more information.

A minifilter driver can call **FltLockUserBuffer** to lock the user buffer for one of the following I/O operations:

* IRP_MJ_DEVICE_CONTROL
* IRP_MJ_DIRECTORY_CONTROL
* IRP_MJ_FILE_SYSTEM_CONTROL
* IRP_MJ_INTERNAL_DEVICE_CONTROL
* IRP_MJ_QUERY_EA
* IRP_MJ_QUERY_QUOTA
* IRP_MJ_QUERY_SECURITY
* IRP_MJ_READ (except with IRP_MN_MDL)
* IRP_MJ_SET_EA
* IRP_MJ_SET_QUOTA
* IRP_MJ_WRITE (except with IRP_MN_MDL)

**FltLockUserBuffer** determines the appropriate access method (IoReadAccess, IoWriteAccess, or IoModifyAccess) to apply for the locked buffer based on the type of I/O operation.

**FltLockUserBuffer** sets the **MdlAddress** (or **OutputMdlAddress**) member in the callback data parameter structure ([**FLT_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_parameters)) to point to the MDL for the locked pages. If there is no MDL, **FltLockUserBuffer** allocates one. (Note that FltMgr cannot generate an MDL before the file system does, which is why **FltLockUserBuffer** returns STATUS_INVALID_PARAMETER for IRP_MJ_READ or IRP_MJ_WRITE with IRP_MN_MDL).

If the callback data parameter structure contains a system buffer (**Irp->AssociatedIrp.SystemBuffer**) and does not contain a user buffer (**Irp->UserBuffer**), **FltLockUserBuffer** locks the system buffer. If there is no MDL for the system buffer, **FltLockUserBuffer** allocates one.

If the callback data parameter structure contains a user buffer, **FltLockUserBuffer** [probes and locks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmprobeandlockpages) the user buffer.

The caller can be running in any process context. **FltLockUserBuffer** automatically locks the buffer in the correct process context.

If **FltLockUserBuffer** is called from a pre-operation callback routine ([**PFLT_PRE_OPERATION_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_pre_operation_callback)) and it allocates an MDL, **FltLockUserBuffer** sets the FLTFL_CALLBACK_DATA_DIRTY flag in the callback data structure ([**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)) so that the I/O system frees the MDL when the I/O operation is completed.

To conserve system page table entries (PTEs), **FltLockUserBuffer** doesn't map the locked pages. After calling **FltLockUserBuffer**, the caller must call [**MmGetSystemAddressForMdlSafe**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetsystemaddressformdlsafe), passing the **MdlAddress** (or **OutputMdlAddress**) member in the callback data parameter structure as the value of the **Mdl** parameter, to get a system buffer that represents this memory.

When the callback data structure is freed, the locked buffer is automatically unlocked, and the MDL is freed. The caller should never free the MDL; the I/O system does this automatically.

**FltLockUserBuffer** can be called for fast I/O and IRP-based operations.

## See also

[**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[**FLT_IS_FASTIO_OPERATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-flt_is_fastio_operation)

[**FLT_IS_IRP_OPERATION**](https://learn.microsoft.com/previous-versions/ff544654(v=vs.85))

[**FLT_IS_SYSTEM_BUFFER**](https://learn.microsoft.com/previous-versions/ff544663(v=vs.85))

[**FLT_PARAMETERS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_parameters)

[**FLT_PARAMETERS for IRP_MJ_DEVICE_CONTROL and IRP_MJ_INTERNAL_DEVICE_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-device-control-and-irp-mj-internal-device-co)

[**FLT_PARAMETERS for IRP_MJ_DIRECTORY_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-directory-control)

[**FLT_PARAMETERS for IRP_MJ_FILE_SYSTEM_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-file-system-control)

[**FLT_PARAMETERS for IRP_MJ_QUERY_EA**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-query-ea)

[**FLT_PARAMETERS for IRP_MJ_QUERY_QUOTA**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-query-quota)

[**FLT_PARAMETERS for IRP_MJ_QUERY_SECURITY**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-query-security)

[**FLT_PARAMETERS for IRP_MJ_READ**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-read)

[**FLT_PARAMETERS for IRP_MJ_SET_EA**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-set-ea)

[**FLT_PARAMETERS for IRP_MJ_SET_QUOTA**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-set-quota)

[**FLT_PARAMETERS for IRP_MJ_WRITE**](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-write)

[**FltDecodeParameters**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdecodeparameters)

[**MmGetSystemAddressForMdlSafe**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmgetsystemaddressformdlsafe)

[**MmProbeAndLockPages**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmprobeandlockpages)

[**PFLT_POST_OPERATION_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_post_operation_callback)

[**PFLT_PRE_OPERATION_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_pre_operation_callback)