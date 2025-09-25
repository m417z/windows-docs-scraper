# ATOMIC_CREATE_ECP_CONTEXT structure

## Description

The **ATOMIC_CREATE_ECP_CONTEXT** structure contains the extra create parameter (ECP) context that allows supplemental operations to be performed on a file atomically during create.

## Members

### `Size`

The size of this context structure, in bytes.

### `InFlags`

Flags that indicate the requested supplemental operation(s) to be performed with the create operation.

| Value | Meaning |
| ----- | ------- |
| ATOMIC_CREATE_ECP_IN_FLAG_SPARSE_SPECIFIED | Requests that the sparse flag be set on the file. |
| ATOMIC_CREATE_ECP_IN_FLAG_REPARSE_POINT_SPECIFIED | Requests that a reparse point be set on the file. |
| ATOMIC_CREATE_ECP_IN_FLAG_EOF_SPECIFIED | Requests that a file size be set on the file. This also implies
that on-disk allocation will occur to support the requested file size. |
| ATOMIC_CREATE_ECP_IN_FLAG_VDL_SPECIFIED | Requests that a valid data length be set on the file. This also implies that the file size be set to at least the requested valid data length. NOTE: this is considered a privileged operation if it could potentially
expose uninitialized data. |
| ATOMIC_CREATE_ECP_IN_FLAG_OPERATION_MASK | Use this flag as a mask to specify the other **InFlags** flag values. |
| ATOMIC_CREATE_ECP_IN_FLAG_BEST_EFFORT | Indicates that the file system should perform the create operation even if some of the requested supplemental operations could not be
performed or are not supported by the file system. The caller can check **OutFlags** to see which operations were performed. If this flag is not specified, the file system should fail the create operation if it cannot successfully perform all of the requested supplemental operations. |

### `OutFlags`

Flags that indicate the actual supplemental operation(s) performed with a successful create operation.

| Value | Meaning |
| ----- | ------- |
| ATOMIC_CREATE_ECP_OUT_FLAG_SPARSE_SET | Indicates that the sparse flag was set on the file. |
| ATOMIC_CREATE_ECP_OUT_FLAG_REPARSE_POINT_SET | Indicates that a reparse point was set on the file. |
| ATOMIC_CREATE_ECP_OUT_FLAG_EOF_SET | Indicates that a file size was set on the file, and that on-disk allocation occurred to support the requested file size. |
| ATOMIC_CREATE_ECP_OUT_FLAG_VDL_SET | Indicates that a valid data length was set on the file, and that the file size was set to at least the requested valid data length. |
| ATOMIC_CREATE_ECP_OUT_FLAG_OPERATION_MASK | Use this flag value as a mask to determine the supplemental operations that were performed with the create operation. |

### `ReparseBufferLength`

The length of the **ReparseBuffer** member. This value can't exceed the **MAXIMUM_REPARSE_DATA_BUFFER_SIZE** (16K).

### `ReparseBuffer`

The optional value that indicates the type of buffer used in the create operation. Possible values are **REPARSE_DATA_BUFFER** or **REPARSE_GUID_DATA_BUFFER**.

### `FileSize`

The optional value that is used with **ATOMIC_CREATE_ECP_IN_FLAG_EOF_SPECIFIED** to indicate the requested file size to be set on the file.

### `ValidDataLength`

The optional value that is used with **ATOMIC_CREATE_ECP_IN_FLAG_VDL_SPECIFIED** to indicate the requested valid data length to be set on the file.

### `FileTimestamps`

Pointer to an optional [**FILE_TIMESTAMPS**](https://learn.microsoft.com/previous-versions/mt826486(v=vs.85)) structure which contains the last recorded instance of specific actions on a file.

### `FileAttributes`

Specifies the attributes of a file.

### `UsnSourceInfo`

Specifies optional Update Sequence Number (USN) source info flags.

### `Usn`

Specifies the Update Sequence Number (USN). This value is filled at the end of **GUID_ECP_ATOMIC_CREATE** .

### `SuppressFileAttributeInheritanceMask`

Mask that indicates the file attributes whose normal inheritance rules should be suppressed.

### `InOpFlags`

ATOMIC_CREATE_ECP_IN_OP_FLAG_xxx flags.

### `OutOpFlags`

ATOMIC_CREATE_ECP_OUT_OP_FLAG_xxx flags.

### `InGenFlags`

ATOMIC_CREATE_ECP_IN_GN_FLAG_xxx flags.

### `OutGenFlags`

ATOMIC_CREATE_ECP_OUT_GN_FLAG_xxx flags.

### `CaseSensitiveFlagsMask`

Indicates which FILE_CS_FLAG_xxx flags are specified; file systems should pick the default values for other flags.

### `InCaseSensitiveFlags`

Input case sensitive flags on the file. Even if no BEST_EFFORT is specified, file systems can ignore some of the InCaseSensitiveFlags. The behavior is similar to FileCaseSensitiveInformation so callers could examine **OutCaseSensitiveFlags** to know the flags that are set. If a flag is not supported on some file or directory then BEST_EFFORT would take effect.

### `OutCaseSensitiveFlags`

This member returns the case sensitive flags on the file, even if no **InCaseSensitiveFlags** are specified.

## Remarks

The system-defined GUID_ECP_ATOMIC_CREATE** value is used with this ECP context structure when calling ECP-related support routines such as [**FltAllocateExtraCreateParameter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocateextracreateparameter) and [**FsRtlRemoveExtraCreateParameter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlremoveextracreateparameter).

See [Introduction to extra create parameters](https://learn.microsoft.com/windows-hardware/drivers/ifs/introduction-to-extra-create-parameters) for more information.