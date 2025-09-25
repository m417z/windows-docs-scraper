# _WDBGEXTS_THREAD_OS_INFO structure

## Description

The IG_GET_THREAD_OS_INFO [Ioctl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nc-wdbgexts-pwindbg_ioctl_routine) operation returns information about an operating system thread in the target. When calling **Ioctl** with *IoctlType* set to IG_GET_THREAD_OS_INFO, *IpvData* should contain an instance of the WDBGEXTS_THREAD_OS_INFO structure.

## Members

### `ThreadId`

Specifies the operating system thread ID (within the current process) for the thread whose information is being requested.

### `ExitStatus`

Receives the exit code of the thread. If the thread is still running or the exit code is not known, **ExitStatus** will be set to STILL_ACTIVE.

### `PriorityClass`

Receives the priority class of the thread. The priority classes are defined by the constants *XXX*_PRIORITY_CLASS in WinBase.h. See the Platform SDK for more information about thread priority classes. If the priority class is not know, **PriorityClass** will be set to zero.

### `Priority`

Receives the priority of the thread relative to the priority class. Some thread priorities are defined by the constants THREAD_PRIORITY_*XXX* in WinBase.h. See the Platform SDK for more information about thread priorities. If the priority is not known, **Priority** will be set to THREAD_PRIORITY_NORMAL.

### `CreateTime`

Receives the creation time of the thread.

### `ExitTime`

Receives the exit time of the thread. If the thread has not exited, **ExitTime** is undefined.

### `KernelTime`

Receives the amount of time that the thread has executed in kernel mode.

### `UserTime`

Receives the amount of time that the thread has executed in user-mode.

### `StartOffset`

Receives the starting address of the thread. If the starting address is not known, **StartOffset** will be set to zero.

### `Affinity`

Receives the thread affinity mask for the thread in a symmetric multiprocessor (SMP) computer. See the Platform SDK for more information about the thread affinity mask. If the affinity mask is not known, **Affinity** is set to zero.

## Remarks

The parameters for the IG_GET_THREAD_OS_INFO [Ioctl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nc-wdbgexts-pwindbg_ioctl_routine) operation are the members of the WDBGEXTS_THREAD_OS_INFO structure.

## See also

[Ioctl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdbgexts/nc-wdbgexts-pwindbg_ioctl_routine)