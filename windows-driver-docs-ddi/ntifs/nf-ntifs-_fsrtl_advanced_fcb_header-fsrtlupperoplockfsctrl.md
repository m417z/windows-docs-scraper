# FsRtlUpperOplockFsctrl function

## Description

The **FsRtlUpperOplockFsctrl** routine processes opportunistic lock (oplock) requests and acknowledgments for secondary, or layered, file systems. The upper file system submits the state of the oplock held in the lower file system. **FsRtlUpperOplockFsctrl** will determine whether to grant or deny the upper file system oplock.

## Parameters

### `Oplock` [in]

An opaque oplock pointer for the file. This pointer must have been initialized by a previous call to [**FsRtlInitializeOplock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlinitializeoplock).

### `Irp` [in]

A pointer to the IRP for the I/O operation.

### `OpenCount` [in]

Number of user handles for the file, if an exclusive oplock is being requested. Setting a nonzero value for a level 2, R, or RH oplock request indicates that there are byte-range locks on the file. For more information about oplock types, see [Types of Oplocks](https://learn.microsoft.com/windows/win32/fileio/types-of-opportunistic-locks).

### `LowerOplockState` [in]

The value the lower oplock level held by the upper file system. This a bitwise OR combination of the following:

| Value | Meaning |
| ----- | ------- |
| OPLOCK_LEVEL_CACHE_READ | Indicates an oplock Read (R) type. |
| OPLOCK_LEVEL_CACHE_WRITE | Indicates an oplock Write (W) type. |
| OPLOCK_LEVEL_CACHE_HANDLE | Indicates an oplock Handle (H) type. |

### `Flags` [in]

A bitmask for the associated oplock operations. A file system or filter driver sets bits to specify the behavior of **FsRtlUpperOplockFsctrl**. The **Flags** parameter has the following options:

| Value | Meaning |
| ----- | ------- |
| OPLOCK_FSCTRL_FLAG_ALL_KEYS_MATCH (0x00000001) | The file system verified that all oplock keys on any currently open handles match. By specifying this flag, you allow the oplock package to grant an oplock of level RW or RWH when more than one open handle to the file exists. |

## Return value

**FsRtlUpperOplockFsctrl** returns one of the following NTSTATUS values:

| Return code | Description |
| ----------- | ----------- |
| STATUS_SUCCESS | For an IRP_MJ_CREATE request, STATUS_SUCCESS indicates that the requested filter opportunistic lock (oplock) was granted. For a FSCTL operation, the meaning of STATUS_SUCCESS depends on the FSCTL code. For more information, see the Remarks section in [**FsRtlOplockFsctrlEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtloplockfsctrlex). |
| STATUS_CANCELLED | The I/O operation was canceled. STATUS_CANCELLED is an error code. |
| STATUS_INVALID_PARAMETER | The FSCTL code for the I/O operation was not a valid values oplock request. Valid request types are listed in the Remarks section of **FsRtlOplockFsctrlEx**. STATUS_INVALID_PARAMETER is an error code. |
| STATUS_OPLOCK_NOT_GRANTED | The oplock could not be granted. The level of the requested upper file system oplock is not valid for the oplock granted for the lower file system. STATUS_OPLOCK_NOT_GRANTED is an error code. |
| STATUS_PENDING | Used only for FSCTL operations. The meaning of STATUS_PENDING depends on the FSCTL code. For more information, see the Remarks section in [**FsRtlOplockFsctrlEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtloplockfsctrlex). STATUS_PENDING is a success code. |
| STATUS_CANNOT_GRANT_REQUESTED_OPLOCK | An oplock acknowledgement for a new oplock is not allowed. The level of the upper file system of lock is not valid for the lower file system oplock. |

## See also

[**FsRtlCheckUpperOplock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlcheckupperoplock)

[**FsRtlOplockFsctrlEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtloplockfsctrlex)