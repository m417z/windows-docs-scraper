# VMShutdownAction enumeration

\[Windows Virtual PC is no longer available for use as of Windows 8. Instead, use the [Hyper-V WMI provider (V2)](https://learn.microsoft.com/windows/desktop/HyperV_v2/windows-virtualization-portal).\]

Specifies how to shut down a virtual machine (VM) when the host shuts down or the vpc.exe process exits.

## Constants

**vmShutdownAction\_Save**

Save the VM state.

**vmShutdownAction\_TurnOff**

Turn off the VM without undoing the drives.

**vmShutdownAction\_Shutdown**

Shut down the guest operating system on the VM without undoing the drives if the integration components are available and will save the VM otherwise.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | None supported<br> |
| End of client support<br> | Windows 7<br> |
| Product<br> | Windows Virtual PC<br> |
| Header<br> | VPCCOMInterfaces.h |

## See also

[Windows Virtual PC Enumerations](https://learn.microsoft.com/windows/win32/vpc/virtual-pc-enumerations)

[**IVMVirtualMachine::ShutdownActionOnQuit**](https://learn.microsoft.com/windows/win32/vpc/ivmvirtualmachine-shutdownactiononquit)

