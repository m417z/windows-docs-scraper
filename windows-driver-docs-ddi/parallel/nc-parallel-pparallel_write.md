# PPARALLEL_WRITE callback

## Description

The PPARALLEL_WRITE-typed callback routine writes data to a parallel device. The system-supplied bus driver for parallel ports supplies this routine.

## Parameters

### `Context` [in]

Pointer to the device extension of a parallel device's physical device object ([PDO](https://learn.microsoft.com/windows-hardware/drivers/)).

### `Buffer` [in]

Pointer to a caller-allocated write buffer.

### `NumBytesToWrite` [in]

Specifies the number of bytes to copy from the write buffer to the parallel device. Must be less than or equal to the number of bytes in the caller-allocated write buffer.

### `NumBytesWritten` [out]

Specifies the number of bytes that were actually copied from the caller-allocated write buffer to the parallel device.

### `Channel` [in]

Not used.

## Return value

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The caller-supplied data was successfully transferred to the device. |
| **STATUS_*Xxx*** | An internal operation resulted in an NTSTATUS error. |

## Prototype

```cpp
typedef NTSTATUS ( *PPARALLEL_WRITE)(
  _In_  PVOID  Context,
  _In_  PVOID  Buffer,
  _In_  ULONG  NumBytesToWrite,
  _Out_ PULONG NumBytesWritten,
  _In_  UCHAR  Channel
);
```

## Remarks

To obtain a pointer to the system-supplied PPARALLEL_WRITE callback, a kernel-mode driver uses an [IOCTL_INTERNAL_PARCLASS_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_parclass_connect) request, which returns a [PARCLASS_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parclass_information) structure. The **ParallelWrite** member of the PARCLASS_INFORMATION structure is a pointer to this callback.

A client can only use this routine if it has a lock on a parallel port. A client obtains a lock on a parallel port by using an [IOCTL_INTERNAL_LOCK_PORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_lock_port) request.

The PPARALLEL_WRITE callback runs in the caller's thread at the IRQL of the caller.

## See also

[PPARALLEL_READ](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_read)

[IOCTL_INTERNAL_LOCK_PORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_lock_port)