# PSS_HANDLE_ENTRY structure

## Description

Holds information about a handle returned by [PssWalkSnapshot](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/nf-processsnapshot-psswalksnapshot).

## Members

### `Handle`

The handle value.

### `Flags`

Flags that indicate what parts of this structure are valid. For more information, see [PSS_HANDLE_FLAGS](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/ne-processsnapshot-pss_handle_flags).

### `ObjectType`

The type of the object that the handle references. For more information, see [PSS_OBJECT_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/ne-processsnapshot-pss_object_type).

### `CaptureTime`

The capture time of this information. For more information, see [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime).

### `Attributes`

Attributes.

### `GrantedAccess`

Reserved for use by the operating system.

### `HandleCount`

Reserved for use by the operating system.

### `PointerCount`

Reserved for use by the operating system.

### `PagedPoolCharge`

Reserved for use by the operating system.

### `NonPagedPoolCharge`

Reserved for use by the operating system.

### `CreationTime`

Reserved for use by the operating system.

### `TypeNameLength`

The length of **TypeName**, in bytes.

### `TypeName`

The type name of the object referenced by this handle. The buffer may not terminated by a **NULL** character. The pointer is valid for the lifetime of the walk marker passed to [PssWalkSnapshot](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/nf-processsnapshot-psswalksnapshot).

### `ObjectNameLength`

The length of **ObjectName**, in bytes.

### `ObjectName`

Specifies the name of the object referenced by this handle. The buffer may not terminated by a **NULL** character. The pointer is valid for the lifetime of the walk marker passed to [PssWalkSnapshot](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/nf-processsnapshot-psswalksnapshot).

### `TypeSpecificInformation`

Type-specific information.

#### Process

Valid for **ObjectType** = **PSS_OBJECT_TYPE_PROCESS**.

##### ExitStatus

The exit code of the process. If the process has not exited, this is set to **STILL_ACTIVE** (259).

##### PebBaseAddress

The address of the process environment block (PEB). Reserved for use by the operating system.

##### AffinityMask

The affinity mask of the process.

##### BasePriority

The base priority level of the process.

##### ProcessId

The process ID.

##### ParentProcessId

The parent process ID.

##### Flags

Flags about the process. For more information, see [PSS_PROCESS_FLAGS](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/ne-processsnapshot-pss_process_flags).

#### Thread

Valid for **ObjectType** = **PSS_OBJECT_TYPE_THREAD**.

##### ExitStatus

The exit code of the process. If the process has not exited, this is set to **STILL_ACTIVE** (259).

##### TebBaseAddress

The address of the thread environment block (TEB). Reserved for use by the operating system.

##### ProcessId

The process ID.

##### ThreadId

The thread ID.

##### AffinityMask

The affinity mask of the process.

##### Priority

The thread’s dynamic priority level.

##### BasePriority

The thread’s base priority level.

##### Win32StartAddress

A pointer to the thread procedure for the thread.

#### Mutant

Valid for **ObjectType** = **PSS_OBJECT_TYPE_MUTANT**.

##### CurrentCount

Reserved for use by the operating system.

##### Abandoned

**TRUE** if the mutant has been abandoned (the owning thread exited without releasing the mutex), **FALSE** if not.

##### OwnerProcessId

The process ID of the owning thread, at the time of snapshot creation and handle capture.

##### OwnerThreadId

The process ID of the owning thread, at the time of snapshot creation and handle capture.

#### Event

Valid for **ObjectType** = **PSS_OBJECT_TYPE_EVENT**.

##### ManualReset

**TRUE** if the event is manual reset, **FALSE** if not.

##### Signaled

**TRUE** if the event was signaled at the time of snapshot creation and handle capture, **FALSE** if not.

#### Section

Valid for **ObjectType** = **PSS_OBJECT_TYPE_SECTION**.

##### BaseAddress

Reserved for use by the operating system.

##### AllocationAttributes

Reserved for use by the operating system.

##### MaximumSize

Reserved for use by the operating system.

### `Process`

### `Process.ExitStatus`

### `Process.PebBaseAddress`

### `Process.AffinityMask`

### `Process.BasePriority`

### `Process.ProcessId`

### `Process.ParentProcessId`

### `Process.Flags`

### `Thread`

### `Thread.ExitStatus`

### `Thread.TebBaseAddress`

### `Thread.ProcessId`

### `Thread.ThreadId`

### `Thread.AffinityMask`

### `Thread.Priority`

### `Thread.BasePriority`

### `Thread.Win32StartAddress`

### `Mutant`

### `Mutant.CurrentCount`

### `Mutant.Abandoned`

### `Mutant.OwnerProcessId`

### `Mutant.OwnerThreadId`

### `Event`

### `Event.ManualReset`

### `Event.Signaled`

### `Section`

### `Section.BaseAddress`

### `Section.AllocationAttributes`

### `Section.MaximumSize`

### `Semaphore`

### `Semaphore.CurrentCount`

### `Semaphore.MaximumCount`

## Remarks

[PssWalkSnapshot](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/nf-processsnapshot-psswalksnapshot) returns a **PSS_HANDLE_ENTRY** structure when the [PSS_WALK_INFORMATION_CLASS](https://learn.microsoft.com/previous-versions/windows/desktop/api/processsnapshot/ne-processsnapshot-pss_walk_information_class) member that the caller provides it is **PSS_WALK_HANDLES**.

## See also

[Process Snapshotting](https://learn.microsoft.com/previous-versions/windows/desktop/proc_snap/process-snapshotting-portal)