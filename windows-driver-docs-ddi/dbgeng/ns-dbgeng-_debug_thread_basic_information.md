# _DEBUG_THREAD_BASIC_INFORMATION structure

## Description

The DEBUG_THREAD_BASIC_INFORMATION structure describes an operating system thread.

## Members

### `Valid`

A bitset that specifies which other members of the structure contain valid information. A member of the structure is valid if the corresponding bit flag is set in **Valid**.

| Flag | Members |
| --- | --- |
| DEBUG_TBINFO_EXIT_STATUS | **ExitStatus** |
| DEBUG_TBINFO_PRIORITY_CLASS | **PriorityClass** |
| DEBUG_TBINFO_PRIORITY | **Priority** |
| DEBUG_TBINFO_TIMES | **CreateTime**, **ExitTime**, **KernelTime**,  **UserTime** |
| DEBUG_TBINFO_START_OFFSET | **StartOffset** |
| DEBUG_TBINFO_AFFINITY | **Affinity** |

### `ExitStatus`

The exit code of the thread. If the thread is still running, **ExitStatus** is set to STILL_ACTIVE.

**ExitStatus** is only valid if the DEBUG_TBINFO_EXIT_STATUS bit flag is set in **Valid**.

### `PriorityClass`

The priority class of the thread. The priority classes are defined by the *XXX*_PRIORITY_CLASS constants in WinBase.h. For more information about thread priority classes, see the Platform SDK.

**PriorityClass** is only valid if the DEBUG_TBINFO_PRIORITY_CLASS bit flag is set in **Valid**.

### `Priority`

The priority of the thread relative to the priority class. Some thread priorities are defined by the THREAD_PRIORITY_*XXX* constants in WinBase.h. For more information about thread priorities, see the Platform SDK.

**Priority** is only valid if the DEBUG_TBINFO_PRIORITY bit flag is set in **Valid**.

### `CreateTime`

The creation time of the thread.

**CreateTime** is only valid if the DEBUG_TBINFO_TIMES bit flag is set in **Valid**.

### `ExitTime`

The exit time of the thread.

**ExitTime** is only valid if the DEBUG_TBINFO_TIMES bit flag is set in **Valid**.

### `KernelTime`

The amount of time the thread has executed in kernel mode.

**KernelTime** is only valid if the DEBUG_TBINFO_TIMES bit flag is set in **Valid**.

### `UserTime`

The amount of time the thread has executed in user-mode.

**UserTime** is only valid if the DEBUG_TBINFO_TIMES bit flag is set in **Valid**.

### `StartOffset`

The starting address of the thread.

**StartOffset** is only valid if the DEBUG_TBINFO_START_OFFSET bit flag is set in **Valid**.

### `Affinity`

The thread affinity mask for the thread in a Symmetric Multiple Processor (SMP) computer. For more information about the thread affinity mask, see the Platform SDK.

**Affinity** is only valid if the DEBUG_TBINFO_AFFINITY bit flag is set in **Valid**.