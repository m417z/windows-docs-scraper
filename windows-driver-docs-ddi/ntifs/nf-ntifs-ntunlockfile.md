# NtUnlockFile function

## Description

The **NtUnlockFile** routine unlocks a byte-range lock in a file.

## Parameters

### `FileHandle` [in]

A handle for the file object that represents the file whose byte range is to be unlocked.

### `IoStatusBlock` [out]

A pointer to an [**IO_STATUS_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block) structure that contains the final status.

### `ByteOffset` [in]

A pointer to a variable that specifies the starting byte offset for the byte range to be unlocked.

### `Length` [in]

A pointer to a variable that specifies the length, in bytes, of the byte range to unlock.

### `Key` [in]

The caller-assigned value used to describe groups of related locks. This value should be set to zero.

## Return value

The **NtUnlockFile** routine returns STATUS_SUCCESS on success or an appropriate NTSTATUS value. Possible NTSTATUS values include:

| Return code | Description |
| ----------- | ----------- |
| STATUS_RANGE_NOT_LOCKED | The byte range specified is not locked. |

## Remarks

The **NtUnlockFile** routine takes a range of bytes as specified by the **ByteOffset** and **Length** arguments. This range must be identical to a range of bytes in the file that was previously locked with a single call to the **NtUnlockFile** routine. It is not possible to unlock two previously locked adjacent ranges with a single call to **NtUnlockFile**. It is also not possible to unlock part of a range that was previously locked with a single call to the **NtUnlockFile** routine.

Callers of **NtUnlockFile** must be running at IRQL = PASSIVE_LEVEL and [with special kernel APCs enabled**](https://learn.microsoft.com/windows-hardware/drivers/kernel/disabling-apcs).

> [!NOTE]
> If the call to the **NtUnlockFile** function occurs in kernel mode, you should use the name "[**ZwUnlockFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwlockfile)" instead of "**NtUnlockFile**".

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[**NtLockFile**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntlockfile)