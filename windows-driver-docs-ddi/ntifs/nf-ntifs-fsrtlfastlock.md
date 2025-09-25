# FsRtlFastLock macro

## Description

The **FsRtlFastLock** macro is used by file systems and filter drivers to request a byte-range lock for a file stream.

## Syntax

```cpp
BOOLEAN
FsRtlFastLock( A1,   /* FileLock            */
               A2,   /* FileObject          */
               A3,   /* FileOffset          */
               A4,   /* Length              */
               A5,   /* ProcessId           */
               A6,   /* Key                 */
               A7,   /* FailImmediately     */
               A8,   /* ExclusiveLock       */
               A9,   /* Iosb                */
               A10,  /* Context             */
               A11   /* AlreadySynchronized */ )
```

## Parameters

### `A1`

[in] **FileLock**: Pointer to the [**FILE_LOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_lock) structure for the file. This structure must have been initialized by a previous call to [**FsRtlAllocateFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlallocatefilelock) or [**FsRtlInitializeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializefilelock).

### `A2`

[in] **FileObject**: Pointer to the [**FILE_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) for the open file. The file object must have been created with GENERIC_READ or GENERIC_WRITE access to the file (or both).

### `A3`

[in] **FileOffset**: Pointer to a variable that specifies the starting byte offset within the file of the range to be locked.

### `A4`

[in] **Length**: Pointer to a variable that specifies the length in bytes of the range to be locked.

### `A5`

[in] **ProcessId**: Pointer to the [**EPROCESS**](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) process ID for the process requesting the byte-range lock.

### `A6`

[in] **Key**: The key to be assigned to the byte-range lock.

### `A7`

[in] **FailImmediately**: Boolean value that specifies whether the lock request should fail if the lock cannot be granted immediately. If the caller can be put into a wait state until the request is granted, set **FailImmediately** to FALSE. If it cannot, set **FailImmediately** to TRUE.

### `A8`

[in] **ExclusiveLock**: Set to TRUE if an exclusive lock is requested, FALSE if a shared lock is requested.

### `A9`

[out] **Iosb**: Pointer to a caller-allocated [**IO_STATUS_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block) structure that receives status information about the lock request.

### `A10`

[in] **Context**: Optional pointer to a context to use when releasing the byte-range lock.

### `A11`

[in] **AlreadySynchronized**: This parameter is obsolete, but is retained for compatibility with legacy drivers.

## Remarks

The **FsRtlFastLock** macro causes the caller to acquire a byte-range lock on a region of the specified file.

**FsRtlFastLock** returns TRUE to indicate that the IO_STATUS_BLOCK structure pointed to by **Iosb** received status information about the lock operation; otherwise it returns FALSE.

To examine the contents of the structure that **Iosb** points to, use the NT_STATUS macro.

## See also

[**FILE_LOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-file_lock)

[**FsRtlAllocateFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlallocatefilelock)

[**FsRtlInitializeFileLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializefilelock)