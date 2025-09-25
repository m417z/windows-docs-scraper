# NtLockFile function

## Description

The **NtLockFile** routine requests a byte-range lock for the specified file.

## Parameters

### `FileHandle` [in]

A handle for the file on which a byte-range lock is requested.

### `Event` [in, optional]

A handle to a caller-created event. If not **NULL**, the caller is placed into a wait state until the operation succeeds, at which time the event is set into the Signaled state.

### `ApcRoutine` [in, optional]

A pointer to a caller-supplied APC routine that is executed after the operation completes. Can be **NULL**.

### `ApcContext` [in, optional]

A pointer to a caller-specified context for the APC routine. This value is passed to the APC routine when it is executed. Can be **NULL**.

### `IoStatusBlock` [out]

A pointer to an [**IO_STATUS_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block) structure that contains the final status.

### `ByteOffset` [in]

A pointer to a variable that specifies the starting byte offset of the range to lock.

### `Length` [in]

A pointer to a variable that specifies the length in bytes of the range to lock.

### `Key` [in]

A caller-assigned value used to describe groups of related locks. This value should be set to zero.

### `FailImmediately` [in]

If **TRUE**, immediately return if the file cannot be locked. If **FALSE**, wait for the lock request to be granted.

### `ExclusiveLock` [in]

If **TRUE**, byte-range lock is exclusive; otherwise, shared lock.

## Return value

The **NtLockFile** routine returns STATUS_SUCCESS or an appropriate error NTSTATUS value. Possible NTSTATUS values include the following:

| Return code | Description |
| ----------- | ----------- |
| STATUS_INSUFFICIENT_RESOURCES | Insufficient resources exist to grant the byte-range lock for the specified file. |
| STATUS_LOCK_NOT_GRANTED | The byte-range lock was not granted for the specified file. |

## Remarks

Callers of **NtLockFile** must be running at IRQL = PASSIVE_LEVEL and [with special kernel APCs enabled**](https://learn.microsoft.com/windows-hardware/drivers/kernel/disabling-apcs).

> [!NOTE]
> If the call to the **NtLockFile** function occurs in user mode, you should use the name "**NtLockFile**" instead of "**ZwLockFile**".

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines**](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[**NtUnlockFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntunlockfile)