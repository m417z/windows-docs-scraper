# VMVirtualMachineEvents enumeration

\[Windows Virtual PC is no longer available for use as of Windows 8. Instead, use the [Hyper-V WMI provider (V2)](https://learn.microsoft.com/windows/desktop/HyperV_v2/windows-virtualization-portal).\]

Specifies the virtual machine (VM) events.

## Constants

**vmVirtualMachineEvent\_StateChanged**

A VM's state has changed.

**vmVirtualMachineEvent\_RequestShutdown**

A shutdown has been requested.

**vmVirtualMachineEvent\_Reset**

A VM has been reset.

**vmVirtualMachineEvent\_TripleFault**

A VM has triple-faulted.

**vmVirtualMachineEvent\_HeartbeatStopped**

A VM's heartbeat has stopped. This usually indicates that the guest operating system has crashed.

**vmVirtualMachineEvent\_ConfigurationChanged**

A value in the configuration for this VM has changed

**vmVirtualMachineEvent\_EnhancedVideoModeChanged**

A VM's video mode has changed.

**vmVirtualMachineEvent\_AdditionsUninstalled**

Integration components have been uninstalled from the VM.

**vmVirtualMachineEvent\_AdditionsAvailable**

Integration are available in the guest operating system.

**vmVirtualMachineEvent\_GuestShutdown**

A guest operating system is shutting down.

**vmVirtualMachineEvent\_GuestLogoff**

A user logged off from the guest operating system.

**vmVirtualMachineEvent\_DiskOutOfSpace**

A disk required by the VM is low on space.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | None supported<br> |
| End of client support<br> | Windows 7<br> |
| Product<br> | Windows Virtual PC<br> |
| Header<br> | VPCCOMInterfaces.h |

## See also

[**IVMVirtualMachineEvents**](https://learn.microsoft.com/windows/win32/vpc/ivmvirtualmachineevents)

