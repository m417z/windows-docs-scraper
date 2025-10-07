# VMTaskResult enumeration

\[Windows Virtual PC is no longer available for use as of Windows 8. Instead, use the [Hyper-V WMI provider (V2)](https://learn.microsoft.com/windows/desktop/HyperV_v2/windows-virtualization-portal).\]

Specifies the result of a task.

## Constants

**vmTaskResult\_Success**

The task was successful.

**vmTaskResult\_Cancelled**

The task was canceled.

**vmTaskResult\_UnexpectedError**

The task had an unexpected error.

**vmTaskResult\_OutOfMemoryError**

There was not enough memory for the task to complete.

**vmTaskResult\_DiskRelatedError**

The task had an error while writing to disk (make sure there is enough disk space).

**vmTaskResult\_IncompatibleSavedStateError**

The virtual machine could not restore because the saved state was incompatible.

**vmTaskResult\_TimeOutError**

The task timed out.

**vmTaskResult\_IllegalValueError**

An illegal preference value was read while the task was processing.

**vmTaskResult\_ThreadCrashError**

A thread associated with the task crashed.

**vmTaskResult\_ShutdownAbort**

The shutdown requested was aborted.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | None supported<br> |
| End of client support<br> | Windows 7<br> |
| Product<br> | Windows Virtual PC<br> |
| Header<br> | VPCCOMInterfaces.h |

## See also

[**IVMTask::Result**](https://learn.microsoft.com/windows/win32/vpc/ivmtask-result)

