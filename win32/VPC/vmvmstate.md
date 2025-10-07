# VMVMState enumeration

\[Windows Virtual PC is no longer available for use as of Windows 8. Instead, use the [Hyper-V WMI provider (V2)](https://learn.microsoft.com/windows/desktop/HyperV_v2/windows-virtualization-portal).\]

Specifies the state of a virtual machine.

## Constants

**vmVMState\_Invalid**

An invalid state (should not occur if the virtual machine exists).

**vmVMState\_TurnedOff**

Off and not saved.

**vmVMState\_Saved**

Off but the guest is saved.

**vmVMState\_TurningOn**

In the process of turning on.

**vmVMState\_Restoring**

Restoring the state.

**vmVMState\_Running**

Running and not paused.

**vmVMState\_Paused**

Running and paused.

**vmVMState\_Saving**

Saving the state.

**vmVMState\_TurningOff**

In the process of turning off.

**vmVMState\_MergingDrives**

In the process of merging undo drives.

**vmVMState\_DeleteMachine**

Deleting the virtual machine.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | None supported<br> |
| End of client support<br> | Windows 7<br> |
| Product<br> | Windows Virtual PC<br> |
| Header<br> | VPCCOMInterfaces.h |

## See also

[**IVMVirtualMachine::State**](https://learn.microsoft.com/windows/win32/vpc/ivmvirtualmachine-state)

[**IVMVirtualMachineEvents::OnStateChange**](https://learn.microsoft.com/windows/win32/vpc/ivmvirtualmachineevents-onstatechange)

[**IVMVirtualPCEvents::OnVMStateChange**](https://learn.microsoft.com/windows/win32/vpc/ivmvirtualpcevents-onvmstatechange)

