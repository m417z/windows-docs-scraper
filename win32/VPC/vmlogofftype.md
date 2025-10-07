# VMLogoffType enumeration

\[Windows Virtual PC is no longer available for use as of Windows 8. Instead, use the [Hyper-V WMI provider (V2)](https://learn.microsoft.com/windows/desktop/HyperV_v2/windows-virtualization-portal).\]

Specifies how to shut down a virtual machine (VM).

## Constants

**vmLogoff\_Normal**

The logoff in the guest VM was normal.

**vmLogoff\_Forced**

The logoff in the guest VM was forced.

**vmLogoff\_External**

The logoff in the guest VM was done using the [**IVMGuestOS::Logoff**](https://learn.microsoft.com/windows/win32/vpc/ivmguestos-logoff) method.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | None supported<br> |
| End of client support<br> | Windows 7<br> |
| Product<br> | Windows Virtual PC<br> |
| Header<br> | VPCCOMInterfaces.h |

## See also

[**IVMVirtualMachine::ShutdownActionOnQuit**](https://learn.microsoft.com/windows/win32/vpc/ivmvirtualmachine-shutdownactiononquit)

