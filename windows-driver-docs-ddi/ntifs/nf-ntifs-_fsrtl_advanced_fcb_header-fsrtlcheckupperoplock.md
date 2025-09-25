# FsRtlCheckUpperOplock function

## Description

The **FsRtlCheckUpperOplock** routine provides opportunistic lock (oplock) checking in secondary, or layered, file systems when the oplocks they hold change state. Secondary file systems, such as network redirectors and clustering file services, call **FsRtlCheckUpperOplock** when an oplock held in a lower file system by the secondary file system, changes state. A state change can occur either by a break or an upgrade. **FsRtlCheckUpperOplock** will break the oplock of upper file system, if necessary, to confirm the new lower oplock state. The caller can also provide optional callbacks for notifications of break acknowledgment and pending status.

## Parameters

### `Oplock` [in]

An opaque oplock pointer for the file. This pointer must have been initialized by a previous call to [**FsRtlInitializeOplock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializeoplock).

### `NewLowerOplockState` [in]

A value representing the requested oplock held in a lower file system by a secondary file system. This a bitwise OR combination of the following:

| Value | Meaning |
| ----- | ------- |
| OPLOCK_LEVEL_CACHE_READ | Indicates an oplock Read (R) type. |
| OPLOCK_LEVEL_CACHE_WRITE | Indicates an oplock Write (W) type. |
| OPLOCK_LEVEL_CACHE_HANDLE | Indicates an oplock Handle (H) type. |

### `CompletionRoutineContext` [in, optional]

A pointer to caller-defined context information to be passed to the callback routines that the **CompletionRoutine** and **PrePendIrpRoutine** parameters point to.

### `CompletionRoutine` [in, optional]

A pointer to a caller-supplied callback routine. If an opportunistic lock break is in progress, this routine is called when the break is completed. This parameter is optional and can be NULL. If it is NULL, the caller is put into a wait state until the opportunistic lock break is completed.

This routine's declaration and parameter descriptions are as follows:

```cpp
typedef VOID
(*POPLOCK_WAIT_COMPLETE_ROUTINE) (
      _In_ PVOID Context,
      _In_opt_ PIRP Irp
      );
```

| Parameter | Description |
| --------- | ----------- |
| **Context** | A context information pointer that was passed in the **CompletionRoutineContext** parameter to **FsRtlCheckUpperOplock**. |
| **Irp** | An optional pointer to the IRP for the I/O operation. **FsRtlCheckUpperOplock** will always set this to NULL. |

### `PrePendRoutine`

A pointer to a caller-supplied callback routine to be called if **FsRtlCheckUpperOplock** will return STATUS_PENDING. This parameter is optional and can be NULL.

This routine's declaration and parameter descriptions are as follows:

```cpp
typedef VOID
(*POPLOCK_FS_PREPOST_IRP) (
      _In_ PVOID Context,
      _in_opt_ PIRP Irp
      );
```

| Parameter | Description |
| --------- | ----------- |
| **Context** | A context information pointer that was passed in the **CompletionRoutineContext** parameter to **FsRtlCheckUpperOplock**. |
| **Irp** | An optional pointer to the IRP for the I/O operation. **FsRtlCheckUpperOplock** will always set this to NULL. |

### `Flags` [in]

A bitmask for the associated file I/O operation. A file system or filter driver sets bits to specify the behavior of **FsRtlCheckUpperOplock**. The **Flags** parameter has the following options:

| Value | Meaning |
| ----- | ------- |
| OPLOCK_UPPER_FLAG_CHECK_NO_BREAK (0x00010000) | Return STATUS_CANNOT_BREAK_OPLOCK if the value of **NewLowerOplockState** results in any oplock break. |
| OPLOCK_UPPER_FLAG_NOTIFY_REFRESH_READ (0x00020000) | Break only Read (R) upper oplocks and notify R holders that they may again request R. All other upper oplock checks it will return STATUS_CANNOT_BREAK_OPLOCK. |

## Return value

**FsRtlCheckUpperOplock** returns an appropriate NTSTATUS code such as one of the following:

| Return code | Description |
| ----------- | ----------- |
| STATUS_SUCCESS | An oplock break is not required or the break was acknowledged. If **CompletionRoutine** is NULL, **FsRtlCheckUpperOplock** blocks while the oplock break is processed rather than return STATUS_PENDING. |
| STATUS_CANNOT_BREAK_OPLOCK | The oplock break cannot be accomplished. See **Flags** for conditions that restrict a break. |
| STATUS_PENDING | An opportunistic lock break is underway. If supplied, **PrePendIrpRoutine** is called as a notification of the pending operation. **CompletionRoutine** is called when the oplock break is complete. STATUS_PENDING is a success code. |

## See also

[**FsRtlCheckOplockEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlcheckoplockex)

[**FsRtlUpperOplockFsctrl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlupperoplockfsctrl)