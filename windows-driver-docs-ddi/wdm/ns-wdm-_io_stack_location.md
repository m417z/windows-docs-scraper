## Description

The **IO_STACK_LOCATION** structure defines an [I/O stack location](https://learn.microsoft.com/windows-hardware/drivers/kernel/i-o-stack-locations), which is an entry in the I/O stack that is associated with each IRP. Each I/O stack location in an IRP has some common members and some request-type-specific members.

## Members

### `MajorFunction`

The [IRP major function code](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-major-function-codes) indicating the type of I/O operation to be performed.

### `MinorFunction`

A subfunction code for **MajorFunction**. The PnP manager, the power manager, file system drivers, and SCSI class drivers set this member for some requests.

### `Flags`

Request-type-specific values used almost exclusively by file system drivers. Removable-media device drivers check whether this member is set with SL_OVERRIDE_VERIFY_VOLUME for read requests to determine whether to continue the read operation even if the device object's **Flags** is set with DO_VERIFY_VOLUME. Intermediate drivers layered over a removable-media device driver must copy this member into the I/O stack location of the next-lower driver in all incoming [IRP_MJ_READ](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-read) requests.

For documentation of other `SL_*` flags for IRP_MJ_CREATE, see [IRP_MJ_CREATE (IFS)](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create).

Possible flag values include:

| Flag | Value | Description |
|---|---|---|
| SL_KEY_SPECIFIED | `0x01` | Indicates that the `IO_STACK_LOCATION.Parameters.Read(OrWrite).Key` contains which copy of a given sector should be read when redundancy is enabled. Today this flag is use only with IRP_MJ_READ operations. |
| SL_OVERRIDE_VERIFY_VOLUME | `0x02` | This flag is used to determine whether to continue the read operation even if the device object's **Flags** is set with DO_VERIFY_VOLUME. |
| SL_WRITE_THROUGH | `0x04` | This flag informs the storage driver to set appropriate flags so that the disk bypasses the write cache in order to force the disk to write through to its persistent storage media. **This flag is device-specific; not all disk drives support bypassing disk-cache.** |
| SL_FT_SEQUENTIAL_WRITE | `0x08` | Reserved for system use. |
| SL_FORCE_DIRECT_WRITE | `0x10` | This flag lets kernel-mode drivers write to volume areas that they normally cannot write to because of blocking direct write in the file system and storage driver stack. Direct write blocking helps improve security. This flag is checked both at the file system layer and storage stack layer. For more information about direct write blocking, see [Blocking Direct Write Operations to Volumes and Disks](https://learn.microsoft.com/windows-hardware/drivers/ddi/). |
| SL_REALTIME_STREAM | `0x20` | This flag hints that the IO is for real-time streaming requests to a CD-ROM class driver. This hints the driver to perform READ/WRITE operations at a guaranteed speed for real-time streaming. **This flag is valid only with optical media.** |
| SL_PERSISTENT_MEMORY_FIXED_MAPPING | `0x20` | The persistent memory mapping of the bytes in the write request cannot change while handling this write request. **This flag is valid only with a persistent memory device and IRP_MJ_WRITE.** |

For persistent memory devices, one of the reasons for remapping (modifying the physical address of a given LBA) on persistent memory devices is to provide efficient sector level atomicity. If the flag is not set, remapping is allowed especially if it results in the driver providing sector atomicity. File systems (or the requester) prefer that a persistent memory device driver provides sector atomicity.
If the flag is set, a persistent memory driver shall not remap the physical addresses corresponding
to the LBAs. If that means sector atomicity can't be provided, so be it. However, the driver is more
than welcome to provide sector atomicity as long as there is no remapping.

### `Control`

Drivers can check this member to determine whether it is set with SL_PENDING_RETURNED and under what conditions the *CompletionRoutine* is called. Drivers have read-only access to this member. Drivers call [**IoSetCompletionRoutine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetcompletionroutine) or [**IoSetCompletionRoutineEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetcompletionroutineex) to specify these conditions.

### `Parameters`

A union that depends on the major and minor IRP function code values contained in **MajorFunction** and **MinorFunction**. The following table shows which IRPs use the individual members of the **Parameters** union.

| Member name | IRPs that use this member |
|---|---|
| **Create** | [IRP_MJ_CREATE](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create) |
| **Read** | [IRP_MJ_READ](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-read) |
| **Write** | [IRP_MJ_WRITE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-write) |
| **QueryFile** | [IRP_MJ_QUERY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-query-information) |
| **SetFile** | [IRP_MJ_SET_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-set-information) |
| **QueryVolume** | [IRP_MJ_QUERY_VOLUME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-query-volume-information) |
| **DeviceIoControl** | [IRP_MJ_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-device-control) and [IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control) |
| **MountVolume** | **IRP_MN_MOUNT_VOLUME** |
| **VerifyVolume** | **IRP_MN_VERIFY_VOLUME** |
| **Scsi** | [IRP_MJ_INTERNAL_DEVICE_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-internal-device-control) (SCSI) |
| **QueryDeviceRelations** | [IRP_MN_QUERY_DEVICE_RELATIONS](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-device-relations) |
| **QueryInterface** | [IRP_MN_QUERY_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-interface) |
| **DeviceCapabilities** | [IRP_MN_QUERY_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-capabilities) |
| **FilterResourceRequirements** | [IRP_MN_FILTER_RESOURCE_REQUIREMENTS](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-filter-resource-requirements) |
| **ReadWriteConfig** | [IRP_MN_READ_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-read-config) and [IRP_MN_WRITE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-write-config) |
| **SetLock** | [IRP_MN_SET_LOCK](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-set-lock) |
| **QueryId** | [IRP_MN_QUERY_ID](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-id) |
| **QueryDeviceText** | [IRP_MN_QUERY_DEVICE_TEXT](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-device-text) |
| **UsageNotification** | [IRP_MN_DEVICE_USAGE_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-device-usage-notification) |
| **WaitWake** | [IRP_MN_WAIT_WAKE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-wait-wake) |
| **PowerSequence** | [IRP_MN_POWER_SEQUENCE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-power-sequence) |
| **Power** | [IRP_MN_SET_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-set-power) and [IRP_MN_QUERY_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-power) |
| **StartDevice** | [IRP_MN_START_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-start-device) |
| **WMI** | [WMI minor IRPs](https://learn.microsoft.com/windows-hardware/drivers/kernel/wmi-minor-irps) |
| **Others** | Driver-specific IRPs |

For more information, see [IRP Major Function Codes](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-major-function-codes).

### `Parameters.Create`

System service parameters for **NtCreateFile**.

### `Parameters.Create.SecurityContext`

### `Parameters.Create.Options`

### `Parameters.Create.FileAttributes`

### `Parameters.Create.ShareAccess`

### `Parameters.Create.EaLength`

### `Parameters.CreatePipe`

 System service parameters fo **NtCreateNamedPipeFile**.

### `Parameters.CreatePipe.SecurityContext`

### `Parameters.CreatePipe.Options`

### `Parameters.CreatePipe.Reserved`

### `Parameters.CreatePipe.ShareAccess`

### `Parameters.CreatePipe.Parameters`

### `Parameters.CreateMailslot`

System service parameters for **NtCreateMailslotFile**.

### `Parameters.CreateMailslot.SecurityContext`

### `Parameters.CreateMailslot.Options`

### `Parameters.CreateMailslot.Reserved`

### `Parameters.CreateMailslot.ShareAccess`

### `Parameters.CreateMailslot.Parameters`

### `Parameters.Read`

 System service parameters for **NtReadFile**.

### `Parameters.Read.Length`

### `Parameters.Read.Key`

### `Parameters.Read.Flags`

### `Parameters.Read.ByteOffset`

### `Parameters.Write`

System service parameters for **NtWriteFile**.

### `Parameters.Write.Length`

### `Parameters.Write.Key`

### `Parameters.Write.Flags`

### `Parameters.Write.ByteOffset`

### `Parameters.QueryDirectory`

System service parameters for **NtQueryDirectoryFile**.

### `Parameters.QueryDirectory.Length`

### `Parameters.QueryDirectory.FileName`

### `Parameters.QueryDirectory.FileInformationClass`

### `Parameters.QueryDirectory.FileIndex`

### `Parameters.NotifyDirectory`

System service parameters for **NtNotifyChangeDirectoryFile**.

### `Parameters.NotifyDirectory.Length`

### `Parameters.NotifyDirectory.CompletionFilter`

### `Parameters.NotifyDirectoryEx`

System service parameters for **NtNotifyChangeDirectoryFileEx**.

### `Parameters.NotifyDirectoryEx.Length`

### `Parameters.NotifyDirectoryEx.CompletionFilter`

### `Parameters.NotifyDirectoryEx.DirectoryNotifyInformationClass`

### `Parameters.QueryFile`

System service parameters for **NtQueryInformationFile**.

### `Parameters.QueryFile.Length`

### `Parameters.QueryFile.FileInformationClass`

### `Parameters.SetFile`

System service parameters for **NtSetInformationFile**.

### `Parameters.SetFile.Length`

### `Parameters.SetFile.FileInformationClass`

### `Parameters.SetFile.FileObject`

### `Parameters.SetFile.ReplaceIfExists`

### `Parameters.SetFile.AdvanceOnly`

### `Parameters.SetFile.ClusterCount`

### `Parameters.SetFile.DeleteHandle`

### `Parameters.QueryEa`

System service parameters for **NtQueryEaFile**.

### `Parameters.QueryEa.Length`

### `Parameters.QueryEa.EaList`

### `Parameters.QueryEa.EaListLength`

### `Parameters.QueryEa.EaIndex`

### `Parameters.SetEa`

System service parameters for **NtSetEaFile**.

### `Parameters.SetEa.Length`

### `Parameters.QueryVolume`

System service parameters for **NtQueryVolumeInformationFile**.

### `Parameters.QueryVolume.Length`

### `Parameters.QueryVolume.FsInformationClass`

### `Parameters.SetVolume`

System service parameters for **NtSetVolumeInformationFile**.

### `Parameters.SetVolume.Length`

### `Parameters.SetVolume.FsInformationClass`

### `Parameters.FileSystemControl`

System service parameters for **NtFsControlFile**.

### `Parameters.FileSystemControl.OutputBufferLength`

### `Parameters.FileSystemControl.InputBufferLength`

### `Parameters.FileSystemControl.FsControlCode`

### `Parameters.FileSystemControl.Type3InputBuffer`

### `Parameters.LockControl`

System service parameters for **LockFile/NtUnlockFile**.

### `Parameters.LockControl.Length`

### `Parameters.LockControl.Key`

### `Parameters.LockControl.ByteOffset`

### `Parameters.DeviceIoControl`

System service parameters for **NtDeviceIoControlFile**.

### `Parameters.DeviceIoControl.OutputBufferLength`

### `Parameters.DeviceIoControl.InputBufferLength`

### `Parameters.DeviceIoControl.IoControlCode`

### `Parameters.DeviceIoControl.Type3InputBuffer`

### `Parameters.QuerySecurity`

System service parameters for **NtQuerySecurityObject**.

### `Parameters.QuerySecurity.SecurityInformation`

### `Parameters.QuerySecurity.Length`

### `Parameters.SetSecurity`

System service parameters for **NtSetSecurityObject**.

### `Parameters.SetSecurity.SecurityInformation`

### `Parameters.SetSecurity.SecurityDescriptor`

### `Parameters.MountVolume`

System service parameters for **MountVolume**.

### `Parameters.MountVolume.Vpb`

### `Parameters.MountVolume.DeviceObject`

### `Parameters.MountVolume.OutputBufferLength`

### `Parameters.VerifyVolume`

System service parameters for **VerifyVolume**.

### `Parameters.VerifyVolume.Vpb`

### `Parameters.VerifyVolume.DeviceObject`

### `Parameters.Scsi`

Parameters for Scsi with internal device control.

### `Parameters.Scsi.Srb`

### `Parameters.QueryQuota`

System service parameters for [**NtQueryQuotaInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntqueryquotainformationfile).

### `Parameters.QueryQuota.Length`

### `Parameters.QueryQuota.StartSid`

### `Parameters.QueryQuota.SidList`

### `Parameters.QueryQuota.SidListLength`

### `Parameters.SetQuota`

System service parameters for [**NtSetQuotaInformationFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntsetquotainformationfile).

### `Parameters.SetQuota.Length`

### `Parameters.QueryDeviceRelations`

Parameters for IRP_MN_QUERY_DEVICE_RELATIONS.

### `Parameters.QueryDeviceRelations.Type`

### `Parameters.QueryInterface`

Parameters for IRP_MN_QUERY_INTERFACE.

### `Parameters.QueryInterface.InterfaceType`

### `Parameters.QueryInterface.Size`

### `Parameters.QueryInterface.Version`

### `Parameters.QueryInterface.Interface`

### `Parameters.QueryInterface.InterfaceSpecificData`

### `Parameters.DeviceCapabilities`

Parameters for IRP_MN_QUERY_CAPABILITIES.

### `Parameters.DeviceCapabilities.Capabilities`

### `Parameters.FilterResourceRequirements`

Parameters for IRP_MN_FILTER_RESOURCE_REQUIREMENTS.

### `Parameters.FilterResourceRequirements.IoResourceRequirementList`

### `Parameters.ReadWriteConfig`

Parameters for IRP_MN_READ_CONFIG and IRP_MN_WRITE_CONFIG.

### `Parameters.ReadWriteConfig.WhichSpace`

### `Parameters.ReadWriteConfig.Buffer`

### `Parameters.ReadWriteConfig.Offset`

### `Parameters.ReadWriteConfig.Length`

### `Parameters.SetLock`

Parameters for IRP_MN_SET_LOCK.

### `Parameters.SetLock.Lock`

### `Parameters.QueryId`

Parameters for IRP_MN_QUERY_ID.

### `Parameters.QueryId.IdType`

### `Parameters.QueryDeviceText`

Parameters for IRP_MN_QUERY_DEVICE_TEXT.

### `Parameters.QueryDeviceText.DeviceTextType`

### `Parameters.QueryDeviceText.LocaleId`

### `Parameters.UsageNotification`

Parameters for IRP_MN_DEVICE_USAGE_NOTIFICATION.

### `Parameters.UsageNotification.InPath`

### `Parameters.UsageNotification.Reserved[3]`

### `Parameters.UsageNotification.Type`

### `Parameters.WaitWake`

Parameters for IRP_MN_WAIT_WAKE.

### `Parameters.WaitWake.PowerState`

### `Parameters.PowerSequence`

Parameter for IRP_MN_POWER_SEQUENCE.

### `Parameters.PowerSequence.PowerSequence`

### `Parameters.Power.SystemPowerStateContext`

### `Parameters.Power`

Parameters for IRP_MN_SET_POWER and IRP_MN_QUERY_POWER.

### `Parameters.Power.SystemContext`

### `Parameters.Power.Type`

### `Parameters.Power.State`

### `Parameters.Power.ShutdownType`

### `Parameters.StartDevice`

 Parameters for StartDevice.

### `Parameters.StartDevice.AllocatedResources`

### `Parameters.StartDevice.AllocatedResourcesTranslated`

### `Parameters.WMI`

 Parameters for WMI IRPs.

### `Parameters.WMI.ProviderId`

### `Parameters.WMI.DataPath`

### `Parameters.WMI.BufferSize`

### `Parameters.WMI.Buffer`

### `Parameters.Others`

Parameters for other driver-specific operations.

### `Parameters.Others.Argument1`

### `Parameters.Others.Argument2`

### `Parameters.Others.Argument3`

### `Parameters.Others.Argument4`

### `DeviceObject`

A pointer to the driver-created [**DEVICE_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure representing the target physical, logical, or virtual device for which this driver is to handle the IRP.

### `FileObject`

A pointer to a [**FILE_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) structure that represents the file object, if any, that is associated with **DeviceObject** pointer.

### `CompletionRoutine`

The completion routine that is invoked depending on the flags in the **Control** field of this structure.

### `Context`

Driver-defined context that is used to store the address of the context parameter that is passed to the CompletionRoutine.

## Remarks

For each IRP, there is one **IO_STACK_LOCATION** structure for each driver in a [driver stack](https://learn.microsoft.com/windows-hardware/drivers/). Each IRP's set of I/O stack locations is appended to the IRP, following the [**IRP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) structure.

Every higher-level driver is responsible for setting up the I/O stack location for the next-lower driver in each IRP. A driver must call [IoGetCurrentIrpStackLocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetcurrentirpstacklocation) to get a pointer to its own stack location for each IRP. Higher-level drivers can call [IoGetNextIrpStackLocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetnextirpstacklocation) to get a pointer to the next-lower driver's stack location.

The higher-level driver must set up the stack location contents before calling [IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver) to pass an IRP to the lower-level driver. If the driver will pass the input IRP on to the next lower-level driver, the dispatch routine should call [IoSkipCurrentIrpStackLocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioskipcurrentirpstacklocation) or [IoCopyCurrentIrpStackLocationToNext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocopycurrentirpstacklocationtonext) to set up the I/O stack location of the next-lower driver.

A higher-level driver's call to **IoCallDriver** sets the **DeviceObject** member to the next-lower-level driver's target device object, in the I/O stack location of the lower driver. The I/O manager passes each higher-level driver's [IoCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_completion_routine) routine a pointer to its own device object when the *IoCompletion* routine is called on completion of the IRP.

If a higher-level driver allocates IRPs to make requests of its own, its *IoCompletion* routine is passed a **NULL** **DeviceObject** pointer if that driver neither allocates a stack location for itself nor sets up the **DeviceObject** pointer in its own stack location of the newly allocated IRP.

In some cases, a higher-level driver layered over a mass-storage device driver is responsible for splitting up large transfer requests for the underlying device driver. In particular, SCSI class drivers must check the **Parameters.Read.Length** and **Parameters.Write.Length**, determine whether the size of the requested transfer exceeds the underlying HBA's transfer capabilities, and, if so, split the **Length** of the original request into a sequence of partial transfers to satisfy the original IRP.

## See also

[**IO_STATUS_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block)

[**IRP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)

[IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver)

[IoCopyCurrentIrpStackLocationToNext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocopycurrentirpstacklocationtonext)

[IoGetCurrentIrpStackLocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetcurrentirpstacklocation)

[IoGetNextIrpStackLocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetnextirpstacklocation)

[IoSetCompletionRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetcompletionroutine)

[IoSetNextIrpStackLocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iosetnextirpstacklocation)

[IoSkipCurrentIrpStackLocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioskipcurrentirpstacklocation)