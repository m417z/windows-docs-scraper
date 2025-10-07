# VMUndoAction enumeration

\[Windows Virtual PC is no longer available for use as of Windows 8. Instead, use the [Hyper-V WMI provider (V2)](https://learn.microsoft.com/windows/desktop/HyperV_v2/windows-virtualization-portal).\]

Specifies what happens to undo drives when a virtual machine is shut down or turned off.

## Constants

**vmUndoAction\_Discard**

Discard the undo drives; the parent drives remain unchanged.

**vmUndoAction\_Keep**

Keep the undo drives; the parent drives remain unchanged, but changes will be maintained the next time the virtual machine starts.

**vmUndoAction\_Commit**

Commit changes to the parent drives.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | None supported<br> |
| End of client support<br> | Windows 7<br> |
| Product<br> | Windows Virtual PC<br> |
| Header<br> | VPCCOMInterfaces.h |

## See also

[**IVMVirtualMachine::UndoAction**](https://learn.microsoft.com/windows/win32/vpc/ivmvirtualmachine-undoaction)

