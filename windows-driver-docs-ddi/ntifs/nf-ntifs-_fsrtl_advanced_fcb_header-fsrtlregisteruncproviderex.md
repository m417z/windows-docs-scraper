# FsRtlRegisterUncProviderEx function

## Description

The **FsRtlRegisterUncProviderEx** routine registers a network redirector as a universal naming convention (UNC) provider with the system multiple UNC provider (MUP).

## Parameters

### `MupHandle` [out]

A pointer to a location in which to return a MUP handle to be used when calling [FsRtlDeregisterUncProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlderegisteruncprovider) to deregister the network redirector. The returned handle is valid only if **FsRtlRegisterUncProviderEx** returns STATUS_SUCCESS.

### `RedirDevName` [in]

A pointer to a Unicode string that contains the device name of the network redirector. MUP uses this device name to create a symbolic link in the Object Manager namespace whose target is \Device\Mup.

### `DeviceObject` [in]

A pointer to an unnamed device object that represents the network redirector.

### `Flags` [in]

A bitmask that indicates features supported by the network redirector. A network redirector sets a bit to indicate that a feature is supported. The *Flags* parameter has two options:

FSRTL_UNC_PROVIDER_FLAGS_MAILSLOTS_SUPPORTED

The network redirector supports mailslots. This option is normally reserved for use by the Microsoft SMB redirector.

FSRTL_UNC_PROVIDER_FLAGS_CSC_ENABLED

The network redirector supports offline access using client-side caching.

## Return value

**FsRtlRegisterUncProviderEx** returns STATUS_SUCCESS on success or an appropriate NTSTATUS value such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_ACCESS_DENIED** | The requester mode of the IRP that is sent to MUP was not from kernel mode. |
| **STATUS_ACCESS_VIOLATION** | An access violation occurred when attempting access to the MUP device. |
| **STATUS_DATATYPE_MISALIGNMENT** | There was a misalignment of data. |
| **STATUS_INSUFFICIENT_RESOURCES** | There were insufficient resources available to allocate memory for buffers. |
| **STATUS_INVALID_DEVICE_REQUEST** | A request was made to register a known provider that was already registered. |
| **STATUS_INVALID_PARAMETER** | The *RedirDevName* parameter was invalid because the length of *RedirDevName* was zero. |
| **STATUS_OBJECT_TYPE_MISMATCH** | An object type mismatch was encountered with the *DeviceObject* parameter. |

## Remarks

A network redirector must register with the multiple UNC provider (MUP) to handle Universal Naming Convention (UNC) names. MUP is a kernel-mode component responsible for channeling all remote file system accesses using a Universal Naming Convention (UNC) name to a network redirector (the UNC provider) that is capable of handling the remote file system requests. MUP is involved when a UNC path is used by an application as illustrated by the following example that could be executed from a command line:

```
notepad \\server\public\readme.txt
```

MUP is not involved during an operation that creates a mapped drive letter (the "NET USE" command, for example). This operation is handled by the multiple provider router (MPR) and a user-mode WNet provider DLL for the network redirector. However, a user-mode WNet provider DLL might communicate directly with a kernel-mode network redirector driver during this operation.

For network redirectors that conform to the Windows Vista redirector model, MUP is involved even when a mapped network drive is used. File operations performed on the mapped drive go through MUP to the network redirector. Note that in this case, MUP simply passes the operation to the network redirector that is involved.

**FsRtlRegisterUncProviderEx** sends a private file system control (FSCTL) to MUP to perform the registration.

The device name specified in the *RedirDevName* parameter in the call to **FsRtlRegisterUncProviderEx** becomes a symbolic link to \device\Mup in the object manager namespace. Also, an open request of the device name, *RedirDevName*, will route itself to the actual network redirector device object pointed to by the *DeviceObject* parameter.

Network redirectors that call **FsRtlRegisterUncProviderEx** must not register themselves as a file system (network redirectors must not call [IoRegisterFileSystem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioregisterfilesystem)). Network mini-redirectors that use the Windows Vista RDBSS (dynamic or static linking) will not be registered as a file system.

File objects on the remote file system stack owned by a network redirector that conforms to the Windows Vista redirector model resolve to MUP. So [IoGetDeviceAttachmentBaseRef](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iogetdeviceattachmentbaseref) returns the device object for MUP, not the network redirector that owns the file object. However, the content of the file object is still owned by the network redirector.

The ProviderOrder registry value determines the order in which MUP issues prefix resolution requests to individual network redirectors. This order can be changed dynamically without a reboot. This registry value is located under the following registry key:

```
HKLM\CurrentControlSet\Control\NetworkProvider\Order
```

Only one network provider on a system can support mailslots. So the FSRTL_UNC_PROVIDER_FLAGS_MAILSLOTS_SUPPORTED option in the *Flags* parameter is normally only set for the Microsoft SMB redirector.

To deregister a UNC provider, use [FsRtlDeregisterUncProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlderegisteruncprovider) and pass the *MupHandle* parameter.

If a driver registers as a local disk file system (by calling [IoCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedevice) with the *DeviceType* parameter set to FILE_DEVICE_DISK_FILE_SYSTEM), the driver must not call **FsRtlRegisterUncProviderEx** to register as a UNC provider with MUP.

For more information, see the following sections in the Design Guide:

[Support for UNC Naming and MUP](https://learn.microsoft.com/windows-hardware/drivers/ifs/support-for-unc-naming-and-mup)

[MUP Changes in Microsoft Windows Vista](https://learn.microsoft.com/windows-hardware/drivers/ifs/mup-changes-in-microsoft-windows-vista)

## See also

[FsRtlCancellableWaitForSingleObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlcancellablewaitforsingleobject)

[FsRtlDeregisterUncProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlderegisteruncprovider)

[FsRtlRegisterUncProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlregisteruncprovider)

[IOCTL_REDIR_QUERY_PATH_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-ioctl_redir_query_path_ex)

[IoCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedevice)

[IoGetDeviceAttachmentBaseRef](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iogetdeviceattachmentbaseref)

[IoRegisterFileSystem](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioregisterfilesystem)