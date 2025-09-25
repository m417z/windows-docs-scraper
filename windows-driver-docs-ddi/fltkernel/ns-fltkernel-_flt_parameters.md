# FLT_PARAMETERS union

## Description

The FLT_PARAMETERS union defines, for a minifilter, the request-type-specific parameters associated with an I/O operation. The **Members** section on this reference page lists the members without providing descriptions. Jump directly to [**Remarks**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_parameters#remarks) for pointers to the actual structure descriptions.

## Members

## Remarks

The FLT_PARAMETERS structure is stored in the **Parameters** field of the [FLT_IO_PARAMETER_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_io_parameter_block) structure for the operation. (A pointer to the FLT_IO_PARAMETER_BLOCK structure is stored in the **Iopb** field of the [FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data) structure for the operation.)

The following table lists each structure member of the FLT_PARAMETERS union and then links to the page that describes that structure's members for the associated IRP. The structures are listed in the order they are defined within FLT_PARAMETERS.

| Structure Name | Description |
| -------------- | ----------- |
| *Create* | [FLT_PARAMETERS for IRP_MJ_CREATE](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-create) |
| *CreatePipe* | [FLT_PARAMETERS for IRP_MJ_CREATE_NAMED_PIPE](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-create-named-pipe) |
| *CreateMailslot* | [FLT_PARAMETERS for IRP_MJ_CREATE_MAILSLOT](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-create-mailslot) |
| *Read* | [FLT_PARAMETERS for IRP_MJ_READ](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-read) |
| *Write* | [FLT_PARAMETERS for IRP_MJ_WRITE](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-write) |
| *QueryFileInformation* | [FLT_PARAMETERS for IRP_MJ_QUERY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-query-information) |
| *SetFileInformation* | [FLT_PARAMETERS for IRP_MJ_SET_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-set-information) |
| *QueryEa* | [FLT_PARAMETERS for IRP_MJ_QUERY_EA](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-query-ea) |
| *SetEa* | [FLT_PARAMETERS for IRP_MJ_SET_EA](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-set-ea) |
| *QueryVolumeInformation* | [FLT_PARAMETERS for IRP_MJ_QUERY_VOLUME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-query-volume-information) |
| *SetVolumeInformation* | [FLT_PARAMETERS for IRP_MJ_SET_VOLUME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-set-volume-information) |
| *DirectoryControl* | [FLT_PARAMETERS for IRP_MJ_DIRECTORY_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-directory-control) |
| *FileSystemControl* | [FLT_PARAMETERS for IRP_MJ_FILE_SYSTEM_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-file-system-control) |
| *DeviceIoControl* | [FLT_PARAMETERS for IRP_MJ_DEVICE_CONTROL and IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-device-control-and-irp-mj-internal-device-co) |
| *LockControl* | [FLT_PARAMETERS for IRP_MJ_LOCK_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-lock-control) |
| *QuerySecurity* | [FLT_PARAMETERS for IRP_MJ_QUERY_SECURITY](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-query-security) |
| *SetSecurity* | [FLT_PARAMETERS for IRP_MJ_SET_SECURITY](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-set-security) |
| *QueryQuota* | [FLT_PARAMETERS for IRP_MJ_QUERY_QUOTA](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-query-quota) |
| *SetQuota* | [FLT_PARAMETERS for IRP_MJ_SET_QUOTA](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-set-quota) |
| *Pnp* | [FLT_PARAMETERS for IRP_MJ_PNP](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-pnp) |
| *AcquireForSectionSynchronization* | [FLT_PARAMETERS for IRP_MJ_ACQUIRE_FOR_SECTION_SYNCHRONIZATION](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-acquire-for-section-synchronization) |
| *AcquireForModifiedPageWriter* | [FLT_PARAMETERS for IRP_MJ_ACQUIRE_FOR_MOD_WRITE](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-acquire-for-mod-write) |
| *ReleaseForModifiedPageWriter* | [FLT_PARAMETERS for IRP_MJ_RELEASE_FOR_MOD_WRITE](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-release-for-mod-write) |
| *QueryOpen* | [FLT_PARAMETERS for IRP_MJ_QUERY_OPEN](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-query-open) |
| *FastIoCheckIfPossible* | [FLT_PARAMETERS for IRP_MJ_FAST_IO_CHECK_IF_POSSIBLE](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-fast-io-check-if-possible) |
| *NetworkQueryOpen* | [FLT_PARAMETERS for IRP_MJ_NETWORK_QUERY_OPEN](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-network-query-open) |
| *MdlRead* | [FLT_PARAMETERS for IRP_MJ_MDL_READ](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-mdl-read) |
| *MdlReadComplete* | [FLT_PARAMETERS for IRP_MJ_MDL_READ_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-mdl-read-complete) |
| *PrepareMdlWrite* | [FLT_PARAMETERS for IRP_MJ_PREPARE_MDL_WRITE](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-prepare-mdl-write) |
| *MdlWriteComplete* | [FLT_PARAMETERS for IRP_MJ_MDL_WRITE_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-mdl-write-complete) |
| *MountVolume* | [FLT_PARAMETERS for IRP_MJ_VOLUME_MOUNT](https://learn.microsoft.com/windows-hardware/drivers/ifs/flt-parameters-for-irp-mj-volume-mount) |

The following I/O operations do not have parameters, and therefore do not have a corresponding member within the FLT_PARAMETERS structure. Minifilter drivers that register a callback routine for these I/O operations should perform any needed processing and return:

- IRP_MJ_ACQUIRE_FOR_CC_FLUSH
- IRP_MJ_CLEANUP
- IRP_MJ_CLOSE
- IRP_MJ_FLUSH_BUFFERS
- IRP_MJ_RELEASE_FOR_CC_FLUSH
- IRP_MJ_RELEASE_FOR_SECTION_SYNCHRONIZATION
- IRP_MJ_SHUTDOWN
- IRP_MJ_VOLUME_DISMOUNT

Note that the terms "acquire" or "release" in some operation names, such as `IRP_MJ_ACQUIRE_FOR_CC_FLUSH` and `IRP_MJ_RELEASE_FOR_CC_FLUSH`, do not imply any guarantees that a minifilter will always see both operations. Just as with operations such as `IRP_MJ_CREATE` and `IRP_MJ_CLEANUP`, a minifilter may be prevented from observing the second operation by other factors, such as receiving an _[InstanceTeardownStartCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_instance_teardown_callback)_ before the second operation occurs.

## See also

[FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[FLT_IO_PARAMETER_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_io_parameter_block)

[**FltSetCallbackDataDirty**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetcallbackdatadirty)