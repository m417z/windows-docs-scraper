# FsRtlRegisterUncProvider function

## Description

The **FsRtlRegisterUncProvider** routine registers a network redirector as a universal naming convention (UNC) provider with the system multiple UNC provider (MUP).

## Parameters

### `MupHandle` [out]

A pointer to a location in which to return a MUP handle to be used when calling **FsRtlRegisterUncProvider** to deregister the network redirector. The returned handle is valid only if **FsRtlRegisterUncProvider** returns STATUS_SUCCESS.

### `RedirectorDeviceName`

A pointer to a Unicode string that contains the device name of the network redirector.

### `MailslotsSupported` [in]

Set to **TRUE** if the network redirector supports mailslots. This option is normally reserved for use by the Microsoft SMB redirector.

## Return value

**FsRtlRegisterUncProvider** returns STATUS_SUCCESS on success or an appropriate NTSTATUS value such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_ACCESS_DENIED** | The execution mode of the original requester for the IRP operation sent to MUP was not from kernel mode. |
| **STATUS_ACCESS_VIOLATION** | An access violation occurred when attempting access to the MUP device. |
| **STATUS_DATATYPE_MISALIGNMENT** | There was a misalignment of data. |
| **STATUS_INSUFFICIENT_RESOURCES** | There were insufficient resources available to allocate memory for buffers. |
| **STATUS_INVALID_HANDLE** | An invalid parameter was passed to MUP in the IRP. |
| **STATUS_INVALID_USER_BUFFER** | An invalid parameter was passed in the *RedirDevName* parameter or an abnormal termination occurred. |

## Remarks

A network redirector must register with the MUP to handle UNC names. MUP is a kernel-mode component responsible for channeling all remote file system accesses using a Universal Naming Convention (UNC) name to a network redirector (the UNC provider) that is capable of handling the remote file system requests. MUP is involved when a UNC path is used by an application as illustrated by the following example that could be executed from a command line:

```
notepad \\server\public\readme.txt
```

MUP is not involved during an operation that creates a mapped drive letter (the "NET USE" command, for example). This operation is handled by the multiple provider router (MPR) and a user-mode WNet provider DLL for the network redirector. However, a user-mode WNet provider DLL might communicate directly with a kernel-mode network redirector driver during this operation.

On Windows Server 2003, Windows XP, and Windows 2000, remote file operations performed on a mapped drive that does not represent a Distributed File System (DFS) drive don't go through MUP. These operations go directly to the network provider that handled the drive letter mapping.

For network redirectors that conform to the Windows Vistaredirector model, MUP is involved even when a mapped network drive is used. File operations performed on the mapped drive go through MUP to the network redirector. Note that in this case that MUP simply passes the operation to the network redirector that is involved.

Network redirectors that conform to the Windows Vista redirector model should use [FsRtlRegisterUncProviderEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlregisteruncproviderex), not **FsRtlRegisterUncProvider**.

**FsRtlRegisterUncProvider** sends a private file system control (FSCTL) to MUP to perform the registration.

The ProviderOrder registry value determines the order in which MUP issues prefix resolution requests to individual network redirectors. This registry value is located under the following registry key:

```
HKLM\CurrentControlSet\Control\NetworkProvider\Order
```

Changes to the ProviderOrder registry value require a reboot to take effect in MUP on Windows Server 2003, Windows XP, and Windows 2000.

Only one network provider on a system can support mailslots. So the *MailslotsSupported* parameter is normally only set to **TRUE** for the Microsoft SMB redirector.

A driver calling [IoCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedevice) to create a device object for a network redirector that registers as a UNC provider (a driver that calls **FsRtlRegisterUncProvider**) must pass FILE_REMOTE_DEVICE as one of the options in the *DeviceCharacteristics* parameter that is passed to **IoCreateDevice**.

To deregister a UNC provider, use [FsRtlDeregisterUncProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlderegisteruncprovider) and pass the *MupHandle* parameter.

If a driver registers as a local disk file system (calls [IoCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedevice) with the *DeviceType* parameter set to FILE_DEVICE_DISK_FILE_SYSTEM rather than FILE_NETWORK_FILE_SYSTEM, for example), the driver must not call **FsRtlRegisterUncProvider** to register as a UNC provider with MUP.

For more information, see the following sections in the Design Guide:

[Support for UNC Naming and MUP](https://learn.microsoft.com/windows-hardware/drivers/ifs/support-for-unc-naming-and-mup)

[MUP Changes in Microsoft Windows Vista](https://learn.microsoft.com/windows-hardware/drivers/ifs/mup-changes-in-microsoft-windows-vista)

## See also

[FsRtlDeregisterUncProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlderegisteruncprovider)

[FsRtlRegisterUncProviderEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlregisteruncproviderex)

[IOCTL_REDIR_QUERY_PATH_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ni-ntifs-ioctl_redir_query_path_ex)

[IoCreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatedevice)